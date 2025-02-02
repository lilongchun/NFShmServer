﻿// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include <string>

//////////////////////////////////////////////////////////////////////////
class NFFishWorldPlayerPlugin : public NFIPlugin
{
public:
	explicit NFFishWorldPlayerPlugin(NFIPluginManager* p): NFIPlugin(p)
	{
	}

	virtual int GetPluginVersion() override;

	virtual std::string GetPluginName() override;

	virtual void Install() override;

	virtual void Uninstall() override;

	virtual bool InitShmObjectRegister() override;
};
