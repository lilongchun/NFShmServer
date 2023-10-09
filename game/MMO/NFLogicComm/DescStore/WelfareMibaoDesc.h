#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Welfare_s.h"

#define MAX_WELFARE_MIBAO_NUM 32

class WelfareMibaoDesc : public NFIDescStore
{
public:
	WelfareMibaoDesc();
	virtual ~WelfareMibaoDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_WelfareMibao_s* GetDesc(int64_t id) const;
	proto_ff_s::E_WelfareMibao_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_WelfareMibao_s* GetDescByIndex(int index) const;
	proto_ff_s::E_WelfareMibao_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(WelfareMibaoDesc, proto_ff_s::E_WelfareMibao_s, E_WelfareMibao, MAX_WELFARE_MIBAO_NUM);
DECLARE_IDCREATE(WelfareMibaoDesc);
};