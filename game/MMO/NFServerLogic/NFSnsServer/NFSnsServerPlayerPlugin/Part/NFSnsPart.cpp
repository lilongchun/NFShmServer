// -------------------------------------------------------------------------
//    @FileName         :    NFSnsPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsPart
//
// -------------------------------------------------------------------------

#include "NFSnsPart.h"
#include "Cache/NFPlayerDetail.h"
#include "Cache/NFPlayerSimple.h"
#include "Cache/NFCacheMgr.h"
#include "NFSnsPartModule.h"

NFSnsPart::NFSnsPart()
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

NFSnsPart::~NFSnsPart()
{
}

int NFSnsPart::CreateInit()
{
    return 0;
}

int NFSnsPart::ResumeInit()
{
    return 0;
}

int NFSnsPart::Init(NFPlayerDetail *pMaster, uint32_t partType, const proto_ff::RoleDBSnsDetail &data)
{
    CHECK_EXPR(pMaster, -1, "pMaster == NULL");
    m_pMaster = pMaster;
    m_partType = partType;

    LoadFromDB(data);
    InitConfig(data);
    return 0;
}

int NFSnsPart::UnInit()
{
    return 0;
}

int NFSnsPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "client part package not handle:{}", packet.ToString());
    return 0;
}

int NFSnsPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "server part package not handle:{}", packet.ToString());
    return 0;
}

int NFSnsPart::RegisterClientMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFSnsPartModule>()->RegisterClientMessage(NF_ST_SNS_SERVER, nMsgID, m_partType, createCo);
}

int NFSnsPart::RegisterServerMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFSnsPartModule>()->RegisterServerMessage(NF_ST_SNS_SERVER, nMsgID, m_partType, createCo);
}

int NFSnsPart::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    return m_pMaster->SendMsgToClient(nMsgId, xData);
}

int NFSnsPart::SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    return m_pMaster->SendMsgToGameServer(nMsgId, xData);
}

int NFSnsPart::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    return m_pMaster->SendMsgToWorldServer(nMsgId, xData);
}

int NFSnsPart::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    return m_pMaster->SendMsgToLogicServer(nMsgId, xData);
}

NFPlayerSimple *NFSnsPart::GetPlayerSimple()
{
    return NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(m_pMaster->Cid());
}

NFPlayerDetail* NFSnsPart::GetMaster()
{
    return m_pMaster;
}

int NFSnsPart::RegisterMessage()
{
    return 0;
}


