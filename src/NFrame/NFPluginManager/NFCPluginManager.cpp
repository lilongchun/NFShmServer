// -------------------------------------------------------------------------
//    @FileName         :    NFCPluginManager.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFCPluginManager
//
// -------------------------------------------------------------------------

#include "NFCPluginManager.h"
#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFProfiler.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFPrintfLogo.h"
#include "NFComm/NFCore/NFServerTime.h"
#include "NFComm/NFPluginModule/NFIConsoleModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFITaskModule.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFSignalHandleMgr.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "hwinfo/hw_info.h"

#include <csignal>
#include <utility>
#include <thread>
#include <chrono>

#include "sigar/sigar.h"

#ifdef __cplusplus
extern "C"
{
#endif
int sigar_net_address_to_string(sigar_t *sigar,
                                sigar_net_address_t *address,
                                char *addr_str);
#ifdef __cplusplus
}
#endif

#if NF_PLATFORM == NF_PLATFORM_WIN
#elif NF_PLATFORM == NF_PLATFORM_LINUX
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFServerIDUtil.h"

#endif

NFCPluginManager::NFCPluginManager() : NFIPluginManager(),m_appInited(this)
{
	m_nCurFrameCount = 0;
	m_nAppID = 0;

	m_strConfigPath = "../../Config";
	m_strPluginPath = "../../Plugin";
	m_strLogPath = "logs";

	m_nInitTime = NFTime::Now().UnixMSec();
	m_nNowTime = m_nInitTime;
	m_isDaemon = false;
	m_bInitShm = false;
	m_isKillPreApp = false;
    m_bReloadServer = false;
    m_bServerStopping = false;
	m_bChangeProfileApp = false;
    m_bHotfixServer = false;
    m_bFixedFrame = true;

	m_isInited = false;

    m_isAllServer = false;

    m_idleSleepUs = 1000;

    NFServerTime::Instance()->Init(m_nFrame);

	NFRandomSeed();
//#ifdef NF_DEBUG_MODE
	SetOpenProfiler(true);
//#endif
}

NFCPluginManager::~NFCPluginManager()
{
}

bool NFCPluginManager::IsDaemon() const
{
	return m_isDaemon;
}

void NFCPluginManager::SetDaemon()
{
	m_isDaemon = true;
}

bool NFCPluginManager::IsInitShm() const
{
	return m_bInitShm;
}

void NFCPluginManager::SetInitShm()
{
	m_bInitShm = true;
}

bool NFCPluginManager::IsLoadAllServer() const
{
	return m_isAllServer;
}

void NFCPluginManager::SetLoadAllServer(bool b)
{
    m_isAllServer = b;
}

bool NFCPluginManager::AfterLoadAllPlugin()
{
    //调用所有module的Awake函数
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        (*iter)->AfterLoadAllPlugin();
    }

    return true;
}

bool NFCPluginManager::AfterInitShmMem()
{
    //调用所有module的Awake函数
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        (*iter)->AfterInitShmMem();
    }

    return true;
}

bool NFCPluginManager::Awake()
{
	//调用所有module的Awake函数
	for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
	{
		(*iter)->Awake();
	}

	return true;
}

bool NFCPluginManager::LoadAllPlugin()
{
#ifndef NF_DYNAMIC_PLUGIN
	RegisterStaticPlugin(); //注册静态引擎
	LoadKernelPlugin(); //NFKernelPlugin比较特殊，提前加载
	//打印LOG
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{}", PrintfLogo());

	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager Awake................");

	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "LoadPlugin:NFKernelPlugin");
	//加载引擎配置plugin.xml, 创建引擎，生成module
	LoadPluginConfig();
	for (PluginNameVec::iterator it = m_nPluginNameVec.begin(); it != m_nPluginNameVec.end(); ++it)
	{
		LoadStaticPlugin(*it);
	}
#else
	LoadKernelPlugin(); //NFKernelPlugin比较特殊，提前加载


	//打印LOG
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{}", PrintfLogo());

	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager Awake................");
	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "LoadPlugin:NFKernelPlugin");
	//加载引擎配置plugin.xml, 创建引擎，生成module
	LoadPluginConfig();
	for (PluginNameVec::iterator it = m_nPluginNameVec.begin(); it != m_nPluginNameVec.end(); ++it)
	{
		LoadPluginLibrary(*it);
		NFIPlugin* pPlugin = FindPlugin(*it);
		if (pPlugin->IsDynamicLoad())
		{
			((NFIPluginManager*)this)->FindModule<NFIConsoleModule>()->AddDynamicPluginFile(*it);
		}
	}

