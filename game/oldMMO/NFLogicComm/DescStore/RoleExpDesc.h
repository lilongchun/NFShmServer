#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/role_s.h"

#define MAX_ROLE_EXP_NUM 2000

class RoleExpDesc : public NFIDescStore
{
public:
	RoleExpDesc();
	virtual ~RoleExpDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoleExp_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoleExp_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoleExp_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoleExp_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RoleExpDesc, proto_ff_s::E_RoleExp_s, E_RoleExp, MAX_ROLE_EXP_NUM);
DECLARE_IDCREATE(RoleExpDesc);
};