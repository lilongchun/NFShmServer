// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Tasktracker.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "E_Tasktracker.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto_ff {

namespace {

const ::google::protobuf::Descriptor* E_TasktrackerTasktracker_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  E_TasktrackerTasktracker_reflection_ = NULL;
const ::google::protobuf::Descriptor* Sheet_TasktrackerTasktracker_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Sheet_TasktrackerTasktracker_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_E_5fTasktracker_2eproto() {
  protobuf_AddDesc_E_5fTasktracker_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "E_Tasktracker.proto");
  GOOGLE_CHECK(file != NULL);
  E_TasktrackerTasktracker_descriptor_ = file->message_type(0);
  static const int E_TasktrackerTasktracker_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_TasktrackerTasktracker, m_comid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_TasktrackerTasktracker, m_trueid_),
  };
  E_TasktrackerTasktracker_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      E_TasktrackerTasktracker_descriptor_,
      E_TasktrackerTasktracker::default_instance_,
      E_TasktrackerTasktracker_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_TasktrackerTasktracker, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_TasktrackerTasktracker, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(E_TasktrackerTasktracker));
  Sheet_TasktrackerTasktracker_descriptor_ = file->message_type(1);
  static const int Sheet_TasktrackerTasktracker_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_TasktrackerTasktracker, e_tasktrackertasktracker_list_),
  };
  Sheet_TasktrackerTasktracker_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Sheet_TasktrackerTasktracker_descriptor_,
      Sheet_TasktrackerTasktracker::default_instance_,
      Sheet_TasktrackerTasktracker_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_TasktrackerTasktracker, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_TasktrackerTasktracker, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Sheet_TasktrackerTasktracker));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_E_5fTasktracker_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    E_TasktrackerTasktracker_descriptor_, &E_TasktrackerTasktracker::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Sheet_TasktrackerTasktracker_descriptor_, &Sheet_TasktrackerTasktracker::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_E_5fTasktracker_2eproto() {
  delete E_TasktrackerTasktracker::default_instance_;
  delete E_TasktrackerTasktracker_reflection_;
  delete Sheet_TasktrackerTasktracker::default_instance_;
  delete Sheet_TasktrackerTasktracker_reflection_;
}

void protobuf_AddDesc_E_5fTasktracker_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023E_Tasktracker.proto\022\010proto_ff\032\025yd_fiel"
    "doptions.proto\"w\n\030E_TasktrackerTasktrack"
    "er\022)\n\007m_comid\030\001 \001(\005B\030\302\377\024\024\345\256\214\346\210\220\346\235\241\344\273\266\347\261\273"
    "\345\236\213ID\0220\n\010m_trueid\030\002 \001(\005B\036\302\377\024\032\345\256\236\351\231\205\345\256\214\346\210"
    "\220\346\235\241\344\273\266\347\261\273\345\236\213ID\"o\n\034Sheet_TasktrackerTask"
    "tracker\022O\n\035E_TasktrackerTasktracker_List"
    "\030\001 \003(\0132\".proto_ff.E_TasktrackerTasktrack"
    "erB\004\210\301\024@", 288);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "E_Tasktracker.proto", &protobuf_RegisterTypes);
  E_TasktrackerTasktracker::default_instance_ = new E_TasktrackerTasktracker();
  Sheet_TasktrackerTasktracker::default_instance_ = new Sheet_TasktrackerTasktracker();
  E_TasktrackerTasktracker::default_instance_->InitAsDefaultInstance();
  Sheet_TasktrackerTasktracker::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_E_5fTasktracker_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_E_5fTasktracker_2eproto {
  StaticDescriptorInitializer_E_5fTasktracker_2eproto() {
    protobuf_AddDesc_E_5fTasktracker_2eproto();
  }
} static_descriptor_initializer_E_5fTasktracker_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int E_TasktrackerTasktracker::kMComidFieldNumber;
const int E_TasktrackerTasktracker::kMTrueidFieldNumber;
#endif  // !_MSC_VER

E_TasktrackerTasktracker::E_TasktrackerTasktracker()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void E_TasktrackerTasktracker::InitAsDefaultInstance() {
}

E_TasktrackerTasktracker::E_TasktrackerTasktracker(const E_TasktrackerTasktracker& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void E_TasktrackerTasktracker::SharedCtor() {
  _cached_size_ = 0;
  m_comid_ = 0;
  m_trueid_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

E_TasktrackerTasktracker::~E_TasktrackerTasktracker() {
  SharedDtor();
}

void E_TasktrackerTasktracker::SharedDtor() {
  if (this != default_instance_) {
  }
}

void E_TasktrackerTasktracker::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* E_TasktrackerTasktracker::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return E_TasktrackerTasktracker_descriptor_;
}

const E_TasktrackerTasktracker& E_TasktrackerTasktracker::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_E_5fTasktracker_2eproto();
  return *default_instance_;
}

E_TasktrackerTasktracker* E_TasktrackerTasktracker::default_instance_ = NULL;

E_TasktrackerTasktracker* E_TasktrackerTasktracker::New() const {
  return new E_TasktrackerTasktracker;
}