#endif
	return true;
}

bool NFCPluginManager::Begin()
{
	LoadAllPlugin();
    AfterLoadAllPlugin();
    AfterInitShmMem();
	Awake();
	Init();
	CheckConfig();
	ReadyExecute();
	return true;
}

bool NFCPluginManager::End()
{
	BeforeShut();
	Shut();
	Finalize();

	return true;
}

inline bool NFCPluginManager::Init()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager Init................");
	for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
	{
		(*iter)->Init();
	}

	return true;
}

bool NFCPluginManager::LoadPluginConfig()
{
	NFPluginConfig* pConfig = ((NFIPluginManager*)this)->FindModule<NFIConfigModule>()->GetPluginConfig(m_strAppName);
	if (pConfig == nullptr)
	{
		NF_ASSERT_MSG(0, "There are no plugin:" + m_strAppName);
		return false;
	}

	for (size_t i = 0; i < pConfig->FramePlugins.size(); i++)
	{
		std::string strPluginName = pConfig->FramePlugins[i];
		m_nPluginNameVec.push_back(strPluginName);
	}

    for (size_t i = 0; i < pConfig->ServerPlugins.size(); i++)
    {
        std::string strPluginName = pConfig->ServerPlugins[i];
        m_nPluginNameVec.push_back(strPluginName);
    }

    for (size_t i = 0; i < pConfig->WorkPlugins.size(); i++)
    {
        std::string strPluginName = pConfig->WorkPlugins[i];
        m_nPluginNameVec.push_back(strPluginName);
    }

	return true;
}

void NFCPluginManager::RegisteredStaticPlugin(const std::string& strPluginName, const CREATE_PLUGIN_FUNCTION& createFunc)
{
	m_nPluginFuncMap.emplace(strPluginName, createFunc);
}

void NFCPluginManager::Registered(NFIPlugin* plugin)
{
	if (plugin == nullptr) return;

	//动态加载的情况下，直接使用FindPlugin(plugin->GetPluginName()) 将导致崩溃， 这到底是为啥呢
	std::string strPluginName = plugin->GetPluginName();
	if (!FindPlugin(strPluginName))
	{
		m_nPluginInstanceMap.insert(PluginInstanceMap::value_type(strPluginName, plugin));
		m_nPluginInstanceList.push_back(plugin);
		plugin->Install();
	}
	else
	{
		assert(0);
	}
}

void NFCPluginManager::UnRegistered(NFIPlugin* plugin)
{
	if (plugin == nullptr)
	{
		std::cerr << "UnRegistered, plugin == nullptr" << std::endl;
		return;
	}

	//动态加载的情况下，直接使用mPluginInstanceMap.find(plugin->GetPluginName()) 将导致崩溃， 这到底是为啥呢
	std::string strPluginName = plugin->GetPluginName();
	PluginInstanceMap::iterator it = m_nPluginInstanceMap.find(strPluginName);
	if (it != m_nPluginInstanceMap.end())
	{
		if (it->second == nullptr)
		{
			m_nPluginInstanceMap.erase(it);
			return;
		}

		for (auto listIt = m_nPluginInstanceList.begin(); listIt != m_nPluginInstanceList.end(); listIt++)
		{
			if (it->second == *listIt)
			{
				m_nPluginInstanceList.erase(listIt);
				break;
			}
		}

		it->second->Uninstall();
		NF_SAFE_DELETE(it->second);
		it->second = nullptr;
		m_nPluginInstanceMap.erase(it);
	}
}

NFIPlugin* NFCPluginManager::FindPlugin(const std::string& strPluginName)
{
	PluginInstanceMap::iterator it = m_nPluginInstanceMap.find(strPluginName);
	if (it != m_nPluginInstanceMap.end())
	{
		return it->second;
	}

	return nullptr;
}

