// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto_svr_common.proto

#ifndef PROTOBUF_proto_5fsvr_5fcommon_2eproto__INCLUDED
#define PROTOBUF_proto_5fsvr_5fcommon_2eproto__INCLUDED

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
void  protobuf_AddDesc_proto_5fsvr_5fcommon_2eproto();
void protobuf_AssignDesc_proto_5fsvr_5fcommon_2eproto();
void protobuf_ShutdownFile_proto_5fsvr_5fcommon_2eproto();

class emailSender;
class PacketMsg;
class ServerPacketMsg;

// ===================================================================

class emailSender : public ::google::protobuf::Message {
 public:
  emailSender();
  virtual ~emailSender();

  emailSender(const emailSender& from);

  inline emailSender& operator=(const emailSender& from) {
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
  static const emailSender& default_instance();

  void Swap(emailSender* other);

  // implements Message ----------------------------------------------

  emailSender* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const emailSender& from);
  void MergeFrom(const emailSender& from);
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

  // optional string email = 1;
  inline bool has_email() const;
  inline void clear_email();
  static const int kEmailFieldNumber = 1;
  inline const ::std::string& email() const;
  inline void set_email(const ::std::string& value);
  inline void set_email(const char* value);
  inline void set_email(const char* value, size_t size);
  inline ::std::string* mutable_email();
  inline ::std::string* release_email();
  inline void set_allocated_email(::std::string* email);

  // optional string title = 2;
  inline bool has_title() const;
  inline void clear_title();
  static const int kTitleFieldNumber = 2;
  inline const ::std::string& title() const;
  inline void set_title(const ::std::string& value);
  inline void set_title(const char* value);
  inline void set_title(const char* value, size_t size);
  inline ::std::string* mutable_title();
  inline ::std::string* release_title();
  inline void set_allocated_title(::std::string* title);

  // optional string msg = 3;
  inline bool has_msg() const;
  inline void clear_msg();
  static const int kMsgFieldNumber = 3;
  inline const ::std::string& msg() const;
  inline void set_msg(const ::std::string& value);
  inline void set_msg(const char* value);
  inline void set_msg(const char* value, size_t size);
  inline ::std::string* mutable_msg();
  inline ::std::string* release_msg();
  inline void set_allocated_msg(::std::string* msg);

  // @@protoc_insertion_point(class_scope:proto_ff.emailSender)
 private:
  inline void set_has_email();
  inline void clear_has_email();
  inline void set_has_title();
  inline void clear_has_title();
  inline void set_has_msg();
  inline void clear_has_msg();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* email_;
  ::std::string* title_;
  ::std::string* msg_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_proto_5fsvr_5fcommon_2eproto();
  friend void protobuf_AssignDesc_proto_5fsvr_5fcommon_2eproto();
  friend void protobuf_ShutdownFile_proto_5fsvr_5fcommon_2eproto();

  void InitAsDefaultInstance();
  static emailSender* default_instance_;
};
// -------------------------------------------------------------------

class PacketMsg : public ::google::protobuf::Message {
 public:
  PacketMsg();
  virtual ~PacketMsg();

  PacketMsg(const PacketMsg& from);

  inline PacketMsg& operator=(const PacketMsg& from) {
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
  static const PacketMsg& default_instance();

  void Swap(PacketMsg* other);

  // implements Message ----------------------------------------------

  PacketMsg* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PacketMsg& from);
  void MergeFrom(const PacketMsg& from);
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

  // optional uint32 cmd = 1;
  inline bool has_cmd() const;
  inline void clear_cmd();
  static const int kCmdFieldNumber = 1;
  inline ::google::protobuf::uint32 cmd() const;
  inline void set_cmd(::google::protobuf::uint32 value);

  // optional uint32 serverType = 2;
  inline bool has_servertype() const;
  inline void clear_servertype();
  static const int kServerTypeFieldNumber = 2;
  inline ::google::protobuf::uint32 servertype() const;
  inline void set_servertype(::google::protobuf::uint32 value);

  // optional uint32 upper_limit = 3;
  inline bool has_upper_limit() const;
  inline void clear_upper_limit();
  static const int kUpperLimitFieldNumber = 3;
  inline ::google::protobuf::uint32 upper_limit() const;
  inline void set_upper_limit(::google::protobuf::uint32 value);

  // optional uint32 min_interval = 4;
  inline bool has_min_interval() const;
  inline void clear_min_interval();
  static const int kMinIntervalFieldNumber = 4;
  inline ::google::protobuf::uint32 min_interval() const;
  inline void set_min_interval(::google::protobuf::uint32 value);

