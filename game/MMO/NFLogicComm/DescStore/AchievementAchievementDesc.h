#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Achievement_s.h"

#define MAX_ACHIEVEMENT_ACHIEVEMENT_NUM 256

class AchievementAchievementDesc : public NFIDescStore
{
public:
	AchievementAchievementDesc();
	virtual ~AchievementAchievementDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_AchievementAchievement_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AchievementAchievement_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AchievementAchievement_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AchievementAchievement_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(AchievementAchievementDesc, proto_ff_s::E_AchievementAchievement_s, E_AchievementAchievement, MAX_ACHIEVEMENT_ACHIEVEMENT_NUM);
DECLARE_IDCREATE(AchievementAchievementDesc);
};