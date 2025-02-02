// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: E_Area.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "E_Area.pb.h"

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

const ::google::protobuf::Descriptor* E_AreaArea_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  E_AreaArea_reflection_ = NULL;
const ::google::protobuf::Descriptor* Sheet_AreaArea_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Sheet_AreaArea_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_E_5fArea_2eproto() {
  protobuf_AddDesc_E_5fArea_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "E_Area.proto");
  GOOGLE_CHECK(file != NULL);
  E_AreaArea_descriptor_ = file->message_type(0);
  static const int E_AreaArea_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_AreaArea, m_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_AreaArea, m_subtype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_AreaArea, m_belongtosceneid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_AreaArea, m_shapetype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_AreaArea, m_isnotice_),
  };
  E_AreaArea_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      E_AreaArea_descriptor_,
      E_AreaArea::default_instance_,
      E_AreaArea_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_AreaArea, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(E_AreaArea, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(E_AreaArea));
  Sheet_AreaArea_descriptor_ = file->message_type(1);
  static const int Sheet_AreaArea_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_AreaArea, e_areaarea_list_),
  };
  Sheet_AreaArea_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Sheet_AreaArea_descriptor_,
      Sheet_AreaArea::default_instance_,
      Sheet_AreaArea_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_AreaArea, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Sheet_AreaArea, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Sheet_AreaArea));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_E_5fArea_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    E_AreaArea_descriptor_, &E_AreaArea::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Sheet_AreaArea_descriptor_, &Sheet_AreaArea::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_E_5fArea_2eproto() {
  delete E_AreaArea::default_instance_;
  delete E_AreaArea_reflection_;
  delete Sheet_AreaArea::default_instance_;
  delete Sheet_AreaArea_reflection_;
}

void protobuf_AddDesc_E_5fArea_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::yd_fieldoptions::protobuf_AddDesc_yd_5ffieldoptions_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014E_Area.proto\022\010proto_ff\032\025yd_fieldoption"
    "s.proto\"\315\001\n\nE_AreaArea\022\032\n\004m_id\030\001 \001(\003B\014\302\377"
    "\024\010\345\214\272\345\237\237ID\022#\n\tm_subType\030\002 \001(\005B\020\302\377\024\014\347\273\206\345\210"
    "\206\347\261\273\345\236\213\022+\n\021m_belongToSceneID\030\003 \001(\003B\020\302\377\024\014"
    "\346\211\200\345\261\236\345\234\272\346\231\257\022%\n\013m_shapeType\030\004 \001(\005B\020\302\377\024\014\345"
    "\275\242\347\212\266\347\261\273\345\236\213\022*\n\nm_isNotice\030\005 \001(\005B\026\302\377\024\022\346\230\257"
    "\345\220\246\350\277\233\345\207\272\346\217\220\347\244\272\"E\n\016Sheet_AreaArea\0223\n\017E_A"
    "reaArea_List\030\001 \003(\0132\024.proto_ff.E_AreaArea"
    "B\004\210\301\024 ", 326);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "E_Area.proto", &protobuf_RegisterTypes);
  E_AreaArea::default_instance_ = new E_AreaArea();
  Sheet_AreaArea::default_instance_ = new Sheet_AreaArea();
  E_AreaArea::default_instance_->InitAsDefaultInstance();
  Sheet_AreaArea::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_E_5fArea_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_E_5fArea_2eproto {
  StaticDescriptorInitializer_E_5fArea_2eproto() {
    protobuf_AddDesc_E_5fArea_2eproto();
  }
} static_descriptor_initializer_E_5fArea_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int E_AreaArea::kMIdFieldNumber;
const int E_AreaArea::kMSubTypeFieldNumber;
const int E_AreaArea::kMBelongToSceneIDFieldNumber;
const int E_AreaArea::kMShapeTypeFieldNumber;
const int E_AreaArea::kMIsNoticeFieldNumber;
#endif  // !_MSC_VER

E_AreaArea::E_AreaArea()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void E_AreaArea::InitAsDefaultInstance() {
}

E_AreaArea::E_AreaArea(const E_AreaArea& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void E_AreaArea::SharedCtor() {
  _cached_size_ = 0;
  m_id_ = GOOGLE_LONGLONG(0);
  m_subtype_ = 0;
  m_belongtosceneid_ = GOOGLE_LONGLONG(0);
  m_shapetype_ = 0;
  m_isnotice_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

E_AreaArea::~E_AreaArea() {
  SharedDtor();
}

void E_AreaArea::SharedDtor() {
  if (this != default_instance_) {
  }
}

void E_AreaArea::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* E_AreaArea::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return E_AreaArea_descriptor_;
}

const E_AreaArea& E_AreaArea::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_E_5fArea_2eproto();
  return *default_instance_;
}

E_AreaArea* E_AreaArea::default_instance_ = NULL;

E_AreaArea* E_AreaArea::New() const {
  return new E_AreaArea;
}

void E_AreaArea::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    m_id_ = GOOGLE_LONGLONG(0);
    m_subtype_ = 0;
    m_belongtosceneid_ = GOOGLE_LONGLONG(0);
    m_shapetype_ = 0;
    m_isnotice_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool E_AreaArea::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 m_id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &m_id_)));
          set_has_m_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_m_subType;
        break;
      }

      // optional int32 m_subType = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_m_subType:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &m_subtype_)));
          set_has_m_subtype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_m_belongToSceneID;
        break;
      }

      // optional int64 m_belongToSceneID = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_m_belongToSceneID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &m_belongtosceneid_)));
          set_has_m_belongtosceneid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_m_shapeType;
        break;
      }

      // optional int32 m_shapeType = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_m_shapeType:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &m_shapetype_)));
          set_has_m_shapetype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_m_isNotice;
        break;
      }

      // optional int32 m_isNotice = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_m_isNotice:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &m_isnotice_)));
          set_has_m_isnotice();
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

