// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Assist.proto

#ifndef PROTOBUF_E_5fAssist_2eproto__INCLUDED
#define PROTOBUF_E_5fAssist_2eproto__INCLUDED

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
void  protobuf_AddDesc_E_5fAssist_2eproto();
void protobuf_AssignDesc_E_5fAssist_2eproto();
void protobuf_ShutdownFile_E_5fAssist_2eproto();

class E_AssistBox;
class Sheet_AssistBox;
class E_AssistThank;
class Sheet_AssistThank;
class E_AssistConst;
class Sheet_AssistConst;

// ===================================================================

class E_AssistBox : public ::google::protobuf::Message {
 public:
  E_AssistBox();
  virtual ~E_AssistBox();

  E_AssistBox(const E_AssistBox& from);

  inline E_AssistBox& operator=(const E_AssistBox& from) {
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
  static const E_AssistBox& default_instance();

  void Swap(E_AssistBox* other);

  // implements Message ----------------------------------------------

  E_AssistBox* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_AssistBox& from);
  void MergeFrom(const E_AssistBox& from);
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

  // optional int32 m_times = 2;
  inline bool has_m_times() const;
  inline void clear_m_times();
  static const int kMTimesFieldNumber = 2;
  inline ::google::protobuf::int32 m_times() const;
  inline void set_m_times(::google::protobuf::int32 value);

  // optional int32 m_itemid = 3;
  inline bool has_m_itemid() const;
  inline void clear_m_itemid();
  static const int kMItemidFieldNumber = 3;
  inline ::google::protobuf::int32 m_itemid() const;
  inline void set_m_itemid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_AssistBox)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_times();
  inline void clear_has_m_times();
  inline void set_has_m_itemid();
  inline void clear_has_m_itemid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_id_;
  ::google::protobuf::int32 m_times_;
  ::google::protobuf::int32 m_itemid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fAssist_2eproto();
  friend void protobuf_AssignDesc_E_5fAssist_2eproto();
  friend void protobuf_ShutdownFile_E_5fAssist_2eproto();

  void InitAsDefaultInstance();
  static E_AssistBox* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_AssistBox : public ::google::protobuf::Message {
 public:
  Sheet_AssistBox();
  virtual ~Sheet_AssistBox();

  Sheet_AssistBox(const Sheet_AssistBox& from);

  inline Sheet_AssistBox& operator=(const Sheet_AssistBox& from) {
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
  static const Sheet_AssistBox& default_instance();

  void Swap(Sheet_AssistBox* other);

  // implements Message ----------------------------------------------

  Sheet_AssistBox* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_AssistBox& from);
  void MergeFrom(const Sheet_AssistBox& from);
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

  // repeated .proto_ff.E_AssistBox E_AssistBox_List = 1;
  inline int e_assistbox_list_size() const;
  inline void clear_e_assistbox_list();
  static const int kEAssistBoxListFieldNumber = 1;
  inline const ::proto_ff::E_AssistBox& e_assistbox_list(int index) const;
  inline ::proto_ff::E_AssistBox* mutable_e_assistbox_list(int index);
  inline ::proto_ff::E_AssistBox* add_e_assistbox_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistBox >&
      e_assistbox_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistBox >*
      mutable_e_assistbox_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_AssistBox)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistBox > e_assistbox_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fAssist_2eproto();
  friend void protobuf_AssignDesc_E_5fAssist_2eproto();
  friend void protobuf_ShutdownFile_E_5fAssist_2eproto();

  void InitAsDefaultInstance();
  static Sheet_AssistBox* default_instance_;
};
// -------------------------------------------------------------------

class E_AssistThank : public ::google::protobuf::Message {
 public:
  E_AssistThank();
  virtual ~E_AssistThank();

  E_AssistThank(const E_AssistThank& from);

  inline E_AssistThank& operator=(const E_AssistThank& from) {
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
  static const E_AssistThank& default_instance();

  void Swap(E_AssistThank* other);

  // implements Message ----------------------------------------------

  E_AssistThank* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_AssistThank& from);
  void MergeFrom(const E_AssistThank& from);
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

