// -------------------------------------------------------------------------
//    @FileName         :    NFPart.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFPart
//
// -------------------------------------------------------------------------

#include "NFPart.h"
#include "Player/NFPlayer.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFPartModule.h"

NFPart::NFPart()
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

NFPart::~NFPart()
{
}

int NFPart::CreateInit()
{
    m_pMaster = NULL;
    m_partType = 0;
    return 0;
}

int NFPart::ResumeInit()
{
    return 0;
}

int NFPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    CHECK_NULL(pMaster);
    m_pMaster = pMaster;
    m_partType = partType;

    LoadFromDB(dbData);
    InitConfig(dbData);
    return 0;
}

int NFPart::UnInit()
{
    return 0;
}

int NFPart::RegisterClientMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFPartModule>()->RegisterClientMessage(NF_ST_LOGIC_SERVER, nMsgID, m_partType, createCo);
}

int NFPart::RegisterServerMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFPartModule>()->RegisterServerMessage(NF_ST_LOGIC_SERVER, nMsgID, m_partType, createCo);
}

int NFPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "client part package not handle:{}", packet.ToString());
    return 0;
}

int NFPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetCid(), "server part package not handle:{}", packet.ToString());
    return 0;
}

uint32_t NFPart::GetCurRoleDetailSeq() const
{
    return GetCurSeq();
}

int NFPart::RegisterMessage()
{
    return 0;
}
