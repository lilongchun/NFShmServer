// -------------------------------------------------------------------------
//    @FileName         :    NFPackageConfig.h
//    @Author           :    gaoyi
//    @Date             :    2022/9/30
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackageConfig
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFILuaLoader.h"
#include "NFServerLogicMessage/ServerConfig.pb.h"
#include "NFServerLogicMessage/ClientServerCmd.pb.h"
#include "proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"

class NFPackageConfig : public NFILuaLoader
{
public:
    NFPackageConfig();
    virtual ~NFPackageConfig();
public:
    int LoadConfig(const std::string &path, const std::string &server);
    const proto_ff::PacketMsg* GetPacketConfig(uint32_t cmd);
public:
    std::vector<proto_ff::PacketMsg> m_packetMsgConfig;
};