void E_TasktrackerTasktracker::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    m_comid_ = 0;
    m_trueid_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool E_TasktrackerTasktracker::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 m_comid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &m_comid_)));
          set_has_m_comid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_m_trueid;
        break;
      }

      // optional int32 m_trueid = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_m_trueid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &m_trueid_)));
          set_has_m_trueid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void E_TasktrackerTasktracker::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 m_comid = 1;
  if (has_m_comid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->m_comid(), output);
  }

  // optional int32 m_trueid = 2;
  if (has_m_trueid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->m_trueid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* E_TasktrackerTasktracker::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 m_comid = 1;
  if (has_m_comid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->m_comid(), target);
  }

  // optional int32 m_trueid = 2;
  if (has_m_trueid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->m_trueid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int E_TasktrackerTasktracker::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 m_comid = 1;
    if (has_m_comid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->m_comid());
    }

    // optional int32 m_trueid = 2;
    if (has_m_trueid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->m_trueid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void E_TasktrackerTasktracker::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const E_TasktrackerTasktracker* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const E_TasktrackerTasktracker*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void E_TasktrackerTasktracker::MergeFrom(const E_TasktrackerTasktracker& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_m_comid()) {
      set_m_comid(from.m_comid());
    }
    if (from.has_m_trueid()) {
      set_m_trueid(from.m_trueid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void E_TasktrackerTasktracker::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void E_TasktrackerTasktracker::CopyFrom(const E_TasktrackerTasktracker& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool E_TasktrackerTasktracker::IsInitialized() const {

  return true;
}

void E_TasktrackerTasktracker::Swap(E_TasktrackerTasktracker* other) {
  if (other != this) {
    std::swap(m_comid_, other->m_comid_);
    std::swap(m_trueid_, other->m_trueid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata E_TasktrackerTasktracker::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = E_TasktrackerTasktracker_descriptor_;
  metadata.reflection = E_TasktrackerTasktracker_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Sheet_TasktrackerTasktracker::kETasktrackerTasktrackerListFieldNumber;
#endif  // !_MSC_VER

Sheet_TasktrackerTasktracker::Sheet_TasktrackerTasktracker()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Sheet_TasktrackerTasktracker::InitAsDefaultInstance() {
}

Sheet_TasktrackerTasktracker::Sheet_TasktrackerTasktracker(const Sheet_TasktrackerTasktracker& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Sheet_TasktrackerTasktracker::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Sheet_TasktrackerTasktracker::~Sheet_TasktrackerTasktracker() {
  SharedDtor();
}

void Sheet_TasktrackerTasktracker::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Sheet_TasktrackerTasktracker::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Sheet_TasktrackerTasktracker::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Sheet_TasktrackerTasktracker_descriptor_;
}

const Sheet_TasktrackerTasktracker& Sheet_TasktrackerTasktracker::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_E_5fTasktracker_2eproto();
  return *default_instance_;
}

Sheet_TasktrackerTasktracker* Sheet_TasktrackerTasktracker::default_instance_ = NULL;

Sheet_TasktrackerTasktracker* Sheet_TasktrackerTasktracker::New() const {
  return new Sheet_TasktrackerTasktracker;
}

void Sheet_TasktrackerTasktracker::Clear() {
  e_tasktrackertasktracker_list_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Sheet_TasktrackerTasktracker::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .proto_ff.E_TasktrackerTasktracker E_TasktrackerTasktracker_List = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_E_TasktrackerTasktracker_List:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_e_tasktrackertasktracker_list()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_E_TasktrackerTasktracker_List;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Sheet_TasktrackerTasktracker::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .proto_ff.E_TasktrackerTasktracker E_TasktrackerTasktracker_List = 1;
  for (int i = 0; i < this->e_tasktrackertasktracker_list_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->e_tasktrackertasktracker_list(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Sheet_TasktrackerTasktracker::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .proto_ff.E_TasktrackerTasktracker E_TasktrackerTasktracker_List = 1;
  for (int i = 0; i < this->e_tasktrackertasktracker_list_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->e_tasktrackertasktracker_list(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Sheet_TasktrackerTasktracker::ByteSize() const {
  int total_size = 0;

  // repeated .proto_ff.E_TasktrackerTasktracker E_TasktrackerTasktracker_List = 1;
  total_size += 1 * this->e_tasktrackertasktracker_list_size();
  for (int i = 0; i < this->e_tasktrackertasktracker_list_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->e_tasktrackertasktracker_list(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Sheet_TasktrackerTasktracker::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Sheet_TasktrackerTasktracker* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Sheet_TasktrackerTasktracker*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Sheet_TasktrackerTasktracker::MergeFrom(const Sheet_TasktrackerTasktracker& from) {
  GOOGLE_CHECK_NE(&from, this);
  e_tasktrackertasktracker_list_.MergeFrom(from.e_tasktrackertasktracker_list_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Sheet_TasktrackerTasktracker::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Sheet_TasktrackerTasktracker::CopyFrom(const Sheet_TasktrackerTasktracker& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Sheet_TasktrackerTasktracker::IsInitialized() const {

  return true;
}

void Sheet_TasktrackerTasktracker::Swap(Sheet_TasktrackerTasktracker* other) {
  if (other != this) {
    e_tasktrackertasktracker_list_.Swap(&other->e_tasktrackertasktracker_list_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Sheet_TasktrackerTasktracker::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Sheet_TasktrackerTasktracker_descriptor_;
  metadata.reflection = Sheet_TasktrackerTasktracker_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)