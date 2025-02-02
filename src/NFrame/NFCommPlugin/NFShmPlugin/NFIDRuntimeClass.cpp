// -------------------------------------------------------------------------
//    @FileName         :    NFIDRuntimeClass.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFIDRuntimeClass.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFShmObjSeg.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFGlobalID.h"


NFIDRuntimeClass::NFIDRuntimeClass()
{
	m_pParent = NULL;
    m_iObjType = -1;
}