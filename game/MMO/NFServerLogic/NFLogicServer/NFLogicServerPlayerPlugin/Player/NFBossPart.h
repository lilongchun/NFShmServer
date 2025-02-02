// -------------------------------------------------------------------------
//    @FileName         :    NFBossPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFBossPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFBossPart : public NFShmObjTemplate<NFBossPart, EOT_LOGIC_PART_ID+PART_BOSS, NFPart>
{
public:
    NFBossPart();

    virtual ~NFBossPart();

    int CreateInit();

    int ResumeInit();
};