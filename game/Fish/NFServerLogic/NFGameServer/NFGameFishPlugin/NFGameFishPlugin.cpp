﻿// -------------------------------------------------------------------------
//    @FileName         :    NFGameLogicPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFGameFishPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFGameFishModule.h"
#include "NFLogicCommon/NFIGameConfig.h"
#include "NFLogicCommon/NFFishDefine.h"
#include "Config/NFFishTraceConfig.h"
#include "Config/NFFishGroupConfig.h"
#include "Config/NFFishConfigConfig.h"
#include "Config/NFFishWayBillConfig.h"
#include "Config/NFFishSettingConfig.h"
#include "Config/NFFishPromptConfig.h"
#include "Desk/NFGameFishDesk.h"
#include "FishTypeHandler/NFFishTypeDelayBomb.h"
#include "FishTypeHandler/NFFishTypeDianCiCannon.h"
#include "FishTypeHandler/NFFishTypeFireStorm.h"
#include "FishTypeHandler/NFFishTypeFreeze.h"
#include "FishTypeHandler/NFFishTypeFullScrBomb.h"
#include "FishTypeHandler/NFFishTypeZuanTou.h"
#include "FishTypeHandler/NFFishTypeHaiWangCrab.h"
#include "FishTypeHandler/NFFishTypeKindBomb.h"
#include "FishTypeHandler/NFFishTypeLightLink.h"
#include "FishTypeHandler/NFFishTypeLightningJellyFish.h"
#include "FishTypeHandler/NFFishTypeMadCow.h"
#include "FishTypeHandler/NFFishTypeSerialBombCrab.h"
#include "FishTypeHandler/NFFishTypeSomeZuanTou.h"

#define MAX_FISH_ROOM_DESK_COUNT 255
#define MAX_GAME_FISH_ROBOT_COUNT 1000

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFGameFishPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFGameFishPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFGameFishPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFGameFishPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFGameFishPlugin);
}

void NFGameFishPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFGameFishModule,    NFGameFishModule);
}

void NFGameFishPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFGameFishModule,    NFGameFishModule);
}

bool NFGameFishPlugin::InitShmObjectRegister()
{
    auto pGameConfig = FindModule<NFIGameConfig>()->GetConfig();
    NF_ASSERT(pGameConfig);

    uint32_t roomNum = FindModule<NFIGameConfig>()->GetAllRoomNum();
    uint32_t maxDeskNumByRoom =  FindModule<NFIGameConfig>()->GetRoomMaxDeskNum();
    uint32_t maxDeskNum = roomNum*maxDeskNumByRoom*1.2;
    REGISTER_SHM_OBJ_WITH_HASH(NFFishTraceConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishGroupConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishConfigConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishWayBillConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishSettingConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishPromptConfig, roomNum);

    REGISTER_SHM_OBJ(NFGameFishDesk, maxDeskNum);

    REGISTER_SHM_OBJ(NFFishTypeMgr, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeHandler, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeDelayBomb, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeDianCiCannon, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeFireStorm, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeFreeze, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeFullScrBomb, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeHaiWangCrab, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeKindBomb, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeLightLink, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeLightningJellyFish, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeMadCow, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeSerialBombCrab, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeSomeZuanTou, maxDeskNum);
    REGISTER_SHM_OBJ(NFFishTypeZuanTou, maxDeskNum);


	return true;
}