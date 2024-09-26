/**
 * @file mysql_chat_session.hpp
 * @brief 主要封装的是对于聊天会话表的操作
 */

#pragma once
#include "mysql.hpp"
#include "chat_session.hxx"
#include "chat_session-odb.hxx"
#include "mysql_chat_session_member.hpp"

namespace im {

// 聊天会话管理类
class ChatSessionTable 
{
public:
    using ptr = std::shared_ptr<ChatSessionTable>;

    ChatSessionTable(const std::shared_ptr<odb::core::database> &db)
        : _db(db)
    {}

    // 插入一对聊天会话
    bool insert(ChatSession &cs) 
    {
        try 
        {
            odb::transaction trans(_db->begin());
            _db->persist(cs);
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("新增会话失败 {}:{}！", cs.chat_session_name(), e.what());
            return false;
        }
        return true;
    }

    // 删除某个SessionID
    bool remove(const std::string &ssid) 
    {
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<ChatSession> query;
            typedef odb::result<ChatSession> result;
            _db->erase_query<ChatSession>(query::chat_session_id == ssid);

            typedef odb::query<ChatSessionMember> mquery;
            _db->erase_query<ChatSessionMember>(mquery::session_id == ssid);
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("删除会话失败 {}:{}！", ssid, e.what());
            return false;
        }

        return true;
    }

    // 移除某个单聊会话，即useID和peerID
    bool remove(const std::string &uid, const std::string &pid) 
    {
        // 单聊会话的删除，-- 根据单聊会话的两个成员
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<SingleChatSession> query;
            typedef odb::result<SingleChatSession> result;
            auto res = _db->query_one<SingleChatSession>(
                query::csm1::user_id == uid && 
                query::csm2::user_id == pid && 
                query::css::chat_session_type == ChatSessionType::SINGLE);

            std::string cssid = res->chat_session_id;
            typedef odb::query<ChatSession> cquery;
            _db->erase_query<ChatSession>(cquery::chat_session_id == cssid);

            typedef odb::query<ChatSessionMember> mquery;
            _db->erase_query<ChatSessionMember>(mquery::session_id == cssid);
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("删除会话失败 {}-{}:{}！", uid, pid, e.what());
            return false;
        }
        return true;
    }

    // 根据SessionID来获取一个聊天会话的对象里面的全部信息，这个是提前封装好的
    std::shared_ptr<ChatSession> select(const std::string &ssid) 
    {
        std::shared_ptr<ChatSession> res;
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<ChatSession> query;
            typedef odb::result<ChatSession> result;
            res.reset(_db->query_one<ChatSession>(query::chat_session_id == ssid));
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("通过会话ID获取会话信息失败 {}:{}！", ssid, e.what());
        }
        return res;
    }

    // 根据用户的ID，获取他现在所处于的所有单聊的会话ID
    std::vector<SingleChatSession> singleChatSession(const std::string &uid) 
    {
        std::vector<SingleChatSession> res;
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<SingleChatSession> query;
            typedef odb::result<SingleChatSession> result;
            // 当前的uid是被申请者的用户ID
            result r(_db->query<SingleChatSession>(
                query::css::chat_session_type == ChatSessionType::SINGLE && 
                query::csm1::user_id == uid && 
                query::csm2::user_id != query::csm1::user_id));
            for (result::iterator i(r.begin()); i != r.end(); ++i) 
            {
                res.push_back(*i);
            }
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("获取用户 {} 的单聊会话失败:{}！", uid, e.what());
        }
        return res;
    }

    // 获取某个用户ID对应的群聊信息
    std::vector<GroupChatSession> groupChatSession(const std::string &uid) 
    {
        std::vector<GroupChatSession> res;
        try 
        {
            odb::transaction trans(_db->begin());
            typedef odb::query<GroupChatSession> query;
            typedef odb::result<GroupChatSession> result;
            // 当前的uid是被申请者的用户ID
            result r(_db->query<GroupChatSession>(
                query::css::chat_session_type == ChatSessionType::GROUP && 
                query::csm::user_id == uid ));
            for (result::iterator i(r.begin()); i != r.end(); ++i) 
            {
                res.push_back(*i);
            }
            trans.commit();
        }
        catch (std::exception &e) 
        {
            LOG_ERROR("获取用户 {} 的群聊会话失败:{}！", uid, e.what());
        }
        return res;
    }

private:
    std::shared_ptr<odb::core::database> _db;
};

}
