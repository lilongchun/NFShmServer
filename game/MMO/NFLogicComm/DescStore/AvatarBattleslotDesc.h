#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/avatar_s.h"

#define MAX_AVATAR_BATTLESLOT_NUM 20

class AvatarBattleslotDesc : public NFIDescStore
{
public:
	AvatarBattleslotDesc();
	virtual ~AvatarBattleslotDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AvatarBattleslot_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarBattleslot_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarBattleslot_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarBattleslot_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AvatarBattleslotDesc, proto_ff_s::E_AvatarBattleslot_s, E_AvatarBattleslot, MAX_AVATAR_BATTLESLOT_NUM);
DECLARE_IDCREATE(AvatarBattleslotDesc);
};