// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Convoy.proto

#ifndef PROTOBUF_Convoy_2eproto__INCLUDED
#define PROTOBUF_Convoy_2eproto__INCLUDED

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
void  protobuf_AddDesc_Convoy_2eproto();
void protobuf_AssignDesc_Convoy_2eproto();
void protobuf_ShutdownFile_Convoy_2eproto();

class NotifyConvoyInfo;
class ConvoyAcceptReq;
class ConvoyAcceptRsp;
class NotifyConvoyReward;
class ConvoyTimeOutNotify;
class RefreshEscortReq;
class RefreshEscortRsp;

// ===================================================================

class NotifyConvoyInfo : public ::google::protobuf::Message {
 public:
  NotifyConvoyInfo();
  virtual ~NotifyConvoyInfo();

  NotifyConvoyInfo(const NotifyConvoyInfo& from);

  inline NotifyConvoyInfo& operator=(const NotifyConvoyInfo& from) {
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
  static const NotifyConvoyInfo& default_instance();

  void Swap(NotifyConvoyInfo* other);

  // implements Message ----------------------------------------------

  NotifyConvoyInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NotifyConvoyInfo& from);
  void MergeFrom(const NotifyConvoyInfo& from);
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

  // optional int32 daynum = 1;
  inline bool has_daynum() const;
  inline void clear_daynum();
  static const int kDaynumFieldNumber = 1;
  inline ::google::protobuf::int32 daynum() const;
  inline void set_daynum(::google::protobuf::int32 value);

  // optional uint64 endTime = 2;
  inline bool has_endtime() const;
  inline void clear_endtime();
  static const int kEndTimeFieldNumber = 2;
  inline ::google::protobuf::uint64 endtime() const;
  inline void set_endtime(::google::protobuf::uint64 value);

  // optional int32 genEscortId = 3;
  inline bool has_genescortid() const;
  inline void clear_genescortid();
  static const int kGenEscortIdFieldNumber = 3;
  inline ::google::protobuf::int32 genescortid() const;
  inline void set_genescortid(::google::protobuf::int32 value);

  // optional int32 freeNum = 4;
  inline bool has_freenum() const;
  inline void clear_freenum();
  static const int kFreeNumFieldNumber = 4;
  inline ::google::protobuf::int32 freenum() const;
  inline void set_freenum(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.NotifyConvoyInfo)
 private:
  inline void set_has_daynum();
  inline void clear_has_daynum();
  inline void set_has_endtime();
  inline void clear_has_endtime();
  inline void set_has_genescortid();
  inline void clear_has_genescortid();
  inline void set_has_freenum();
  inline void clear_has_freenum();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint64 endtime_;
  ::google::protobuf::int32 daynum_;
  ::google::protobuf::int32 genescortid_;
  ::google::protobuf::int32 freenum_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_Convoy_2eproto();
  friend void protobuf_AssignDesc_Convoy_2eproto();
  friend void protobuf_ShutdownFile_Convoy_2eproto();

  void InitAsDefaultInstance();
  static NotifyConvoyInfo* default_instance_;
};
// -------------------------------------------------------------------

class ConvoyAcceptReq : public ::google::protobuf::Message {
 public:
  ConvoyAcceptReq();
  virtual ~ConvoyAcceptReq();

  ConvoyAcceptReq(const ConvoyAcceptReq& from);

  inline ConvoyAcceptReq& operator=(const ConvoyAcceptReq& from) {
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
  static const ConvoyAcceptReq& default_instance();

  void Swap(ConvoyAcceptReq* other);

  // implements Message ----------------------------------------------

  ConvoyAcceptReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConvoyAcceptReq& from);
  void MergeFrom(const ConvoyAcceptReq& from);
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

  // @@protoc_insertion_point(class_scope:proto_ff.ConvoyAcceptReq)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_Convoy_2eproto();
  friend void protobuf_AssignDesc_Convoy_2eproto();
  friend void protobuf_ShutdownFile_Convoy_2eproto();

  void InitAsDefaultInstance();
  static ConvoyAcceptReq* default_instance_;
};
// -------------------------------------------------------------------

class ConvoyAcceptRsp : public ::google::protobuf::Message {
 public:
  ConvoyAcceptRsp();
  virtual ~ConvoyAcceptRsp();

  ConvoyAcceptRsp(const ConvoyAcceptRsp& from);

