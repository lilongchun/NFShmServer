// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Ai.proto

#ifndef PROTOBUF_E_5fAi_2eproto__INCLUDED
#define PROTOBUF_E_5fAi_2eproto__INCLUDED

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
void  protobuf_AddDesc_E_5fAi_2eproto();
void protobuf_AssignDesc_E_5fAi_2eproto();
void protobuf_ShutdownFile_E_5fAi_2eproto();

class E_AiAiHpDesc;
class E_AiAi;
class Sheet_AiAi;

// ===================================================================

class E_AiAiHpDesc : public ::google::protobuf::Message {
 public:
  E_AiAiHpDesc();
  virtual ~E_AiAiHpDesc();

  E_AiAiHpDesc(const E_AiAiHpDesc& from);

  inline E_AiAiHpDesc& operator=(const E_AiAiHpDesc& from) {
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
  static const E_AiAiHpDesc& default_instance();

  void Swap(E_AiAiHpDesc* other);

  // implements Message ----------------------------------------------

  E_AiAiHpDesc* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_AiAiHpDesc& from);
  void MergeFrom(const E_AiAiHpDesc& from);
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

  // optional int64 m_chat = 1;
  inline bool has_m_chat() const;
  inline void clear_m_chat();
  static const int kMChatFieldNumber = 1;
  inline ::google::protobuf::int64 m_chat() const;
  inline void set_m_chat(::google::protobuf::int64 value);

  // optional int64 m_skill = 2;
  inline bool has_m_skill() const;
  inline void clear_m_skill();
  static const int kMSkillFieldNumber = 2;
  inline ::google::protobuf::int64 m_skill() const;
  inline void set_m_skill(::google::protobuf::int64 value);

  // optional int32 m_percent = 3;
  inline bool has_m_percent() const;
  inline void clear_m_percent();
  static const int kMPercentFieldNumber = 3;
  inline ::google::protobuf::int32 m_percent() const;
  inline void set_m_percent(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.E_AiAiHpDesc)
 private:
  inline void set_has_m_chat();
  inline void clear_has_m_chat();
  inline void set_has_m_skill();
  inline void clear_has_m_skill();
  inline void set_has_m_percent();
  inline void clear_has_m_percent();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 m_chat_;
  ::google::protobuf::int64 m_skill_;
  ::google::protobuf::int32 m_percent_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fAi_2eproto();
  friend void protobuf_AssignDesc_E_5fAi_2eproto();
  friend void protobuf_ShutdownFile_E_5fAi_2eproto();

  void InitAsDefaultInstance();
  static E_AiAiHpDesc* default_instance_;
};
// -------------------------------------------------------------------

class E_AiAi : public ::google::protobuf::Message {
 public:
  E_AiAi();
  virtual ~E_AiAi();

  E_AiAi(const E_AiAi& from);

  inline E_AiAi& operator=(const E_AiAi& from) {
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
  static const E_AiAi& default_instance();

  void Swap(E_AiAi* other);

  // implements Message ----------------------------------------------

  E_AiAi* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const E_AiAi& from);
  void MergeFrom(const E_AiAi& from);
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

  // optional int32 m_type = 2;
  inline bool has_m_type() const;
  inline void clear_m_type();
  static const int kMTypeFieldNumber = 2;
  inline ::google::protobuf::int32 m_type() const;
  inline void set_m_type(::google::protobuf::int32 value);

  // optional string m_deadHateRemain = 3;
  inline bool has_m_deadhateremain() const;
  inline void clear_m_deadhateremain();
  static const int kMDeadHateRemainFieldNumber = 3;
  inline const ::std::string& m_deadhateremain() const;
  inline void set_m_deadhateremain(const ::std::string& value);
  inline void set_m_deadhateremain(const char* value);
  inline void set_m_deadhateremain(const char* value, size_t size);
  inline ::std::string* mutable_m_deadhateremain();
  inline ::std::string* release_m_deadhateremain();
  inline void set_allocated_m_deadhateremain(::std::string* m_deadhateremain);

  // optional string m_invisibleRemain = 4;
  inline bool has_m_invisibleremain() const;
  inline void clear_m_invisibleremain();
  static const int kMInvisibleRemainFieldNumber = 4;
  inline const ::std::string& m_invisibleremain() const;
  inline void set_m_invisibleremain(const ::std::string& value);
  inline void set_m_invisibleremain(const char* value);
  inline void set_m_invisibleremain(const char* value, size_t size);
  inline ::std::string* mutable_m_invisibleremain();
  inline ::std::string* release_m_invisibleremain();
  inline void set_allocated_m_invisibleremain(::std::string* m_invisibleremain);

