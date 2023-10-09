#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xingchen_s.h"

#define MAX_XINGCHEN_XCMATERIAL_NUM 8

class XingchenXcmaterialDesc : public NFIDescStore
{
public:
	XingchenXcmaterialDesc();
	virtual ~XingchenXcmaterialDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_XingchenXcmaterial_s* GetDesc(int64_t id) const;
	proto_ff_s::E_XingchenXcmaterial_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_XingchenXcmaterial_s* GetDescByIndex(int index) const;
	proto_ff_s::E_XingchenXcmaterial_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(XingchenXcmaterialDesc, proto_ff_s::E_XingchenXcmaterial_s, E_XingchenXcmaterial, MAX_XINGCHEN_XCMATERIAL_NUM);
DECLARE_IDCREATE(XingchenXcmaterialDesc);
};