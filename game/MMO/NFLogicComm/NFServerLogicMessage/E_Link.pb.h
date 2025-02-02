// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Link.proto

#ifndef PROTOBUF_E_5fLink_2eproto__INCLUDED
#define PROTOBUF_E_5fLink_2eproto__INCLUDED

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
#include "yd_fieldoptions.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_E_5fLink_2eproto();
void protobuf_AssignDesc_E_5fLink_2eproto();
void protobuf_ShutdownFile_E_5fLink_2eproto();

class E_LinkLink;
class Sheet_LinkLink;
class E_LinkImagelink;
class Sheet_LinkImagelink;

// ===================================================================

class E_LinkLink : public ::google::protobuf::Message {
 public:
  E_LinkLink();
  virtual ~E_LinkLink();

  E_LinkLink(const E_LinkLink& from);

  inline E_LinkLink& operator=(const E_LinkLink& from) {
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
  static const E_LinkLink& default_instance();

  void Swap(E_LinkLink* other);

  // implements Message ----------------------------------------------

  E_LinkLink* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_LinkLink& from);
  void MergeFrom(const E_LinkLink& from);
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

  // optional int64 m_id = 1;
  inline bool has_m_id() const;
  inline void clear_m_id();
  static const int kMIdFieldNumber = 1;
  inline ::google::protobuf::int64 m_id() const;
  inline void set_m_id(::google::protobuf::int64 value);

  // optional string m_icon = 2;
  inline bool has_m_icon() const;
  inline void clear_m_icon();
  static const int kMIconFieldNumber = 2;
  inline const ::std::string& m_icon() const;
  inline void set_m_icon(const ::std::string& value);
  inline void set_m_icon(const char* value);
  inline void set_m_icon(const char* value, size_t size);
  inline ::std::string* mutable_m_icon();
  inline ::std::string* release_m_icon();
  inline void set_allocated_m_icon(::std::string* m_icon);

  // optional string m_dbArgs = 3;
  inline bool has_m_dbargs() const;
  inline void clear_m_dbargs();
  static const int kMDbArgsFieldNumber = 3;
  inline const ::std::string& m_dbargs() const;
  inline void set_m_dbargs(const ::std::string& value);
  inline void set_m_dbargs(const char* value);
  inline void set_m_dbargs(const char* value, size_t size);
  inline ::std::string* mutable_m_dbargs();
  inline ::std::string* release_m_dbargs();
  inline void set_allocated_m_dbargs(::std::string* m_dbargs);

  // optional string m_argsm = 4;
  inline bool has_m_argsm() const;
  inline void clear_m_argsm();
  static const int kMArgsmFieldNumber = 4;
  inline const ::std::string& m_argsm() const;
  inline void set_m_argsm(const ::std::string& value);
  inline void set_m_argsm(const char* value);
  inline void set_m_argsm(const char* value, size_t size);
  inline ::std::string* mutable_m_argsm();
  inline ::std::string* release_m_argsm();
  inline void set_allocated_m_argsm(::std::string* m_argsm);

  // optional int32 m_functionUnlock = 5;
  inline bool has_m_functionunlock() const;
  inline void clear_m_functionunlock();
  static const int kMFunctionUnlockFieldNumber = 5;
  inline ::google::protobuf::int32 m_functionunlock() const;
  inline void set_m_functionunlock(::google::protobuf::int32 value);

  // optional string m_linkNpc = 6;
  inline bool has_m_linknpc() const;
  inline void clear_m_linknpc();
  static const int kMLinkNpcFieldNumber = 6;
  inline const ::std::string& m_linknpc() const;
  inline void set_m_linknpc(const ::std::string& value);
  inline void set_m_linknpc(const char* value);
  inline void set_m_linknpc(const char* value, size_t size);
  inline ::std::string* mutable_m_linknpc();
  inline ::std::string* release_m_linknpc();
  inline void set_allocated_m_linknpc(::std::string* m_linknpc);