  // optional int32 m_isActive = 5;
  inline bool has_m_isactive() const;
  inline void clear_m_isactive();
  static const int kMIsActiveFieldNumber = 5;
  inline ::google::protobuf::int32 m_isactive() const;
  inline void set_m_isactive(::google::protobuf::int32 value);

  // optional int32 m_returnType = 6;
  inline bool has_m_returntype() const;
  inline void clear_m_returntype();
  static const int kMReturnTypeFieldNumber = 6;
  inline ::google::protobuf::int32 m_returntype() const;
  inline void set_m_returntype(::google::protobuf::int32 value);

  // optional int32 m_view = 7;
  inline bool has_m_view() const;
  inline void clear_m_view();
  static const int kMViewFieldNumber = 7;
  inline ::google::protobuf::int32 m_view() const;
  inline void set_m_view(::google::protobuf::int32 value);

  // optional int32 m_isAttackedShowOff = 8;
  inline bool has_m_isattackedshowoff() const;
  inline void clear_m_isattackedshowoff();
  static const int kMIsAttackedShowOffFieldNumber = 8;
  inline ::google::protobuf::int32 m_isattackedshowoff() const;
  inline void set_m_isattackedshowoff(::google::protobuf::int32 value);

  // optional int32 m_pursueRange = 9;
  inline bool has_m_pursuerange() const;
  inline void clear_m_pursuerange();
  static const int kMPursueRangeFieldNumber = 9;
  inline ::google::protobuf::int32 m_pursuerange() const;
  inline void set_m_pursuerange(::google::protobuf::int32 value);

  // optional int32 m_actionRange = 10;
  inline bool has_m_actionrange() const;
  inline void clear_m_actionrange();
  static const int kMActionRangeFieldNumber = 10;
  inline ::google::protobuf::int32 m_actionrange() const;
  inline void set_m_actionrange(::google::protobuf::int32 value);

  // optional int32 m_wakeupRadius = 11;
  inline bool has_m_wakeupradius() const;
  inline void clear_m_wakeupradius();
  static const int kMWakeupRadiusFieldNumber = 11;
  inline ::google::protobuf::int32 m_wakeupradius() const;
  inline void set_m_wakeupradius(::google::protobuf::int32 value);

  // optional int32 m_isAIWorkWhenNobody = 12;
  inline bool has_m_isaiworkwhennobody() const;
  inline void clear_m_isaiworkwhennobody();
  static const int kMIsAIWorkWhenNobodyFieldNumber = 12;
  inline ::google::protobuf::int32 m_isaiworkwhennobody() const;
  inline void set_m_isaiworkwhennobody(::google::protobuf::int32 value);

  // optional int32 m_bornEffectAIDelay = 13;
  inline bool has_m_borneffectaidelay() const;
  inline void clear_m_borneffectaidelay();
  static const int kMBornEffectAIDelayFieldNumber = 13;
  inline ::google::protobuf::int32 m_borneffectaidelay() const;
  inline void set_m_borneffectaidelay(::google::protobuf::int32 value);

  // optional string m_initSkills = 14;
  inline bool has_m_initskills() const;
  inline void clear_m_initskills();
  static const int kMInitSkillsFieldNumber = 14;
  inline const ::std::string& m_initskills() const;
  inline void set_m_initskills(const ::std::string& value);
  inline void set_m_initskills(const char* value);
  inline void set_m_initskills(const char* value, size_t size);
  inline ::std::string* mutable_m_initskills();
  inline ::std::string* release_m_initskills();
  inline void set_allocated_m_initskills(::std::string* m_initskills);

  // repeated .proto_ff.E_AiAiHpDesc m_hp = 15;
  inline int m_hp_size() const;
  inline void clear_m_hp();
  static const int kMHpFieldNumber = 15;
  inline const ::proto_ff::E_AiAiHpDesc& m_hp(int index) const;
  inline ::proto_ff::E_AiAiHpDesc* mutable_m_hp(int index);
  inline ::proto_ff::E_AiAiHpDesc* add_m_hp();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAiHpDesc >&
      m_hp() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAiHpDesc >*
      mutable_m_hp();

