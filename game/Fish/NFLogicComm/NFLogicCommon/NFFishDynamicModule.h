// -------------------------------------------------------------------------
//    @FileName         :    NFFishDynamicModule.h
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishDynamicModule
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFCommMap.hpp"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFLogicBindRpcService.h"
#include "AllProtocol.h"

class NFFishDynamicModule : public NFIDynamicModule
{
public:
    NFFishDynamicModule(NFIPluginManager* p);

    virtual ~NFFishDynamicModule();
};