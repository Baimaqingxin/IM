/**
 * @file asr.hpp
 * @brief 基于百度语音翻译的二次封装
 * @author zhaobohan (zhaobohan_free@163.com)
 */

#pragma once
#include "../third/include/aip-cpp-sdk/speech.h"
#include "logger.hpp"

namespace im {

class ASRClient 
{
public:
    using ptr = std::shared_ptr<ASRClient>;

    ASRClient(const std::string &app_id, const std::string &api_key, const std::string &secret_key)
        : _client(app_id, api_key, secret_key) 
    {}

    std::string recognize(const std::string &speech_data, std::string &err)
    {
        // 直接调用即可
        Json::Value result = _client.recognize(speech_data, "pcm", 16000, aip::null);
        if (result["err_no"].asInt() != 0) 
        {
            LOG_ERROR("语音识别失败：{}", result["err_msg"].asString());
            err = result["err_msg"].asString();
            return std::string();
        }
        return result["result"][0].asString();
    }

private:
    aip::Speech _client;
};

}