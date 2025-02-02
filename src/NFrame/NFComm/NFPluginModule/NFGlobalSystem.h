// -------------------------------------------------------------------------
//    @FileName         :    NFLogMgr.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFKernelMessage/proto_common.pb.h"
#include "NFILuaLoader.h"
#include <vector>
#include <unordered_set>

class NFIPluginManager;

class NFGlobalSystem : public NFSingleton<NFGlobalSystem>, public NFILuaLoader
{
public:
    NFGlobalSystem();

    virtual ~NFGlobalSystem();

public:
    bool LoadConfig(const std::string &path);
public:
    /*
     * reload server
     * */
    bool IsReloadApp() const;

    /*
     * reload server
     * */
    void SetReloadServer(bool reloadApp);

    /*
     * stop server
     * */
    bool IsServerStopping() const;

    /*
     * stop server
     * */
    void SetServerStopping(bool exitApp);

    /*
     * kill server
     * */
    bool IsServerKilling() const;

    /*
     * kill server
     * */
    void SetServerKilling(bool exitApp);

    /*
     *
     * */
    bool IsHotfixServer() const;

    /*
     *
     * */
    void SetHotfixServer(bool hotfixExitApp);

public:
    virtual bool RegisterSpecialMsg(uint32_t moduleId, uint32_t msgId);
    virtual bool IsSpecialMsg(uint32_t moduleId, uint32_t msgId);
public:
    /**
     * @brief �ͷ�singleton��Դ
     */
    void ReleaseSingleton();
private:
    bool m_gIsMoreServer;
    NFIPluginManager *m_gGlobalPluginManager;
    std::vector<NFIPluginManager *> m_gGlobalPluginManagerList;
    proto_ff::pbPluginConfig m_gAllMoreServerConfig;
    bool m_reloadApp;
    bool m_serverStopping;
    bool m_serverKilling;
    bool m_hotfixServer;

    std::vector<std::vector<bool>> mSpecialMsgMap;
public:
    bool IsMoreServer() const
    {
        return m_gIsMoreServer;
    }

    void SetMoreServer(bool isMoreServer)
    {
        m_gIsMoreServer = isMoreServer;
    }

    NFIPluginManager *GetGlobalPluginManager() const
    {
        return m_gGlobalPluginManager;
    }

    void SetGlobalPluginManager(NFIPluginManager *pPluginManager)
    {
        if (m_gGlobalPluginManager == NULL)
        {
            m_gGlobalPluginManager = pPluginManager;
        }
    }

    void AddPluginManager(NFIPluginManager *pPluginManager)
    {
        m_gGlobalPluginManagerList.push_back(pPluginManager);
    }

    std::vector<NFIPluginManager *> GetPluginManagerList()
    {
        return m_gGlobalPluginManagerList;
    }

    const proto_ff::pbPluginConfig *GetAllMoreServerConfig() const
    {
        return &m_gAllMoreServerConfig;
    }
};