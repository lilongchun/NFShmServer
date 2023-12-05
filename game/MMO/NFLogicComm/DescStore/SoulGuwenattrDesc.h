#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_GUWENATTR_NUM 128

class SoulGuwenattrDesc : public NFIDescTemplate<SoulGuwenattrDesc, proto_ff_s::E_SoulGuwenattr_s, EOT_CONST_SOUL_GUWENATTR_DESC_ID, MAX_SOUL_GUWENATTR_NUM>
{
public:
	SoulGuwenattrDesc();
	virtual ~SoulGuwenattrDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};