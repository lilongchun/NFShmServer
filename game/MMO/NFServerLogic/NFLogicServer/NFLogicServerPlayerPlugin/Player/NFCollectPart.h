// -------------------------------------------------------------------------
//    @FileName         :    NFCollectPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFCollectPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFCollectPart : public NFShmObjTemplate<NFCollectPart, EOT_LOGIC_PART_ID+PART_COLLECT, NFPart>
{
public:
    NFCollectPart();

    virtual ~NFCollectPart();

    int CreateInit();

    int ResumeInit();
};