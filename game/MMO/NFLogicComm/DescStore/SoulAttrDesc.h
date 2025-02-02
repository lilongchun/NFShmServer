#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_ATTR_NUM 512

class SoulAttrDesc : public NFIDescTemplate<SoulAttrDesc, proto_ff_s::E_SoulAttr_s, EOT_CONST_SOUL_ATTR_DESC_ID, MAX_SOUL_ATTR_NUM>
{
public:
	SoulAttrDesc();
	virtual ~SoulAttrDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