  // @@protoc_insertion_point(class_scope:proto_ff.E_AiAi)
 private:
  inline void set_has_m_id();
  inline void clear_has_m_id();
  inline void set_has_m_type();
  inline void clear_has_m_type();
  inline void set_has_m_deadhateremain();
  inline void clear_has_m_deadhateremain();
  inline void set_has_m_invisibleremain();
  inline void clear_has_m_invisibleremain();
  inline void set_has_m_isactive();
  inline void clear_has_m_isactive();
  inline void set_has_m_returntype();
  inline void clear_has_m_returntype();
  inline void set_has_m_view();
  inline void clear_has_m_view();
  inline void set_has_m_isattackedshowoff();
  inline void clear_has_m_isattackedshowoff();
  inline void set_has_m_pursuerange();
  inline void clear_has_m_pursuerange();
  inline void set_has_m_actionrange();
  inline void clear_has_m_actionrange();
  inline void set_has_m_wakeupradius();
  inline void clear_has_m_wakeupradius();
  inline void set_has_m_isaiworkwhennobody();
  inline void clear_has_m_isaiworkwhennobody();
  inline void set_has_m_borneffectaidelay();
  inline void clear_has_m_borneffectaidelay();
  inline void set_has_m_initskills();
  inline void clear_has_m_initskills();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 m_id_;
  ::std::string* m_deadhateremain_;
  ::google::protobuf::int32 m_type_;
  ::google::protobuf::int32 m_isactive_;
  ::std::string* m_invisibleremain_;
  ::google::protobuf::int32 m_returntype_;
  ::google::protobuf::int32 m_view_;
  ::google::protobuf::int32 m_isattackedshowoff_;
  ::google::protobuf::int32 m_pursuerange_;
  ::google::protobuf::int32 m_actionrange_;
  ::google::protobuf::int32 m_wakeupradius_;
  ::google::protobuf::int32 m_isaiworkwhennobody_;
  ::google::protobuf::int32 m_borneffectaidelay_;
  ::std::string* m_initskills_;
  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAiHpDesc > m_hp_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(15 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fAi_2eproto();
  friend void protobuf_AssignDesc_E_5fAi_2eproto();
  friend void protobuf_ShutdownFile_E_5fAi_2eproto();

  void InitAsDefaultInstance();
  static E_AiAi* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_AiAi : public ::google::protobuf::Message {
 public:
  Sheet_AiAi();
  virtual ~Sheet_AiAi();

  Sheet_AiAi(const Sheet_AiAi& from);

  inline Sheet_AiAi& operator=(const Sheet_AiAi& from) {
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
  static const Sheet_AiAi& default_instance();

  void Swap(Sheet_AiAi* other);

  // implements Message ----------------------------------------------

  Sheet_AiAi* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_AiAi& from);
  void MergeFrom(const Sheet_AiAi& from);
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

  // repeated .proto_ff.E_AiAi E_AiAi_List = 1;
  inline int e_aiai_list_size() const;
  inline void clear_e_aiai_list();
  static const int kEAiAiListFieldNumber = 1;
  inline const ::proto_ff::E_AiAi& e_aiai_list(int index) const;
  inline ::proto_ff::E_AiAi* mutable_e_aiai_list(int index);
  inline ::proto_ff::E_AiAi* add_e_aiai_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAi >&
      e_aiai_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAi >*
      mutable_e_aiai_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_AiAi)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAi > e_aiai_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_E_5fAi_2eproto();
  friend void protobuf_AssignDesc_E_5fAi_2eproto();
  friend void protobuf_ShutdownFile_E_5fAi_2eproto();

  void InitAsDefaultInstance();
  static Sheet_AiAi* default_instance_;
};
// ===================================================================


// ===================================================================

// E_AiAiHpDesc

// optional int64 m_chat = 1;
inline bool E_AiAiHpDesc::has_m_chat() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_AiAiHpDesc::set_has_m_chat() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_AiAiHpDesc::clear_has_m_chat() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_AiAiHpDesc::clear_m_chat() {
  m_chat_ = GOOGLE_LONGLONG(0);
  clear_has_m_chat();
}
inline ::google::protobuf::int64 E_AiAiHpDesc::m_chat() const {
  return m_chat_;
}
inline void E_AiAiHpDesc::set_m_chat(::google::protobuf::int64 value) {
  set_has_m_chat();
  m_chat_ = value;
}

// optional int64 m_skill = 2;
inline bool E_AiAiHpDesc::has_m_skill() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_AiAiHpDesc::set_has_m_skill() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_AiAiHpDesc::clear_has_m_skill() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_AiAiHpDesc::clear_m_skill() {
  m_skill_ = GOOGLE_LONGLONG(0);
  clear_has_m_skill();
}
inline ::google::protobuf::int64 E_AiAiHpDesc::m_skill() const {
  return m_skill_;
}
inline void E_AiAiHpDesc::set_m_skill(::google::protobuf::int64 value) {
  set_has_m_skill();
  m_skill_ = value;
}

// optional int32 m_percent = 3;
inline bool E_AiAiHpDesc::has_m_percent() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_AiAiHpDesc::set_has_m_percent() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_AiAiHpDesc::clear_has_m_percent() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_AiAiHpDesc::clear_m_percent() {
  m_percent_ = 0;
  clear_has_m_percent();
}
inline ::google::protobuf::int32 E_AiAiHpDesc::m_percent() const {
  return m_percent_;
}
inline void E_AiAiHpDesc::set_m_percent(::google::protobuf::int32 value) {
  set_has_m_percent();
  m_percent_ = value;
}

// -------------------------------------------------------------------

// E_AiAi

// optional int64 m_id = 1;
inline bool E_AiAi::has_m_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void E_AiAi::set_has_m_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void E_AiAi::clear_has_m_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void E_AiAi::clear_m_id() {
  m_id_ = GOOGLE_LONGLONG(0);
  clear_has_m_id();
}
inline ::google::protobuf::int64 E_AiAi::m_id() const {
  return m_id_;
}
inline void E_AiAi::set_m_id(::google::protobuf::int64 value) {
  set_has_m_id();
  m_id_ = value;
}

// optional int32 m_type = 2;
inline bool E_AiAi::has_m_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void E_AiAi::set_has_m_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void E_AiAi::clear_has_m_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void E_AiAi::clear_m_type() {
  m_type_ = 0;
  clear_has_m_type();
}
inline ::google::protobuf::int32 E_AiAi::m_type() const {
  return m_type_;
}
inline void E_AiAi::set_m_type(::google::protobuf::int32 value) {
  set_has_m_type();
  m_type_ = value;
}

// optional string m_deadHateRemain = 3;
inline bool E_AiAi::has_m_deadhateremain() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void E_AiAi::set_has_m_deadhateremain() {
  _has_bits_[0] |= 0x00000004u;
}
inline void E_AiAi::clear_has_m_deadhateremain() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void E_AiAi::clear_m_deadhateremain() {
  if (m_deadhateremain_ != &::google::protobuf::internal::kEmptyString) {
    m_deadhateremain_->clear();
  }
  clear_has_m_deadhateremain();
}
inline const ::std::string& E_AiAi::m_deadhateremain() const {
  return *m_deadhateremain_;
}
inline void E_AiAi::set_m_deadhateremain(const ::std::string& value) {
  set_has_m_deadhateremain();
  if (m_deadhateremain_ == &::google::protobuf::internal::kEmptyString) {
    m_deadhateremain_ = new ::std::string;
  }
  m_deadhateremain_->assign(value);
}
inline void E_AiAi::set_m_deadhateremain(const char* value) {
  set_has_m_deadhateremain();
  if (m_deadhateremain_ == &::google::protobuf::internal::kEmptyString) {
    m_deadhateremain_ = new ::std::string;
  }
  m_deadhateremain_->assign(value);
}
inline void E_AiAi::set_m_deadhateremain(const char* value, size_t size) {
  set_has_m_deadhateremain();
  if (m_deadhateremain_ == &::google::protobuf::internal::kEmptyString) {
    m_deadhateremain_ = new ::std::string;
  }
  m_deadhateremain_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_AiAi::mutable_m_deadhateremain() {
  set_has_m_deadhateremain();
  if (m_deadhateremain_ == &::google::protobuf::internal::kEmptyString) {
    m_deadhateremain_ = new ::std::string;
  }
  return m_deadhateremain_;
}
inline ::std::string* E_AiAi::release_m_deadhateremain() {
  clear_has_m_deadhateremain();
  if (m_deadhateremain_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_deadhateremain_;
    m_deadhateremain_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_AiAi::set_allocated_m_deadhateremain(::std::string* m_deadhateremain) {
  if (m_deadhateremain_ != &::google::protobuf::internal::kEmptyString) {
    delete m_deadhateremain_;
  }
  if (m_deadhateremain) {
    set_has_m_deadhateremain();
    m_deadhateremain_ = m_deadhateremain;
  } else {
    clear_has_m_deadhateremain();
    m_deadhateremain_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string m_invisibleRemain = 4;
inline bool E_AiAi::has_m_invisibleremain() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void E_AiAi::set_has_m_invisibleremain() {
  _has_bits_[0] |= 0x00000008u;
}
inline void E_AiAi::clear_has_m_invisibleremain() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void E_AiAi::clear_m_invisibleremain() {
  if (m_invisibleremain_ != &::google::protobuf::internal::kEmptyString) {
    m_invisibleremain_->clear();
  }
  clear_has_m_invisibleremain();
}
inline const ::std::string& E_AiAi::m_invisibleremain() const {
  return *m_invisibleremain_;
}
inline void E_AiAi::set_m_invisibleremain(const ::std::string& value) {
  set_has_m_invisibleremain();
  if (m_invisibleremain_ == &::google::protobuf::internal::kEmptyString) {
    m_invisibleremain_ = new ::std::string;
  }
  m_invisibleremain_->assign(value);
}
inline void E_AiAi::set_m_invisibleremain(const char* value) {
  set_has_m_invisibleremain();
  if (m_invisibleremain_ == &::google::protobuf::internal::kEmptyString) {
    m_invisibleremain_ = new ::std::string;
  }
  m_invisibleremain_->assign(value);
}
inline void E_AiAi::set_m_invisibleremain(const char* value, size_t size) {
  set_has_m_invisibleremain();
  if (m_invisibleremain_ == &::google::protobuf::internal::kEmptyString) {
    m_invisibleremain_ = new ::std::string;
  }
  m_invisibleremain_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_AiAi::mutable_m_invisibleremain() {
  set_has_m_invisibleremain();
  if (m_invisibleremain_ == &::google::protobuf::internal::kEmptyString) {
    m_invisibleremain_ = new ::std::string;
  }
  return m_invisibleremain_;
}
inline ::std::string* E_AiAi::release_m_invisibleremain() {
  clear_has_m_invisibleremain();
  if (m_invisibleremain_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_invisibleremain_;
    m_invisibleremain_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_AiAi::set_allocated_m_invisibleremain(::std::string* m_invisibleremain) {
  if (m_invisibleremain_ != &::google::protobuf::internal::kEmptyString) {
    delete m_invisibleremain_;
  }
  if (m_invisibleremain) {
    set_has_m_invisibleremain();
    m_invisibleremain_ = m_invisibleremain;
  } else {
    clear_has_m_invisibleremain();
    m_invisibleremain_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 m_isActive = 5;
inline bool E_AiAi::has_m_isactive() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void E_AiAi::set_has_m_isactive() {
  _has_bits_[0] |= 0x00000010u;
}
inline void E_AiAi::clear_has_m_isactive() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void E_AiAi::clear_m_isactive() {
  m_isactive_ = 0;
  clear_has_m_isactive();
}
inline ::google::protobuf::int32 E_AiAi::m_isactive() const {
  return m_isactive_;
}
inline void E_AiAi::set_m_isactive(::google::protobuf::int32 value) {
  set_has_m_isactive();
  m_isactive_ = value;
}

// optional int32 m_returnType = 6;
inline bool E_AiAi::has_m_returntype() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void E_AiAi::set_has_m_returntype() {
  _has_bits_[0] |= 0x00000020u;
}
inline void E_AiAi::clear_has_m_returntype() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void E_AiAi::clear_m_returntype() {
  m_returntype_ = 0;
  clear_has_m_returntype();
}
inline ::google::protobuf::int32 E_AiAi::m_returntype() const {
  return m_returntype_;
}
inline void E_AiAi::set_m_returntype(::google::protobuf::int32 value) {
  set_has_m_returntype();
  m_returntype_ = value;
}

// optional int32 m_view = 7;
inline bool E_AiAi::has_m_view() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void E_AiAi::set_has_m_view() {
  _has_bits_[0] |= 0x00000040u;
}
inline void E_AiAi::clear_has_m_view() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void E_AiAi::clear_m_view() {
  m_view_ = 0;
  clear_has_m_view();
}
inline ::google::protobuf::int32 E_AiAi::m_view() const {
  return m_view_;
}
inline void E_AiAi::set_m_view(::google::protobuf::int32 value) {
  set_has_m_view();
  m_view_ = value;
}

// optional int32 m_isAttackedShowOff = 8;
inline bool E_AiAi::has_m_isattackedshowoff() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void E_AiAi::set_has_m_isattackedshowoff() {
  _has_bits_[0] |= 0x00000080u;
}
inline void E_AiAi::clear_has_m_isattackedshowoff() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void E_AiAi::clear_m_isattackedshowoff() {
  m_isattackedshowoff_ = 0;
  clear_has_m_isattackedshowoff();
}
inline ::google::protobuf::int32 E_AiAi::m_isattackedshowoff() const {
  return m_isattackedshowoff_;
}
inline void E_AiAi::set_m_isattackedshowoff(::google::protobuf::int32 value) {
  set_has_m_isattackedshowoff();
  m_isattackedshowoff_ = value;
}

// optional int32 m_pursueRange = 9;
inline bool E_AiAi::has_m_pursuerange() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void E_AiAi::set_has_m_pursuerange() {
  _has_bits_[0] |= 0x00000100u;
}
inline void E_AiAi::clear_has_m_pursuerange() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void E_AiAi::clear_m_pursuerange() {
  m_pursuerange_ = 0;
  clear_has_m_pursuerange();
}
inline ::google::protobuf::int32 E_AiAi::m_pursuerange() const {
  return m_pursuerange_;
}
inline void E_AiAi::set_m_pursuerange(::google::protobuf::int32 value) {
  set_has_m_pursuerange();
  m_pursuerange_ = value;
}

// optional int32 m_actionRange = 10;
inline bool E_AiAi::has_m_actionrange() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void E_AiAi::set_has_m_actionrange() {
  _has_bits_[0] |= 0x00000200u;
}
inline void E_AiAi::clear_has_m_actionrange() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void E_AiAi::clear_m_actionrange() {
  m_actionrange_ = 0;
  clear_has_m_actionrange();
}
inline ::google::protobuf::int32 E_AiAi::m_actionrange() const {
  return m_actionrange_;
}
inline void E_AiAi::set_m_actionrange(::google::protobuf::int32 value) {
  set_has_m_actionrange();
  m_actionrange_ = value;
}

// optional int32 m_wakeupRadius = 11;
inline bool E_AiAi::has_m_wakeupradius() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void E_AiAi::set_has_m_wakeupradius() {
  _has_bits_[0] |= 0x00000400u;
}
inline void E_AiAi::clear_has_m_wakeupradius() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void E_AiAi::clear_m_wakeupradius() {
  m_wakeupradius_ = 0;
  clear_has_m_wakeupradius();
}
inline ::google::protobuf::int32 E_AiAi::m_wakeupradius() const {
  return m_wakeupradius_;
}
inline void E_AiAi::set_m_wakeupradius(::google::protobuf::int32 value) {
  set_has_m_wakeupradius();
  m_wakeupradius_ = value;
}

// optional int32 m_isAIWorkWhenNobody = 12;
inline bool E_AiAi::has_m_isaiworkwhennobody() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void E_AiAi::set_has_m_isaiworkwhennobody() {
  _has_bits_[0] |= 0x00000800u;
}
inline void E_AiAi::clear_has_m_isaiworkwhennobody() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void E_AiAi::clear_m_isaiworkwhennobody() {
  m_isaiworkwhennobody_ = 0;
  clear_has_m_isaiworkwhennobody();
}
inline ::google::protobuf::int32 E_AiAi::m_isaiworkwhennobody() const {
  return m_isaiworkwhennobody_;
}
inline void E_AiAi::set_m_isaiworkwhennobody(::google::protobuf::int32 value) {
  set_has_m_isaiworkwhennobody();
  m_isaiworkwhennobody_ = value;
}

// optional int32 m_bornEffectAIDelay = 13;
inline bool E_AiAi::has_m_borneffectaidelay() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void E_AiAi::set_has_m_borneffectaidelay() {
  _has_bits_[0] |= 0x00001000u;
}
inline void E_AiAi::clear_has_m_borneffectaidelay() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void E_AiAi::clear_m_borneffectaidelay() {
  m_borneffectaidelay_ = 0;
  clear_has_m_borneffectaidelay();
}
inline ::google::protobuf::int32 E_AiAi::m_borneffectaidelay() const {
  return m_borneffectaidelay_;
}
inline void E_AiAi::set_m_borneffectaidelay(::google::protobuf::int32 value) {
  set_has_m_borneffectaidelay();
  m_borneffectaidelay_ = value;
}

// optional string m_initSkills = 14;
inline bool E_AiAi::has_m_initskills() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void E_AiAi::set_has_m_initskills() {
  _has_bits_[0] |= 0x00002000u;
}
inline void E_AiAi::clear_has_m_initskills() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void E_AiAi::clear_m_initskills() {
  if (m_initskills_ != &::google::protobuf::internal::kEmptyString) {
    m_initskills_->clear();
  }
  clear_has_m_initskills();
}
inline const ::std::string& E_AiAi::m_initskills() const {
  return *m_initskills_;
}
inline void E_AiAi::set_m_initskills(const ::std::string& value) {
  set_has_m_initskills();
  if (m_initskills_ == &::google::protobuf::internal::kEmptyString) {
    m_initskills_ = new ::std::string;
  }
  m_initskills_->assign(value);
}
inline void E_AiAi::set_m_initskills(const char* value) {
  set_has_m_initskills();
  if (m_initskills_ == &::google::protobuf::internal::kEmptyString) {
    m_initskills_ = new ::std::string;
  }
  m_initskills_->assign(value);
}
inline void E_AiAi::set_m_initskills(const char* value, size_t size) {
  set_has_m_initskills();
  if (m_initskills_ == &::google::protobuf::internal::kEmptyString) {
    m_initskills_ = new ::std::string;
  }
  m_initskills_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* E_AiAi::mutable_m_initskills() {
  set_has_m_initskills();
  if (m_initskills_ == &::google::protobuf::internal::kEmptyString) {
    m_initskills_ = new ::std::string;
  }
  return m_initskills_;
}
inline ::std::string* E_AiAi::release_m_initskills() {
  clear_has_m_initskills();
  if (m_initskills_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = m_initskills_;
    m_initskills_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void E_AiAi::set_allocated_m_initskills(::std::string* m_initskills) {
  if (m_initskills_ != &::google::protobuf::internal::kEmptyString) {
    delete m_initskills_;
  }
  if (m_initskills) {
    set_has_m_initskills();
    m_initskills_ = m_initskills;
  } else {
    clear_has_m_initskills();
    m_initskills_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// repeated .proto_ff.E_AiAiHpDesc m_hp = 15;
inline int E_AiAi::m_hp_size() const {
  return m_hp_.size();
}
inline void E_AiAi::clear_m_hp() {
  m_hp_.Clear();
}
inline const ::proto_ff::E_AiAiHpDesc& E_AiAi::m_hp(int index) const {
  return m_hp_.Get(index);
}
inline ::proto_ff::E_AiAiHpDesc* E_AiAi::mutable_m_hp(int index) {
  return m_hp_.Mutable(index);
}
inline ::proto_ff::E_AiAiHpDesc* E_AiAi::add_m_hp() {
  return m_hp_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAiHpDesc >&
E_AiAi::m_hp() const {
  return m_hp_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAiHpDesc >*
E_AiAi::mutable_m_hp() {
  return &m_hp_;
}

// -------------------------------------------------------------------

// Sheet_AiAi

// repeated .proto_ff.E_AiAi E_AiAi_List = 1;
inline int Sheet_AiAi::e_aiai_list_size() const {
  return e_aiai_list_.size();
}
inline void Sheet_AiAi::clear_e_aiai_list() {
  e_aiai_list_.Clear();
}
inline const ::proto_ff::E_AiAi& Sheet_AiAi::e_aiai_list(int index) const {
  return e_aiai_list_.Get(index);
}
inline ::proto_ff::E_AiAi* Sheet_AiAi::mutable_e_aiai_list(int index) {
  return e_aiai_list_.Mutable(index);
}
inline ::proto_ff::E_AiAi* Sheet_AiAi::add_e_aiai_list() {
  return e_aiai_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAi >&
Sheet_AiAi::e_aiai_list() const {
  return e_aiai_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::E_AiAi >*
Sheet_AiAi::mutable_e_aiai_list() {
  return &e_aiai_list_;
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

#endif  // PROTOBUF_E_5fAi_2eproto__INCLUDED