bool NFCPluginManager::Execute()
{
	bool bRet = true;
	m_nNowTime = NFTime::Now().UnixMSec();
	uint64_t startTime = NFTime::Tick();
	uint64_t endTime = 0;
	m_nCurFrameCount++;

    NFServerTime::Instance()->Update(startTime);   //

	BeginProfiler("MainLoop");

	if (!IsInited()) {
        m_appInited.Execute();
    }

	for (auto it = m_nPluginInstanceMap.begin(); it != m_nPluginInstanceMap.end(); ++it)
	{
		BeginProfiler(it->first + "--Loop");
		bool tembRet = it->second->Execute();
		bRet = bRet && tembRet;
		uint64_t useTime = EndProfiler();
		if (useTime >= 30000) //>= 10毫秒
		{
			if (!IsLoadAllServer())
			{
				NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "mainthread:{} use time:{} ms", it->first + "--Loop", useTime / 1000);
			}
		}
	}

	EndProfiler();

	//采用固定帧率
	endTime = NFTime::Tick();
	uint32_t cost = static_cast<uint32_t>(endTime > startTime ? (endTime - startTime) : 0);
	if (m_bFixedFrame)
    {
        uint32_t sleepTime = m_nFrameTime > cost ? (m_nFrameTime - cost) : 0;
        if (sleepTime > 0)
        {
            NFSLEEP(sleepTime*1000);
        }
        else
        {
            if (cost >= 40 && cost <= 200)
            {
                if (!IsLoadAllServer())
                {
                    NFLogWarning(NF_LOG_PLUGIN_MANAGER, 0, "mainthread frame timeout:{}", cost);

                }
            }
            else if (cost > 200)
            {
                if (!IsLoadAllServer())
                {
                    NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "mainthread frame timeout:{}, something wrong", cost);
                    //PrintProfiler();
                }
            }
            else
            {
                NFSLEEP(1000);
            }
        }
    }
    else
    {
        if (cost >= 40 && cost <= 200)
        {
            if (!IsLoadAllServer())
            {
                NFLogWarning(NF_LOG_PLUGIN_MANAGER, 0, "mainthread:{} frame timeout:{}", NFCommon::tostr(std::this_thread::get_id()), cost);
            }
        }
        else if (cost > 200)
        {
            if (!IsLoadAllServer())
            {
                NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "mainthread:{} frame timeout:{}, something wrong", NFCommon::tostr(std::this_thread::get_id()), cost);
                //PrintProfiler();
            }
        }
        else
        {
            if (IsLoadAllServer())
            {
                NFSLEEP(1000);
            }
            else
            {
                NFSLEEP(m_idleSleepUs);
            }
        }
    }

    if (m_bFixedFrame)
    {
        if (m_nCurFrameCount % 10000 == 0)
        {
            PrintProfiler();
        }
    }
    else
    {
        if (m_nCurFrameCount % 1000000 == 0)
        {
            PrintProfiler();
        }
    }


	return bRet;
}

inline int NFCPluginManager::GetAppID() const
{
	return m_nAppID;
}

void NFCPluginManager::SetAppID(const int nAppID)
{
	m_nAppID = nAppID;
}

int NFCPluginManager::GetWorldID() const
{
    return NFServerIDUtil::GetWorldID(m_nAppID);
}


int NFCPluginManager::GetZoneID() const
{
    return NFServerIDUtil::GetZoneID(m_nAppID);
}



const std::string& NFCPluginManager::GetConfigPath() const
{
	return m_strConfigPath;
}

void NFCPluginManager::SetConfigPath(const std::string& strPath)
{
	if (strPath.empty()) return;

	m_strConfigPath = strPath;
}

const std::string& NFCPluginManager::GetPluginPath() const
{
	return m_strPluginPath;
}

void NFCPluginManager::SetPluginPath(const std::string& strPath)
{
	if (strPath.empty()) return;

	m_strPluginPath = strPath;
}

void NFCPluginManager::SetLuaScriptPath(const std::string& luaScriptPath)
{
	if (luaScriptPath.empty()) return;
	m_strLuaScriptPath = luaScriptPath;
}

void NFCPluginManager::SetGame(const std::string& game)
{
	if (game.empty()) return;
	m_strGame = game;
}

const std::string& NFCPluginManager::GetLuaScriptPath() const
{
	return m_strLuaScriptPath;
}

const std::string& NFCPluginManager::GetGame() const
{
	return m_strGame;
}

void NFCPluginManager::SetBusName(const std::string& busName)
{
	m_mStrBusName = busName;
}

const std::string& NFCPluginManager::GetBusName() const
{
	return m_mStrBusName;
}

const std::string& NFCPluginManager::GetAppName() const
{
	return m_strAppName;
}

const std::string& NFCPluginManager::GetStrParam() const
{
    return m_strParam;
}

void NFCPluginManager::SetStrParam(const std::string& strAppName)
{
    m_strParam = strAppName;
}


const std::string& NFCPluginManager::GetFullPath() const
{
	return m_strFullPath;
}

void NFCPluginManager::SetFullPath(const std::string& str)
{
	m_strFullPath = str;
	m_strExeName = NFFileUtility::GetFileName(str);
}

