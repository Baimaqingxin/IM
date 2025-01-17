// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: gateway.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_gateway_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_gateway_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "base.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_gateway_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_gateway_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_gateway_2eproto;
namespace im {
class ClientAuthenticationReq;
class ClientAuthenticationReqDefaultTypeInternal;
extern ClientAuthenticationReqDefaultTypeInternal _ClientAuthenticationReq_default_instance_;
}  // namespace im
PROTOBUF_NAMESPACE_OPEN
template<> ::im::ClientAuthenticationReq* Arena::CreateMaybeMessage<::im::ClientAuthenticationReq>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace im {

// ===================================================================

class ClientAuthenticationReq PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:im.ClientAuthenticationReq) */ {
 public:
  inline ClientAuthenticationReq() : ClientAuthenticationReq(nullptr) {}
  virtual ~ClientAuthenticationReq();

  ClientAuthenticationReq(const ClientAuthenticationReq& from);
  ClientAuthenticationReq(ClientAuthenticationReq&& from) noexcept
    : ClientAuthenticationReq() {
    *this = ::std::move(from);
  }

  inline ClientAuthenticationReq& operator=(const ClientAuthenticationReq& from) {
    CopyFrom(from);
    return *this;
  }
  inline ClientAuthenticationReq& operator=(ClientAuthenticationReq&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ClientAuthenticationReq& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ClientAuthenticationReq* internal_default_instance() {
    return reinterpret_cast<const ClientAuthenticationReq*>(
               &_ClientAuthenticationReq_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ClientAuthenticationReq& a, ClientAuthenticationReq& b) {
    a.Swap(&b);
  }
  inline void Swap(ClientAuthenticationReq* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ClientAuthenticationReq* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ClientAuthenticationReq* New() const final {
    return CreateMaybeMessage<ClientAuthenticationReq>(nullptr);
  }

  ClientAuthenticationReq* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ClientAuthenticationReq>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ClientAuthenticationReq& from);
  void MergeFrom(const ClientAuthenticationReq& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ClientAuthenticationReq* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "im.ClientAuthenticationReq";
  }
  protected:
  explicit ClientAuthenticationReq(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_gateway_2eproto);
    return ::descriptor_table_gateway_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRequestIdFieldNumber = 1,
    kSessionIdFieldNumber = 2,
  };
  // string request_id = 1;
  void clear_request_id();
  const std::string& request_id() const;
  void set_request_id(const std::string& value);
  void set_request_id(std::string&& value);
  void set_request_id(const char* value);
  void set_request_id(const char* value, size_t size);
  std::string* mutable_request_id();
  std::string* release_request_id();
  void set_allocated_request_id(std::string* request_id);
  private:
  const std::string& _internal_request_id() const;
  void _internal_set_request_id(const std::string& value);
  std::string* _internal_mutable_request_id();
  public:

  // string session_id = 2;
  void clear_session_id();
  const std::string& session_id() const;
  void set_session_id(const std::string& value);
  void set_session_id(std::string&& value);
  void set_session_id(const char* value);
  void set_session_id(const char* value, size_t size);
  std::string* mutable_session_id();
  std::string* release_session_id();
  void set_allocated_session_id(std::string* session_id);
  private:
  const std::string& _internal_session_id() const;
  void _internal_set_session_id(const std::string& value);
  std::string* _internal_mutable_session_id();
  public:

  // @@protoc_insertion_point(class_scope:im.ClientAuthenticationReq)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr request_id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr session_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_gateway_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ClientAuthenticationReq

// string request_id = 1;
inline void ClientAuthenticationReq::clear_request_id() {
  request_id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& ClientAuthenticationReq::request_id() const {
  // @@protoc_insertion_point(field_get:im.ClientAuthenticationReq.request_id)
  return _internal_request_id();
}
inline void ClientAuthenticationReq::set_request_id(const std::string& value) {
  _internal_set_request_id(value);
  // @@protoc_insertion_point(field_set:im.ClientAuthenticationReq.request_id)
}
inline std::string* ClientAuthenticationReq::mutable_request_id() {
  // @@protoc_insertion_point(field_mutable:im.ClientAuthenticationReq.request_id)
  return _internal_mutable_request_id();
}
inline const std::string& ClientAuthenticationReq::_internal_request_id() const {
  return request_id_.Get();
}
inline void ClientAuthenticationReq::_internal_set_request_id(const std::string& value) {
  
  request_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void ClientAuthenticationReq::set_request_id(std::string&& value) {
  
  request_id_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:im.ClientAuthenticationReq.request_id)
}
inline void ClientAuthenticationReq::set_request_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  request_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:im.ClientAuthenticationReq.request_id)
}
inline void ClientAuthenticationReq::set_request_id(const char* value,
    size_t size) {
  
  request_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:im.ClientAuthenticationReq.request_id)
}
inline std::string* ClientAuthenticationReq::_internal_mutable_request_id() {
  
  return request_id_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* ClientAuthenticationReq::release_request_id() {
  // @@protoc_insertion_point(field_release:im.ClientAuthenticationReq.request_id)
  return request_id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void ClientAuthenticationReq::set_allocated_request_id(std::string* request_id) {
  if (request_id != nullptr) {
    
  } else {
    
  }
  request_id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), request_id,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:im.ClientAuthenticationReq.request_id)
}

// string session_id = 2;
inline void ClientAuthenticationReq::clear_session_id() {
  session_id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& ClientAuthenticationReq::session_id() const {
  // @@protoc_insertion_point(field_get:im.ClientAuthenticationReq.session_id)
  return _internal_session_id();
}
inline void ClientAuthenticationReq::set_session_id(const std::string& value) {
  _internal_set_session_id(value);
  // @@protoc_insertion_point(field_set:im.ClientAuthenticationReq.session_id)
}
inline std::string* ClientAuthenticationReq::mutable_session_id() {
  // @@protoc_insertion_point(field_mutable:im.ClientAuthenticationReq.session_id)
  return _internal_mutable_session_id();
}
inline const std::string& ClientAuthenticationReq::_internal_session_id() const {
  return session_id_.Get();
}
inline void ClientAuthenticationReq::_internal_set_session_id(const std::string& value) {
  
  session_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void ClientAuthenticationReq::set_session_id(std::string&& value) {
  
  session_id_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:im.ClientAuthenticationReq.session_id)
}
inline void ClientAuthenticationReq::set_session_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  session_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:im.ClientAuthenticationReq.session_id)
}
inline void ClientAuthenticationReq::set_session_id(const char* value,
    size_t size) {
  
  session_id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:im.ClientAuthenticationReq.session_id)
}
inline std::string* ClientAuthenticationReq::_internal_mutable_session_id() {
  
  return session_id_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* ClientAuthenticationReq::release_session_id() {
  // @@protoc_insertion_point(field_release:im.ClientAuthenticationReq.session_id)
  return session_id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void ClientAuthenticationReq::set_allocated_session_id(std::string* session_id) {
  if (session_id != nullptr) {
    
  } else {
    
  }
  session_id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), session_id,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:im.ClientAuthenticationReq.session_id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace im

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_gateway_2eproto
