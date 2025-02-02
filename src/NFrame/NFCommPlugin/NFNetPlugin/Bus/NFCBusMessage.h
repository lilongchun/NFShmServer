﻿// -------------------------------------------------------------------------
//    @FileName         :    NFCBusModule.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFBusPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIBusModule.h"
#include "NFComm/NFCore/NFSpinLock.h"
#include "NFBusHash.h"
#include "NFBusDefine.h"
#include "NFBusShm.h"
#include "../NFINetMessage.h"
#include "../NFNetDefine.h"
#include "NFComm/NFCore/NFBuffer.h"
#include "NFComm/NFCore/NFCommMapEx.hpp"
#include "NFComm/NFCore/NFConcurrentQueue.h"
#include "NFIBusConnection.h"
#include <map>

class NFCBusServer;
class NFCBusClient;

class NFCBusMessage : public NFINetMessage
{
public:
	explicit NFCBusMessage(NFIPluginManager* p, NF_SERVER_TYPES serverType);

	virtual ~NFCBusMessage();

    virtual bool ReadyExecute() override;

	virtual bool Execute() override;

	virtual bool Shut() override;

	virtual bool Finalize() override;
public:
	/**
	* @brief	初始化
	*
	* @return 是否成功
	*/
	virtual uint64_t BindServer(const NFMessageFlag& flag);

	/**
	* @brief	初始化
	*
	* @return 是否成功
	*/
	virtual uint64_t ConnectServer(const NFMessageFlag& flag);

    /**
     * @brief	发送数据 不包含数据头
     *
     * @param pData		发送的数据,
     * @param unSize	数据的大小
     * @return
     */
    virtual bool Send(uint64_t usLinkId, NFDataPackage& packet, const char* msg, uint32_t nLen);
    virtual bool Send(uint64_t usLinkId, NFDataPackage& packet, const google::protobuf::Message& xData);

	/**
	 * @brief 获得连接IP
	 *
	 * @param  usLinkId
	 * @return std::string
	 */
	virtual std::string GetLinkIp(uint64_t usLinkId);
    virtual uint32_t GetPort(uint64_t usLinkId);

	/**
	* @brief 关闭连接
	*
	* @param  usLinkId
	* @return
	*/
	virtual void CloseLinkId(uint64_t usLinkId);

    virtual void OnHandleMsgPeer(eMsgType type, uint64_t serverLinkId, uint64_t objectLinkId, NFDataPackage& package);

    virtual int ResumeConnect() override;

    virtual int OnTimer(uint32_t nTimerID) override;

    virtual void SendHeartMsg();

    virtual void CheckServerHeartBeat();
private:
    NFCommMapEx<uint64_t, NFIBusConnection> m_busConnectMap;
    NF_SHARE_PTR<NFIBusConnection> m_bindConnect;
};
