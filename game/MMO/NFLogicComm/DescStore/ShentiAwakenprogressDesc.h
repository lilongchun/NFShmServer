#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Shenti_s.h"

#define MAX_SHENTI_AWAKENPROGRESS_NUM 64

class ShentiAwakenprogressDesc : public NFIDescStore
{
public:
	ShentiAwakenprogressDesc();
	virtual ~ShentiAwakenprogressDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_ShentiAwakenprogress_s* GetDesc(int64_t id) const;
	proto_ff_s::E_ShentiAwakenprogress_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_ShentiAwakenprogress_s* GetDescByIndex(int index) const;
	proto_ff_s::E_ShentiAwakenprogress_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(ShentiAwakenprogressDesc, proto_ff_s::E_ShentiAwakenprogress_s, E_ShentiAwakenprogress, MAX_SHENTI_AWAKENPROGRESS_NUM);
DECLARE_IDCREATE(ShentiAwakenprogressDesc);
};