  // optional uint32 control_time = 5;
  inline bool has_control_time() const;
  inline void clear_control_time();
  static const int kControlTimeFieldNumber = 5;
  inline ::google::protobuf::uint32 control_time() const;
  inline void set_control_time(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.PacketMsg)
 private:
  inline void set_has_cmd();
  inline void clear_has_cmd();
  inline void set_has_servertype();
  inline void clear_has_servertype();
  inline void set_has_upper_limit();
  inline void clear_has_upper_limit();
  inline void set_has_min_interval();
  inline void clear_has_min_interval();
  inline void set_has_control_time();
  inline void clear_has_control_time();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 cmd_;
  ::google::protobuf::uint32 servertype_;
  ::google::protobuf::uint32 upper_limit_;
  ::google::protobuf::uint32 min_interval_;
  ::google::protobuf::uint32 control_time_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_proto_5fsvr_5fcommon_2eproto();
  friend void protobuf_AssignDesc_proto_5fsvr_5fcommon_2eproto();
  friend void protobuf_ShutdownFile_proto_5fsvr_5fcommon_2eproto();

  void InitAsDefaultInstance();
  static PacketMsg* default_instance_;
};
// -------------------------------------------------------------------

class ServerPacketMsg : public ::google::protobuf::Message {
 public:
  ServerPacketMsg();
  virtual ~ServerPacketMsg();

  ServerPacketMsg(const ServerPacketMsg& from);

  inline ServerPacketMsg& operator=(const ServerPacketMsg& from) {
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
  static const ServerPacketMsg& default_instance();

  void Swap(ServerPacketMsg* other);

  // implements Message ----------------------------------------------

  ServerPacketMsg* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ServerPacketMsg& from);
  void MergeFrom(const ServerPacketMsg& from);
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

  // repeated .proto_ff.PacketMsg PacketMsg = 1;
  inline int packetmsg_size() const;
  inline void clear_packetmsg();
  static const int kPacketMsgFieldNumber = 1;
  inline const ::proto_ff::PacketMsg& packetmsg(int index) const;
  inline ::proto_ff::PacketMsg* mutable_packetmsg(int index);
  inline ::proto_ff::PacketMsg* add_packetmsg();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::PacketMsg >&
      packetmsg() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::PacketMsg >*
      mutable_packetmsg();

  // @@protoc_insertion_point(class_scope:proto_ff.ServerPacketMsg)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::PacketMsg > packetmsg_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_proto_5fsvr_5fcommon_2eproto();
  friend void protobuf_AssignDesc_proto_5fsvr_5fcommon_2eproto();
  friend void protobuf_ShutdownFile_proto_5fsvr_5fcommon_2eproto();

  void InitAsDefaultInstance();
  static ServerPacketMsg* default_instance_;
};
// ===================================================================


// ===================================================================

// emailSender

