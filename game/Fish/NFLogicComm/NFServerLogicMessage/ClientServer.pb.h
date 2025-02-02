// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ClientServer.proto

#ifndef PROTOBUF_ClientServer_2eproto__INCLUDED
#define PROTOBUF_ClientServer_2eproto__INCLUDED

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
#include "Com.pb.h"
// @@protoc_insertion_point(includes)

namespace proto_ff {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ClientServer_2eproto();
void protobuf_AssignDesc_ClientServer_2eproto();
void protobuf_ShutdownFile_ClientServer_2eproto();

class Proto_CSErrorRsp;

// ===================================================================

class Proto_CSErrorRsp : public ::google::protobuf::Message {
 public:
  Proto_CSErrorRsp();
  virtual ~Proto_CSErrorRsp();

  Proto_CSErrorRsp(const Proto_CSErrorRsp& from);

  inline Proto_CSErrorRsp& operator=(const Proto_CSErrorRsp& from) {
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
  static const Proto_CSErrorRsp& default_instance();

  void Swap(Proto_CSErrorRsp* other);

  // implements Message ----------------------------------------------

  Proto_CSErrorRsp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Proto_CSErrorRsp& from);
  void MergeFrom(const Proto_CSErrorRsp& from);
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

  // optional uint64 user_id = 1;
  inline bool has_user_id() const;
  inline void clear_user_id();
  static const int kUserIdFieldNumber = 1;
  inline ::google::protobuf::uint64 user_id() const;
  inline void set_user_id(::google::protobuf::uint64 value);

  // optional uint32 req_msg_id = 2;
  inline bool has_req_msg_id() const;
  inline void clear_req_msg_id();
  static const int kReqMsgIdFieldNumber = 2;
  inline ::google::protobuf::uint32 req_msg_id() const;
  inline void set_req_msg_id(::google::protobuf::uint32 value);

  // optional int32 error = 3;
  inline bool has_error() const;
  inline void clear_error();
  static const int kErrorFieldNumber = 3;
  inline ::google::protobuf::int32 error() const;
  inline void set_error(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.Proto_CSErrorRsp)
 private:
  inline void set_has_user_id();
  inline void clear_has_user_id();
  inline void set_has_req_msg_id();
  inline void clear_has_req_msg_id();
  inline void set_has_error();
  inline void clear_has_error();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint64 user_id_;
  ::google::protobuf::uint32 req_msg_id_;
  ::google::protobuf::int32 error_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_ClientServer_2eproto();
  friend void protobuf_AssignDesc_ClientServer_2eproto();
  friend void protobuf_ShutdownFile_ClientServer_2eproto();

  void InitAsDefaultInstance();
  static Proto_CSErrorRsp* default_instance_;
};
// ===================================================================


// ===================================================================

// Proto_CSErrorRsp

// optional uint64 user_id = 1;
inline bool Proto_CSErrorRsp::has_user_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Proto_CSErrorRsp::set_has_user_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Proto_CSErrorRsp::clear_has_user_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Proto_CSErrorRsp::clear_user_id() {
  user_id_ = GOOGLE_ULONGLONG(0);
  clear_has_user_id();
}
inline ::google::protobuf::uint64 Proto_CSErrorRsp::user_id() const {
  return user_id_;
}
inline void Proto_CSErrorRsp::set_user_id(::google::protobuf::uint64 value) {
  set_has_user_id();
  user_id_ = value;
}

// optional uint32 req_msg_id = 2;
inline bool Proto_CSErrorRsp::has_req_msg_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Proto_CSErrorRsp::set_has_req_msg_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Proto_CSErrorRsp::clear_has_req_msg_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Proto_CSErrorRsp::clear_req_msg_id() {
  req_msg_id_ = 0u;
  clear_has_req_msg_id();
}
inline ::google::protobuf::uint32 Proto_CSErrorRsp::req_msg_id() const {
  return req_msg_id_;
}
inline void Proto_CSErrorRsp::set_req_msg_id(::google::protobuf::uint32 value) {
  set_has_req_msg_id();
  req_msg_id_ = value;
}

// optional int32 error = 3;
inline bool Proto_CSErrorRsp::has_error() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Proto_CSErrorRsp::set_has_error() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Proto_CSErrorRsp::clear_has_error() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Proto_CSErrorRsp::clear_error() {
  error_ = 0;
  clear_has_error();
}
inline ::google::protobuf::int32 Proto_CSErrorRsp::error() const {
  return error_;
}
inline void Proto_CSErrorRsp::set_error(::google::protobuf::int32 value) {
  set_has_error();
  error_ = value;
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

#endif  // PROTOBUF_ClientServer_2eproto__INCLUDED