void E_AreaArea::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int64 m_id = 1;
  if (has_m_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->m_id(), output);
  }

  // optional int32 m_subType = 2;
  if (has_m_subtype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->m_subtype(), output);
  }

  // optional int64 m_belongToSceneID = 3;
  if (has_m_belongtosceneid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->m_belongtosceneid(), output);
  }

  // optional int32 m_shapeType = 4;
  if (has_m_shapetype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->m_shapetype(), output);
  }

  // optional int32 m_isNotice = 5;
  if (has_m_isnotice()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->m_isnotice(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* E_AreaArea::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int64 m_id = 1;
  if (has_m_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->m_id(), target);
  }

  // optional int32 m_subType = 2;
  if (has_m_subtype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->m_subtype(), target);
  }

  // optional int64 m_belongToSceneID = 3;
  if (has_m_belongtosceneid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->m_belongtosceneid(), target);
  }

  // optional int32 m_shapeType = 4;
  if (has_m_shapetype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->m_shapetype(), target);
  }

  // optional int32 m_isNotice = 5;
  if (has_m_isnotice()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->m_isnotice(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int E_AreaArea::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 m_id = 1;
    if (has_m_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->m_id());
    }

    // optional int32 m_subType = 2;
    if (has_m_subtype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->m_subtype());
    }

    // optional int64 m_belongToSceneID = 3;
    if (has_m_belongtosceneid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->m_belongtosceneid());
    }

    // optional int32 m_shapeType = 4;
    if (has_m_shapetype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->m_shapetype());
    }

    // optional int32 m_isNotice = 5;
    if (has_m_isnotice()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->m_isnotice());
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

void E_AreaArea::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const E_AreaArea* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const E_AreaArea*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void E_AreaArea::MergeFrom(const E_AreaArea& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_m_id()) {
      set_m_id(from.m_id());
    }
    if (from.has_m_subtype()) {
      set_m_subtype(from.m_subtype());
    }
    if (from.has_m_belongtosceneid()) {
      set_m_belongtosceneid(from.m_belongtosceneid());
    }
    if (from.has_m_shapetype()) {
      set_m_shapetype(from.m_shapetype());
    }
    if (from.has_m_isnotice()) {
      set_m_isnotice(from.m_isnotice());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void E_AreaArea::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void E_AreaArea::CopyFrom(const E_AreaArea& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool E_AreaArea::IsInitialized() const {

  return true;
}

void E_AreaArea::Swap(E_AreaArea* other) {
  if (other != this) {
    std::swap(m_id_, other->m_id_);
    std::swap(m_subtype_, other->m_subtype_);
    std::swap(m_belongtosceneid_, other->m_belongtosceneid_);
    std::swap(m_shapetype_, other->m_shapetype_);
    std::swap(m_isnotice_, other->m_isnotice_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata E_AreaArea::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = E_AreaArea_descriptor_;
  metadata.reflection = E_AreaArea_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Sheet_AreaArea::kEAreaAreaListFieldNumber;
#endif  // !_MSC_VER

Sheet_AreaArea::Sheet_AreaArea()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Sheet_AreaArea::InitAsDefaultInstance() {
}

Sheet_AreaArea::Sheet_AreaArea(const Sheet_AreaArea& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Sheet_AreaArea::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Sheet_AreaArea::~Sheet_AreaArea() {
  SharedDtor();
}

void Sheet_AreaArea::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Sheet_AreaArea::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Sheet_AreaArea::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Sheet_AreaArea_descriptor_;
}

const Sheet_AreaArea& Sheet_AreaArea::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_E_5fArea_2eproto();
  return *default_instance_;
}

Sheet_AreaArea* Sheet_AreaArea::default_instance_ = NULL;

Sheet_AreaArea* Sheet_AreaArea::New() const {
  return new Sheet_AreaArea;
}

void Sheet_AreaArea::Clear() {
  e_areaarea_list_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Sheet_AreaArea::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .proto_ff.E_AreaArea E_AreaArea_List = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_E_AreaArea_List:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_e_areaarea_list()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_E_AreaArea_List;
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

void Sheet_AreaArea::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .proto_ff.E_AreaArea E_AreaArea_List = 1;
  for (int i = 0; i < this->e_areaarea_list_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->e_areaarea_list(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Sheet_AreaArea::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .proto_ff.E_AreaArea E_AreaArea_List = 1;
  for (int i = 0; i < this->e_areaarea_list_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->e_areaarea_list(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Sheet_AreaArea::ByteSize() const {
  int total_size = 0;

  // repeated .proto_ff.E_AreaArea E_AreaArea_List = 1;
  total_size += 1 * this->e_areaarea_list_size();
  for (int i = 0; i < this->e_areaarea_list_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->e_areaarea_list(i));
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

void Sheet_AreaArea::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Sheet_AreaArea* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Sheet_AreaArea*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Sheet_AreaArea::MergeFrom(const Sheet_AreaArea& from) {
  GOOGLE_CHECK_NE(&from, this);
  e_areaarea_list_.MergeFrom(from.e_areaarea_list_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Sheet_AreaArea::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Sheet_AreaArea::CopyFrom(const Sheet_AreaArea& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Sheet_AreaArea::IsInitialized() const {

  return true;
}

void Sheet_AreaArea::Swap(Sheet_AreaArea* other) {
  if (other != this) {
    e_areaarea_list_.Swap(&other->e_areaarea_list_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Sheet_AreaArea::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Sheet_AreaArea_descriptor_;
  metadata.reflection = Sheet_AreaArea_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_ff

// @@protoc_insertion_point(global_scope)