void NFCPluginManager::SetAppName(const std::string& strAppName)
{
	if (!m_strAppName.empty())
	{
		return;
	}

	m_strAppName = strAppName;
}

const std::string& NFCPluginManager::GetLogPath() const
{
	return m_strLogPath;
}

void NFCPluginManager::SetLogPath(const std::string& strName)
{
	if (strName.empty()) return;
	m_strLogPath = strName;
}

int NFCPluginManager::AddModule(const std::string& strModuleName, NFIModule* pModule)
{
    CHECK_EXPR_ASSERT(pModule != NULL, -1, "pModule != NULL name:{}", strModuleName);
    CHECK_EXPR_ASSERT(m_nModuleInstanceMap.find(strModuleName) == m_nModuleInstanceMap.end(), -1, "module exist name:{} --- {}", strModuleName, pModule->m_strName);

	m_nModuleInstanceMap.insert(ModuleInstanceMap::value_type(strModuleName, pModule));
	return 0;
}

void NFCPluginManager::RemoveModule(const std::string& strModuleName)
{
	ModuleInstanceMap::iterator it = m_nModuleInstanceMap.find(strModuleName);
	if (it != m_nModuleInstanceMap.end())
	{
		m_nModuleInstanceMap.erase(it);
	}
}

NFIModule* NFCPluginManager::FindModule(const std::string& strModuleName)
{
	std::string strSubModuleName = strModuleName;

#if NF_PLATFORM == NF_PLATFORM_WIN
	
	std::size_t position = strSubModuleName.find(' ');
	if (string::npos != position)
	{
		strSubModuleName = strSubModuleName.substr(position + 1, strSubModuleName.length());
	}
	
#else
	
	for (int i = 0; i < (int)strSubModuleName.length(); i++)
	{
		std::string s = strSubModuleName.substr(0, i + 1);
		int n = atof(s.c_str());
		if ((int)strSubModuleName.length() == i + 1 + n)
		{
			strSubModuleName = strSubModuleName.substr(i + 1, strSubModuleName.length());
			break;
		}
	}
	
#endif

	ModuleInstanceMap::iterator it = m_nModuleInstanceMap.find(strSubModuleName);
	if (it != m_nModuleInstanceMap.end())
	{
		return it->second;
	}

	return nullptr;
}

bool NFCPluginManager::CheckConfig()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager CheckConfig................");
	
	for (PluginInstanceMap::iterator itCheckInstance = m_nPluginInstanceMap.begin(); itCheckInstance != m_nPluginInstanceMap.end(); ++itCheckInstance)
	{
		itCheckInstance->second->CheckConfig();
	}
	return true;
}

bool NFCPluginManager::ReadyExecute()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager ReadyExecute................");

	if (!m_bFixedFrame) {
#ifdef NF_DEBUG_MODE
	    m_profilerMgr.SetOpenProfiler(true);
#endif
    }
	
	for (PluginInstanceMap::iterator itCheckInstance = m_nPluginInstanceMap.begin(); itCheckInstance != m_nPluginInstanceMap.end(); ++itCheckInstance)
	{
		itCheckInstance->second->ReadyExecute();
	}

	return true;
}

bool NFCPluginManager::BeforeShut()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager BeforeShut................");
	
	for (PluginInstanceMap::iterator itBeforeInstance = m_nPluginInstanceMap.begin(); itBeforeInstance != m_nPluginInstanceMap.end(); ++itBeforeInstance)
	{
		itBeforeInstance->second->BeforeShut();
	}

	return true;
}

bool NFCPluginManager::Shut()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager Shut................");
	
	for (PluginInstanceMap::iterator itInstance = m_nPluginInstanceMap.begin(); itInstance != m_nPluginInstanceMap.end(); ++itInstance)
	{
		itInstance->second->Shut();
	}

	return true;
}

bool NFCPluginManager::OnReloadConfig()
{
	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFPluginManager OnReloadConfig................");

	/*
	加载服务器配置
	*/
	FindModule<NFIConfigModule>()->LoadConfig();

	for (PluginInstanceMap::iterator itInstance = m_nPluginInstanceMap.begin(); itInstance != m_nPluginInstanceMap.end(); ++itInstance)
	{
        itInstance->second->OnReloadConfig();
	}

	return true;
}


bool NFCPluginManager::AfterOnReloadConfig()
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFPluginManager AfterOnReloadConfig................");

    for (PluginInstanceMap::iterator itInstance = m_nPluginInstanceMap.begin(); itInstance != m_nPluginInstanceMap.end(); ++itInstance)
    {
        itInstance->second->AfterOnReloadConfig();
    }

    return true;
}