  // @@protoc_insertion_point(class_scope:proto_ff.E_LinkLink)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_icon();
  inline void clear_has_m_icon();
  inline void set_has_m_dbargs();
  inline void clear_has_m_dbargs();
  inline void set_has_m_argsm();
  inline void clear_has_m_argsm();
  inline void set_has_m_functionunlock();
  inline void clear_has_m_functionunlock();
  inline void set_has_m_linknpc();
  inline void clear_has_m_linknpc();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 m_id_;
  ::std::string* m_icon_;
  ::std::string* m_dbargs_;
  ::std::string* m_argsm_;
  ::std::string* m_linknpc_;
  ::google::protobuf::int32 m_functionunlock_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fLink_2eproto();
  friend void protobuf_AssignDesc_E_5fLink_2eproto();
  friend void protobuf_ShutdownFile_E_5fLink_2eproto();

  void InitAsDefaultInstance();
  static E_LinkLink* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_LinkLink : public ::google::protobuf::Message {
 public:
  Sheet_LinkLink();
  virtual ~Sheet_LinkLink();

  Sheet_LinkLink(const Sheet_LinkLink& from);

  inline Sheet_LinkLink& operator=(const Sheet_LinkLink& from) {
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
  static const Sheet_LinkLink& default_instance();

  void Swap(Sheet_LinkLink* other);

  // implements Message ----------------------------------------------

  Sheet_LinkLink* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_LinkLink& from);
  void MergeFrom(const Sheet_LinkLink& from);
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

  // repeated .proto_ff.E_LinkLink E_LinkLink_List = 1;
  inline int e_linklink_list_size() const;
  inline void clear_e_linklink_list();
  static const int kELinkLinkListFieldNumber = 1;
  inline const ::proto_ff::E_LinkLink& e_linklink_list(int index) const;
  inline ::proto_ff::E_LinkLink* mutable_e_linklink_list(int index);
  inline ::proto_ff::E_LinkLink* add_e_linklink_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkLink >&
      e_linklink_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkLink >*
      mutable_e_linklink_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_LinkLink)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkLink > e_linklink_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fLink_2eproto();
  friend void protobuf_AssignDesc_E_5fLink_2eproto();
  friend void protobuf_ShutdownFile_E_5fLink_2eproto();

  void InitAsDefaultInstance();
  static Sheet_LinkLink* default_instance_;
};
// -------------------------------------------------------------------

class E_LinkImagelink : public ::google::protobuf::Message {
 public:
  E_LinkImagelink();
  virtual ~E_LinkImagelink();

  E_LinkImagelink(const E_LinkImagelink& from);

  inline E_LinkImagelink& operator=(const E_LinkImagelink& from) {
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
  static const E_LinkImagelink& default_instance();

  void Swap(E_LinkImagelink* other);

  // implements Message ----------------------------------------------

  E_LinkImagelink* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_LinkImagelink& from);
  void MergeFrom(const E_LinkImagelink& from);
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

  // optional int32 m_id = 1;
  inline bool has_m_id() const;
  inline void clear_m_id();
  static const int kMIdFieldNumber = 1;
  inline ::google::protobuf::int32 m_id() const;
  inline void set_m_id(::google::protobuf::int32 value);

  // optional int32 m_closeType = 2;
  inline bool has_m_closetype() const;
  inline void clear_m_closetype();
  static const int kMCloseTypeFieldNumber = 2;
  inline ::google::protobuf::int32 m_closetype() const;
  inline void set_m_closetype(::google::protobuf::int32 value);