  inline ConvoyAcceptRsp& operator=(const ConvoyAcceptRsp& from) {
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
  static const ConvoyAcceptRsp& default_instance();

  void Swap(ConvoyAcceptRsp* other);

  // implements Message ----------------------------------------------

  ConvoyAcceptRsp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConvoyAcceptRsp& from);
  void MergeFrom(const ConvoyAcceptRsp& from);
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

  // @@protoc_insertion_point(class_scope:proto_ff.ConvoyAcceptRsp)
 private:
  inline void set_has_ret();
  inline void clear_has_ret();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 ret_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_Convoy_2eproto();
  friend void protobuf_AssignDesc_Convoy_2eproto();
  friend void protobuf_ShutdownFile_Convoy_2eproto();

  void InitAsDefaultInstance();
  static ConvoyAcceptRsp* default_instance_;
};
// -------------------------------------------------------------------

class NotifyConvoyReward : public ::google::protobuf::Message {
 public:
  NotifyConvoyReward();
  virtual ~NotifyConvoyReward();

  NotifyConvoyReward(const NotifyConvoyReward& from);

  inline NotifyConvoyReward& operator=(const NotifyConvoyReward& from) {
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
  static const NotifyConvoyReward& default_instance();

  void Swap(NotifyConvoyReward* other);

  // implements Message ----------------------------------------------

  NotifyConvoyReward* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NotifyConvoyReward& from);
  void MergeFrom(const NotifyConvoyReward& from);
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

  // optional int64 exp = 1;
  inline bool has_exp() const;
  inline void clear_exp();
  static const int kExpFieldNumber = 1;
  inline ::google::protobuf::int64 exp() const;
  inline void set_exp(::google::protobuf::int64 value);

  // repeated .proto_ff.ComPair64 items = 2;
  inline int items_size() const;
  inline void clear_items();
  static const int kItemsFieldNumber = 2;
  inline const ::proto_ff::ComPair64& items(int index) const;
  inline ::proto_ff::ComPair64* mutable_items(int index);
  inline ::proto_ff::ComPair64* add_items();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::ComPair64 >&
      items() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::ComPair64 >*
      mutable_items();

  // @@protoc_insertion_point(class_scope:proto_ff.NotifyConvoyReward)
 private:
  inline void set_has_exp();
  inline void clear_has_exp();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 exp_;
  ::google::protobuf::RepeatedPtrField< ::proto_ff::ComPair64 > items_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_Convoy_2eproto();
  friend void protobuf_AssignDesc_Convoy_2eproto();
  friend void protobuf_ShutdownFile_Convoy_2eproto();

  void InitAsDefaultInstance();
  static NotifyConvoyReward* default_instance_;
};
// -------------------------------------------------------------------

class ConvoyTimeOutNotify : public ::google::protobuf::Message {
 public:
  ConvoyTimeOutNotify();
  virtual ~ConvoyTimeOutNotify();

  ConvoyTimeOutNotify(const ConvoyTimeOutNotify& from);

  inline ConvoyTimeOutNotify& operator=(const ConvoyTimeOutNotify& from) {
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
  static const ConvoyTimeOutNotify& default_instance();

  void Swap(ConvoyTimeOutNotify* other);

  // implements Message ----------------------------------------------

  ConvoyTimeOutNotify* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ConvoyTimeOutNotify& from);
  void MergeFrom(const ConvoyTimeOutNotify& from);
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

  // optional int32 escortId = 1;
  inline bool has_escortid() const;
  inline void clear_escortid();
  static const int kEscortIdFieldNumber = 1;
  inline ::google::protobuf::int32 escortid() const;
  inline void set_escortid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.ConvoyTimeOutNotify)
 private:
  inline void set_has_escortid();
  inline void clear_has_escortid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 escortid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_Convoy_2eproto();
  friend void protobuf_AssignDesc_Convoy_2eproto();
  friend void protobuf_ShutdownFile_Convoy_2eproto();

  void InitAsDefaultInstance();
  static ConvoyTimeOutNotify* default_instance_;
};
// -------------------------------------------------------------------

class RefreshEscortReq : public ::google::protobuf::Message {
 public:
  RefreshEscortReq();
  virtual ~RefreshEscortReq();

  RefreshEscortReq(const RefreshEscortReq& from);

  inline RefreshEscortReq& operator=(const RefreshEscortReq& from) {
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
  static const RefreshEscortReq& default_instance();

  void Swap(RefreshEscortReq* other);

  // implements Message ----------------------------------------------

  RefreshEscortReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RefreshEscortReq& from);
  void MergeFrom(const RefreshEscortReq& from);
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

