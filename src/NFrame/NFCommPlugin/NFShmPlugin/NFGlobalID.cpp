// -------------------------------------------------------------------------
//    @FileName         :    NFGlobalID.cpp
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFGlobalID.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFDateTime.hpp"
#include "NFIDRuntimeClass.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

NFGlobalID::NFGlobalID() : NFShmObj(), m_iThisRoundCountMax(0), m_iThisRoundCount(0),
                                                           m_iGlobalIDAppendNum(0)
{
    snprintf(m_szFileName, sizeof(m_szFileName), "%s_globalid",
             NFServerIDUtil::GetBusNameFromBusID(FindModule<NFISharedMemModule>()->GetRunTimeFileId()).c_str());
    //strcpy(m_szFileName,"round_time");
    //校验
    COMPILE_TIME_ASSERT((int64_t) MAX_GLOBALID_NUM * GLOBALID_LOOP_BACK < INT_MAX);

    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFGlobalID::~NFGlobalID()
{
}

void SetRunTimeFileID(int id)
{
}

int NFGlobalID::CreateInit()
{
    m_iUseCount = 0;
    //初始化的时候可以保证转完一圈不重复
    m_iThisRoundCountMax = MAX_GLOBALID_NUM;

    //memset(m_stIDTable, -1, sizeof(m_stIDTable));
    for (int i = 1; i < (int) ARRAYSIZE(m_stIDTable); i++)
    {
        m_stIDTable[i].iID = -1;
        m_stIDTable[i].iIndex = -1;
        m_stIDTable[i].iType = -1;
        m_stIDTable[i].pObjPtr = 0;
    }

    InitQueue(&m_Queue);

    for (int i = 0; i < MAX_GLOBALID_NUM; i++)
    {
        if (InQueue(&m_Queue, i))
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "InQueue error in CGlobalID");
            return -1;
        }
    }

    if (ResumeFileUpdateData())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "ResumeFileUpdateData error in CGlobalID");
        return -1;
    }

    m_tRoundBegin = time(NULL);

    m_iSecOffSet = 0;
    m_uuid = 10000;
    return 0;
}

int NFGlobalID::ResumeInit()
{
    return 0;
}

int NFGlobalID::SetTypeAndIndex(int iType, int iIndex, NFShmObj *pObj)
{
    int iID = pObj->GetGlobalId();
    int inID = (iID & MAX_GLOBALID_NUM_MASK);

    if (likely(inID >= 0))
    {
        if (likely(m_stIDTable[inID].iID == iID))
        {
            m_stIDTable[inID].iType = iType;
            m_stIDTable[inID].iIndex = iIndex;
            return 0;
        }
    }

    return -1;
}

int NFGlobalID::GetGlobalID(int iType, int iIndex, NFShmObj *pObj)
{
    //**********************************************modify by xxxx begin************************************************
    if (CalcRoundUpdateFile())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CalcRoundUpdateFile error in CGlobalID");
        return -1;
    }

    int iQueueIndex = OutQueue(&m_Queue);

    if (iQueueIndex < 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Global id work out!");
        return -1;
    }

    TIDIndex *pTIDIndex = &m_stIDTable[iQueueIndex];
    pTIDIndex->iID = iQueueIndex + m_iGlobalIDAppendNum;
    //**********************************************modify by xxxx end**********************************************
    pTIDIndex->iType = iType;
    pTIDIndex->iIndex = iIndex;
    pTIDIndex->pObjPtr = pObj;
    m_iUseCount++;
    return pTIDIndex->iID;
}

int NFGlobalID::ReleaseID(int iID)
{
    if (iID < 0)
    {
        return -1;
    }

    int inID;
    inID = iID & MAX_GLOBALID_NUM_MASK;

    if (inID < 0)
    {
        return -1;
    }

    /*error return*/
    TIDIndex *pII = NULL;
    pII = &m_stIDTable[inID];

    if (pII->iID != iID)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Release Index ID:{} ID:{}", pII->iID, iID);
        return -1;
    }

    //**********************************************modify by xxxx begin**********************************************
    if (InQueue(&m_Queue, inID))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "InQueue Error in CGlobalID");
        return -1;
    }

    pII->iID = -1;
    //**********************************************modify by xxxx end**********************************************
    pII->iIndex = -1;
    pII->iType = -1;
    pII->pObjPtr = 0;
    m_iUseCount--;
    return 0;
}

NFShmObj *NFGlobalID::GetObj(int iID)
{
    int inID = (iID & MAX_GLOBALID_NUM_MASK);

    if (likely(inID >= 0))
    {
        if (likely(m_stIDTable[inID].iID == iID))
        {
            NFShmObj *pObj = m_stIDTable[inID].pObjPtr;

#ifdef NF_DEBUG_MODE
            NFShmObj *pObjGetObjFromTypeIndex = FindModule<NFISharedMemModule>()->GetObjByObjId(m_stIDTable[inID].iType, m_stIDTable[inID].iIndex);
            assert(pObjGetObjFromTypeIndex == pObj);
#endif
            //理论上还是存在这种可能性，只要服务器运行时间足够久
            if (pObj && pObj->GetGlobalId() != iID)
            {
                /*发生这种情况说明上层逻辑不对，对象不存在已经很久了，为什么还去Get呢.*/
                NFLogError(NF_LOG_SYSTEMLOG, 0, "id {} in({},{},{})", pObj->GetGlobalId(), m_stIDTable[inID].iID, m_stIDTable[inID].iIndex,
                           m_stIDTable[inID].iType);
                debug_assert();
                return NULL;
            }

            return pObj;
        }
        else
        {
            return NULL;
        }
    }

    return NULL;
}

