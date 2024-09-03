/**
 * @file mysql_apply.hpp
 * @brief 对于好友申请过程的二次封装，主要封装的是好友申请记录表的操作
 * @author zhaobohan (zhaobohan_free@163.com)
 */

#pragma once
#include "mysql.hpp"
#include "logger.hpp"
#include "friend_apply.hxx"
#include "friend_apply-odb.hxx"

namespace im {

// 好友申请表类
class FriendApplyTable 
{
public:
    using ptr = std::shared_ptr<FriendApplyTable>;
    FriendApplyTable(const std::shared_ptr<odb::core::database> &db) 
        : _db(db)
    {}

    // 向数据库中插入一个事件
    bool insert(FriendApply &ev) 
    {
        try 
        {
            odb::transaction trans(_db->begin());
            _db->persist(ev);
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("新增好友申请事件失败 {}-{}:{}！", ev.user_id(), ev.peer_id(), e.what());
            return false;
        }
        return true;
    }

    // 判断当前的这对ID，uid到peerID是否存在
    bool exists(const std::string &uid, const std::string &pid) 
    {
        bool flag = false;
        try 
        {
            typedef odb::query<FriendApply> query;
            typedef odb::result<FriendApply> result;
            odb::transaction trans(_db->begin());

            // 构造一个查询语句，去判断在不在
            result r(_db->query<FriendApply>(query::user_id == uid && query::peer_id == pid));
            LOG_DEBUG("{} - {} 好友事件数量：{}", uid, pid, r.size());
            flag = !r.empty();
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("获取好友申请事件失败:{}-{}-{}！", uid, pid, e.what());
        }
        return flag;
    }

    // 删除一对指定的uid和peerID的映射关系
    bool remove(const std::string &uid, const std::string &pid) 
    {
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<FriendApply> query;
            typedef odb::result<FriendApply> result;
            _db->erase_query<FriendApply>(query::user_id == uid && query::peer_id == pid);
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("删除好友申请事件失败 {}-{}:{}！", uid, pid, e.what());
            return false;
        }
        return true;
    }

    // 获取当前指定用户的 所有好友申请者ID
    std::vector<std::string> applyUsers(const std::string &uid)
    {
        std::vector<std::string> res;
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<FriendApply> query;
            typedef odb::result<FriendApply> result;

            // 当前的uid是被申请者的用户ID
            result r(_db->query<FriendApply>(query::peer_id == uid));
            for (result::iterator i(r.begin()); i != r.end(); ++i) 
            {
                res.push_back(i->user_id());
            }
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("通过用户{}的好友申请者失败:{}！", uid, e.what());
        }
        return res;
    }
    
private:
    // 数据库操作的句柄
    std::shared_ptr<odb::core::database> _db;
};

}