bool NFCPluginManager::Finalize()
{
	NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager Finalize................");
	
	for (PluginInstanceMap::iterator itInstance = m_nPluginInstanceMap.begin(); itInstance != m_nPluginInstanceMap.end(); ++itInstance)
	{
		itInstance->second->Finalize();
	}

#ifndef NF_DYNAMIC_PLUGIN
	////////////////////////////////////////////////

	for (auto it = m_nPluginNameVec.begin(); it != m_nPluginNameVec.end(); ++it)
	{
		if (*it != "NFKernelPlugin")
		{
			UnLoadStaticPlugin(*it);
		}
	}

	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "UnLoadPlugin:NFKernelPlugin");
	UnLoadStaticPlugin("NFKernelPlugin");
#else
	for (auto it = m_nPluginNameVec.begin(); it != m_nPluginNameVec.end(); ++it)
	{
		if (*it != "NFKernelPlugin")
		{
			UnLoadPluginLibrary(*it);
		}
	}

	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "UnLoadPlugin:NFKernelPlugin");
	UnLoadPluginLibrary("NFKernelPlugin");
#endif

	m_nPluginInstanceMap.clear();
	m_nPluginInstanceList.clear();
	m_nModuleInstanceMap.clear();
	m_nPluginNameVec.clear();
	return true;
}

bool NFCPluginManager::LoadStaticPlugin(const std::string& strPluginName)
{
	auto it = m_nPluginFuncMap.find(strPluginName);
	if (it == m_nPluginFuncMap.end())
	{
		NFLogError(NF_LOG_PLUGIN_MANAGER, 0, " Load Static Plugin [{0}] Failed, The Plugin Not Registered, Please Registed like this 'REGISTER_STATIC_PLUGIN(this, {0})' in the NFCLoadStaticPlugin.cpp", strPluginName);
		assert(0);
		return false;
	}

	if (FindPlugin(strPluginName)) return true;

	NFIPlugin* pPlugin = it->second(this);
	if (pPlugin)
	{
		NFLogWarning(NF_LOG_SYSTEMLOG, 0, "LoadPlugin:{}", strPluginName);
		Registered(pPlugin);
	}
	return true;
}

bool NFCPluginManager::UnLoadStaticPlugin(const std::string& strPluginDLLName)
{
	NFLogWarning(NF_LOG_SYSTEMLOG, 0, "UnLoadPlugin:{}", strPluginDLLName);
	UnRegistered(FindPlugin(strPluginDLLName));
	return true;
}

uint32_t NFCPluginManager::GetFrame() const
{
	return m_nFrame;
}

uint32_t NFCPluginManager::GetFrameTime() const
{
	return m_nFrameTime;
}

bool NFCPluginManager::IsFixedFrame() const
{
    return m_bFixedFrame;
}

void NFCPluginManager::SetFixedFrame(bool frame)
{
    if (IsLoadAllServer()) return;

    m_bFixedFrame = frame;
}

uint32_t NFCPluginManager::GetIdleSleepUs() const
{
    return m_idleSleepUs;
}

void NFCPluginManager::SetIdelSleepUs(uint32_t time)
{
    if (IsLoadAllServer()) return;

    m_idleSleepUs = time;
}

uint64_t NFCPluginManager::GetInitTime() const
{
	return m_nInitTime;
}

uint64_t NFCPluginManager::GetNowTime() const
{
	return m_nNowTime;
}

int NFCPluginManager::GetMachineAddr(const std::string& str) {
    sigar_t *pSigar;
    sigar_open(&pSigar);

    sigar_net_interface_config_t netConfig;
    if (sigar_net_interface_config_get(pSigar, NULL, &netConfig) != SIGAR_OK)
    {
        return -1;
    }

    char name[SIGAR_FQDN_LEN];
    sigar_net_address_to_string(pSigar, &netConfig.hwaddr, name);
    std::string macAddr = name;

    std::string cpuId;
    std::string diskId;
    std::string boardSerial;
    if (get_cpu_id(cpuId) || get_disk_id(diskId) || get_board_serial_number(boardSerial))
    {
        std::string machineAddr = NF_FORMAT("{}|{}|{}|{}|{}", macAddr, str, cpuId, diskId, boardSerial);
        m_iMachineAddrMD5 = NFMD5::md5str(machineAddr);
    }
    else
    {
        std::string machineAddr = NF_FORMAT("{}|{}", macAddr, str);
        m_iMachineAddrMD5 = NFMD5::md5str(machineAddr);
    }

    sigar_close(pSigar);

    return 0;
}

