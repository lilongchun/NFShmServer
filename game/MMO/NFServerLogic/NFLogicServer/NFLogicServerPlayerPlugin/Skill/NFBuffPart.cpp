// -------------------------------------------------------------------------
//    @FileName         :    NFBuffPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFBuffPart
//
// -------------------------------------------------------------------------

#include "NFBuffPart.h"

NFBuffPart::NFBuffPart()
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

NFBuffPart::~NFBuffPart()
{
}

int NFBuffPart::CreateInit()
{
    return 0;
}

int NFBuffPart::ResumeInit()
{
    return 0;
}
