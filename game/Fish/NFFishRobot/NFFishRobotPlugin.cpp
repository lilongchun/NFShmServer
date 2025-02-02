// -------------------------------------------------------------------------
//    @FileName         :    NFRobotPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFRobotPlugin.cpp
//
// -------------------------------------------------------------------------
#include "NFFishRobotPlugin.h"
#include "NFRobotModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFFishRobotPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFFishRobotPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFFishRobotPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFFishRobotPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFFishRobotPlugin);
}

void NFFishRobotPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFCRobotModule, NFCRobotModule);
}

void NFFishRobotPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFCRobotModule, NFCRobotModule);
}
