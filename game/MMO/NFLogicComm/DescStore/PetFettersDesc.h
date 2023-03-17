#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/pet_s.h"

#define MAX_PET_FETTERS_NUM 20

class PetFettersDesc : public NFIDescStore
{
public:
	PetFettersDesc();
	virtual ~PetFettersDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_PetFetters_s* GetDesc(int64_t id) const;
	proto_ff_s::E_PetFetters_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_PetFetters_s* GetDescByIndex(int index) const;
	proto_ff_s::E_PetFetters_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(PetFettersDesc, proto_ff_s::E_PetFetters_s, E_PetFetters, MAX_PET_FETTERS_NUM);
DECLARE_IDCREATE(PetFettersDesc);
};