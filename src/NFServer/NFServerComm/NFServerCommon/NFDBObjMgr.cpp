// -------------------------------------------------------------------------
//    @FileName         :    NFDBObjMgr.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFDBObjMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFDBObjMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFBaseDBObj.h"
#include "NFDBObjTrans.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFError.h"

NFDBObjMgr::NFDBObjMgr()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFDBObjMgr::~NFDBObjMgr()
{
    if (m_iTimer != INVALID_ID)
    {
        DeleteTimer(m_iTimer);
        m_iTimer = INVALID_ID;
    }
}

int NFDBObjMgr::CreateInit()
{
    m_iLastSavingObjIndex = 0;
    m_iLastTickTime = 0;
    m_iTransMngObjID = 0;
    m_iTimer = INVALID_ID;
    m_iTimer = SetTimer(1000, 0, 0, 0, 10, 0);
    return 0;
}

int NFDBObjMgr::ResumeInit()
{
    return 0;
}

int NFDBObjMgr::OnTimer(int timeId, int callcount)
{
    if (m_iTimer == timeId)
    {
        Tick();
    }
    return 0;
}

int NFDBObjMgr::Tick()
{
    for (auto iter = m_failedObjList.begin(); iter != m_failedObjList.end();)
    {
        NFBaseDBObj* pObj = GetObj(*iter);
        if (pObj)
        {
            int iRet = LoadFromDB(pObj);
            if (iRet == 0)
            {
                iter = m_failedObjList.erase(iter);
            }
            else
            {
                iter++;
            }
        }
        else
        {
            iter = m_failedObjList.erase(iter);
        }
    }

    if (m_iLastSavingObjIndex >= (int)m_runningObjList.size())
    {
        m_iLastSavingObjIndex = 0;
    }

    int iSavedObjNum = 0;
    int idx = 0;
    uint64_t now = NFTime::Now().UnixSec();
    for (auto iter = m_runningObjList.begin(); iter != m_runningObjList.end() && iSavedObjNum < MAX_SAVED_OBJ_PRE_SEC;)
    {
        if (idx < m_iLastSavingObjIndex)
        {
            ++idx;
            ++iter;
            continue;
        }

        NFBaseDBObj* pObj = GetObj(*iter);
        if (pObj)
        {
            // 不在存储中 + 有修改
            if (pObj->GetTransID() == 0 && pObj->IsUrgentNeedSave())
            {
                if (pObj->GetLastDBOpTime() + pObj->GetSaveDis() < now)
                {
                    int iRet = SaveToDB(pObj);
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "save obj ret:{} className{} key:{}", iRet, pObj->GetClassName(), pObj->GetModeKey());

                    ++iSavedObjNum;
                }
            }
            ++iter;
            ++idx;
            ++m_iLastSavingObjIndex;
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Remove running obj:{}", *iter);
            iter = m_runningObjList.erase(iter);
        }
    }

    if (m_loadDBList.size() > 0 && m_loadDBList.size() == m_loadDBFinishList.size())
    {
        m_loadDBList.clear();
        m_loadDBFinishList.clear();
        CheckWhenAllDataLoaded();
        m_pObjPluginManager->FinishAppTask(NF_ST_NONE, APP_INIT_LOAD_GLOBAL_DATA_DB, APP_INIT_TASK_GROUP_SERVER_LOAD_OBJ_FROM_DB);
    }

    return 0;
}

int NFDBObjMgr::CheckWhenAllDataLoaded()
{
    for (auto iter = m_runningObjList.begin(); iter != m_runningObjList.end(); iter++)
    {
        NFBaseDBObj* pObj = GetObj(*iter);
        if (pObj)
        {
            int iRet = pObj->CheckWhenAllDataLoaded();
            if (iRet != 0)
            {
                NFLogFatal(NF_LOG_SYSTEMLOG, 0, "Shutdown Server by obj check faled, key:{} className:{}", pObj->GetModeKey(), pObj->GetClassName());
                assert(0);
            }
        }
    }
    return 0;
}