bool NFCPluginManager::LoadPluginLibrary(const std::string& strPluginDLLName)
{
	PluginLibMap::iterator it = m_nPluginLibMap.find(strPluginDLLName);
	if (it == m_nPluginLibMap.end())
	{
		NFCDynLib* pLib = new NFCDynLib(strPluginDLLName);
		bool bLoad = pLib->Load();

		if (bLoad)
		{
			m_nPluginLibMap.insert(PluginLibMap::value_type(strPluginDLLName, pLib));

			DLL_START_PLUGIN_FUNC pFunc = (DLL_START_PLUGIN_FUNC)pLib->GetSymbol("DllStartPlugin");
			if (!pFunc)
			{
				NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "Find function DllStartPlugin Failed in [{}]", pLib->GetName());
				assert(0);
				return false;
			}

			pFunc(this);

			return true;
		}
		else
		{
#if NF_PLATFORM == NF_PLATFORM_LINUX || NF_PLATFORM == NF_PLATFORM_APPLE
			char* error = dlerror();
			if (error)
			{
				std::cout << "Load shared lib failed: " << strPluginDLLName << std::endl;
				NFLogError(NF_LOG_PLUGIN_MANAGER, 0, " Load DLL[{0}] failed, ErrorNo. = [{1}] Load [{0}] failed", strPluginDLLName, error);
                NFSLEEP(1000);
				exit(0);
				return false;
			}
			else
            {
                std::cout << "Load shared lib failed: " << strPluginDLLName << std::endl;
                NFSLEEP(1000);
                exit(0);
                return false;
            }
#elif NF_PLATFORM == NF_PLATFORM_WIN
			NFLogError(NF_LOG_PLUGIN_MANAGER, 0, " Load DLL[{0}] failed, ErrorNo. = [{1}] Load [{0}] failed", pLib->GetName(), GetLastError());
			exit(0);
			return false;
#endif // NF_PLATFORM
		}
	}

	return false;
}

bool NFCPluginManager::UnLoadPluginLibrary(const std::string& strPluginDLLName)
{
	PluginLibMap::iterator it = m_nPluginLibMap.find(strPluginDLLName);
	if (it != m_nPluginLibMap.end())
	{
		NFCDynLib* pLib = it->second;
		DLL_STOP_PLUGIN_FUNC pFunc = (DLL_STOP_PLUGIN_FUNC)pLib->GetSymbol("DllStopPlugin");

		if (pFunc)
		{
			pFunc(this);
		}

		pLib->UnLoad();

		delete pLib;
		pLib = NULL;
		m_nPluginLibMap.erase(it);

		return true;
	}

	return false;
}

bool NFCPluginManager::DynamicLoadPluginLibrary(const std::string& strPluginDLLName)
{
#ifndef NF_DYNAMIC_PLUGIN
	NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "can't load plugin:{}, you are static load!", strPluginDLLName);
#else
	NFIPlugin* pPlugin = FindPlugin(strPluginDLLName);
	if (pPlugin)
	{
		if (pPlugin->IsDynamicLoad() == false)
		{
			NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "plugin:{} can't not dynamic load!", strPluginDLLName);
			return false;
		}

		/*
		**卸载动态库
		*/
		pPlugin->OnDynamicPlugin();
		pPlugin->BeforeShut();
		pPlugin->Shut();
		pPlugin->Finalize();
		pPlugin = nullptr;
		UnLoadPluginLibrary(strPluginDLLName);

		/*
		**重新加载动态库
		*/
		//EN_OBJ_MODE oldMode = NFShmMgr::Instance()->GetInitMode();
		//NFShmMgr::Instance()->SetInitMode(EN_OBJ_MODE_RECOVER);
		LoadPluginLibrary(strPluginDLLName);
		pPlugin = FindPlugin(strPluginDLLName);
		if (pPlugin)
		{
			pPlugin->Awake();
			pPlugin->Init();
			pPlugin->ReadyExecute();
		}
		else
		{
			NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "dynamic load plugin:{} failed!", strPluginDLLName);
		}
		//NFShmMgr::Instance()->SetInitMode(oldMode);
	}
	else
	{
		NFLogError(NF_LOG_PLUGIN_MANAGER, 0, "plugin:{} is not exist!", strPluginDLLName);
		return false;
	}
#endif
	return true;
}

void NFCPluginManager::BeginProfiler(const std::string& funcName)
{
	m_profilerMgr.BeginProfiler(funcName);
}

uint64_t NFCPluginManager::EndProfiler()
{
	return m_profilerMgr.EndProfiler();
}

