// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ClientServerCmd.proto

#ifndef PROTOBUF_ClientServerCmd_2eproto__INCLUDED
#define PROTOBUF_ClientServerCmd_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include "yd_fieldoptions.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ClientServerCmd_2eproto();
void protobuf_AssignDesc_ClientServerCmd_2eproto();
void protobuf_ShutdownFile_ClientServerCmd_2eproto();


enum ClientServerCmd {
  E_CS_ERROR = 1000,
  NF_CS_Msg_Get_Room_Info_Req = 1011,
  NF_SC_Msg_Get_Room_Info_Rsp = 1012,
  NF_CS_MSG_EnterGame_AUTO_JOIN_Req = 1013,
  NF_CS_MSG_EnterGame_AUTO_JOIN_Rsp = 1014,
  NF_CS_MSG_DeskListReq = 1015,
  NF_SC_MSG_DeskListRsp = 1016,
  NF_CS_MSG_ChairCheckReq = 1017,
  NF_SC_MSG_ChairCheckRsp = 1018,
  NF_CS_MSG_EnterGameReq = 1019,
  NF_SC_MSG_EnterGameRsp = 1020,
  NF_CS_MSG_ExitRoomReq = 1021,
  NF_SC_MSG_ExitRoomRsp = 1022,
  NF_CS_MSG_ExitGameReq = 1023,
  NF_SC_MSG_ExitGameRsp = 1024,
  NF_CS_MSG_UserRecomeReq = 1025,
  NF_SC_MSG_UserRecomeRsp = 1026,
  NF_SC_MSG_GamePlayerLeave = 1028,
  NF_SC_MSG_MoneyChangeNotify = 1030,
  NF_SC_MSG_PaoMaDengNotify = 1031,
  NF_CS_MSG_RedeemCodeReq = 1032,
  NF_SC_MSG_RedeemCodeRsp = 1033,
  NF_CS_Msg_ReConnect_REQ = 1005,
  NF_SC_Msg_ReConnect_RSP = 1006,
  NF_SC_Msg_KitPlayer_Notify = 1007,
  NF_CS_Msg_HeartBeat_REQ = 1009,
  NF_SC_Msg_HeartBeat_RSP = 1010,
  NF_CS_MSG_AccountLoginReq = 1101,
  NF_SC_MSG_AccountLoginRsp = 1102,
  NF_CS_MSG_UserLoginReq = 1103,
  NF_SC_MSG_UserLoginRsp = 1104,
  NF_CS_MSG_RegisterAccountReq = 1105,
  NF_SC_MSG_RegisterAccountRsp = 1106,
  NF_CS_MSG_LoginServer_PhoneAutoCodeReq = 1107,
  NF_SC_MSG_LoginServer_PhoneAutoCodeRsp = 1108,
  NF_CS_MSG_LoginServer_CheckPhoneCodeReq = 1109,
  NF_SC_MSG_LoginServer_CheckPhoneCodeRsp = 1110,
  NF_CS_MSG_CHANGE_PASSWORD_REQ = 1111,
  NF_SC_MSG_CHANGE_PASSWORD_RESP = 1112,
  NF_SC_MSG_LoginServer_NotifyPhoneCheck = 1113,
  NF_CS_MSG_PlayerPhoneAutoCodeReq = 1130,
  NF_SC_MSG_PlayerPhoneAutoCodeRsp = 1131,
  NF_CS_MSG_PlayerCheckPhoneCodeReq = 1132,
  NF_SC_MSG_PlayerCheckPhoneCodeRsp = 1133,
  NF_CS_MSG_ChangeFaceReq = 1134,
  NF_SC_MSG_ChangeFaceRsp = 1135,
  NF_CS_MSG_ChangeNickNameReq = 1136,
  NF_SC_MSG_ChangeNickNameRsp = 1137,
  NF_CS_MSG_BIND_PHONE_REQ = 1138,
  NF_CS_MSG_BIND_PHONE_RSP = 1139,
  NF_CS_MSG_PHONE_CHANG_BAND_PASSWORD_REQ = 1140,
  NF_CS_MSG_PHONE_CHANG_BAND_PASSWORD_RSP = 1141,
  NF_CS_QUERY_USER_SIMPLE_DATA_REQ = 1198,
  NF_SC_QUERY_USER_SIMPLE_DATA_RSP = 1199,
  NF_CS_SNS_MAIL_LIST_REQ = 1150,
  NF_SC_SNS_MAIL_LIST_RSP = 1151,
  NF_CS_SNS_MAIL_READ_REQ = 1152,
  NF_SC_SNS_MAIL_READ_RSP = 1153,
  NF_CS_SNS_MAIL_DEL_REQ = 1154,
  NF_SC_SNS_MAIL_DEL_RSP = 1155,
  NF_SC_SNS_MAIL_AUTO_PUSH_RSP = 1156,
  NF_CS_SNS_MAIL_GET_ITEM_REQ = 1157,
  NF_SC_SNS_MAIL_GET_ITEM_RSP = 1158,
  NF_CS_BANK_GET_DATA_REQ = 1170,
  NF_SC_BANK_GET_DATA_RSP = 1171,
  NF_CS_BANK_SAVE_MONEY_REQ = 1172,
  NF_SC_BANK_SAVE_MONEY_RSP = 1173,
  NF_CS_BANK_GET_MONEY_REQ = 1174,
  NF_SC_BANK_GET_MONEY_RSP = 1175,
  NF_CS_BANK_SET_PASSWORD_REQ = 1176,
  NF_SC_BANK_SET_PASSWORD_RSP = 1177,
  NF_CS_BANK_GIVE_BANK_JETTON_REQ = 1178,
  NF_SC_BANK_GIVE_BANK_JETTON_RSP = 1179,
  NF_SC_BANK_GIVE_BANK_JETTON_AUTO_PUSH_RSP = 1180,
  NF_CS_BANK_GET_RECORD_REQ = 1181,
  NF_SC_BANK_GET_RECORD_RSP = 1182,
  NF_CS_GET_COMMON_RANK_REQ = 1200,
  NF_CS_GET_COMMON_RANK_RSP = 1201,
  NF_CS_MSG_UserStatusReq = 10017,
  NF_SC_MSG_UserStatusRsp = 10018,
  CLIENT_SERVER_MAX_CMD = 20000
};
bool ClientServerCmd_IsValid(int value);
const ClientServerCmd ClientServerCmd_MIN = E_CS_ERROR;
const ClientServerCmd ClientServerCmd_MAX = CLIENT_SERVER_MAX_CMD;
const int ClientServerCmd_ARRAYSIZE = ClientServerCmd_MAX + 1;

const ::google::protobuf::EnumDescriptor* ClientServerCmd_descriptor();
inline const ::std::string& ClientServerCmd_Name(ClientServerCmd value) {
  return ::google::protobuf::internal::NameOfEnum(
    ClientServerCmd_descriptor(), value);
}
inline bool ClientServerCmd_Parse(
    const ::std::string& name, ClientServerCmd* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ClientServerCmd>(
    ClientServerCmd_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::ClientServerCmd>() {
  return ::proto_ff::ClientServerCmd_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ClientServerCmd_2eproto__INCLUDED
