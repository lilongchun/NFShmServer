#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/arena_s.h"

#define MAX_ARENA_ROBOT_NUM 6000

class ArenaRobotDesc : public NFIDescStore
{
public:
	ArenaRobotDesc();
	virtual ~ArenaRobotDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_ArenaRobot_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ArenaRobot_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ArenaRobot_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ArenaRobot_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(ArenaRobotDesc, proto_ff_s::E_ArenaRobot_s, E_ArenaRobot, MAX_ARENA_ROBOT_NUM);
DECLARE_IDCREATE(ArenaRobotDesc);
};