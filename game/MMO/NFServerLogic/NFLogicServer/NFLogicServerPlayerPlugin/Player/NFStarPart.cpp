// -------------------------------------------------------------------------
//    @FileName         :    NFPartStar.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPartStar
//
// -------------------------------------------------------------------------

#include "NFStarPart.h"

NFStarPart::NFStarPart()
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

NFStarPart::~NFStarPart()
{
}

int NFStarPart::CreateInit()
{
    return 0;
}

int NFStarPart::ResumeInit()
{
    return 0;
}