// optional string email = 1;
inline bool emailSender::has_email() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void emailSender::set_has_email() {
  _has_bits_[0] |= 0x00000001u;
}
inline void emailSender::clear_has_email() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void emailSender::clear_email() {
  if (email_ != &::google::protobuf::internal::kEmptyString) {
    email_->clear();
  }
  clear_has_email();
}
inline const ::std::string& emailSender::email() const {
  return *email_;
}
inline void emailSender::set_email(const ::std::string& value) {
  set_has_email();
  if (email_ == &::google::protobuf::internal::kEmptyString) {
    email_ = new ::std::string;
  }
  email_->assign(value);
}
inline void emailSender::set_email(const char* value) {
  set_has_email();
  if (email_ == &::google::protobuf::internal::kEmptyString) {
    email_ = new ::std::string;
  }
  email_->assign(value);
}
inline void emailSender::set_email(const char* value, size_t size) {
  set_has_email();
  if (email_ == &::google::protobuf::internal::kEmptyString) {
    email_ = new ::std::string;
  }
  email_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* emailSender::mutable_email() {
  set_has_email();
  if (email_ == &::google::protobuf::internal::kEmptyString) {
    email_ = new ::std::string;
  }
  return email_;
}
inline ::std::string* emailSender::release_email() {
  clear_has_email();
  if (email_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = email_;
    email_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void emailSender::set_allocated_email(::std::string* email) {
  if (email_ != &::google::protobuf::internal::kEmptyString) {
    delete email_;
  }
  if (email) {
    set_has_email();
    email_ = email;
  } else {
    clear_has_email();
    email_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string title = 2;
inline bool emailSender::has_title() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void emailSender::set_has_title() {
  _has_bits_[0] |= 0x00000002u;
}
inline void emailSender::clear_has_title() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void emailSender::clear_title() {
  if (title_ != &::google::protobuf::internal::kEmptyString) {
    title_->clear();
  }
  clear_has_title();
}
inline const ::std::string& emailSender::title() const {
  return *title_;
}
inline void emailSender::set_title(const ::std::string& value) {
  set_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    title_ = new ::std::string;
  }
  title_->assign(value);
}
inline void emailSender::set_title(const char* value) {
  set_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    title_ = new ::std::string;
  }
  title_->assign(value);
}
inline void emailSender::set_title(const char* value, size_t size) {
  set_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    title_ = new ::std::string;
  }
  title_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* emailSender::mutable_title() {
  set_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    title_ = new ::std::string;
  }
  return title_;
}
inline ::std::string* emailSender::release_title() {
  clear_has_title();
  if (title_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = title_;
    title_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void emailSender::set_allocated_title(::std::string* title) {
  if (title_ != &::google::protobuf::internal::kEmptyString) {
    delete title_;
  }
  if (title) {
    set_has_title();
    title_ = title;
  } else {
    clear_has_title();
    title_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string msg = 3;
inline bool emailSender::has_msg() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void emailSender::set_has_msg() {
  _has_bits_[0] |= 0x00000004u;
}
inline void emailSender::clear_has_msg() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void emailSender::clear_msg() {
  if (msg_ != &::google::protobuf::internal::kEmptyString) {
    msg_->clear();
  }
  clear_has_msg();
}
inline const ::std::string& emailSender::msg() const {
  return *msg_;
}
inline void emailSender::set_msg(const ::std::string& value) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  msg_->assign(value);
}
inline void emailSender::set_msg(const char* value) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  msg_->assign(value);
}
inline void emailSender::set_msg(const char* value, size_t size) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  msg_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* emailSender::mutable_msg() {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    msg_ = new ::std::string;
  }
  return msg_;
}
inline ::std::string* emailSender::release_msg() {
  clear_has_msg();
  if (msg_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = msg_;
    msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void emailSender::set_allocated_msg(::std::string* msg) {
  if (msg_ != &::google::protobuf::internal::kEmptyString) {
    delete msg_;
  }
  if (msg) {
    set_has_msg();
    msg_ = msg;
  } else {
    clear_has_msg();
    msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// PacketMsg

// optional uint32 cmd = 1;
inline bool PacketMsg::has_cmd() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PacketMsg::set_has_cmd() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PacketMsg::clear_has_cmd() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PacketMsg::clear_cmd() {
  cmd_ = 0u;
  clear_has_cmd();
}
inline ::google::protobuf::uint32 PacketMsg::cmd() const {
  return cmd_;
}
inline void PacketMsg::set_cmd(::google::protobuf::uint32 value) {
  set_has_cmd();
  cmd_ = value;
}

// optional uint32 serverType = 2;
inline bool PacketMsg::has_servertype() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PacketMsg::set_has_servertype() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PacketMsg::clear_has_servertype() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PacketMsg::clear_servertype() {
  servertype_ = 0u;
  clear_has_servertype();
}
inline ::google::protobuf::uint32 PacketMsg::servertype() const {
  return servertype_;
}
inline void PacketMsg::set_servertype(::google::protobuf::uint32 value) {
  set_has_servertype();
  servertype_ = value;
}

// optional uint32 upper_limit = 3;
inline bool PacketMsg::has_upper_limit() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PacketMsg::set_has_upper_limit() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PacketMsg::clear_has_upper_limit() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PacketMsg::clear_upper_limit() {
  upper_limit_ = 0u;
  clear_has_upper_limit();
}
inline ::google::protobuf::uint32 PacketMsg::upper_limit() const {
  return upper_limit_;
}
inline void PacketMsg::set_upper_limit(::google::protobuf::uint32 value) {
  set_has_upper_limit();
  upper_limit_ = value;
}

// optional uint32 min_interval = 4;
inline bool PacketMsg::has_min_interval() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void PacketMsg::set_has_min_interval() {
  _has_bits_[0] |= 0x00000008u;
}
inline void PacketMsg::clear_has_min_interval() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void PacketMsg::clear_min_interval() {
  min_interval_ = 0u;
  clear_has_min_interval();
}
inline ::google::protobuf::uint32 PacketMsg::min_interval() const {
  return min_interval_;
}
inline void PacketMsg::set_min_interval(::google::protobuf::uint32 value) {
  set_has_min_interval();
  min_interval_ = value;
}

// optional uint32 control_time = 5;
inline bool PacketMsg::has_control_time() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void PacketMsg::set_has_control_time() {
  _has_bits_[0] |= 0x00000010u;
}
inline void PacketMsg::clear_has_control_time() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void PacketMsg::clear_control_time() {
  control_time_ = 0u;
  clear_has_control_time();
}
inline ::google::protobuf::uint32 PacketMsg::control_time() const {
  return control_time_;
}
inline void PacketMsg::set_control_time(::google::protobuf::uint32 value) {
  set_has_control_time();
  control_time_ = value;
}

// -------------------------------------------------------------------

// ServerPacketMsg

// repeated .proto_ff.PacketMsg PacketMsg = 1;
inline int ServerPacketMsg::packetmsg_size() const {
  return packetmsg_.size();
}
inline void ServerPacketMsg::clear_packetmsg() {
  packetmsg_.Clear();
}
inline const ::proto_ff::PacketMsg& ServerPacketMsg::packetmsg(int index) const {
  return packetmsg_.Get(index);
}
inline ::proto_ff::PacketMsg* ServerPacketMsg::mutable_packetmsg(int index) {
  return packetmsg_.Mutable(index);
}
inline ::proto_ff::PacketMsg* ServerPacketMsg::add_packetmsg() {
  return packetmsg_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::PacketMsg >&
ServerPacketMsg::packetmsg() const {
  return packetmsg_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::PacketMsg >*
ServerPacketMsg::mutable_packetmsg() {
  return &packetmsg_;
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

#endif  // PROTOBUF_proto_5fsvr_5fcommon_2eproto__INCLUDED
