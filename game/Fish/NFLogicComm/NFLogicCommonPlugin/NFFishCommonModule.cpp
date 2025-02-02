﻿// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFFishCommonModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFLogicCommon/NFLogicError.h"

bool NFFishCommonModule::Awake()
{
    NFError::Instance()->SetErrorFunction(GetLogicErrorStr);
    return true;
}
