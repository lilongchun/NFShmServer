// -------------------------------------------------------------------------
//    @FileName         :    NFIProxyClientModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFServerComm/NFServerCommon/NFServerCommonDefine.h"

class NFIProxyClientModule : public NFIDynamicModule
{
public:
	NFIProxyClientModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}
	virtual ~NFIProxyClientModule()
	{

	}
};