int NFDBObjMgr::LoadFromDB(NFBaseDBObj* pObj)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_NULL(pObj);

    m_loadDBList.insert(pObj->GetGlobalId());

    if (pObj->IsDataInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "data already inited:{} name:{}", pObj->GetGlobalId(), pObj->GetClassName())
        return -1;
    }

    NFDBObjTrans* pTrans = dynamic_cast<NFDBObjTrans *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_DB_OBJ));
    CHECK_EXPR(pTrans, -1, "Create NFDBObjTrans:EOT_TRANS_DB_OBJ Failed! use num:{}", NFDBObjTrans::GetStaticUsedCount(m_pObjPluginManager));

    int iRet = pTrans->Init(pObj->GetServerType(), pObj->GetGlobalId(), pObj->GetCurSeq());
    CHECK_EXPR(iRet == 0, -1, "Init Trans Failed!");

    google::protobuf::Message* pMessage = pObj->CreateTempProtobufData();
    CHECK_NULL(pMessage);
    iRet = pObj->MakeLoadData(pMessage);
    if (iRet != 0)
    {
        NF_SAFE_DELETE(pMessage);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Make LoadData Failed:{} iRet:{}", pObj->GetClassName(), iRet);
        m_failedObjList.push_back(pObj->GetGlobalId());
        return iRet;
    }

    pObj->SetLastDBOpTime(NFTime::Now().UnixSec());
    pObj->SetTransID(pTrans->GetGlobalId());
    iRet = pTrans->Load(pObj->GetModeKey(), pMessage);
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "Load db ob from key:{} className:{} transName:{} iRet:{}", pObj->GetModeKey(), pObj->GetClassName(), pTrans->GetClassName(), iRet);
    NF_SAFE_DELETE(pMessage);
    if (iRet != 0)
    {
        m_failedObjList.push_back(pObj->GetGlobalId());
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Make LoadData Failed:{} iRet:{}", pObj->GetClassName(), iRet);
        return iRet;
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int NFDBObjMgr::OnDataLoaded(int iObjID, int32_t err_code, const google::protobuf::Message* pData)
{
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "Date Loaded:{} err_code:{}", iObjID, GetErrorStr(err_code));
    NFBaseDBObj* pObj = GetObj(iObjID);
    CHECK_NULL(pObj);

    pObj->SetTransID(0);
    int iRet = 0;
    if (err_code == 0)
    {
        pObj->SetRetryTimes(0);
        iRet = pObj->InitWithDBData(pData);
    }
    else if ((int)err_code == proto_ff::ERR_CODE_STORESVR_ERRCODE_SELECT_EMPTY)
    {
        pObj->SetRetryTimes(0);
        pObj->SetNeedInsertDB(true);
        iRet = pObj->InitWithoutDBData();
    }
    else
    {
        iRet = -1;
    }

    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "className:{} key:{} load faled! iRet:{}", pObj->GetClassName(), pObj->GetModeKey(), iRet);
        switch (pObj->DealWithFailed())
        {
            case EN_DW_LOG_FAIL:
            {
                pObj->SetInRecycle(true);
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Load From DB Error:{} DB error code:{}", iRet, err_code);
                break;
            }
            case EN_DW_RETRY:
            {
                pObj->SetRetryTimes(pObj->GetRetryTimes() + 1);
                iRet = LoadFromDB(pObj);
                break;
            }
            case EN_DW_SHUTDOWN:
            {
                NFLogFatal(NF_LOG_SYSTEMLOG, 0, "className:{} Load Failed", pObj->GetClassName());
                NFLogFatal(NF_LOG_SYSTEMLOG, 0, "Shutdown Server by obj init faled, key:{} className:{}", pObj->GetModeKey(), pObj->GetClassName());
                assert(0);
                return -1;
            }
            case EN_DW_RETRY_ANY_SHUTDOWN:
            {
                if (pObj->GetRetryTimes() > MAX_FAIL_RETRY_TIMES)
                {
                    NFLogFatal(NF_LOG_SYSTEMLOG, 0, "className:{} Load Failed", pObj->GetClassName());
                    NFLogFatal(NF_LOG_SYSTEMLOG, 0, "Shutdown Server by obj init faled, key:{} className:{}", pObj->GetModeKey(), pObj->GetClassName());
                    NF_ASSERT(false);
                    return -1;
                }
                pObj->SetRetryTimes(pObj->GetRetryTimes() + 1);
                iRet = LoadFromDB(pObj);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else
    {
        m_runningObjList.push_back(pObj->GetGlobalId());
        m_loadDBFinishList.insert(pObj->GetGlobalId());
    }

    return 0;
}

int NFDBObjMgr::OnDataInserted(NFDBObjTrans* pTrans, bool success)
{
    CHECK_NULL(pTrans);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Data Inserted:{} {}", pTrans->GetLinkedObjID(), pTrans->GetClassName());
    NFBaseDBObj* pObj = GetObj(pTrans->GetLinkedObjID());
    CHECK_NULL(pObj);

    pObj->SetTransID(0);
    if (success)
    {
        pObj->SetLastDBOpTime(NFTime::Now().UnixSec());
        pObj->SetNeedInsertDB(false);
        if (pTrans->GetObjSeqOP() == pObj->GetCurSeq())
        {
            pObj->ClearUrgent();
        }
    }
    return 0;
}

int NFDBObjMgr::OnDataSaved(NFDBObjTrans* pTrans, bool success)
{
    CHECK_NULL(pTrans);
    NFBaseDBObj* pObj = GetObj(pTrans->GetLinkedObjID());
    CHECK_NULL(pObj);

    pObj->SetTransID(0);
    if (success)
    {
        pObj->SetLastDBOpTime(NFTime::Now().UnixSec());
        if (pTrans->GetObjSeqOP() == pObj->GetCurSeq())
        {
            pObj->ClearUrgent();
        }
    }
    return 0;
}

NFBaseDBObj* NFDBObjMgr::GetObj(int iObjID)
{
    return dynamic_cast<NFBaseDBObj *>(FindModule<NFISharedMemModule>()->GetObjByGlobalId(EOT_BASE_DB_OBJ, iObjID, true));
}

int NFDBObjMgr::SaveToDB(NFBaseDBObj* pObj)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_NULL(pObj);

    if (!pObj->IsDataInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "data not init:{} name:{}", pObj->GetGlobalId(), pObj->GetClassName())
        return -1;
    }

    NFDBObjTrans* pTrans = dynamic_cast<NFDBObjTrans *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_TRANS_DB_OBJ));
    CHECK_EXPR(pTrans, -1, "Create NFDBObjTrans:EOT_TRANS_DB_OBJ Failed! use num:{}", NFDBObjTrans::GetStaticUsedCount(m_pObjPluginManager));

    int iRet = pTrans->Init(pObj->GetServerType(), pObj->GetGlobalId(), pObj->GetCurSeq());
    CHECK_EXPR(iRet == 0, -1, "Init Trans Failed!");

    google::protobuf::Message* pMessage = pObj->CreateTempProtobufData();
    CHECK_NULL(pMessage);
    iRet = pObj->MakeSaveData(pMessage);
    if (iRet != 0)
    {
        NF_SAFE_DELETE(pMessage);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Make save Failed:{} iRet:{}", pObj->GetClassName(), iRet);
        return iRet;
    }

    pObj->SetTransID(pTrans->GetGlobalId());
    if (pObj->GetNeedInsertDB())
    {
        iRet = pTrans->Insert(pObj->GetModeKey(), pMessage);
    }
    else
    {
        iRet = pTrans->Save(pObj->GetModeKey(), pMessage);
    }

    NF_SAFE_DELETE(pMessage);
    CHECK_RET(iRet, "SaveToDB Failed, key:{} pObj:{}", pObj->GetModeKey(), pObj->GetClassName());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}
