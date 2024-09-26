/**
 * @file etcd.hpp
 * @brief 对于etcd服务发现的封装
 */

#pragma once
#include <etcd/Client.hpp>
#include <etcd/KeepAlive.hpp>
#include <etcd/Response.hpp>
#include <etcd/Watcher.hpp>
#include <etcd/Value.hpp>
#include <functional>
#include "logger.hpp"

namespace im {
// 服务注册客户端类
class Registry 
{
public:
    using ptr = std::shared_ptr<Registry>;

    Registry(const std::string &host)
        : _client(std::make_shared<etcd::Client>(host))
        , _keep_alive(_client->leasekeepalive(3).get())
        , _lease_id(_keep_alive->Lease())
    {}

    // 取消租约保持
    ~Registry() { _keep_alive->Cancel(); }

    // 将键值对key-value注册到服务中心
    bool registry(const std::string &key, const std::string &val) 
    {
        auto resp = _client->put(key, val, _lease_id).get();
        if (resp.is_ok() == false) 
        {
            LOG_ERROR("注册数据失败：{}", resp.error_message());
            return false;
        }
        return true;
    }

private:
    // 客户端的智能指针，用于和服务端进行通信方法集
    std::shared_ptr<etcd::Client> _client;
    // 租约保持对象，用于自动续约
    std::shared_ptr<etcd::KeepAlive> _keep_alive;
    // 租约ID，用于标记键值对的生命周期
    uint64_t _lease_id;
};

// 服务发现客户端类
class Discovery 
{
public:
    using ptr = std::shared_ptr<Discovery>;
    // Watcher的回调函数
    using NotifyCallback = std::function<void(std::string, std::string)>;

    Discovery(const std::string &host, const std::string &basedir,
        const NotifyCallback &put_cb, const NotifyCallback &del_cb)
        : _client(std::make_shared<etcd::Client>(host)), _put_cb(put_cb), _del_cb(del_cb)
    {
        // 先进行服务发现,先获取到当前已有的数据
        auto resp = _client->ls(basedir).get();
        if (resp.is_ok() == false) 
        {
            LOG_ERROR("获取服务信息数据失败：{}", resp.error_message());
        }
        int sz = resp.keys().size();
        // 遍历获取到的结果，调用回调函数
        for (int i = 0; i < sz; ++i)
        {
            if (_put_cb) 
                _put_cb(resp.key(i), resp.value(i).as_string());
        }
        // 然后进行事件监控，监听基于basedir上面的事件，监控数据发生的改变并调用回调进行处理
        _watcher = std::make_shared<etcd::Watcher>(*_client.get(), basedir,
            std::bind(&Discovery::callback, this, std::placeholders::_1), true);
    }

    ~Discovery() 
    {
        _watcher->Cancel();
    }

private:
    void callback(const etcd::Response &resp) 
    {
        if (resp.is_ok() == false) 
        {
            LOG_ERROR("收到一个错误的事件通知: {}", resp.error_message());
            return;
        }

        // 根据事件类型调用回调函数
        for (auto const& ev : resp.events()) 
        {
            // 如果是新增事件，就调用新增事件的回调函数
            if (ev.event_type() == etcd::Event::EventType::PUT) 
            {
                if (_put_cb) 
                    _put_cb(ev.kv().key(), ev.kv().as_string());
                LOG_DEBUG("新增服务：{}-{}", ev.kv().key(), ev.kv().as_string());
            }
            // 如果是删除事件，就调用删除事件的回调函数
            else if (ev.event_type() == etcd::Event::EventType::DELETE_) 
            {
                if (_del_cb) 
                    _del_cb(ev.prev_kv().key(), ev.prev_kv().as_string());
                LOG_DEBUG("下线服务：{}-{}", ev.prev_kv().key(), ev.prev_kv().as_string());
            }
        }
    }
    
private:
    NotifyCallback _put_cb;
    NotifyCallback _del_cb;
    std::shared_ptr<etcd::Client> _client;
    // 用于监听服务变更
    std::shared_ptr<etcd::Watcher> _watcher;
};

}
