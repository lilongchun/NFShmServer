// -------------------------------------------------------------------------
//    @FileName         :    NFServerFrameTypeDefines.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTypeDefines.h"


typedef enum
{
	EOT_SF_BEGIN_ID = EOT_SERVER_FRAME_BEGIN_ID,
    ////////////////////////////server common////////////////////////////////////////////////

    ////////////////////////////server common////////////////////////////////////////////////

	////////////////////////////sns server/////////////////////////////
    EOT_SNS_ROLE_SIMPLE_ID,
    EOT_SNS_ROLE_DETAIL_ID,
    EOT_PLAYER_ONLINE_ID,
    EOT_SNS_CACHE_MGR_ID,
    EOT_SNS_LOAD_CACHE_MGR_ID,
    ////////////////////////////sns trans server/////////////////////////////
    EOT_SNS_TRANS_CACHE_BASE_ID,
    EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID,
    EOT_SNS_TRANS_GET_ROLE_DETAIL_ID,
    EOT_SNS_TRANS_SAVE_PLAYER_SIMPLE,
    EOT_SNS_TRANS_SAVE_PLAYER_DETAIL,
    ////////////////////////////sns part server/////////////////////////////
    EOT_SNS_PART_ID,
    EOT_NFSnsJettonPart_ID,
	////////////////////////////sns server/////////////////////////////

	////////////////////////////logic server/////////////////////////////

    //////////////////////////logic part////////////////////////
    EOT_LOGIC_PART_ID,
    EOT_NFJettonPart_ID,
    EOT_NFRoomPart_ID,
    //////////////////////////logic trans////////////////////////
    EOT_TRANS_LOGIC_USER_BASE,
    EOT_TRANS_SAVE_PLAYER,
	////////////////////////////logic server/////////////////////////////
    EOT_LOGIC_PLAYER_MGR_ID,
    EOT_LOGIC_PLAYER_ID,
	////////////////////////////login server/////////////////////////////
    EOT_ACCOUNTLOGIN_HASHTABLE_ID,
	////////////////////////////login server/////////////////////////////
	////////////////////////////world server/////////////////////////////
    EOT_WORLD_PLAYER_MGR_ID,
    EOT_WORLD_PLAYER_ID,
    EOT_NFWorldRoom_ID,
    EOT_NFWorldRoomMgr_ID,
    ////////////////////////////world server trans/////////////////////////////

    ////////////////////////////world server trans/////////////////////////////
	////////////////////////////world server/////////////////////////////

	////////////////////////////game server/////////////////////////////
    EOT_NFGamePlayer_ID,
    EOT_NFGamePlayerMgr_ID,
    EOT_NFGameRoom_ID,
    EOT_NFGameRoomMgr_ID,
    EOT_NFGameDesc_ID,
    EOT_NFGameConfig_ID,
    EOT_FISH_GROUP_MGR_ID,
    EOT_FISH_TRACE_MGR_ID,
    EOT_FISH_CONFIG_MGR_ID,
    EOT_GAME_FISH_WAY_BILL_DESC_ID,
    EOT_GAME_FISH_SETTING_DESC_ID,
    EOT_GAME_FISH_PROMPT_CFG_DESC_ID,
    EOT_NFGameFishDesk_ID,
    EOT_NFFishTypeMgr_ID,
    ////////////////////////////fish type handler///////////////////////
    EOT_GAME_FISH_TYPE_HANDLE_ID,
    EOT_GAME_FISH_TYPE_HANDLE_DELAYBOMB_ID,
    EOT_GAME_FISH_TYPE_HANDLE_DIANCICANNON_ID,
    EOT_GAME_FISH_TYPE_HANDLE_DNTG_ID,
    EOT_GAME_FISH_TYPE_HANDLE_FIRESTORM_ID,
    EOT_GAME_FISH_TYPE_HANDLE_FREEZE_ID,
    EOT_GAME_FISH_TYPE_HANDLE_FULLSCRBOMB_ID,
    EOT_GAME_FISH_TYPE_HANDLE_HAIWANGCRAB_ID,
    EOT_GAME_FISH_TYPE_HANDLE_KINDBOMB_ID,
    EOT_GAME_FISH_TYPE_HANDLE_LIGHTLINK_ID,
    EOT_GAME_FISH_TYPE_HANDLE_LIGHTNINGJELLYFISH_ID,
    EOT_GAME_FISH_TYPE_HANDLE_MADCOW_ID,
    EOT_GAME_FISH_TYPE_HANDLE_SERIALBOMBCRAB_ID,
    EOT_GAME_FISH_TYPE_HANDLE_SOME_ZUANTOU_ID,
    EOT_GAME_FISH_TYPE_HANDLE_ZUANTOU_ID,
    EOT_GAME_FISH_TYPE_HANDLE_BLACKHOLEBOMB_ID,
    EOT_GAME_FISH_TYPE_HANDLE_HAISHEN_ID,
    EOT_GAME_FISH_TYPE_HANDLE_GOLDENBULL_ID,
    EOT_GAME_FISH_TYPE_HANDLE_CAISHEN_ID,
    EOT_GAME_FISH_TYPE_HANDLE_FISHPROPSAVER_ID,
    ////////////////////////////game server/////////////////////////////
	///////////////////////////////////////////////////////////
	EOT_SF_END_ID = EOT_SERVER_FRAME_END_ID,
} EN_SERVERFRAME_SHMOBJ_TYPE;