  // optional bool onekey = 1;
  inline bool has_onekey() const;
  inline void clear_onekey();
  static const int kOnekeyFieldNumber = 1;
  inline bool onekey() const;
  inline void set_onekey(bool value);

  // @@protoc_insertion_point(class_scope:proto_ff.RefreshEscortReq)
 private:
  inline void set_has_onekey();
  inline void clear_has_onekey();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  bool onekey_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_Convoy_2eproto();
  friend void protobuf_AssignDesc_Convoy_2eproto();
  friend void protobuf_ShutdownFile_Convoy_2eproto();

  void InitAsDefaultInstance();
  static RefreshEscortReq* default_instance_;
};
// -------------------------------------------------------------------

class RefreshEscortRsp : public ::google::protobuf::Message {
 public:
  RefreshEscortRsp();
  virtual ~RefreshEscortRsp();

  RefreshEscortRsp(const RefreshEscortRsp& from);

  inline RefreshEscortRsp& operator=(const RefreshEscortRsp& from) {
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
  static const RefreshEscortRsp& default_instance();

  void Swap(RefreshEscortRsp* other);

  // implements Message ----------------------------------------------

  RefreshEscortRsp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RefreshEscortRsp& from);
  void MergeFrom(const RefreshEscortRsp& from);
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

  // optional int32 genEscortId = 2;
  inline bool has_genescortid() const;
  inline void clear_genescortid();
  static const int kGenEscortIdFieldNumber = 2;
  inline ::google::protobuf::int32 genescortid() const;
  inline void set_genescortid(::google::protobuf::int32 value);

  // optional int32 refreshTimes = 3;
  inline bool has_refreshtimes() const;
  inline void clear_refreshtimes();
  static const int kRefreshTimesFieldNumber = 3;
  inline ::google::protobuf::int32 refreshtimes() const;
  inline void set_refreshtimes(::google::protobuf::int32 value);

  // optional int32 costMoneyCount = 4;
  inline bool has_costmoneycount() const;
  inline void clear_costmoneycount();
  static const int kCostMoneyCountFieldNumber = 4;
  inline ::google::protobuf::int32 costmoneycount() const;
  inline void set_costmoneycount(::google::protobuf::int32 value);

  // optional int32 costItemCount = 5;
  inline bool has_costitemcount() const;
  inline void clear_costitemcount();
  static const int kCostItemCountFieldNumber = 5;
  inline ::google::protobuf::int32 costitemcount() const;
  inline void set_costitemcount(::google::protobuf::int32 value);

  // optional bool onekey = 6;
  inline bool has_onekey() const;
  inline void clear_onekey();
  static const int kOnekeyFieldNumber = 6;
  inline bool onekey() const;
  inline void set_onekey(bool value);

  // @@protoc_insertion_point(class_scope:proto_ff.RefreshEscortRsp)
 private:
  inline void set_has_ret();
  inline void clear_has_ret();
  inline void set_has_genescortid();
  inline void clear_has_genescortid();
  inline void set_has_refreshtimes();
  inline void clear_has_refreshtimes();
  inline void set_has_costmoneycount();
  inline void clear_has_costmoneycount();
  inline void set_has_costitemcount();
  inline void clear_has_costitemcount();
  inline void set_has_onekey();
  inline void clear_has_onekey();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 ret_;
  ::google::protobuf::int32 genescortid_;
  ::google::protobuf::int32 refreshtimes_;
  ::google::protobuf::int32 costmoneycount_;
  ::google::protobuf::int32 costitemcount_;
  bool onekey_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];

  friend void  protobuf_AddDesc_Convoy_2eproto();
  friend void protobuf_AssignDesc_Convoy_2eproto();
  friend void protobuf_ShutdownFile_Convoy_2eproto();

  void InitAsDefaultInstance();
  static RefreshEscortRsp* default_instance_;
};
// ===================================================================


// ===================================================================

// NotifyConvoyInfo

// optional int32 daynum = 1;
inline bool NotifyConvoyInfo::has_daynum() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NotifyConvoyInfo::set_has_daynum() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NotifyConvoyInfo::clear_has_daynum() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NotifyConvoyInfo::clear_daynum() {
  daynum_ = 0;
  clear_has_daynum();
}
inline ::google::protobuf::int32 NotifyConvoyInfo::daynum() const {
  return daynum_;
}
inline void NotifyConvoyInfo::set_daynum(::google::protobuf::int32 value) {
  set_has_daynum();
  daynum_ = value;
}

