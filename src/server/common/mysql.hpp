/**
 * @file mysql.hpp
 * @brief 实例化ODB的连接
 * @author zhaobohan (zhaobohan_free@163.com)
 */

#pragma once
#include <string>
#include <memory>
#include <cstdlib>
#include <odb/database.hxx>
#include <odb/mysql/database.hxx>

namespace im {

// ODB工厂生产类
class ODBFactory 
{
public:
    // 工厂模式创建出一个工厂，然后实例化出一个连接出来
    static std::shared_ptr<odb::core::database> create(
        const std::string &user,
        const std::string &pswd,
        const std::string &host,
        const std::string &db,
        const std::string &cset,
        int port,
        int conn_pool_count) 
    {
        std::unique_ptr<odb::mysql::connection_pool_factory> cpf(new odb::mysql::connection_pool_factory(conn_pool_count, 0));
        auto res = std::make_shared<odb::mysql::database>(user, pswd, 
            db, host, port, "", cset, 0, std::move(cpf));
        return res;
    }
};

}