  // optional int32 m_closeArg = 3;
  inline bool has_m_closearg() const;
  inline void clear_m_closearg();
  static const int kMCloseArgFieldNumber = 3;
  inline ::google::protobuf::int32 m_closearg() const;
  inline void set_m_closearg(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_LinkImagelink)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_closetype();
  inline void clear_has_m_closetype();
  inline void set_has_m_closearg();
  inline void clear_has_m_closearg();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_id_;
  ::google::protobuf::int32 m_closetype_;
  ::google::protobuf::int32 m_closearg_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fLink_2eproto();
  friend void protobuf_AssignDesc_E_5fLink_2eproto();
  friend void protobuf_ShutdownFile_E_5fLink_2eproto();

  void InitAsDefaultInstance();
  static E_LinkImagelink* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_LinkImagelink : public ::google::protobuf::Message {
 public:
  Sheet_LinkImagelink();
  virtual ~Sheet_LinkImagelink();

  Sheet_LinkImagelink(const Sheet_LinkImagelink& from);

  inline Sheet_LinkImagelink& operator=(const Sheet_LinkImagelink& from) {
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
  static const Sheet_LinkImagelink& default_instance();

  void Swap(Sheet_LinkImagelink* other);

  // implements Message ----------------------------------------------

  Sheet_LinkImagelink* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_LinkImagelink& from);
  void MergeFrom(const Sheet_LinkImagelink& from);
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

  // repeated .proto_ff.E_LinkImagelink E_LinkImagelink_List = 1;
  inline int e_linkimagelink_list_size() const;
  inline void clear_e_linkimagelink_list();
  static const int kELinkImagelinkListFieldNumber = 1;
  inline const ::proto_ff::E_LinkImagelink& e_linkimagelink_list(int index) const;
  inline ::proto_ff::E_LinkImagelink* mutable_e_linkimagelink_list(int index);
  inline ::proto_ff::E_LinkImagelink* add_e_linkimagelink_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkImagelink >&
      e_linkimagelink_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkImagelink >*
      mutable_e_linkimagelink_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_LinkImagelink)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkImagelink > e_linkimagelink_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fLink_2eproto();
  friend void protobuf_AssignDesc_E_5fLink_2eproto();
  friend void protobuf_ShutdownFile_E_5fLink_2eproto();

  void InitAsDefaultInstance();
  static Sheet_LinkImagelink* default_instance_;
};
// ===================================================================


// ===================================================================

// E_LinkLink