// optional uint64 endTime = 2;
inline bool NotifyConvoyInfo::has_endtime() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void NotifyConvoyInfo::set_has_endtime() {
  _has_bits_[0] |= 0x00000002u;
}
inline void NotifyConvoyInfo::clear_has_endtime() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void NotifyConvoyInfo::clear_endtime() {
  endtime_ = GOOGLE_ULONGLONG(0);
  clear_has_endtime();
}
inline ::google::protobuf::uint64 NotifyConvoyInfo::endtime() const {
  return endtime_;
}
inline void NotifyConvoyInfo::set_endtime(::google::protobuf::uint64 value) {
  set_has_endtime();
  endtime_ = value;
}

// optional int32 genEscortId = 3;
inline bool NotifyConvoyInfo::has_genescortid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void NotifyConvoyInfo::set_has_genescortid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void NotifyConvoyInfo::clear_has_genescortid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void NotifyConvoyInfo::clear_genescortid() {
  genescortid_ = 0;
  clear_has_genescortid();
}
inline ::google::protobuf::int32 NotifyConvoyInfo::genescortid() const {
  return genescortid_;
}
inline void NotifyConvoyInfo::set_genescortid(::google::protobuf::int32 value) {
  set_has_genescortid();
  genescortid_ = value;
}

// optional int32 freeNum = 4;
inline bool NotifyConvoyInfo::has_freenum() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void NotifyConvoyInfo::set_has_freenum() {
  _has_bits_[0] |= 0x00000008u;
}
inline void NotifyConvoyInfo::clear_has_freenum() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void NotifyConvoyInfo::clear_freenum() {
  freenum_ = 0;
  clear_has_freenum();
}
inline ::google::protobuf::int32 NotifyConvoyInfo::freenum() const {
  return freenum_;
}
inline void NotifyConvoyInfo::set_freenum(::google::protobuf::int32 value) {
  set_has_freenum();
  freenum_ = value;
}

// -------------------------------------------------------------------

// ConvoyAcceptReq

// -------------------------------------------------------------------

// ConvoyAcceptRsp

// optional int32 ret = 1;
inline bool ConvoyAcceptRsp::has_ret() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ConvoyAcceptRsp::set_has_ret() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ConvoyAcceptRsp::clear_has_ret() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ConvoyAcceptRsp::clear_ret() {
  ret_ = 0;
  clear_has_ret();
}
inline ::google::protobuf::int32 ConvoyAcceptRsp::ret() const {
  return ret_;
}
inline void ConvoyAcceptRsp::set_ret(::google::protobuf::int32 value) {
  set_has_ret();
  ret_ = value;
}

// -------------------------------------------------------------------

// NotifyConvoyReward

// optional int64 exp = 1;
inline bool NotifyConvoyReward::has_exp() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NotifyConvoyReward::set_has_exp() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NotifyConvoyReward::clear_has_exp() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NotifyConvoyReward::clear_exp() {
  exp_ = GOOGLE_LONGLONG(0);
  clear_has_exp();
}
inline ::google::protobuf::int64 NotifyConvoyReward::exp() const {
  return exp_;
}
inline void NotifyConvoyReward::set_exp(::google::protobuf::int64 value) {
  set_has_exp();
  exp_ = value;
}

