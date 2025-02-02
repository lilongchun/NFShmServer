#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"

class FishDescEx : public NFIDescStoreEx
{
public:
	FishDescEx();
	virtual ~FishDescEx();
	int CreateInit();
	int ResumeInit();
private:
IMPL_RES_DESC_EX(FishDescEx)
DECLARE_IDCREATE(FishDescEx)
};
