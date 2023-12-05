#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Festival_s.h"

#define MAX_FESTIVAL_MUBAN_EGGSDRAW_NUM 16

class FestivalMuban_eggsdrawDesc : public NFIDescTemplate<FestivalMuban_eggsdrawDesc, proto_ff_s::E_FestivalMuban_eggsdraw_s, EOT_CONST_FESTIVAL_MUBAN_EGGSDRAW_DESC_ID, MAX_FESTIVAL_MUBAN_EGGSDRAW_NUM>
{
public:
	FestivalMuban_eggsdrawDesc();
	virtual ~FestivalMuban_eggsdrawDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};