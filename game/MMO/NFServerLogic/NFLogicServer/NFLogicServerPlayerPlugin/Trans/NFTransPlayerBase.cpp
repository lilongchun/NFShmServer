﻿// -------------------------------------------------------------------------
//    @FileName         :    NFTransCreateUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransCreateUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFTransPlayerBase.h"

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"
#include "NFComm/NFPluginModule/NFICoroutineModule.h"

NFTransPlayerBase::NFTransPlayerBase()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFTransPlayerBase::~NFTransPlayerBase()
{

}

int NFTransPlayerBase::CreateInit()
{
    m_cid = 0;
    m_cmd = 0;
    m_fromBusId = 0;
    m_bHasIncreasedCount = false;
    m_reqTransId = 0;
    return 0;
}

int NFTransPlayerBase::ResumeInit()
{
    return 0;
}

int NFTransPlayerBase::Init(uint64_t cid, uint32_t cmd, uint32_t fromBusId, uint32_t reqTransId)
{
    m_cid = cid;
    m_cmd = cmd;
    m_fromBusId = fromBusId;
    m_reqTransId = reqTransId;

    if (!m_bHasIncreasedCount)
    {
        NFPlayer *pPlayer = GetPlayer();
        if (pPlayer)
        {
            pPlayer->IncreaseTransNum();
            m_bHasIncreasedCount = true;
        }
    }
    return 0;
}

int NFTransPlayerBase::Init(NFPlayer *pPlayer, uint32_t cmd, uint32_t fromBusId, uint32_t reqTransId)
{
    CHECK_NULL(pPlayer);

    m_cid = pPlayer->GetCid();
    m_cmd = cmd;
    m_fromBusId = fromBusId;
    m_reqTransId = reqTransId;

    if (!m_bHasIncreasedCount)
    {
        pPlayer->IncreaseTransNum();
        m_bHasIncreasedCount = true;
    }
    return 0;
}

NFPlayer *NFTransPlayerBase::GetPlayer()
{
    return NFPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(m_cid);
}

int NFTransPlayerBase::OnTimeOut()
{
    NFPlayer *pPlayer = GetPlayer();
    if (pPlayer && m_bHasIncreasedCount)
    {
        pPlayer->DecreaseTransNum();
        m_bHasIncreasedCount = false;
    }

    SetFinished(proto_ff::ERR_CODE_SVR_SYSTEM_TIMEOUT);

    NFLogError(NF_LOG_SYSTEMLOG, m_cid, "NFTransLogicUserBase timeout, playerId:{}, cmd:{}, transid:{}",
               m_cid, m_cmd, m_reqTransId);
    return 0;
}

int NFTransPlayerBase::OnTransFinished(int iRunLogicRetCode)
{
    NFPlayer *pPlayer = GetPlayer();
    if (!pPlayer)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, m_cid, "GetPlayer Failed, this player may off line! cmd:{}", m_cmd);
        return 0;
    }

    if (m_bHasIncreasedCount)
    {
        pPlayer->DecreaseTransNum();
        m_bHasIncreasedCount = false;
    }

    if (0 == iRunLogicRetCode)
    {
        return 0;
    }

    NFLogDebug(NF_LOG_SYSTEMLOG, pPlayer->GetCid(), "player:{} failed errcode={}, msgid={} globalid={} classtype:{}", pPlayer->GetCid(),
               iRunLogicRetCode, m_cmd, GetGlobalId(), GetClassType());

    if (0 == m_cmd)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayer->GetCid(),
                   "Server should not call this function because request head uninitialized, player:{}!", pPlayer->GetCid());

        return -1;
    }

    return 0;
}