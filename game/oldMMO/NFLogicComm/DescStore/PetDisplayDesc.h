#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/pet_s.h"

#define MAX_PET_DISPLAY_NUM 20

class PetDisplayDesc : public NFIDescStore
{
public:
	PetDisplayDesc();
	virtual ~PetDisplayDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PetDisplay_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetDisplay_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetDisplay_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetDisplay_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(PetDisplayDesc, proto_ff_s::E_PetDisplay_s, E_PetDisplay, MAX_PET_DISPLAY_NUM);
DECLARE_IDCREATE(PetDisplayDesc);
};