void NFCPluginManager::ClearProfiler()
{
	m_profilerMgr.ResetAllProfilerTimer();
}

void NFCPluginManager::PrintProfiler()
{
	if (m_profilerMgr.IsOpenProfiler())
	{
		std::string str = m_profilerMgr.OutputTopProfilerTimer();
		NFLogDebug(NF_LOG_PLUGIN_MANAGER, 0, "{}", str);
	}
}

void NFCPluginManager::SetOpenProfiler(bool b)
{
	m_profilerMgr.SetOpenProfiler(b);
}

bool NFCPluginManager::IsOpenProfiler()
{
	return m_profilerMgr.IsOpenProfiler();
}

uint32_t NFCPluginManager::GetCurFrameCount() const
{
   return m_nCurFrameCount;
}

void NFCPluginManager::SetPidFileName()
{
	m_strPidFileName = NF_FORMAT("{}_{}.pid", m_strAppName, m_mStrBusName);
}

const std::string& NFCPluginManager::GetPidFileName()
{
	return m_strPidFileName;
}

#if NF_PLATFORM == NF_PLATFORM_LINUX
int NFCPluginManager::CheckPidFile()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist == false)
	{
		return 0;
	}

	std::string content;
	NFFileUtility::ReadFileContent(m_strPidFileName, content);

	pid_t proc_id = NFCommon::strto<pid_t>(content);

	std::string exe_path = NF_FORMAT("/proc/{}/cwd/{}", proc_id, m_strExeName);
	std::cout << "path = " << exe_path << std::endl;
	exist = NFFileUtility::IsFileExist(exe_path);
	if (exist == false)
	{
		return 0;
	}

	return -1;
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
int  NFCPluginManager::CreatePidFile()
{
	pid_t proc_id = NFGetPID();
	std::cout << "pid = " << proc_id << std::endl;
	std::string pidName = NFCommon::tostr(proc_id);

	int32_t fd = ::open(m_strPidFileName.c_str(), O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
	if (-1 != fd &&
		::write( fd, (const void*)pidName.c_str(), pidName.length()))
	{
		close( fd );
		return 0;
	}
	return -1;
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
int  NFCPluginManager::TimedWait(pid_t pid, int sec)
{
	int count = 0;
	do
	{
		sleep(1);
		count++;
		if (count >= sec)
		{
			return -1;
		}

		if (kill(pid, 0) == 0 || errno == EPERM)
			continue;
		else if (errno == ESRCH)
			break;
		else
			std::cout << "error checking pid:" << pid << " status" << std::endl;

	} while(true);
	return 0;
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
int NFCPluginManager::KillPreApp()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist)
	{
		std::string content;
		NFFileUtility::ReadFileContent(m_strPidFileName, content);
		pid_t proc_id = NFCommon::strto<pid_t>(content);
		kill( proc_id, SIGUNUSED );

		return TimedWait( proc_id, 10);
	}

	return 0;
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
void NFCPluginManager::StopApp()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist)
	{
		std::string content;
		NFFileUtility::ReadFileContent(m_strPidFileName, content);
		pid_t proc_id = NFCommon::strto<pid_t>(content);
		kill( proc_id, SIGUSR1);
	}
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
void NFCPluginManager::ReloadApp()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist)
	{
		std::string content;
		NFFileUtility::ReadFileContent(m_strPidFileName, content);
		pid_t proc_id = NFCommon::strto<pid_t>(content);
		kill( proc_id, SIGUSR2);
	}
}
#endif

#if NF_PLATFORM == NF_PLATFORM_LINUX
void NFCPluginManager::QuitApp()
{
	bool exist = false;
	exist = NFFileUtility::IsFileExist(m_strPidFileName);
	if (exist)
	{
		std::string content;
		NFFileUtility::ReadFileContent(m_strPidFileName, content);
		pid_t proc_id = NFCommon::strto<pid_t>(content);
		kill( proc_id, SIGUNUSED);
	}
}
#endif

bool NFCPluginManager::IsInited() const 
{ 
	return m_isInited; 
}

bool NFCPluginManager::IsInited(NF_SERVER_TYPES eServerType) const
{
    return m_appInited.IsInited(eServerType);
}

bool NFCPluginManager::IsFinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup) const
{
    return m_appInited.IsFinishAppTask(eServerType, taskGroup);
}

bool NFCPluginManager::IsHasAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup) const
{
    return m_appInited.IsHasAppTask(eServerType, taskGroup);
}