  // optional string m_msg = 2;
  inline bool has_m_msg() const;
  inline void clear_m_msg();
  static const int kMMsgFieldNumber = 2;
  inline const ::std::string& m_msg() const;
  inline void set_m_msg(const ::std::string& value);
  inline void set_m_msg(const char* value);
  inline void set_m_msg(const char* value, size_t size);
  inline ::std::string* mutable_m_msg();
  inline ::std::string* release_m_msg();
  inline void set_allocated_m_msg(::std::string* m_msg);

  // @@protoc_insertion_point(class_scope:proto_ff.E_AssistThank)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_msg();
  inline void clear_has_m_msg();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* m_msg_;
  ::google::protobuf::int32 m_id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fAssist_2eproto();
  friend void protobuf_AssignDesc_E_5fAssist_2eproto();
  friend void protobuf_ShutdownFile_E_5fAssist_2eproto();

  void InitAsDefaultInstance();
  static E_AssistThank* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_AssistThank : public ::google::protobuf::Message {
 public:
  Sheet_AssistThank();
  virtual ~Sheet_AssistThank();

  Sheet_AssistThank(const Sheet_AssistThank& from);

  inline Sheet_AssistThank& operator=(const Sheet_AssistThank& from) {
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
  static const Sheet_AssistThank& default_instance();

  void Swap(Sheet_AssistThank* other);

  // implements Message ----------------------------------------------

  Sheet_AssistThank* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_AssistThank& from);
  void MergeFrom(const Sheet_AssistThank& from);
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

  // repeated .proto_ff.E_AssistThank E_AssistThank_List = 1;
  inline int e_assistthank_list_size() const;
  inline void clear_e_assistthank_list();
  static const int kEAssistThankListFieldNumber = 1;
  inline const ::proto_ff::E_AssistThank& e_assistthank_list(int index) const;
  inline ::proto_ff::E_AssistThank* mutable_e_assistthank_list(int index);
  inline ::proto_ff::E_AssistThank* add_e_assistthank_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistThank >&
      e_assistthank_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistThank >*
      mutable_e_assistthank_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_AssistThank)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistThank > e_assistthank_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fAssist_2eproto();
  friend void protobuf_AssignDesc_E_5fAssist_2eproto();
  friend void protobuf_ShutdownFile_E_5fAssist_2eproto();

  void InitAsDefaultInstance();
  static Sheet_AssistThank* default_instance_;
};
// -------------------------------------------------------------------

class E_AssistConst : public ::google::protobuf::Message {
 public:
  E_AssistConst();
  virtual ~E_AssistConst();

  E_AssistConst(const E_AssistConst& from);

  inline E_AssistConst& operator=(const E_AssistConst& from) {
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
  static const E_AssistConst& default_instance();

  void Swap(E_AssistConst* other);

  // implements Message ----------------------------------------------

  E_AssistConst* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_AssistConst& from);
  void MergeFrom(const E_AssistConst& from);
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

  // optional int32 m_senderGift = 2;
  inline bool has_m_sendergift() const;
  inline void clear_m_sendergift();
  static const int kMSenderGiftFieldNumber = 2;
  inline ::google::protobuf::int32 m_sendergift() const;
  inline void set_m_sendergift(::google::protobuf::int32 value);

  // optional int32 m_senderGiftNum = 3;
  inline bool has_m_sendergiftnum() const;
  inline void clear_m_sendergiftnum();
  static const int kMSenderGiftNumFieldNumber = 3;
  inline ::google::protobuf::int32 m_sendergiftnum() const;
  inline void set_m_sendergiftnum(::google::protobuf::int32 value);

  // optional int32 m_helperGift = 4;
  inline bool has_m_helpergift() const;
  inline void clear_m_helpergift();
  static const int kMHelperGiftFieldNumber = 4;
  inline ::google::protobuf::int32 m_helpergift() const;
  inline void set_m_helpergift(::google::protobuf::int32 value);

