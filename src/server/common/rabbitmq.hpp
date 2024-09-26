/**
 * @file rabbitmq.hpp
 * @brief 对于RabbitMQ进行封装
 */

#pragma once
#include <ev.h>
#include <amqpcpp.h>
#include <amqpcpp/libev.h>
#include <openssl/ssl.h>
#include <openssl/opensslv.h>
#include <iostream>
#include <functional>
#include "logger.hpp"

namespace im {

// 消息队列的客户端
class MQClient 
{
public:
    // 关于消息的回调处理函数
    using MessageCallback = std::function<void(const char*, size_t)>;
    using ptr = std::shared_ptr<MQClient>;

    MQClient(const std::string &user, const std::string passwd, const std::string host)
    {
        // 设置默认的循环
        _loop = EV_DEFAULT;
        // 创建一个LibEvHandler，用于处理RabbitMQ的异步事件
        _handler = std::make_unique<AMQP::LibEvHandler>(_loop);
        // amqp://root:123456@127.0.0.1:5672/
        // 平凑出来URL进行连接
        std::string url = "amqp://" + user + ":" + passwd + "@" + host + "/";
        AMQP::Address address(url);

        // 创建TCP连接和通道
        _connection = std::make_unique<AMQP::TcpConnection>(_handler.get(), address);
        _channel = std::make_unique<AMQP::TcpChannel>(_connection.get());

        // 启动事件循环线程
        _loop_thread = std::thread([this]() {
            ev_run(_loop, 0);
        });
    }

    ~MQClient() 
    {
        // 初始化异步观察者，用于通知事件循环退出
        ev_async_init(&_async_watcher, watcher_callback);
        // 将异步观察者添加到事件循环中
        ev_async_start(_loop, &_async_watcher);
        // 发送异步事件，触发watcher_callback
        ev_async_send(_loop, &_async_watcher);
        // 等待事件循环线程结束
        _loop_thread.join();
        _loop = nullptr;
    }

    // 声明RabbitMQ的交换机、队列和绑定
    void declareComponents(const std::string &exchange,
        const std::string &queue,
        const std::string &routing_key = "routing_key",
        AMQP::ExchangeType echange_type = AMQP::ExchangeType::direct) 
    {
        // 声明一个交换机，具体的名字和对应的交换机类型
        _channel->declareExchange(exchange, echange_type)
            .onError([](const char *message) {
                LOG_ERROR("声明交换机失败：{}", message);
                exit(0);
            })
            .onSuccess([exchange](){
                LOG_DEBUG("{} 交换机创建成功！", exchange);
            });

        // 声明一个队列
        _channel->declareQueue(queue)
            .onError([](const char *message) {
                LOG_ERROR("声明队列失败：{}", message);
                exit(0);
            })
            .onSuccess([queue](){
                LOG_DEBUG("{} 队列创建成功！", queue);
            });

        // 针对交换机和队列进行绑定
        _channel->bindQueue(exchange, queue, routing_key)
            .onError([exchange, queue](const char *message) {
                LOG_ERROR("{} - {} 绑定失败：", exchange, queue);
                exit(0);
            })
            .onSuccess([exchange, queue, routing_key](){
                LOG_DEBUG("{} - {} - {} 绑定成功！", exchange, queue, routing_key);
            });
    }

    // 发布消息到RabbitMQ
    bool publish(const std::string &exchange, const std::string &msg, const std::string &routing_key = "routing_key") 
    {
        LOG_DEBUG("向交换机 {}-{} 发布消息！", exchange, routing_key);
        bool ret = _channel->publish(exchange, routing_key, msg);
        if (ret == false)
        {
            LOG_ERROR("{} 发布消息失败：", exchange);
            return false;
        }
        return true;
    }

    // 订阅队列的消息，以及关于消息的回调处理函数
    void consume(const std::string &queue, const MessageCallback &cb) 
    {
        LOG_DEBUG("开始订阅 {} 队列消息！", queue);
        _channel->consume(queue, "consume-tag")  // 返回值 DeferredConsumer
            .onReceived([this, cb](const AMQP::Message &message, 
                uint64_t deliveryTag, 
                bool redelivered) {
                cb(message.body(), message.bodySize());
                _channel->ack(deliveryTag);
            })
            .onError([queue](const char *message){
                LOG_ERROR("订阅 {} 队列消息失败: {}", queue, message);
                exit(0);
            });
    }

private:
    // 触发异步回调函数，直接退出所有的事件循环
    static void watcher_callback(struct ev_loop *loop, ev_async *watcher, int32_t revents) 
    {
        ev_break(loop, EVBREAK_ALL);
    }

private:
    // 异步观察者，用于通知事件循环退出
    struct ev_async _async_watcher;
    // 事件循环指针
    struct ev_loop *_loop;
    // AMQP的LibEv处理器
    std::unique_ptr<AMQP::LibEvHandler> _handler;
    // AMQP的TCP连接
    std::unique_ptr<AMQP::TcpConnection> _connection;
    // AMQP的TCP通道
    std::unique_ptr<AMQP::TcpChannel> _channel;
    // 事件循环线程
    std::thread _loop_thread;
};

}
