#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/daily_s.h"

#define MAX_DAILY_REWARD_NUM 20

class DailyRewardDesc : public NFIDescStore
{
public:
	DailyRewardDesc();
	virtual ~DailyRewardDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_DailyReward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_DailyReward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_DailyReward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_DailyReward_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(DailyRewardDesc, proto_ff_s::E_DailyReward_s, E_DailyReward, MAX_DAILY_REWARD_NUM);
DECLARE_IDCREATE(DailyRewardDesc);
};