NFShmObj *NFGlobalID::ResumeObject(NFIPluginManager *pPluginManager, void *pBuffer)
{
    NFShmObj *pTmp = NULL;
    pTmp = new(pBuffer) NFGlobalID();
    return pTmp;
}

NFShmObj *NFGlobalID::CreateObject(NFIPluginManager *pPluginManager)
{
    NFGlobalID *pTmp = NULL;
    void *pVoid = pPluginManager->FindModule<NFISharedMemModule>()->AllocMemForObject(EOT_GLOBAL_ID);
    if (!pVoid)
    {
        return NULL;
    }

    NFShmMgr::Instance()->m_pTempPluginManager = pPluginManager;
    NFShmMgr::Instance()->m_iType = EOT_GLOBAL_ID;
    pTmp = new(pVoid) NFGlobalID();
    NFShmMgr::Instance()->m_pTempPluginManager = NULL;
    NFShmMgr::Instance()->m_iType = INVALID_ID;
    return pTmp;
}

void NFGlobalID::DestroyObject(NFIPluginManager *pPluginManager, NFShmObj *pObj)
{
    NFGlobalID *pTmp = NULL;
    pTmp = (NFGlobalID *) pObj;
    (*pTmp).NFGlobalID::~NFGlobalID();
    pPluginManager->FindModule<NFISharedMemModule>()->FreeMemForObject(EOT_GLOBAL_ID, pTmp);
    return;
}

void *NFGlobalID::operator new(size_t nSize, void *pBuffer) throw()
{
    return pBuffer;
}

int NFGlobalID::RegisterClassToObjSeg(NFIPluginManager *pPluginManager, int bType, int iObjSize, int iObjCount, const std::string &className, bool useHash,
                          bool singleton)
{
    pPluginManager->FindModule<NFISharedMemModule>()->RegisterClassToObjSeg(bType, iObjSize, iObjCount, NFGlobalID::ResumeObject,
                                                                            NFGlobalID::CreateObject,
                                                                            NFGlobalID::DestroyObject, -1, className, useHash,
                                                                            singleton);
    return 0;
}

int NFGlobalID::ResumeFileUpdateData()
{
    //该程序的作用是如果Round_time存在，读取其中的数字，如果不存在，则创建之
    FILE *fp;
    char buf[BUFFSIZE];
    fp = fopen(m_szFileName, "r");

    if (fp == NULL)
    {
        //创建文件名为m_szFileName的文件
        fp = fopen(m_szFileName, "w+");

        if (fp == NULL)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "fopen round_times error ");
            return -1;
        }

        if (fwrite("0", sizeof(char), 1, fp) != 1)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "fwrite pszFileName error ");
            fclose(fp);
            return -1;
        }

        if (fseek(fp, 0, SEEK_SET) != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "fseek pszFileName error ");
            fclose(fp);
            return -1;
        }
    }

    fgets(buf, sizeof(buf), fp);
    fclose(fp);
    m_iRoundMultiple = atoi(buf) + 1; //加一保证ID和上次不重复
    m_iRoundMultiple = m_iRoundMultiple % GLOBALID_LOOP_BACK;
    m_iGlobalIDAppendNum = m_iRoundMultiple * MAX_GLOBALID_NUM;

    if (WriteRound())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "WriteRound round_time error ");
        return -1;
    }

    return 0;
}

int NFGlobalID::CalcRoundUpdateFile()
{
    //该函数实现的功能是计算循环次数是不是达到m_iThisRoundCount，如果达到则RoundTimes+1并写到文件中
    if (m_iThisRoundCount >= m_iThisRoundCountMax)
    {
        m_iThisRoundCountMax = MAX_GLOBALID_NUM - m_iUseCount;
        m_iThisRoundCount = 0;
        m_iRoundMultiple++;
        m_iRoundMultiple = m_iRoundMultiple % GLOBALID_LOOP_BACK;
        m_iGlobalIDAppendNum = m_iRoundMultiple * MAX_GLOBALID_NUM;
        m_tRoundBegin = time(NULL);

        if (WriteRound())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "WriteRound round_time error ");
            return -1;
        }
    }

    m_iThisRoundCount++;
    return 0;
}

int NFGlobalID::WriteRound()
{
    //该函数的作用是把循环次数RoundTimes写到文件pszFileName中
    FILE *fp;
    char buf[BUFFSIZE];
    snprintf(buf, sizeof(buf), "%d", m_iRoundMultiple);
    fp = fopen(m_szFileName, "w+");

    if (fp == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "fopen for pszFileName error ");
        return -1;
    }

    if (fwrite(buf, sizeof(char), strlen(buf), fp) != strlen(buf))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "fwrite for pszFileName error ");
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

//modify by xxxx end****************************************************************************
char *NFGlobalID::GetOperatingStatictis()
{
    static char szStatistic[128];
    szStatistic[0] = '\0';
    snprintf(szStatistic, sizeof(szStatistic), "GlobalID: total %d, used %d, round %d, roundbegin %s",
             MAX_GLOBALID_NUM, m_iUseCount, m_iRoundMultiple, NFDateTime(m_tRoundBegin).GetDbTimeString().c_str());
    return szStatistic;
}

int NFGlobalID::Get32UUID()
{
    return m_uuid++;
}