  // optional int32 m_helperGiftNum = 5;
  inline bool has_m_helpergiftnum() const;
  inline void clear_m_helpergiftnum();
  static const int kMHelperGiftNumFieldNumber = 5;
  inline ::google::protobuf::int32 m_helpergiftnum() const;
  inline void set_m_helpergiftnum(::google::protobuf::int32 value);

  // optional int32 m_prestigeDaylimit = 6;
  inline bool has_m_prestigedaylimit() const;
  inline void clear_m_prestigedaylimit();
  static const int kMPrestigeDaylimitFieldNumber = 6;
  inline ::google::protobuf::int32 m_prestigedaylimit() const;
  inline void set_m_prestigedaylimit(::google::protobuf::int32 value);

  // optional int32 m_prestigeDayBosslimit = 7;
  inline bool has_m_prestigedaybosslimit() const;
  inline void clear_m_prestigedaybosslimit();
  static const int kMPrestigeDayBosslimitFieldNumber = 7;
  inline ::google::protobuf::int32 m_prestigedaybosslimit() const;
  inline void set_m_prestigedaybosslimit(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_AssistConst)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_sendergift();
  inline void clear_has_m_sendergift();
  inline void set_has_m_sendergiftnum();
  inline void clear_has_m_sendergiftnum();
  inline void set_has_m_helpergift();
  inline void clear_has_m_helpergift();
  inline void set_has_m_helpergiftnum();
  inline void clear_has_m_helpergiftnum();
  inline void set_has_m_prestigedaylimit();
  inline void clear_has_m_prestigedaylimit();
  inline void set_has_m_prestigedaybosslimit();
  inline void clear_has_m_prestigedaybosslimit();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 m_id_;
  ::google::protobuf::int32 m_sendergift_;
  ::google::protobuf::int32 m_sendergiftnum_;
  ::google::protobuf::int32 m_helpergift_;
  ::google::protobuf::int32 m_helpergiftnum_;
  ::google::protobuf::int32 m_prestigedaylimit_;
  ::google::protobuf::int32 m_prestigedaybosslimit_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fAssist_2eproto();
  friend void protobuf_AssignDesc_E_5fAssist_2eproto();
  friend void protobuf_ShutdownFile_E_5fAssist_2eproto();

  void InitAsDefaultInstance();
  static E_AssistConst* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_AssistConst : public ::google::protobuf::Message {
 public:
  Sheet_AssistConst();
  virtual ~Sheet_AssistConst();

  Sheet_AssistConst(const Sheet_AssistConst& from);

  inline Sheet_AssistConst& operator=(const Sheet_AssistConst& from) {
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
  static const Sheet_AssistConst& default_instance();

  void Swap(Sheet_AssistConst* other);

  // implements Message ----------------------------------------------

  Sheet_AssistConst* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_AssistConst& from);
  void MergeFrom(const Sheet_AssistConst& from);
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

  // repeated .proto_ff.E_AssistConst E_AssistConst_List = 1;
  inline int e_assistconst_list_size() const;
  inline void clear_e_assistconst_list();
  static const int kEAssistConstListFieldNumber = 1;
  inline const ::proto_ff::E_AssistConst& e_assistconst_list(int index) const;
  inline ::proto_ff::E_AssistConst* mutable_e_assistconst_list(int index);
  inline ::proto_ff::E_AssistConst* add_e_assistconst_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistConst >&
      e_assistconst_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistConst >*
      mutable_e_assistconst_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_AssistConst)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistConst > e_assistconst_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fAssist_2eproto();
  friend void protobuf_AssignDesc_E_5fAssist_2eproto();
  friend void protobuf_ShutdownFile_E_5fAssist_2eproto();

  void InitAsDefaultInstance();
  static Sheet_AssistConst* default_instance_;
};
// ===================================================================


// ===================================================================

