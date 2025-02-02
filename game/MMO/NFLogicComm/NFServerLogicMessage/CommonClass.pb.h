// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: CommonClass.proto

#ifndef PROTOBUF_CommonClass_2eproto__INCLUDED
#define PROTOBUF_CommonClass_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "yd_fieldoptions.pb.h"
#include "Com.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_CommonClass_2eproto();
void protobuf_AssignDesc_CommonClass_2eproto();
void protobuf_ShutdownFile_CommonClass_2eproto();

class ItemBase;
class EquipBase;

enum enPlayerStatus {
  PLAYER_STATUS_NONE = 0,
  PLAYER_STATUS_ONLINE = 1,
  PLAYER_STATUS_OFFLINE = 2,
  PLAYER_STATUS_LOGOUT = 3,
  PLAYER_STATUS_DEAD = 4
};
bool enPlayerStatus_IsValid(int value);
const enPlayerStatus enPlayerStatus_MIN = PLAYER_STATUS_NONE;
const enPlayerStatus enPlayerStatus_MAX = PLAYER_STATUS_DEAD;
const int enPlayerStatus_ARRAYSIZE = enPlayerStatus_MAX + 1;

const ::google::protobuf::EnumDescriptor* enPlayerStatus_descriptor();
inline const ::std::string& enPlayerStatus_Name(enPlayerStatus value) {
  return ::google::protobuf::internal::NameOfEnum(
    enPlayerStatus_descriptor(), value);
}
inline bool enPlayerStatus_Parse(
    const ::std::string& name, enPlayerStatus* value) {
  return ::google::protobuf::internal::ParseNamedEnum<enPlayerStatus>(
    enPlayerStatus_descriptor(), name, value);
}
// ===================================================================

class ItemBase : public ::google::protobuf::Message {
 public:
  ItemBase();
  virtual ~ItemBase();

  ItemBase(const ItemBase& from);

  inline ItemBase& operator=(const ItemBase& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ItemBase& default_instance();

  void Swap(ItemBase* other);

  // implements Message ----------------------------------------------

  ItemBase* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ItemBase& from);
  void MergeFrom(const ItemBase& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 index = 1;
  inline bool has_index() const;
  inline void clear_index();
  static const int kIndexFieldNumber = 1;
  inline ::google::protobuf::uint32 index() const;
  inline void set_index(::google::protobuf::uint32 value);

  // optional uint32 item_id = 2;
  inline bool has_item_id() const;
  inline void clear_item_id();
  static const int kItemIdFieldNumber = 2;
  inline ::google::protobuf::uint32 item_id() const;
  inline void set_item_id(::google::protobuf::uint32 value);

  // optional uint64 item_num = 3;
  inline bool has_item_num() const;
  inline void clear_item_num();
  static const int kItemNumFieldNumber = 3;
  inline ::google::protobuf::uint64 item_num() const;
  inline void set_item_num(::google::protobuf::uint64 value);

  // optional bool bind = 4;
  inline bool has_bind() const;
  inline void clear_bind();
  static const int kBindFieldNumber = 4;
  inline bool bind() const;
  inline void set_bind(bool value);

  // optional uint32 level = 6;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 6;
  inline ::google::protobuf::uint32 level() const;
  inline void set_level(::google::protobuf::uint32 value);

  // optional uint64 expireTime = 7;
  inline bool has_expiretime() const;
  inline void clear_expiretime();
  static const int kExpireTimeFieldNumber = 7;
  inline ::google::protobuf::uint64 expiretime() const;
  inline void set_expiretime(::google::protobuf::uint64 value);

  // optional uint32 type = 8;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 8;
  inline ::google::protobuf::uint32 type() const;
  inline void set_type(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.ItemBase)
 private:
  inline void set_has_index();
  inline void clear_has_index();
  inline void set_has_item_id();
  inline void clear_has_item_id();
  inline void set_has_item_num();
  inline void clear_has_item_num();
  inline void set_has_bind();
  inline void clear_has_bind();
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_expiretime();
  inline void clear_has_expiretime();
  inline void set_has_type();
  inline void clear_has_type();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 index_;
  ::google::protobuf::uint32 item_id_;
  ::google::protobuf::uint64 item_num_;
  bool bind_;
  ::google::protobuf::uint32 level_;
  ::google::protobuf::uint64 expiretime_;
  ::google::protobuf::uint32 type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_CommonClass_2eproto();
  friend void protobuf_AssignDesc_CommonClass_2eproto();
  friend void protobuf_ShutdownFile_CommonClass_2eproto();

  void InitAsDefaultInstance();
  static ItemBase* default_instance_;
};
// -------------------------------------------------------------------

class EquipBase : public ::google::protobuf::Message {
 public:
  EquipBase();
  virtual ~EquipBase();

