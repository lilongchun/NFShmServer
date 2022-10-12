#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/operate_s.h"

#define MAX_OPERATE_RAND_NUM 60

class OperateRandDesc : public NFIDescStore
{
public:
	OperateRandDesc(NFIPluginManager* pPluginManager);
	virtual ~OperateRandDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::operaterand_s* GetDesc(int id) const;
	proto_ff_s::operaterand_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::operaterand_s, MAX_OPERATE_RAND_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::operaterand_s, MAX_OPERATE_RAND_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::operaterand_s, operaterand, MAX_OPERATE_RAND_NUM);
DECLARE_IDCREATE(OperateRandDesc);
};