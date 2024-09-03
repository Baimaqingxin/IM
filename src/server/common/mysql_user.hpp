/**
 * @file mysql_user.hpp
 * @brief 利用ODB对于MySQL中的对象进行操作，主要封装的是user表的操作
 * @author zhaobohan (zhaobohan_free@163.com)
 */

#include "mysql.hpp"
#include "user.hxx"
#include "user-odb.hxx"
#include "logger.hpp"

namespace im {

class UserTable 
{
public:
    using ptr = std::shared_ptr<UserTable>;

    UserTable(const std::shared_ptr<odb::core::database> &db)
        : _db(db)
    {}

    // 插入一个用户的信息
    bool insert(const std::shared_ptr<User> &user) 
    {
        try 
        {
            // 开启一个ODB事务，将对应的信息存储到db中，提交事务，有异常会throw
            odb::transaction trans(_db->begin());
            _db->persist(*user);
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("新增用户失败 {}:{}！", user->nickname(), e.what());
            return false;
        }

        return true;
    }

    // 更新一条用户信息
    bool update(const std::shared_ptr<User> &user) 
    {
        try 
        {
            odb::transaction trans(_db->begin());
            _db->update(*user);
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("更新用户失败 {}:{}！", user->nickname(), e.what());
            return false;
        }
        return true;
    }

    // 根据昵称筛选信息
    std::shared_ptr<User> select_by_nickname(const std::string &nickname) 
    {
        std::shared_ptr<User> res;
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<User> query;
            typedef odb::result<User> result;
            res.reset(_db->query_one<User>(query::nickname == nickname));
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("通过昵称查询用户失败 {}:{}！", nickname, e.what());
        }
        return res;
    }

    // 根据手机号筛选信息
    std::shared_ptr<User> select_by_phone(const std::string &phone) 
    {
        std::shared_ptr<User> res;
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<User> query;
            typedef odb::result<User> result;
            res.reset(_db->query_one<User>(query::phone == phone));
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("通过手机号查询用户失败 {}:{}！", phone, e.what());
        }

        return res;
    }

    // 根据用户ID筛选信息
    std::shared_ptr<User> select_by_id(const std::string &user_id) 
    {
        std::shared_ptr<User> res;
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<User> query;
            typedef odb::result<User> result;
            res.reset(_db->query_one<User>(query::user_id == user_id));
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("通过用户ID查询用户失败 {}:{}！", user_id, e.what());
        }

        return res;
    }

    // 一次筛选多个用户的信息
    std::vector<User> select_multi_users(const std::vector<std::string> &id_list) 
    {
        // select * from user where id in ('id1', 'id2', ...)
        std::vector<User> res;
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<User> query;
            typedef odb::result<User> result;
            std::stringstream ss;
            ss << "user_id in (";
            for (const auto &id : id_list) 
            {
                ss << "'" << id << "',";
            }

            std::string condition = ss.str();
            condition.pop_back();
            condition += ")";
            result r(_db->query<User>(condition));
            for (result::iterator i(r.begin()); i != r.end(); ++i) 
            {
                res.push_back(*i);
            }

            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("通过用户ID批量查询用户失败:{}！", e.what());
        }

        return res;
    }

private:
    std::shared_ptr<odb::core::database> _db;
};

}