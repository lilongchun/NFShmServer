// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Armor.proto

#ifndef PROTOBUF_Armor_2eproto__INCLUDED
#define PROTOBUF_Armor_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
#include "Com.pb.h"
#include "ComDefine.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Armor_2eproto();
void protobuf_AssignDesc_Armor_2eproto();
void protobuf_ShutdownFile_Armor_2eproto();

class NotifyArmorRsp;
class ArmorActiveReq;
class ArmorActiveRsp;

// ===================================================================

class NotifyArmorRsp : public ::google::protobuf::Message {
 public:
  NotifyArmorRsp();
  virtual ~NotifyArmorRsp();

  NotifyArmorRsp(const NotifyArmorRsp& from);

  inline NotifyArmorRsp& operator=(const NotifyArmorRsp& from) {
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
  static const NotifyArmorRsp& default_instance();

  void Swap(NotifyArmorRsp* other);

  // implements Message ----------------------------------------------

  NotifyArmorRsp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NotifyArmorRsp& from);
  void MergeFrom(const NotifyArmorRsp& from);
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

  // optional int32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // repeated .proto_ff.ArmorInfo infos = 2;
  inline int infos_size() const;
  inline void clear_infos();
  static const int kInfosFieldNumber = 2;
  inline const ::proto_ff::ArmorInfo& infos(int index) const;
  inline ::proto_ff::ArmorInfo* mutable_infos(int index);
  inline ::proto_ff::ArmorInfo* add_infos();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::ArmorInfo >&
      infos() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::ArmorInfo >*
      mutable_infos();

  // @@protoc_insertion_point(class_scope:proto_ff.NotifyArmorRsp)
 private:
  inline void set_has_type();
  inline void clear_has_type();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::ArmorInfo > infos_;
  ::google::protobuf::int32 type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_Armor_2eproto();
  friend void protobuf_AssignDesc_Armor_2eproto();
  friend void protobuf_ShutdownFile_Armor_2eproto();

  void InitAsDefaultInstance();
  static NotifyArmorRsp* default_instance_;
};
// -------------------------------------------------------------------

class ArmorActiveReq : public ::google::protobuf::Message {
 public:
  ArmorActiveReq();
  virtual ~ArmorActiveReq();

  ArmorActiveReq(const ArmorActiveReq& from);

  inline ArmorActiveReq& operator=(const ArmorActiveReq& from) {
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
  static const ArmorActiveReq& default_instance();

  void Swap(ArmorActiveReq* other);

  // implements Message ----------------------------------------------

  ArmorActiveReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ArmorActiveReq& from);
  void MergeFrom(const ArmorActiveReq& from);
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

  // optional int32 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int32 id() const;
  inline void set_id(::google::protobuf::int32 value);

  // optional int32 index = 2;
  inline bool has_index() const;
  inline void clear_index();
  static const int kIndexFieldNumber = 2;
  inline ::google::protobuf::int32 index() const;
  inline void set_index(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.ArmorActiveReq)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_index();
  inline void clear_has_index();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 index_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_Armor_2eproto();
  friend void protobuf_AssignDesc_Armor_2eproto();
  friend void protobuf_ShutdownFile_Armor_2eproto();

  void InitAsDefaultInstance();
  static ArmorActiveReq* default_instance_;
};
// -------------------------------------------------------------------

class ArmorActiveRsp : public ::google::protobuf::Message {
 public:
  ArmorActiveRsp();
  virtual ~ArmorActiveRsp();

  ArmorActiveRsp(const ArmorActiveRsp& from);

  inline ArmorActiveRsp& operator=(const ArmorActiveRsp& from) {
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
  static const ArmorActiveRsp& default_instance();

  void Swap(ArmorActiveRsp* other);

  // implements Message ----------------------------------------------

  ArmorActiveRsp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ArmorActiveRsp& from);
  void MergeFrom(const ArmorActiveRsp& from);
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

  // optional int32 ret = 1;
  inline bool has_ret() const;
  inline void clear_ret();
  static const int kRetFieldNumber = 1;
  inline ::google::protobuf::int32 ret() const;
  inline void set_ret(::google::protobuf::int32 value);