  EquipBase(const EquipBase& from);

  inline EquipBase& operator=(const EquipBase& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const EquipBase& default_instance();

  void Swap(EquipBase* other);

  // implements Message ----------------------------------------------

  EquipBase* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const EquipBase& from);
  void MergeFrom(const EquipBase& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 base_attr_percent = 1;
  inline bool has_base_attr_percent() const;
  inline void clear_base_attr_percent();
  static const int kBaseAttrPercentFieldNumber = 1;
  inline ::google::protobuf::uint32 base_attr_percent() const;
  inline void set_base_attr_percent(::google::protobuf::uint32 value);

  // optional uint32 star_attr_percent = 2;
  inline bool has_star_attr_percent() const;
  inline void clear_star_attr_percent();
  static const int kStarAttrPercentFieldNumber = 2;
  inline ::google::protobuf::uint32 star_attr_percent() const;
  inline void set_star_attr_percent(::google::protobuf::uint32 value);

  // optional uint32 god_attr_percent = 3;
  inline bool has_god_attr_percent() const;
  inline void clear_god_attr_percent();
  static const int kGodAttrPercentFieldNumber = 3;
  inline ::google::protobuf::uint32 god_attr_percent() const;
  inline void set_god_attr_percent(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.EquipBase)
 private:
  inline void set_has_base_attr_percent();
  inline void clear_has_base_attr_percent();
  inline void set_has_star_attr_percent();
  inline void clear_has_star_attr_percent();
  inline void set_has_god_attr_percent();
  inline void clear_has_god_attr_percent();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 base_attr_percent_;
  ::google::protobuf::uint32 star_attr_percent_;
  ::google::protobuf::uint32 god_attr_percent_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_CommonClass_2eproto();
  friend void protobuf_AssignDesc_CommonClass_2eproto();
  friend void protobuf_ShutdownFile_CommonClass_2eproto();

  void InitAsDefaultInstance();
  static EquipBase* default_instance_;
};
// ===================================================================


// ===================================================================

// ItemBase

// optional uint32 index = 1;
inline bool ItemBase::has_index() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ItemBase::set_has_index() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ItemBase::clear_has_index() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ItemBase::clear_index() {
  index_ = 0u;
  clear_has_index();
}
inline ::google::protobuf::uint32 ItemBase::index() const {
  return index_;
}
inline void ItemBase::set_index(::google::protobuf::uint32 value) {
  set_has_index();
  index_ = value;
}

// optional uint32 item_id = 2;
inline bool ItemBase::has_item_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ItemBase::set_has_item_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ItemBase::clear_has_item_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ItemBase::clear_item_id() {
  item_id_ = 0u;
  clear_has_item_id();
}
inline ::google::protobuf::uint32 ItemBase::item_id() const {
  return item_id_;
}
inline void ItemBase::set_item_id(::google::protobuf::uint32 value) {
  set_has_item_id();
  item_id_ = value;
}

// optional uint64 item_num = 3;
inline bool ItemBase::has_item_num() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ItemBase::set_has_item_num() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ItemBase::clear_has_item_num() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ItemBase::clear_item_num() {
  item_num_ = GOOGLE_ULONGLONG(0);
  clear_has_item_num();
}
inline ::google::protobuf::uint64 ItemBase::item_num() const {
  return item_num_;
}
inline void ItemBase::set_item_num(::google::protobuf::uint64 value) {
  set_has_item_num();
  item_num_ = value;
}

// optional bool bind = 4;
inline bool ItemBase::has_bind() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ItemBase::set_has_bind() {
  _has_bits_[0] |= 0x00000008u;
}
inline void ItemBase::clear_has_bind() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void ItemBase::clear_bind() {
  bind_ = false;
  clear_has_bind();
}
inline bool ItemBase::bind() const {
  return bind_;
}
inline void ItemBase::set_bind(bool value) {
  set_has_bind();
  bind_ = value;
}

// optional uint32 level = 6;
inline bool ItemBase::has_level() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void ItemBase::set_has_level() {
  _has_bits_[0] |= 0x00000010u;
}
inline void ItemBase::clear_has_level() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void ItemBase::clear_level() {
  level_ = 0u;
  clear_has_level();
}
inline ::google::protobuf::uint32 ItemBase::level() const {
  return level_;
}
inline void ItemBase::set_level(::google::protobuf::uint32 value) {
  set_has_level();
  level_ = value;
}

// optional uint64 expireTime = 7;
inline bool ItemBase::has_expiretime() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void ItemBase::set_has_expiretime() {
  _has_bits_[0] |= 0x00000020u;
}
inline void ItemBase::clear_has_expiretime() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void ItemBase::clear_expiretime() {
  expiretime_ = GOOGLE_ULONGLONG(0);
  clear_has_expiretime();
}
inline ::google::protobuf::uint64 ItemBase::expiretime() const {
  return expiretime_;
}
inline void ItemBase::set_expiretime(::google::protobuf::uint64 value) {
  set_has_expiretime();
  expiretime_ = value;
}

// optional uint32 type = 8;
inline bool ItemBase::has_type() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void ItemBase::set_has_type() {
  _has_bits_[0] |= 0x00000040u;
}
inline void ItemBase::clear_has_type() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void ItemBase::clear_type() {
  type_ = 0u;
  clear_has_type();
}
inline ::google::protobuf::uint32 ItemBase::type() const {
  return type_;
}
inline void ItemBase::set_type(::google::protobuf::uint32 value) {
  set_has_type();
  type_ = value;
}

// -------------------------------------------------------------------

// EquipBase

// optional uint32 base_attr_percent = 1;
inline bool EquipBase::has_base_attr_percent() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void EquipBase::set_has_base_attr_percent() {
  _has_bits_[0] |= 0x00000001u;
}
inline void EquipBase::clear_has_base_attr_percent() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void EquipBase::clear_base_attr_percent() {
  base_attr_percent_ = 0u;
  clear_has_base_attr_percent();
}
inline ::google::protobuf::uint32 EquipBase::base_attr_percent() const {
  return base_attr_percent_;
}
inline void EquipBase::set_base_attr_percent(::google::protobuf::uint32 value) {
  set_has_base_attr_percent();
  base_attr_percent_ = value;
}

// optional uint32 star_attr_percent = 2;
inline bool EquipBase::has_star_attr_percent() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void EquipBase::set_has_star_attr_percent() {
  _has_bits_[0] |= 0x00000002u;
}
inline void EquipBase::clear_has_star_attr_percent() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void EquipBase::clear_star_attr_percent() {
  star_attr_percent_ = 0u;
  clear_has_star_attr_percent();
}
inline ::google::protobuf::uint32 EquipBase::star_attr_percent() const {
  return star_attr_percent_;
}
inline void EquipBase::set_star_attr_percent(::google::protobuf::uint32 value) {
  set_has_star_attr_percent();
  star_attr_percent_ = value;
}

// optional uint32 god_attr_percent = 3;
inline bool EquipBase::has_god_attr_percent() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void EquipBase::set_has_god_attr_percent() {
  _has_bits_[0] |= 0x00000004u;
}
inline void EquipBase::clear_has_god_attr_percent() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void EquipBase::clear_god_attr_percent() {
  god_attr_percent_ = 0u;
  clear_has_god_attr_percent();
}
inline ::google::protobuf::uint32 EquipBase::god_attr_percent() const {
  return god_attr_percent_;
}
inline void EquipBase::set_god_attr_percent(::google::protobuf::uint32 value) {
  set_has_god_attr_percent();
  god_attr_percent_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::proto_ff::enPlayerStatus>() {
  return ::proto_ff::enPlayerStatus_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_CommonClass_2eproto__INCLUDED
