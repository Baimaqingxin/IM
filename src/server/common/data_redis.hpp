/**
 * @file data_redis.hpp
 * @brief 封装对于Redis的数据管理
 * @author zhaobohan (zhaobohan_free@163.com)
 */
#include <sw/redis++/redis.h>
#include <iostream>

namespace im {

// 生产Redis连接的工厂
class RedisClientFactory 
{
public:
    static std::shared_ptr<sw::redis::Redis> create(
        const std::string &host,
        int port,
        int db,
        bool keep_alive) 
    {
        sw::redis::ConnectionOptions opts;
        opts.host = host;
        opts.port = port;
        opts.db = db;
        opts.keep_alive = keep_alive;
        opts.password = "zhaobohanREDIS";
        auto res = std::make_shared<sw::redis::Redis>(opts);
        return res;
    }
};

// 对于会话的管理
class Session 
{
public:
    using ptr = std::shared_ptr<Session>;

    Session(const std::shared_ptr<sw::redis::Redis> &redis_client)
        : _redis_client(redis_client)
    {}

    // 进行一些增删查的操作
    void append(const std::string &ssid, const std::string &uid) 
    {
        _redis_client->set(ssid, uid);
    }

    void remove(const std::string &ssid) 
    {
        _redis_client->del(ssid);
    }

    sw::redis::OptionalString uid(const std::string &ssid) 
    {
        return _redis_client->get(ssid);
    }

private:
    std::shared_ptr<sw::redis::Redis> _redis_client;
};

// 判断用户此时的登录状态信息
class Status 
{
public:
    using ptr = std::shared_ptr<Status>;

    Status(const std::shared_ptr<sw::redis::Redis> &redis_client)
        : _redis_client(redis_client)
    {}

    void append(const std::string &uid) 
    {
        _redis_client->set(uid, "");
    }

    void remove(const std::string &uid) 
    {
        _redis_client->del(uid);
    }

    bool exists(const std::string &uid) 
    {
        auto res = _redis_client->get(uid);
        if (res) 
            return true;
        return false;
    }

private:
    std::shared_ptr<sw::redis::Redis> _redis_client;
};

// 验证码的管理
class Codes 
{
public:
    using ptr = std::shared_ptr<Codes>;

    Codes(const std::shared_ptr<sw::redis::Redis> &redis_client)
        : _redis_client(redis_client)
    {}

    // 进行一些常规的操作
    void append(const std::string &cid, const std::string &code, 
        const std::chrono::milliseconds &t = std::chrono::milliseconds(300000)) 
    {
        _redis_client->set(cid, code, t);
    }

    void remove(const std::string &cid) 
    {
        _redis_client->del(cid);
    }

    sw::redis::OptionalString code(const std::string &cid)  
    {
        return _redis_client->get(cid);
    }

private:
    std::shared_ptr<sw::redis::Redis> _redis_client;
};

}