  // optional int32 id = 2;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 2;
  inline ::google::protobuf::int32 id() const;
  inline void set_id(::google::protobuf::int32 value);

  // optional int32 index = 3;
  inline bool has_index() const;
  inline void clear_index();
  static const int kIndexFieldNumber = 3;
  inline ::google::protobuf::int32 index() const;
  inline void set_index(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.ArmorActiveRsp)
 private:
  inline void set_has_ret();
  inline void clear_has_ret();
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_index();
  inline void clear_has_index();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 ret_;
  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 index_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_Armor_2eproto();
  friend void protobuf_AssignDesc_Armor_2eproto();
  friend void protobuf_ShutdownFile_Armor_2eproto();

  void InitAsDefaultInstance();
  static ArmorActiveRsp* default_instance_;
};
// ===================================================================


// ===================================================================

// NotifyArmorRsp

// optional int32 type = 1;
inline bool NotifyArmorRsp::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NotifyArmorRsp::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NotifyArmorRsp::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NotifyArmorRsp::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 NotifyArmorRsp::type() const {
  return type_;
}
inline void NotifyArmorRsp::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// repeated .proto_ff.ArmorInfo infos = 2;
inline int NotifyArmorRsp::infos_size() const {
  return infos_.size();
}
inline void NotifyArmorRsp::clear_infos() {
  infos_.Clear();
}
inline const ::proto_ff::ArmorInfo& NotifyArmorRsp::infos(int index) const {
  return infos_.Get(index);
}
inline ::proto_ff::ArmorInfo* NotifyArmorRsp::mutable_infos(int index) {
  return infos_.Mutable(index);
}
inline ::proto_ff::ArmorInfo* NotifyArmorRsp::add_infos() {
  return infos_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::ArmorInfo >&
NotifyArmorRsp::infos() const {
  return infos_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::ArmorInfo >*
NotifyArmorRsp::mutable_infos() {
  return &infos_;
}

// -------------------------------------------------------------------

// ArmorActiveReq

// optional int32 id = 1;
inline bool ArmorActiveReq::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ArmorActiveReq::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ArmorActiveReq::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ArmorActiveReq::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 ArmorActiveReq::id() const {
  return id_;
}
inline void ArmorActiveReq::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
}

// optional int32 index = 2;
inline bool ArmorActiveReq::has_index() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ArmorActiveReq::set_has_index() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ArmorActiveReq::clear_has_index() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ArmorActiveReq::clear_index() {
  index_ = 0;
  clear_has_index();
}
inline ::google::protobuf::int32 ArmorActiveReq::index() const {
  return index_;
}
inline void ArmorActiveReq::set_index(::google::protobuf::int32 value) {
  set_has_index();
  index_ = value;
}

// -------------------------------------------------------------------

// ArmorActiveRsp

// optional int32 ret = 1;
inline bool ArmorActiveRsp::has_ret() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ArmorActiveRsp::set_has_ret() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ArmorActiveRsp::clear_has_ret() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ArmorActiveRsp::clear_ret() {
  ret_ = 0;
  clear_has_ret();
}
inline ::google::protobuf::int32 ArmorActiveRsp::ret() const {
  return ret_;
}
inline void ArmorActiveRsp::set_ret(::google::protobuf::int32 value) {
  set_has_ret();
  ret_ = value;
}

// optional int32 id = 2;
inline bool ArmorActiveRsp::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ArmorActiveRsp::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ArmorActiveRsp::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ArmorActiveRsp::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 ArmorActiveRsp::id() const {
  return id_;
}
inline void ArmorActiveRsp::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
}

// optional int32 index = 3;
inline bool ArmorActiveRsp::has_index() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ArmorActiveRsp::set_has_index() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ArmorActiveRsp::clear_has_index() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ArmorActiveRsp::clear_index() {
  index_ = 0;
  clear_has_index();
}
inline ::google::protobuf::int32 ArmorActiveRsp::index() const {
  return index_;
}
inline void ArmorActiveRsp::set_index(::google::protobuf::int32 value) {
  set_has_index();
  index_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Armor_2eproto__INCLUDED