// optional int64 m_id = 1;
inline bool E_LinkLink::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_LinkLink::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_LinkLink::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_LinkLink::clear_m_id() {
  m_id_ = GOOGLE_LONGLONG(0);
  clear_has_m_id();
}
inline ::google::protobuf::int64 E_LinkLink::m_id() const {
  return m_id_;
}
inline void E_LinkLink::set_m_id(::google::protobuf::int64 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional string m_icon = 2;
inline bool E_LinkLink::has_m_icon() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_LinkLink::set_has_m_icon() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_LinkLink::clear_has_m_icon() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_LinkLink::clear_m_icon() {
  if (m_icon_ != &::google::protobuf::internal::kEmptyString) {
    m_icon_->clear();
  }
  clear_has_m_icon();
}
inline const ::std::string& E_LinkLink::m_icon() const {
  return *m_icon_;
}
inline void E_LinkLink::set_m_icon(const ::std::string& value) {
  set_has_m_icon();
  if (m_icon_ == &::google::protobuf::internal::kEmptyString) {
    m_icon_ = new ::std::string;
  }
  m_icon_->assign(value);
}
inline void E_LinkLink::set_m_icon(const char* value) {
  set_has_m_icon();
  if (m_icon_ == &::google::protobuf::internal::kEmptyString) {
    m_icon_ = new ::std::string;
  }
  m_icon_->assign(value);
}
inline void E_LinkLink::set_m_icon(const char* value, size_t size) {
  set_has_m_icon();
  if (m_icon_ == &::google::protobuf::internal::kEmptyString) {
    m_icon_ = new ::std::string;
  }
  m_icon_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_LinkLink::mutable_m_icon() {
  set_has_m_icon();
  if (m_icon_ == &::google::protobuf::internal::kEmptyString) {
    m_icon_ = new ::std::string;
  }
  return m_icon_;
}
inline ::std::string* E_LinkLink::release_m_icon() {
  clear_has_m_icon();
  if (m_icon_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_icon_;
    m_icon_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_LinkLink::set_allocated_m_icon(::std::string* m_icon) {
  if (m_icon_ != &::google::protobuf::internal::kEmptyString) {
    delete m_icon_;
  }
  if (m_icon) {
    set_has_m_icon();
    m_icon_ = m_icon;
  } else {
    clear_has_m_icon();
    m_icon_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string m_dbArgs = 3;
inline bool E_LinkLink::has_m_dbargs() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_LinkLink::set_has_m_dbargs() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_LinkLink::clear_has_m_dbargs() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_LinkLink::clear_m_dbargs() {
  if (m_dbargs_ != &::google::protobuf::internal::kEmptyString) {
    m_dbargs_->clear();
  }
  clear_has_m_dbargs();
}
inline const ::std::string& E_LinkLink::m_dbargs() const {
  return *m_dbargs_;
}
inline void E_LinkLink::set_m_dbargs(const ::std::string& value) {
  set_has_m_dbargs();
  if (m_dbargs_ == &::google::protobuf::internal::kEmptyString) {
    m_dbargs_ = new ::std::string;
  }
  m_dbargs_->assign(value);
}
inline void E_LinkLink::set_m_dbargs(const char* value) {
  set_has_m_dbargs();
  if (m_dbargs_ == &::google::protobuf::internal::kEmptyString) {
    m_dbargs_ = new ::std::string;
  }
  m_dbargs_->assign(value);
}
inline void E_LinkLink::set_m_dbargs(const char* value, size_t size) {
  set_has_m_dbargs();
  if (m_dbargs_ == &::google::protobuf::internal::kEmptyString) {
    m_dbargs_ = new ::std::string;
  }
  m_dbargs_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_LinkLink::mutable_m_dbargs() {
  set_has_m_dbargs();
  if (m_dbargs_ == &::google::protobuf::internal::kEmptyString) {
    m_dbargs_ = new ::std::string;
  }
  return m_dbargs_;
}
inline ::std::string* E_LinkLink::release_m_dbargs() {
  clear_has_m_dbargs();
  if (m_dbargs_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_dbargs_;
    m_dbargs_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_LinkLink::set_allocated_m_dbargs(::std::string* m_dbargs) {
  if (m_dbargs_ != &::google::protobuf::internal::kEmptyString) {
    delete m_dbargs_;
  }
  if (m_dbargs) {
    set_has_m_dbargs();
    m_dbargs_ = m_dbargs;
  } else {
    clear_has_m_dbargs();
    m_dbargs_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string m_argsm = 4;
inline bool E_LinkLink::has_m_argsm() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void E_LinkLink::set_has_m_argsm() {
  _has_bits_[0] |= 0x00000008u;
}
inline void E_LinkLink::clear_has_m_argsm() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void E_LinkLink::clear_m_argsm() {
  if (m_argsm_ != &::google::protobuf::internal::kEmptyString) {
    m_argsm_->clear();
  }
  clear_has_m_argsm();
}
inline const ::std::string& E_LinkLink::m_argsm() const {
  return *m_argsm_;
}
inline void E_LinkLink::set_m_argsm(const ::std::string& value) {
  set_has_m_argsm();
  if (m_argsm_ == &::google::protobuf::internal::kEmptyString) {
    m_argsm_ = new ::std::string;
  }
  m_argsm_->assign(value);
}
inline void E_LinkLink::set_m_argsm(const char* value) {
  set_has_m_argsm();
  if (m_argsm_ == &::google::protobuf::internal::kEmptyString) {
    m_argsm_ = new ::std::string;
  }
  m_argsm_->assign(value);
}
inline void E_LinkLink::set_m_argsm(const char* value, size_t size) {
  set_has_m_argsm();
  if (m_argsm_ == &::google::protobuf::internal::kEmptyString) {
    m_argsm_ = new ::std::string;
  }
  m_argsm_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_LinkLink::mutable_m_argsm() {
  set_has_m_argsm();
  if (m_argsm_ == &::google::protobuf::internal::kEmptyString) {
    m_argsm_ = new ::std::string;
  }
  return m_argsm_;
}
inline ::std::string* E_LinkLink::release_m_argsm() {
  clear_has_m_argsm();
  if (m_argsm_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_argsm_;
    m_argsm_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_LinkLink::set_allocated_m_argsm(::std::string* m_argsm) {
  if (m_argsm_ != &::google::protobuf::internal::kEmptyString) {
    delete m_argsm_;
  }
  if (m_argsm) {
    set_has_m_argsm();
    m_argsm_ = m_argsm;
  } else {
    clear_has_m_argsm();
    m_argsm_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 m_functionUnlock = 5;
inline bool E_LinkLink::has_m_functionunlock() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void E_LinkLink::set_has_m_functionunlock() {
  _has_bits_[0] |= 0x00000010u;
}
inline void E_LinkLink::clear_has_m_functionunlock() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void E_LinkLink::clear_m_functionunlock() {
  m_functionunlock_ = 0;
  clear_has_m_functionunlock();
}
inline ::google::protobuf::int32 E_LinkLink::m_functionunlock() const {
  return m_functionunlock_;
}
inline void E_LinkLink::set_m_functionunlock(::google::protobuf::int32 value) {
  set_has_m_functionunlock();
  m_functionunlock_ = value;
}

// optional string m_linkNpc = 6;
inline bool E_LinkLink::has_m_linknpc() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void E_LinkLink::set_has_m_linknpc() {
  _has_bits_[0] |= 0x00000020u;
}
inline void E_LinkLink::clear_has_m_linknpc() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void E_LinkLink::clear_m_linknpc() {
  if (m_linknpc_ != &::google::protobuf::internal::kEmptyString) {
    m_linknpc_->clear();
  }
  clear_has_m_linknpc();
}
inline const ::std::string& E_LinkLink::m_linknpc() const {
  return *m_linknpc_;
}
inline void E_LinkLink::set_m_linknpc(const ::std::string& value) {
  set_has_m_linknpc();
  if (m_linknpc_ == &::google::protobuf::internal::kEmptyString) {
    m_linknpc_ = new ::std::string;
  }
  m_linknpc_->assign(value);
}
inline void E_LinkLink::set_m_linknpc(const char* value) {
  set_has_m_linknpc();
  if (m_linknpc_ == &::google::protobuf::internal::kEmptyString) {
    m_linknpc_ = new ::std::string;
  }
  m_linknpc_->assign(value);
}
inline void E_LinkLink::set_m_linknpc(const char* value, size_t size) {
  set_has_m_linknpc();
  if (m_linknpc_ == &::google::protobuf::internal::kEmptyString) {
    m_linknpc_ = new ::std::string;
  }
  m_linknpc_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_LinkLink::mutable_m_linknpc() {
  set_has_m_linknpc();
  if (m_linknpc_ == &::google::protobuf::internal::kEmptyString) {
    m_linknpc_ = new ::std::string;
  }
  return m_linknpc_;
}
inline ::std::string* E_LinkLink::release_m_linknpc() {
  clear_has_m_linknpc();
  if (m_linknpc_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_linknpc_;
    m_linknpc_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_LinkLink::set_allocated_m_linknpc(::std::string* m_linknpc) {
  if (m_linknpc_ != &::google::protobuf::internal::kEmptyString) {
    delete m_linknpc_;
  }
  if (m_linknpc) {
    set_has_m_linknpc();
    m_linknpc_ = m_linknpc;
  } else {
    clear_has_m_linknpc();
    m_linknpc_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// Sheet_LinkLink

// repeated .proto_ff.E_LinkLink E_LinkLink_List = 1;
inline int Sheet_LinkLink::e_linklink_list_size() const {
  return e_linklink_list_.size();
}
inline void Sheet_LinkLink::clear_e_linklink_list() {
  e_linklink_list_.Clear();
}
inline const ::proto_ff::E_LinkLink& Sheet_LinkLink::e_linklink_list(int index) const {
  return e_linklink_list_.Get(index);
}
inline ::proto_ff::E_LinkLink* Sheet_LinkLink::mutable_e_linklink_list(int index) {
  return e_linklink_list_.Mutable(index);
}
inline ::proto_ff::E_LinkLink* Sheet_LinkLink::add_e_linklink_list() {
  return e_linklink_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkLink >&
Sheet_LinkLink::e_linklink_list() const {
  return e_linklink_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkLink >*
Sheet_LinkLink::mutable_e_linklink_list() {
  return &e_linklink_list_;
}

// -------------------------------------------------------------------

// E_LinkImagelink

// optional int32 m_id = 1;
inline bool E_LinkImagelink::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_LinkImagelink::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_LinkImagelink::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_LinkImagelink::clear_m_id() {
  m_id_ = 0;
  clear_has_m_id();
}
inline ::google::protobuf::int32 E_LinkImagelink::m_id() const {
  return m_id_;
}
inline void E_LinkImagelink::set_m_id(::google::protobuf::int32 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional int32 m_closeType = 2;
inline bool E_LinkImagelink::has_m_closetype() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_LinkImagelink::set_has_m_closetype() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_LinkImagelink::clear_has_m_closetype() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_LinkImagelink::clear_m_closetype() {
  m_closetype_ = 0;
  clear_has_m_closetype();
}
inline ::google::protobuf::int32 E_LinkImagelink::m_closetype() const {
  return m_closetype_;
}
inline void E_LinkImagelink::set_m_closetype(::google::protobuf::int32 value) {
  set_has_m_closetype();
  m_closetype_ = value;
}

// optional int32 m_closeArg = 3;
inline bool E_LinkImagelink::has_m_closearg() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_LinkImagelink::set_has_m_closearg() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_LinkImagelink::clear_has_m_closearg() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_LinkImagelink::clear_m_closearg() {
  m_closearg_ = 0;
  clear_has_m_closearg();
}
inline ::google::protobuf::int32 E_LinkImagelink::m_closearg() const {
  return m_closearg_;
}
inline void E_LinkImagelink::set_m_closearg(::google::protobuf::int32 value) {
  set_has_m_closearg();
  m_closearg_ = value;
}

// -------------------------------------------------------------------

// Sheet_LinkImagelink

// repeated .proto_ff.E_LinkImagelink E_LinkImagelink_List = 1;
inline int Sheet_LinkImagelink::e_linkimagelink_list_size() const {
  return e_linkimagelink_list_.size();
}
inline void Sheet_LinkImagelink::clear_e_linkimagelink_list() {
  e_linkimagelink_list_.Clear();
}
inline const ::proto_ff::E_LinkImagelink& Sheet_LinkImagelink::e_linkimagelink_list(int index) const {
  return e_linkimagelink_list_.Get(index);
}
inline ::proto_ff::E_LinkImagelink* Sheet_LinkImagelink::mutable_e_linkimagelink_list(int index) {
  return e_linkimagelink_list_.Mutable(index);
}
inline ::proto_ff::E_LinkImagelink* Sheet_LinkImagelink::add_e_linkimagelink_list() {
  return e_linkimagelink_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkImagelink >&
Sheet_LinkImagelink::e_linkimagelink_list() const {
  return e_linkimagelink_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_LinkImagelink >*
Sheet_LinkImagelink::mutable_e_linkimagelink_list() {
  return &e_linkimagelink_list_;
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

#endif  // PROTOBUF_E_5fLink_2eproto__INCLUDED
