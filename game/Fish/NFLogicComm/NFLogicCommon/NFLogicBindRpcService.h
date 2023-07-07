// -------------------------------------------------------------------------
//    @FileName         :    NFLogicBindRpcService.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicBindRpcService
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIRpcService.h"
#include "ClientServerCmd.pb.h"
#include "CSLogin.pb.h"
#include "ServerInternal.pb.h"
#include "ServerInternalCmd.pb.h"

/**
 * @brief 账号登录rpc, proxy server to login server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_AccountLoginReq, proto_ff::Proto_CSAccountLoginReq, proto_ff::Proto_SCAccountLoginRsp)

/**
 * @brief 账号注册rpc, proxy server to login server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_RegisterAccountReq, proto_ff::Proto_CSRegisterAccountReq, proto_ff::Proto_SCRegisterAccountRsp)

/**
 * @brief 玩家登录rpc, proxy server to world server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_PTW_PLAYER_LOGIN_REQ, proto_ff::Proto_PTWUserLoginReq, proto_ff::Proto_WTPPlayerLoginRsp)

/**
 * @brief 玩家登录rpc, world server to logic server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTL_PLAYER_LOGIN_REQ, proto_ff::Proto_WorldToLogicLoginReq, proto_ff::Proto_LogicToWorldLoginRsp)