// E_AssistBox

// optional int32 m_id = 1;
inline bool E_AssistBox::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_AssistBox::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_AssistBox::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_AssistBox::clear_m_id() {
  m_id_ = 0;
  clear_has_m_id();
}
inline ::google::protobuf::int32 E_AssistBox::m_id() const {
  return m_id_;
}
inline void E_AssistBox::set_m_id(::google::protobuf::int32 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional int32 m_times = 2;
inline bool E_AssistBox::has_m_times() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_AssistBox::set_has_m_times() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_AssistBox::clear_has_m_times() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_AssistBox::clear_m_times() {
  m_times_ = 0;
  clear_has_m_times();
}
inline ::google::protobuf::int32 E_AssistBox::m_times() const {
  return m_times_;
}
inline void E_AssistBox::set_m_times(::google::protobuf::int32 value) {
  set_has_m_times();
  m_times_ = value;
}

// optional int32 m_itemid = 3;
inline bool E_AssistBox::has_m_itemid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_AssistBox::set_has_m_itemid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_AssistBox::clear_has_m_itemid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_AssistBox::clear_m_itemid() {
  m_itemid_ = 0;
  clear_has_m_itemid();
}
inline ::google::protobuf::int32 E_AssistBox::m_itemid() const {
  return m_itemid_;
}
inline void E_AssistBox::set_m_itemid(::google::protobuf::int32 value) {
  set_has_m_itemid();
  m_itemid_ = value;
}

// -------------------------------------------------------------------

// Sheet_AssistBox

// repeated .proto_ff.E_AssistBox E_AssistBox_List = 1;
inline int Sheet_AssistBox::e_assistbox_list_size() const {
  return e_assistbox_list_.size();
}
inline void Sheet_AssistBox::clear_e_assistbox_list() {
  e_assistbox_list_.Clear();
}
inline const ::proto_ff::E_AssistBox& Sheet_AssistBox::e_assistbox_list(int index) const {
  return e_assistbox_list_.Get(index);
}
inline ::proto_ff::E_AssistBox* Sheet_AssistBox::mutable_e_assistbox_list(int index) {
  return e_assistbox_list_.Mutable(index);
}
inline ::proto_ff::E_AssistBox* Sheet_AssistBox::add_e_assistbox_list() {
  return e_assistbox_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistBox >&
Sheet_AssistBox::e_assistbox_list() const {
  return e_assistbox_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistBox >*
Sheet_AssistBox::mutable_e_assistbox_list() {
  return &e_assistbox_list_;
}

// -------------------------------------------------------------------

// E_AssistThank

// optional int32 m_id = 1;
inline bool E_AssistThank::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_AssistThank::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_AssistThank::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_AssistThank::clear_m_id() {
  m_id_ = 0;
  clear_has_m_id();
}
inline ::google::protobuf::int32 E_AssistThank::m_id() const {
  return m_id_;
}
inline void E_AssistThank::set_m_id(::google::protobuf::int32 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional string m_msg = 2;
inline bool E_AssistThank::has_m_msg() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_AssistThank::set_has_m_msg() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_AssistThank::clear_has_m_msg() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_AssistThank::clear_m_msg() {
  if (m_msg_ != &::google::protobuf::internal::kEmptyString) {
    m_msg_->clear();
  }
  clear_has_m_msg();
}
inline const ::std::string& E_AssistThank::m_msg() const {
  return *m_msg_;
}
inline void E_AssistThank::set_m_msg(const ::std::string& value) {
  set_has_m_msg();
  if (m_msg_ == &::google::protobuf::internal::kEmptyString) {
    m_msg_ = new ::std::string;
  }
  m_msg_->assign(value);
}
inline void E_AssistThank::set_m_msg(const char* value) {
  set_has_m_msg();
  if (m_msg_ == &::google::protobuf::internal::kEmptyString) {
    m_msg_ = new ::std::string;
  }
  m_msg_->assign(value);
}
inline void E_AssistThank::set_m_msg(const char* value, size_t size) {
  set_has_m_msg();
  if (m_msg_ == &::google::protobuf::internal::kEmptyString) {
    m_msg_ = new ::std::string;
  }
  m_msg_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_AssistThank::mutable_m_msg() {
  set_has_m_msg();
  if (m_msg_ == &::google::protobuf::internal::kEmptyString) {
    m_msg_ = new ::std::string;
  }
  return m_msg_;
}
inline ::std::string* E_AssistThank::release_m_msg() {
  clear_has_m_msg();
  if (m_msg_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_msg_;
    m_msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_AssistThank::set_allocated_m_msg(::std::string* m_msg) {
  if (m_msg_ != &::google::protobuf::internal::kEmptyString) {
    delete m_msg_;
  }
  if (m_msg) {
    set_has_m_msg();
    m_msg_ = m_msg;
  } else {
    clear_has_m_msg();
    m_msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// Sheet_AssistThank

// repeated .proto_ff.E_AssistThank E_AssistThank_List = 1;
inline int Sheet_AssistThank::e_assistthank_list_size() const {
  return e_assistthank_list_.size();
}
inline void Sheet_AssistThank::clear_e_assistthank_list() {
  e_assistthank_list_.Clear();
}
inline const ::proto_ff::E_AssistThank& Sheet_AssistThank::e_assistthank_list(int index) const {
  return e_assistthank_list_.Get(index);
}
inline ::proto_ff::E_AssistThank* Sheet_AssistThank::mutable_e_assistthank_list(int index) {
  return e_assistthank_list_.Mutable(index);
}
inline ::proto_ff::E_AssistThank* Sheet_AssistThank::add_e_assistthank_list() {
  return e_assistthank_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistThank >&
Sheet_AssistThank::e_assistthank_list() const {
  return e_assistthank_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistThank >*
Sheet_AssistThank::mutable_e_assistthank_list() {
  return &e_assistthank_list_;
}

// -------------------------------------------------------------------

// E_AssistConst

// optional int32 m_id = 1;
inline bool E_AssistConst::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_AssistConst::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_AssistConst::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_AssistConst::clear_m_id() {
  m_id_ = 0;
  clear_has_m_id();
}
inline ::google::protobuf::int32 E_AssistConst::m_id() const {
  return m_id_;
}
inline void E_AssistConst::set_m_id(::google::protobuf::int32 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional int32 m_senderGift = 2;
inline bool E_AssistConst::has_m_sendergift() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_AssistConst::set_has_m_sendergift() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_AssistConst::clear_has_m_sendergift() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_AssistConst::clear_m_sendergift() {
  m_sendergift_ = 0;
  clear_has_m_sendergift();
}
inline ::google::protobuf::int32 E_AssistConst::m_sendergift() const {
  return m_sendergift_;
}
inline void E_AssistConst::set_m_sendergift(::google::protobuf::int32 value) {
  set_has_m_sendergift();
  m_sendergift_ = value;
}

// optional int32 m_senderGiftNum = 3;
inline bool E_AssistConst::has_m_sendergiftnum() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_AssistConst::set_has_m_sendergiftnum() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_AssistConst::clear_has_m_sendergiftnum() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_AssistConst::clear_m_sendergiftnum() {
  m_sendergiftnum_ = 0;
  clear_has_m_sendergiftnum();
}
inline ::google::protobuf::int32 E_AssistConst::m_sendergiftnum() const {
  return m_sendergiftnum_;
}
inline void E_AssistConst::set_m_sendergiftnum(::google::protobuf::int32 value) {
  set_has_m_sendergiftnum();
  m_sendergiftnum_ = value;
}

// optional int32 m_helperGift = 4;
inline bool E_AssistConst::has_m_helpergift() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void E_AssistConst::set_has_m_helpergift() {
  _has_bits_[0] |= 0x00000008u;
}
inline void E_AssistConst::clear_has_m_helpergift() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void E_AssistConst::clear_m_helpergift() {
  m_helpergift_ = 0;
  clear_has_m_helpergift();
}
inline ::google::protobuf::int32 E_AssistConst::m_helpergift() const {
  return m_helpergift_;
}
inline void E_AssistConst::set_m_helpergift(::google::protobuf::int32 value) {
  set_has_m_helpergift();
  m_helpergift_ = value;
}

// optional int32 m_helperGiftNum = 5;
inline bool E_AssistConst::has_m_helpergiftnum() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void E_AssistConst::set_has_m_helpergiftnum() {
  _has_bits_[0] |= 0x00000010u;
}
inline void E_AssistConst::clear_has_m_helpergiftnum() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void E_AssistConst::clear_m_helpergiftnum() {
  m_helpergiftnum_ = 0;
  clear_has_m_helpergiftnum();
}
inline ::google::protobuf::int32 E_AssistConst::m_helpergiftnum() const {
  return m_helpergiftnum_;
}
inline void E_AssistConst::set_m_helpergiftnum(::google::protobuf::int32 value) {
  set_has_m_helpergiftnum();
  m_helpergiftnum_ = value;
}

// optional int32 m_prestigeDaylimit = 6;
inline bool E_AssistConst::has_m_prestigedaylimit() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void E_AssistConst::set_has_m_prestigedaylimit() {
  _has_bits_[0] |= 0x00000020u;
}
inline void E_AssistConst::clear_has_m_prestigedaylimit() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void E_AssistConst::clear_m_prestigedaylimit() {
  m_prestigedaylimit_ = 0;
  clear_has_m_prestigedaylimit();
}
inline ::google::protobuf::int32 E_AssistConst::m_prestigedaylimit() const {
  return m_prestigedaylimit_;
}
inline void E_AssistConst::set_m_prestigedaylimit(::google::protobuf::int32 value) {
  set_has_m_prestigedaylimit();
  m_prestigedaylimit_ = value;
}

// optional int32 m_prestigeDayBosslimit = 7;
inline bool E_AssistConst::has_m_prestigedaybosslimit() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void E_AssistConst::set_has_m_prestigedaybosslimit() {
  _has_bits_[0] |= 0x00000040u;
}
inline void E_AssistConst::clear_has_m_prestigedaybosslimit() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void E_AssistConst::clear_m_prestigedaybosslimit() {
  m_prestigedaybosslimit_ = 0;
  clear_has_m_prestigedaybosslimit();
}
inline ::google::protobuf::int32 E_AssistConst::m_prestigedaybosslimit() const {
  return m_prestigedaybosslimit_;
}
inline void E_AssistConst::set_m_prestigedaybosslimit(::google::protobuf::int32 value) {
  set_has_m_prestigedaybosslimit();
  m_prestigedaybosslimit_ = value;
}

// -------------------------------------------------------------------

// Sheet_AssistConst

// repeated .proto_ff.E_AssistConst E_AssistConst_List = 1;
inline int Sheet_AssistConst::e_assistconst_list_size() const {
  return e_assistconst_list_.size();
}
inline void Sheet_AssistConst::clear_e_assistconst_list() {
  e_assistconst_list_.Clear();
}
inline const ::proto_ff::E_AssistConst& Sheet_AssistConst::e_assistconst_list(int index) const {
  return e_assistconst_list_.Get(index);
}
inline ::proto_ff::E_AssistConst* Sheet_AssistConst::mutable_e_assistconst_list(int index) {
  return e_assistconst_list_.Mutable(index);
}
inline ::proto_ff::E_AssistConst* Sheet_AssistConst::add_e_assistconst_list() {
  return e_assistconst_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistConst >&
Sheet_AssistConst::e_assistconst_list() const {
  return e_assistconst_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AssistConst >*
Sheet_AssistConst::mutable_e_assistconst_list() {
  return &e_assistconst_list_;
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

#endif  // PROTOBUF_E_5fAssist_2eproto__INCLUDED
