// -------------------------------------------------------------------------
//    @FileName         :    NFCrashHandlerMgr.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFPluginManager
//
// -------------------------------------------------------------------------

#pragma once

#include <time.h>
#include <stdio.h>
#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <future>
#include <functional>
#include <atomic>

#include "NFCPluginManager.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFCmdLine.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFFileUtility.h"


#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/prctl.h>
#endif

#if NF_PLATFORM == NF_PLATFORM_WIN

void CreateDumpFile(const std::string& strDumpFilePathName, EXCEPTION_POINTERS* pException);

long ApplicationCrashHandler(EXCEPTION_POINTERS* pException);

#endif
