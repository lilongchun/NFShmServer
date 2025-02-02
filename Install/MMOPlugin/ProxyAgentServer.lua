require "Common"		--

--ProxyAgentServer 网管服务器， 负责与外部的客户端连接, 转发数据
--ServerId = "15.100.5.1" 15是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 5是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
ProxyAgentServer = {
    ProxyAgentServer_1 = {
        ServerName = "ProxyAgentServer_1",
        ServerType = NF_ST_PROXY_AGENT_SERVER,
        ServerId = NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_PROXY_AGENT_SERVER..".1",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
        IdleSleepUS = 1000,
        LinkMode = NF_LINK_MODE,
        BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
        MaxConnectNum = NF_INTER_MAX_CONNECT,
        NetThreadNum = 5,
        WorkThreadNum = 1,
        MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
        ServerIp = NF_INTER_SERVER_IP,
        ServerPort = NF_INTER_SERVER_PORT+NF_ST_PROXY_AGENT_SERVER*10+1,
        HandleMsgNumPerFrame = NF_TRANS_SERVER_HANDLE_MSG_COUNT,
        RouteConfig = {
            RouteAgent = NF_ROUTE_AGENT_ID,
            MasterIp = NF_MASTER_IP,
            MasterPort = NF_MASTER_PORT,
        },
    };

    CrossProxyAgentServer_1 = {
        ServerName = "CrossProxyAgentServer_1",
        ServerType = NF_ST_PROXY_AGENT_SERVER,
        ServerId = NF_ST_WORLD_ID.."."..NF_ST_CROSS_ZONE_ID.."."..NF_ST_PROXY_AGENT_SERVER..".1",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
        IdleSleepUS = 1000,
        LinkMode = NF_LINK_MODE,
        BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
        MaxConnectNum = NF_INTER_MAX_CONNECT,
        NetThreadNum = 5,
        WorkThreadNum = 1,
        CrossServer = true,
        MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
        ServerIp = NF_INTER_CROSS_SERVER_IP,
        ServerPort = NF_INTER_CROSS_SERVER_PORT+NF_ST_PROXY_AGENT_SERVER*10+1,
        HandleMsgNumPerFrame = NF_TRANS_SERVER_HANDLE_MSG_COUNT,
        RouteConfig = {
            RouteAgent = NF_CROSS_ROUTE_AGENT_ID1,
            MasterIp = NF_MASTER_IP,
            MasterPort = NF_MASTER_PORT,
        },
    };
};
