// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef FRIEND_APPLY_ODB_HXX
#define FRIEND_APPLY_ODB_HXX

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2047700 // 2.5.0-b.27
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <odb/boost/date-time/mysql/gregorian-traits.hxx>
#include <odb/boost/date-time/mysql/posix-time-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if ODB_VERSION != 20477UL
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "friend_apply.hxx"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // FriendApply
  //
  template <>
  struct class_traits< ::im::FriendApply >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::im::FriendApply >
  {
    public:
    typedef ::im::FriendApply object_type;
    typedef ::im::FriendApply* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef long unsigned int id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mysql/version.hxx>
#include <odb/mysql/forward.hxx>
#include <odb/mysql/binding.hxx>
#include <odb/mysql/mysql-types.hxx>
#include <odb/mysql/query.hxx>

namespace odb
{
  // FriendApply
  //
  template <typename A>
  struct query_columns< ::im::FriendApply, id_mysql, A >
  {
    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    id_type_;

    static const id_type_ id;

    // event_id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    event_id_type_;

    static const event_id_type_ event_id;

    // user_id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    user_id_type_;

    static const user_id_type_ user_id;

    // peer_id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    peer_id_type_;

    static const peer_id_type_ peer_id;
  };

  template <typename A>
  const typename query_columns< ::im::FriendApply, id_mysql, A >::id_type_
  query_columns< ::im::FriendApply, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename query_columns< ::im::FriendApply, id_mysql, A >::event_id_type_
  query_columns< ::im::FriendApply, id_mysql, A >::
  event_id (A::table_name, "`event_id`", 0);

  template <typename A>
  const typename query_columns< ::im::FriendApply, id_mysql, A >::user_id_type_
  query_columns< ::im::FriendApply, id_mysql, A >::
  user_id (A::table_name, "`user_id`", 0);

  template <typename A>
  const typename query_columns< ::im::FriendApply, id_mysql, A >::peer_id_type_
  query_columns< ::im::FriendApply, id_mysql, A >::
  peer_id (A::table_name, "`peer_id`", 0);

  template <typename A>
  struct pointer_query_columns< ::im::FriendApply, id_mysql, A >:
    query_columns< ::im::FriendApply, id_mysql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::im::FriendApply, id_mysql >:
    public access::object_traits< ::im::FriendApply >
  {
    public:
    struct id_image_type
    {
      unsigned long long id_value;
      my_bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // _id
      //
      unsigned long long _id_value;
      my_bool _id_null;

      // _event_id
      //
      details::buffer _event_id_value;
      unsigned long _event_id_size;
      my_bool _event_id_null;

      // _user_id
      //
      details::buffer _user_id_value;
      unsigned long _user_id_size;
      my_bool _user_id_null;

      // _peer_id
      //
      details::buffer _peer_id_value;
      unsigned long _peer_id_size;
      my_bool _peer_id_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef mysql::object_statements<object_type> statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 4UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::im::FriendApply, id_common >:
    public access::object_traits_impl< ::im::FriendApply, id_mysql >
  {
  };

  // FriendApply
  //
}

#include "friend_apply-odb.ixx"

#include <odb/post.hxx>

#endif // FRIEND_APPLY_ODB_HXX
