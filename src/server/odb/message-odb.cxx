// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "message-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/mysql/traits.hxx>
#include <odb/mysql/database.hxx>
#include <odb/mysql/transaction.hxx>
#include <odb/mysql/connection.hxx>
#include <odb/mysql/statement.hxx>
#include <odb/mysql/statement-cache.hxx>
#include <odb/mysql/simple-object-statements.hxx>
#include <odb/mysql/container-statements.hxx>
#include <odb/mysql/exceptions.hxx>
#include <odb/mysql/simple-object-result.hxx>
#include <odb/mysql/enum.hxx>

namespace odb
{
  // Message
  //

  struct access::object_traits_impl< ::im::Message, id_mysql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      mysql::connection&,
      image_type&,
      id_image_type&,
      mysql::binding&,
      mysql::binding&)
    {
    }
  };

  access::object_traits_impl< ::im::Message, id_mysql >::id_type
  access::object_traits_impl< ::im::Message, id_mysql >::
  id (const id_image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        id,
        i.id_value,
        i.id_null);
    }

    return id;
  }

  access::object_traits_impl< ::im::Message, id_mysql >::id_type
  access::object_traits_impl< ::im::Message, id_mysql >::
  id (const image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        id,
        i._id_value,
        i._id_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::im::Message, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // _id
    //
    t[0UL] = 0;

    // _message_id
    //
    if (t[1UL])
    {
      i._message_id_value.capacity (i._message_id_size);
      grew = true;
    }

    // _session_id
    //
    if (t[2UL])
    {
      i._session_id_value.capacity (i._session_id_size);
      grew = true;
    }

    // _user_id
    //
    if (t[3UL])
    {
      i._user_id_value.capacity (i._user_id_size);
      grew = true;
    }

    // _message_type
    //
    t[4UL] = 0;

    // _create_time
    //
    t[5UL] = 0;

    // _content
    //
    if (t[6UL])
    {
      i._content_value.capacity (i._content_size);
      grew = true;
    }

    // _file_id
    //
    if (t[7UL])
    {
      i._file_id_value.capacity (i._file_id_size);
      grew = true;
    }

    // _file_name
    //
    if (t[8UL])
    {
      i._file_name_value.capacity (i._file_name_size);
      grew = true;
    }

    // _file_size
    //
    t[9UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::im::Message, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // _id
    //
    if (sk != statement_update)
    {
      b[n].buffer_type = MYSQL_TYPE_LONGLONG;
      b[n].is_unsigned = 1;
      b[n].buffer = &i._id_value;
      b[n].is_null = &i._id_null;
      n++;
    }

    // _message_id
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i._message_id_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i._message_id_value.capacity ());
    b[n].length = &i._message_id_size;
    b[n].is_null = &i._message_id_null;
    n++;

    // _session_id
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i._session_id_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i._session_id_value.capacity ());
    b[n].length = &i._session_id_size;
    b[n].is_null = &i._session_id_null;
    n++;

    // _user_id
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i._user_id_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i._user_id_value.capacity ());
    b[n].length = &i._user_id_size;
    b[n].is_null = &i._user_id_null;
    n++;

    // _message_type
    //
    b[n].buffer_type = MYSQL_TYPE_TINY;
    b[n].is_unsigned = 1;
    b[n].buffer = &i._message_type_value;
    b[n].is_null = &i._message_type_null;
    n++;

    // _create_time
    //
    b[n].buffer_type = MYSQL_TYPE_TIMESTAMP;
    b[n].buffer = &i._create_time_value;
    b[n].is_null = &i._create_time_null;
    n++;

    // _content
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i._content_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i._content_value.capacity ());
    b[n].length = &i._content_size;
    b[n].is_null = &i._content_null;
    n++;

    // _file_id
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i._file_id_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i._file_id_value.capacity ());
    b[n].length = &i._file_id_size;
    b[n].is_null = &i._file_id_null;
    n++;

    // _file_name
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i._file_name_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i._file_name_value.capacity ());
    b[n].length = &i._file_name_size;
    b[n].is_null = &i._file_name_null;
    n++;

    // _file_size
    //
    b[n].buffer_type = MYSQL_TYPE_LONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i._file_size_value;
    b[n].is_null = &i._file_size_null;
    n++;
  }

  void access::object_traits_impl< ::im::Message, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::im::Message, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

    // _id
    //
    if (sk == statement_insert)
    {
      long unsigned int const& v =
        o._id;

      bool is_null (false);
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_image (
        i._id_value, is_null, v);
      i._id_null = is_null;
    }

    // _message_id
    //
    {
      ::std::string const& v =
        o._message_id;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i._message_id_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i._message_id_value,
        size,
        is_null,
        v);
      i._message_id_null = is_null;
      i._message_id_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i._message_id_value.capacity ());
    }

    // _session_id
    //
    {
      ::std::string const& v =
        o._session_id;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i._session_id_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i._session_id_value,
        size,
        is_null,
        v);
      i._session_id_null = is_null;
      i._session_id_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i._session_id_value.capacity ());
    }

    // _user_id
    //
    {
      ::std::string const& v =
        o._user_id;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i._user_id_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i._user_id_value,
        size,
        is_null,
        v);
      i._user_id_null = is_null;
      i._user_id_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i._user_id_value.capacity ());
    }

    // _message_type
    //
    {
      unsigned char const& v =
        o._message_type;

      bool is_null (false);
      mysql::value_traits<
          unsigned char,
          mysql::id_utiny >::set_image (
        i._message_type_value, is_null, v);
      i._message_type_null = is_null;
    }

    // _create_time
    //
    {
      ::boost::posix_time::ptime const& v =
        o._create_time;

      bool is_null (true);
      mysql::value_traits<
          ::boost::posix_time::ptime,
          mysql::id_timestamp >::set_image (
        i._create_time_value, is_null, v);
      i._create_time_null = is_null;
    }

    // _content
    //
    {
      ::odb::nullable< ::std::basic_string< char > > const& v =
        o._content;

      bool is_null (true);
      std::size_t size (0);
      std::size_t cap (i._content_value.capacity ());
      mysql::value_traits<
          ::odb::nullable< ::std::basic_string< char > >,
          mysql::id_string >::set_image (
        i._content_value,
        size,
        is_null,
        v);
      i._content_null = is_null;
      i._content_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i._content_value.capacity ());
    }

    // _file_id
    //
    {
      ::odb::nullable< ::std::basic_string< char > > const& v =
        o._file_id;

      bool is_null (true);
      std::size_t size (0);
      std::size_t cap (i._file_id_value.capacity ());
      mysql::value_traits<
          ::odb::nullable< ::std::basic_string< char > >,
          mysql::id_string >::set_image (
        i._file_id_value,
        size,
        is_null,
        v);
      i._file_id_null = is_null;
      i._file_id_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i._file_id_value.capacity ());
    }

    // _file_name
    //
    {
      ::odb::nullable< ::std::basic_string< char > > const& v =
        o._file_name;

      bool is_null (true);
      std::size_t size (0);
      std::size_t cap (i._file_name_value.capacity ());
      mysql::value_traits<
          ::odb::nullable< ::std::basic_string< char > >,
          mysql::id_string >::set_image (
        i._file_name_value,
        size,
        is_null,
        v);
      i._file_name_null = is_null;
      i._file_name_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i._file_name_value.capacity ());
    }

    // _file_size
    //
    {
      ::odb::nullable< unsigned int > const& v =
        o._file_size;

      bool is_null (true);
      mysql::value_traits<
          ::odb::nullable< unsigned int >,
          mysql::id_ulong >::set_image (
        i._file_size_value, is_null, v);
      i._file_size_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::im::Message, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // _id
    //
    {
      long unsigned int& v =
        o._id;

      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_value (
        v,
        i._id_value,
        i._id_null);
    }

    // _message_id
    //
    {
      ::std::string& v =
        o._message_id;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i._message_id_value,
        i._message_id_size,
        i._message_id_null);
    }

    // _session_id
    //
    {
      ::std::string& v =
        o._session_id;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i._session_id_value,
        i._session_id_size,
        i._session_id_null);
    }

    // _user_id
    //
    {
      ::std::string& v =
        o._user_id;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i._user_id_value,
        i._user_id_size,
        i._user_id_null);
    }

    // _message_type
    //
    {
      unsigned char& v =
        o._message_type;

      mysql::value_traits<
          unsigned char,
          mysql::id_utiny >::set_value (
        v,
        i._message_type_value,
        i._message_type_null);
    }

    // _create_time
    //
    {
      ::boost::posix_time::ptime& v =
        o._create_time;

      mysql::value_traits<
          ::boost::posix_time::ptime,
          mysql::id_timestamp >::set_value (
        v,
        i._create_time_value,
        i._create_time_null);
    }

    // _content
    //
    {
      ::odb::nullable< ::std::basic_string< char > >& v =
        o._content;

      mysql::value_traits<
          ::odb::nullable< ::std::basic_string< char > >,
          mysql::id_string >::set_value (
        v,
        i._content_value,
        i._content_size,
        i._content_null);
    }

    // _file_id
    //
    {
      ::odb::nullable< ::std::basic_string< char > >& v =
        o._file_id;

      mysql::value_traits<
          ::odb::nullable< ::std::basic_string< char > >,
          mysql::id_string >::set_value (
        v,
        i._file_id_value,
        i._file_id_size,
        i._file_id_null);
    }

    // _file_name
    //
    {
      ::odb::nullable< ::std::basic_string< char > >& v =
        o._file_name;

      mysql::value_traits<
          ::odb::nullable< ::std::basic_string< char > >,
          mysql::id_string >::set_value (
        v,
        i._file_name_value,
        i._file_name_size,
        i._file_name_null);
    }

    // _file_size
    //
    {
      ::odb::nullable< unsigned int >& v =
        o._file_size;

      mysql::value_traits<
          ::odb::nullable< unsigned int >,
          mysql::id_ulong >::set_value (
        v,
        i._file_size_value,
        i._file_size_null);
    }
  }

  void access::object_traits_impl< ::im::Message, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      mysql::value_traits<
          long unsigned int,
          mysql::id_ulonglong >::set_image (
        i.id_value, is_null, id);
      i.id_null = is_null;
    }
  }

  const char access::object_traits_impl< ::im::Message, id_mysql >::persist_statement[] =
  "INSERT INTO `message` "
  "(`id`, "
  "`message_id`, "
  "`session_id`, "
  "`user_id`, "
  "`message_type`, "
  "`create_time`, "
  "`content`, "
  "`file_id`, "
  "`file_name`, "
  "`file_size`) "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::im::Message, id_mysql >::find_statement[] =
  "SELECT "
  "`message`.`id`, "
  "`message`.`message_id`, "
  "`message`.`session_id`, "
  "`message`.`user_id`, "
  "`message`.`message_type`, "
  "`message`.`create_time`, "
  "`message`.`content`, "
  "`message`.`file_id`, "
  "`message`.`file_name`, "
  "`message`.`file_size` "
  "FROM `message` "
  "WHERE `message`.`id`=?";

  const char access::object_traits_impl< ::im::Message, id_mysql >::update_statement[] =
  "UPDATE `message` "
  "SET "
  "`message_id`=?, "
  "`session_id`=?, "
  "`user_id`=?, "
  "`message_type`=?, "
  "`create_time`=?, "
  "`content`=?, "
  "`file_id`=?, "
  "`file_name`=?, "
  "`file_size`=? "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::im::Message, id_mysql >::erase_statement[] =
  "DELETE FROM `message` "
  "WHERE `id`=?";

  const char access::object_traits_impl< ::im::Message, id_mysql >::query_statement[] =
  "SELECT "
  "`message`.`id`, "
  "`message`.`message_id`, "
  "`message`.`session_id`, "
  "`message`.`user_id`, "
  "`message`.`message_type`, "
  "`message`.`create_time`, "
  "`message`.`content`, "
  "`message`.`file_id`, "
  "`message`.`file_name`, "
  "`message`.`file_size` "
  "FROM `message`";

  const char access::object_traits_impl< ::im::Message, id_mysql >::erase_query_statement[] =
  "DELETE FROM `message`";

  const char access::object_traits_impl< ::im::Message, id_mysql >::table_name[] =
  "`message`";

  void access::object_traits_impl< ::im::Message, id_mysql >::
  persist (database& db, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    im._id_value = 0;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj._id = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::im::Message, id_mysql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;
    using mysql::update_statement;

    callback (db, obj, callback_event::pre_update);

    mysql::transaction& tr (mysql::transaction::current ());
    mysql::connection& conn (tr.connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& idi (sts.id_image ());
    init (idi, id (obj));

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::im::Message, id_mysql >::
  erase (database& db, const id_type& id)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::im::Message, id_mysql >::pointer_type
  access::object_traits_impl< ::im::Message, id_mysql >::
  find (database& db, const id_type& id)
  {
    using namespace mysql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::im::Message, id_mysql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    assert (l.locked ()) /* Must be a top-level call. */;

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::im::Message, id_mysql >::
  reload (database& db, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection (db));
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    assert (l.locked ()) /* Must be a top-level call. */;

    const id_type& id (object_traits_impl::id (obj));
    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::im::Message, id_mysql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mysql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::im::Message, id_mysql >::object_type >
  access::object_traits_impl< ::im::Message, id_mysql >::
  query (database& db, const query_base_type& q)
  {
    using namespace mysql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    mysql::connection& conn (
      mysql::transaction::current ().connection (db));

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) mysql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::im::Message, id_mysql >::
  erase_query (database& db, const query_base_type& q)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection (db));

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
