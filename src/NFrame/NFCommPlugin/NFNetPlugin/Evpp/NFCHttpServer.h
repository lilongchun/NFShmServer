// -------------------------------------------------------------------------
//    @FileName         :    NFCHttpServer.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCHttpServer.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIHttpHandle.h"
#include "evpp/http/http_server.h"
#include <list>
#include <map>
#include "NFComm/NFCore/NFConcurrentQueue.h"
#include "NFComm/NFPluginModule/NFObjectPool.hpp"
#include <unordered_map>

class NFServerHttpHandle : public NFIHttpHandle {
public:
    NFServerHttpHandle() {
		type = NF_HTTP_REQ_GET;
		requestId = 0;
		timeOut = 0;
    }

    virtual void Reset() override {
        requestId = 0;
        timeOut = 0;
        mCtx = nullptr;
        mResponseCb = nullptr;
    }

    virtual std::string GetOriginalUri() const override { return mCtx->original_uri(); }

    virtual const std::string &GetUrl() const override { return mCtx->uri(); }

    virtual const std::string &GetPath() const override { return mCtx->uri(); }

    virtual const std::string &GetRemoteHost() const override { return mCtx->remote_ip(); }

    virtual int GetType() const override { return type; }

    virtual std::string GetBody() const override { return mCtx->body().ToString(); }

    virtual uint64_t GetRequestId() const override { return requestId; }

    virtual uint64_t GetTimeOut() const override { return timeOut; }

    virtual void AddResponseHeader(const std::string &key, const std::string &value) const override {
        if (mCtx)
        {
            mCtx->AddResponseHeader(key, value);
        }
    }

    virtual bool
    ResponseMsg(const std::string &strMsg, NFWebStatus code, const std::string &strReason = "OK") const override {
        AddResponseHeader("Content-Type", "application/json");
        AddResponseHeader("Access-Control-Allow-Origin", "*");

        if (mCtx)
        {
            mCtx->set_response_http_code(code);
        }

        if (mResponseCb)
        {
            mResponseCb(strMsg);
        }
        return true;
    }

    virtual std::string GetQuery(const std::string& query_key) const override
    {
        if (mCtx)
        {
            return mCtx->GetQuery(query_key);
        }
        return std::string();
    }

    NFHttpType type;
    uint64_t requestId;
    uint64_t timeOut;
    evpp::http::ContextPtr mCtx;
    evpp::http::HTTPSendResponseCallback mResponseCb;
};

class NFEvppHttMsg {
public:
    NFEvppHttMsg()
    {
        Clear();
    }

    virtual ~NFEvppHttMsg()
    {
        Clear();
    }

    NFEvppHttMsg(const NFEvppHttMsg& msg)
    {
        if (this != &msg)
        {
            mCtx = msg.mCtx;
            mResponseCb = msg.mResponseCb;
        }
    }

    NFEvppHttMsg& operator=(const NFEvppHttMsg& msg)
    {
        if (this != &msg)
        {
            mCtx = msg.mCtx;
            mResponseCb = msg.mResponseCb;
        }
        return *this;
    }

    void Clear()
    {
        mCtx = NULL;
        mResponseCb = NULL;
    }
    evpp::http::ContextPtr mCtx;
    evpp::http::HTTPSendResponseCallback mResponseCb;
};

class NFCHttpServer {
public:
    NFCHttpServer(uint32_t serverType, uint32_t netThreadNum);

    virtual ~NFCHttpServer();

    virtual bool Execute();

    virtual uint32_t GetServerType() const;

    virtual bool InitServer(uint32_t listen_port);

    virtual bool InitServer(const std::vector<uint32_t> &listen_ports);

    virtual bool InitServer(const std::string &listen_ports/*like "80,8080,443"*/);

#if defined(EVPP_HTTP_SERVER_SUPPORTS_SSL)
    /* berif 对指定监听端口设置SSL选项
     * param listen_port 监听的端口
     * param enable_ssl 是否开启SSL支持
     * param certificate_chain_file 证书链文件
     * param private_key_file 私钥文件
     */
    void SetPortSSLOption(int listen_port,
                          bool enable_ssl,
                          const char* certificate_chain_file = "",
                          const char* private_key_file = "");
    /* berif 设置端口默认SSL配置选项
     * param enable_ssl 是否开启SSL支持
     * param certificate_chain_file 证书链文件
     * param private_key_file 私钥文件
     */
    void SetPortSSLDefaultOption(
            bool enable_ssl,
            const char* certificate_chain_file = "",
            const char* private_key_file = "");
#endif

    virtual void ProcessMsgLogicThread();

    NFServerHttpHandle *AllocHttpRequest();

    virtual bool ResponseMsg(const NFIHttpHandle &req, const std::string &strMsg, NFWebStatus code,
                             const std::string &strReason = "OK");

    virtual bool
    ResponseMsg(uint64_t reqeustId, const std::string &strMsg, NFWebStatus code, const std::string &strReason = "OK");
public:
    /**
    *@brief  设置接收回调.
    */
    template<typename BaseType>
    void SetRecvCB(BaseType *pBaseType, bool (BaseType::*handleRecieve)(uint32_t, const NFIHttpHandle &req)) {
        mReceiveCB = std::bind(handleRecieve, pBaseType, std::placeholders::_1, std::placeholders::_2);
    }

    /**
     *@brief  设置连接事件回调.
     */
    template<typename BaseType>
    void SetFilterCB(BaseType *pBaseType, NFWebStatus(BaseType::*handleFilter)(uint32_t, const NFIHttpHandle &req)) {
        mFilter = std::bind(handleFilter, pBaseType, std::placeholders::_1, std::placeholders::_2);
    }

    /**
     *@brief  设置接收回调.
     */
    void SetRecvCB(const HTTP_RECEIVE_FUNCTOR &recvcb) {
        mReceiveCB = recvcb;
    }

    /**
     *@brief  设置连接事件回调.
     */
    void SetFilterCB(const HTTP_FILTER_FUNCTOR &eventcb) {
        mFilter = eventcb;
    }
private:
    evpp::http::Server *m_pHttpServer;
private:
    uint32_t mPort;
    uint32_t mServerType;
    std::vector<uint32_t> mVecPort;

    NFConcurrentQueue<NFEvppHttMsg> mMsgQueue;

    uint64_t mIndex;
    std::unordered_map<uint64_t, NFServerHttpHandle *> mHttpRequestMap;
    NFObjectPool<NFServerHttpHandle>* mListHttpRequestPool;
protected:
    HTTP_RECEIVE_FUNCTOR mReceiveCB;
    HTTP_FILTER_FUNCTOR mFilter;
};