bool NFCPluginManager::IsHasAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup, uint32_t taskType) const
{
    return m_appInited.IsHasAppTask(eServerType, taskGroup, taskType);
}

void NFCPluginManager::SetIsInited(bool b) 
{ 
	m_isInited = b; 
}

int NFCPluginManager::RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string& desc, uint32_t taskGroup)
{
	return m_appInited.RegisterAppTask(eServerType, taskType, desc, taskGroup);
}

int NFCPluginManager::FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, uint32_t taskGroup)
{
	return m_appInited.FinishAppTask(eServerType, taskType, taskGroup);
}

int NFCPluginManager::SendDumpInfo(const std::string& dumpInfo)
{
    if (IsLoadAllServer()) return 0;

    NFServerConfig* pConfig = ((NFIPluginManager*)this)->FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
    CHECK_NULL(pConfig);

    proto_ff::Proto_ServerDumpInfoNtf ntf;
    ntf.set_dump_info(dumpInfo);
    ntf.set_bus_id(pConfig->BusId);

    auto pServerData = FindModule<NFIMessageModule>()->GetMasterData((NF_SERVER_TYPES)pConfig->ServerType);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, eType error:{}", (int) pConfig->ServerType);

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, proto_ff::NF_STS_SEND_DUMP_INFO_NTF, ntf);
    return 0;
}

bool NFCPluginManager::HotfixServer()
{
    bool ret = true;
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        if ((*iter)->HotfixServer() == false)
        {
            ret = false;
        }
    }

    return ret;
}

std::list<NFIPlugin*> NFCPluginManager::GetListPlugin()
{
    return m_nPluginInstanceList;
}

std::string NFCPluginManager::GetMachineAddrMD5()
{
    return m_iMachineAddrMD5;
}

bool NFCPluginManager::LoadKernelPlugin()
{
#ifndef NF_DYNAMIC_PLUGIN
    m_nPluginNameVec.push_back("NFKernelPlugin");
	LoadStaticPlugin("NFKernelPlugin");
#else
    m_nPluginNameVec.push_back("NFKernelPlugin");
    LoadPluginLibrary("NFKernelPlugin");
#endif

    /*
        log 系统第一个启动，然后是配置
    */
    FindModule<NFILogModule>()->InitLogSystem();
    /*
        加载服务器配置
    */
    FindModule<NFIConfigModule>()->LoadConfig();
    /*
        log 加载配置
    */
    FindModule<NFILogModule>()->SetDefaultLogConfig();

    return true;
}

bool NFCPluginManager::SaveDB()
{
    NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager SaveDB................");
    bool ret = true;
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        if ((*iter)->SaveDB() == false)
        {
            ret = false;
        }
    }

    return ret;
}

bool NFCPluginManager::OnStopServer()
{
    NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager OnStopServer................");
    bool ret = true;
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        if ((*iter)->OnStopServer() == false)
        {
            ret = false;
        }
    }

    return ret;
}

bool NFCPluginManager::CheckStopServer()
{
    NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager CheckStopServer................");
    bool ret = true;
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        if ((*iter)->OnStopServer() == false)
        {
            ret = false;
        }
    }

    return ret;
}

bool NFCPluginManager::StopServer()
{
    NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager StopServer................");
    bool ret = CheckStopServer();
    if (ret == false)
    {
        OnStopServer();
        return false;
    }

    return true;
}

bool NFCPluginManager::AfterAllConnectFinish()
{
    NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager AfterAllConnectFinish................");
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        (*iter)->AfterAllConnectFinish();
    }

    return true;
}

bool NFCPluginManager::AfterAllDescStoreLoaded()
{
    NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager AfterAllDescStoreLoaded................");
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        (*iter)->AfterAllDescStoreLoaded();
    }

    return true;
}

bool NFCPluginManager::AfterObjFromDBLoaded()
{
    NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager AfterObjFromDBLoaded................");
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        (*iter)->AfterObjFromDBLoaded();
    }

    return true;
}

bool NFCPluginManager::AfterServerRegisterFinish()
{
    NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager AfterServerRegisterFinish................");
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        (*iter)->AfterServerRegisterFinish();
    }

    return true;
}

bool NFCPluginManager::AfterAppInitFinish()
{
    NFLogInfo(NF_LOG_PLUGIN_MANAGER, 0, "NFPluginManager AfterAppInitFinish................");
    for (auto iter = m_nPluginInstanceList.begin(); iter != m_nPluginInstanceList.end(); ++iter)
    {
        (*iter)->AfterAppInitFinish();
    }

    return true;
}
