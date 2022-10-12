﻿// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include <ClientServerCmd.pb.h>
#include <Com.pb.h>
#include <ComDefine.pb.h>
#include <ClientServer.pb.h>
#include <ServerClient.pb.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include <NFComm/NFCore/NFServerIDUtil.h>
#include "NFWorldPlayerModule.h"

#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIWorldServerModule.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"

NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFCWorldPlayerModule::~NFCWorldPlayerModule()
{
}

bool NFCWorldPlayerModule::Awake()
{
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::CLIENT_TO_CENTER_LOGIN, this,
                                                       &NFCWorldPlayerModule::OnHandleClientCenterLogin);
    //////////check proxy msg///////////////////////
    FindModule<NFIWorldServerModule>()->AddProxyMsgCheckCallBack(this, &NFCWorldPlayerModule::OnCheckWorldServerMsg);

    return true;
}

bool NFCWorldPlayerModule::Execute()
{
    return true;
}

bool NFCWorldPlayerModule::OnDynamicPlugin()
{
    return true;
}

int NFCWorldPlayerModule::OnHandleClientCenterLogin(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::ClientLoginGateReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL, FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER)");

    //验证版本号，如果版本号不对，不让进入
    CHECK_EXPR(xMsg.version() == pConfig->ClientVersion, -1, "xMsg.version():{} != pConfig->ClientVersion:{}", xMsg.version(),
               pConfig->ClientVersion);

    uint32_t zid = NFServerIDUtil::GetZoneID(pConfig->BusId);
    uint32_t gateid = packet.nSrcId;
    uint32_t chanid = xMsg.channel_id();
    uint32_t uid = xMsg.uid();
    uint32_t loginzid = xMsg.zid();

    return 0;
}

int NFCWorldPlayerModule::OnCheckWorldServerMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }
    return 0;
}