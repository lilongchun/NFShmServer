// -------------------------------------------------------------------------
//    @FileName         :    NFMountPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMountPart
//
// -------------------------------------------------------------------------

#include "NFMountPart.h"

NFMountPart::NFMountPart()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFMountPart::~NFMountPart()
{
}

int NFMountPart::CreateInit()
{
    return 0;
}

int NFMountPart::ResumeInit()
{
    return 0;
}