// repeated .proto_ff.ComPair64 items = 2;
inline int NotifyConvoyReward::items_size() const {
  return items_.size();
}
inline void NotifyConvoyReward::clear_items() {
  items_.Clear();
}
inline const ::proto_ff::ComPair64& NotifyConvoyReward::items(int index) const {
  return items_.Get(index);
}
inline ::proto_ff::ComPair64* NotifyConvoyReward::mutable_items(int index) {
  return items_.Mutable(index);
}
inline ::proto_ff::ComPair64* NotifyConvoyReward::add_items() {
  return items_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::ComPair64 >&
NotifyConvoyReward::items() const {
  return items_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::ComPair64 >*
NotifyConvoyReward::mutable_items() {
  return &items_;
}

// -------------------------------------------------------------------

// ConvoyTimeOutNotify

// optional int32 escortId = 1;
inline bool ConvoyTimeOutNotify::has_escortid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ConvoyTimeOutNotify::set_has_escortid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ConvoyTimeOutNotify::clear_has_escortid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ConvoyTimeOutNotify::clear_escortid() {
  escortid_ = 0;
  clear_has_escortid();
}
inline ::google::protobuf::int32 ConvoyTimeOutNotify::escortid() const {
  return escortid_;
}
inline void ConvoyTimeOutNotify::set_escortid(::google::protobuf::int32 value) {
  set_has_escortid();
  escortid_ = value;
}

// -------------------------------------------------------------------

// RefreshEscortReq

// optional bool onekey = 1;
inline bool RefreshEscortReq::has_onekey() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RefreshEscortReq::set_has_onekey() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RefreshEscortReq::clear_has_onekey() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RefreshEscortReq::clear_onekey() {
  onekey_ = false;
  clear_has_onekey();
}
inline bool RefreshEscortReq::onekey() const {
  return onekey_;
}
inline void RefreshEscortReq::set_onekey(bool value) {
  set_has_onekey();
  onekey_ = value;
}

// -------------------------------------------------------------------

// RefreshEscortRsp

// optional int32 ret = 1;
inline bool RefreshEscortRsp::has_ret() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RefreshEscortRsp::set_has_ret() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RefreshEscortRsp::clear_has_ret() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RefreshEscortRsp::clear_ret() {
  ret_ = 0;
  clear_has_ret();
}
inline ::google::protobuf::int32 RefreshEscortRsp::ret() const {
  return ret_;
}
inline void RefreshEscortRsp::set_ret(::google::protobuf::int32 value) {
  set_has_ret();
  ret_ = value;
}

// optional int32 genEscortId = 2;
inline bool RefreshEscortRsp::has_genescortid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RefreshEscortRsp::set_has_genescortid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RefreshEscortRsp::clear_has_genescortid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RefreshEscortRsp::clear_genescortid() {
  genescortid_ = 0;
  clear_has_genescortid();
}
inline ::google::protobuf::int32 RefreshEscortRsp::genescortid() const {
  return genescortid_;
}
inline void RefreshEscortRsp::set_genescortid(::google::protobuf::int32 value) {
  set_has_genescortid();
  genescortid_ = value;
}

// optional int32 refreshTimes = 3;
inline bool RefreshEscortRsp::has_refreshtimes() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RefreshEscortRsp::set_has_refreshtimes() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RefreshEscortRsp::clear_has_refreshtimes() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RefreshEscortRsp::clear_refreshtimes() {
  refreshtimes_ = 0;
  clear_has_refreshtimes();
}
inline ::google::protobuf::int32 RefreshEscortRsp::refreshtimes() const {
  return refreshtimes_;
}
inline void RefreshEscortRsp::set_refreshtimes(::google::protobuf::int32 value) {
  set_has_refreshtimes();
  refreshtimes_ = value;
}

// optional int32 costMoneyCount = 4;
inline bool RefreshEscortRsp::has_costmoneycount() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void RefreshEscortRsp::set_has_costmoneycount() {
  _has_bits_[0] |= 0x00000008u;
}
inline void RefreshEscortRsp::clear_has_costmoneycount() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void RefreshEscortRsp::clear_costmoneycount() {
  costmoneycount_ = 0;
  clear_has_costmoneycount();
}
inline ::google::protobuf::int32 RefreshEscortRsp::costmoneycount() const {
  return costmoneycount_;
}
inline void RefreshEscortRsp::set_costmoneycount(::google::protobuf::int32 value) {
  set_has_costmoneycount();
  costmoneycount_ = value;
}

// optional int32 costItemCount = 5;
inline bool RefreshEscortRsp::has_costitemcount() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void RefreshEscortRsp::set_has_costitemcount() {
  _has_bits_[0] |= 0x00000010u;
}
inline void RefreshEscortRsp::clear_has_costitemcount() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void RefreshEscortRsp::clear_costitemcount() {
  costitemcount_ = 0;
  clear_has_costitemcount();
}
inline ::google::protobuf::int32 RefreshEscortRsp::costitemcount() const {
  return costitemcount_;
}
inline void RefreshEscortRsp::set_costitemcount(::google::protobuf::int32 value) {
  set_has_costitemcount();
  costitemcount_ = value;
}

// optional bool onekey = 6;
inline bool RefreshEscortRsp::has_onekey() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void RefreshEscortRsp::set_has_onekey() {
  _has_bits_[0] |= 0x00000020u;
}
inline void RefreshEscortRsp::clear_has_onekey() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void RefreshEscortRsp::clear_onekey() {
  onekey_ = false;
  clear_has_onekey();
}
inline bool RefreshEscortRsp::onekey() const {
  return onekey_;
}
inline void RefreshEscortRsp::set_onekey(bool value) {
  set_has_onekey();
  onekey_ = value;
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

#endif  // PROTOBUF_Convoy_2eproto__INCLUDED
