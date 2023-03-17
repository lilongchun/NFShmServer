#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/avatar_s.h"

#define MAX_AVATAR_EQUIPSUIT_NUM 20

class AvatarEquipsuitDesc : public NFIDescStore
{
public:
	AvatarEquipsuitDesc();
	virtual ~AvatarEquipsuitDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AvatarEquipsuit_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarEquipsuit_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarEquipsuit_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarEquipsuit_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(AvatarEquipsuitDesc, proto_ff_s::E_AvatarEquipsuit_s, E_AvatarEquipsuit, MAX_AVATAR_EQUIPSUIT_NUM);
DECLARE_IDCREATE(AvatarEquipsuitDesc);
};