// -------------------------------------------------------------------------
//    @FileName         :    NFFindTreasurePart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFindTreasurePart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFFindTreasurePart : public NFShmObjTemplate<NFFindTreasurePart, EOT_LOGIC_PART_ID+PART_FINDTREASURE, NFPart>
{
public:
    NFFindTreasurePart();

    virtual ~NFFindTreasurePart();

    int CreateInit();

    int ResumeInit();
};