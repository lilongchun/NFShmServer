// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFSnsTransSaveSimpleDB.h"

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFICoroutineModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "Cache/NFPlayerSimple.h"
#include "Cache/NFCacheMgr.h"

NFSnsTransSaveSimpleDB::NFSnsTransSaveSimpleDB() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFSnsTransSaveSimpleDB::~NFSnsTransSaveSimpleDB() {

}

int NFSnsTransSaveSimpleDB::CreateInit() {
    m_curSeq = 0;
    m_playerId = 0;
    return 0;
}

int NFSnsTransSaveSimpleDB::ResumeInit() {
    return 0;
}

int NFSnsTransSaveSimpleDB::SaveDB(NFPlayerSimple* pPlayer)
{
    CHECK_EXPR(pPlayer, -1, "Save Failed! Can't find player data, userId:{}", m_playerId);

    m_playerId = pPlayer->GetPlayerId();
    m_curSeq = pPlayer->GetCurSeq();
    pPlayer->SetLastSaveDBTime(NFTime::Now().UnixSec());

    proto_ff::tbFishSnsPlayerSimpleData tbData;
    tbData.set_player_id(m_playerId);
    pPlayer->SaveDB(tbData);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "Ready Save Sns Player Simple InTo Mysql:{}", tbData.DebugString());

    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcModifyObjService(NF_ST_SNS_SERVER, m_playerId, tbData, [this](int rpcRetCode) {
        if (rpcRetCode == 0)
        {
            NFPlayerSimple* pPlayer = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(m_playerId);
            if (pPlayer)
            {
                pPlayer->OnSaveDB(true, m_curSeq);
            }
        }

        SetFinished(rpcRetCode);
    });

    if (m_rpcId == INVALID_ID)
    {
        return proto_ff::ERR_CODE_RPC_SYSTEM_ERROR;
    }

    return 0;
}

int NFSnsTransSaveSimpleDB::HandleTransFinished(int iRunLogicRetCode) {
    if (iRunLogicRetCode != 0) {
        NFPlayerSimple* pPlayer = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(m_playerId);
        if (pPlayer) {
            pPlayer->OnSaveDB(false, 0);
        }
        return iRunLogicRetCode;
    }

    return 0;
}