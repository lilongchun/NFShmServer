// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: artifact.proto

#ifndef PROTOBUF_artifact_2eproto__INCLUDED
#define PROTOBUF_artifact_2eproto__INCLUDED

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
void  protobuf_AddDesc_artifact_2eproto();
void protobuf_AssignDesc_artifact_2eproto();
void protobuf_ShutdownFile_artifact_2eproto();

class artifactartifactattributeDesc;
class artifactartifact;
class Sheet_artifactartifact;

// ===================================================================

class artifactartifactattributeDesc : public ::google::protobuf::Message {
 public:
  artifactartifactattributeDesc();
  virtual ~artifactartifactattributeDesc();

  artifactartifactattributeDesc(const artifactartifactattributeDesc& from);

  inline artifactartifactattributeDesc& operator=(const artifactartifactattributeDesc& from) {
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
  static const artifactartifactattributeDesc& default_instance();

  void Swap(artifactartifactattributeDesc* other);

  // implements Message ----------------------------------------------

  artifactartifactattributeDesc* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const artifactartifactattributeDesc& from);
  void MergeFrom(const artifactartifactattributeDesc& from);
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

  // optional int32 value = 2;
  inline bool has_value() const;
  inline void clear_value();
  static const int kValueFieldNumber = 2;
  inline ::google::protobuf::int32 value() const;
  inline void set_value(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:proto_ff.artifactartifactattributeDesc)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_value();
  inline void clear_has_value();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 type_;
  ::google::protobuf::int32 value_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_artifact_2eproto();
  friend void protobuf_AssignDesc_artifact_2eproto();
  friend void protobuf_ShutdownFile_artifact_2eproto();

  void InitAsDefaultInstance();
  static artifactartifactattributeDesc* default_instance_;
};
// -------------------------------------------------------------------

class artifactartifact : public ::google::protobuf::Message {
 public:
  artifactartifact();
  virtual ~artifactartifact();

  artifactartifact(const artifactartifact& from);

  inline artifactartifact& operator=(const artifactartifact& from) {
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
  static const artifactartifact& default_instance();

  void Swap(artifactartifact* other);

  // implements Message ----------------------------------------------

  artifactartifact* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const artifactartifact& from);
  void MergeFrom(const artifactartifact& from);
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

  // optional int64 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::int64 id() const;
  inline void set_id(::google::protobuf::int64 value);

  // optional string resource = 2;
  inline bool has_resource() const;
  inline void clear_resource();
  static const int kResourceFieldNumber = 2;
  inline const ::std::string& resource() const;
  inline void set_resource(const ::std::string& value);
  inline void set_resource(const char* value);
  inline void set_resource(const char* value, size_t size);
  inline ::std::string* mutable_resource();
  inline ::std::string* release_resource();
  inline void set_allocated_resource(::std::string* resource);

  // optional string previewRes = 3;
  inline bool has_previewres() const;
  inline void clear_previewres();
  static const int kPreviewResFieldNumber = 3;
  inline const ::std::string& previewres() const;
  inline void set_previewres(const ::std::string& value);
  inline void set_previewres(const char* value);
  inline void set_previewres(const char* value, size_t size);
  inline ::std::string* mutable_previewres();
  inline ::std::string* release_previewres();
  inline void set_allocated_previewres(::std::string* previewres);

  // optional int32 professionID = 4;
  inline bool has_professionid() const;
  inline void clear_professionid();
  static const int kProfessionIDFieldNumber = 4;
  inline ::google::protobuf::int32 professionid() const;
  inline void set_professionid(::google::protobuf::int32 value);

  // optional string name = 5;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 5;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional string activeDesc = 6;
  inline bool has_activedesc() const;
  inline void clear_activedesc();
  static const int kActiveDescFieldNumber = 6;
  inline const ::std::string& activedesc() const;
  inline void set_activedesc(const ::std::string& value);
  inline void set_activedesc(const char* value);
  inline void set_activedesc(const char* value, size_t size);
  inline ::std::string* mutable_activedesc();
  inline ::std::string* release_activedesc();
  inline void set_allocated_activedesc(::std::string* activedesc);

  // optional int32 quality = 7;
  inline bool has_quality() const;
  inline void clear_quality();
  static const int kQualityFieldNumber = 7;
  inline ::google::protobuf::int32 quality() const;
  inline void set_quality(::google::protobuf::int32 value);

  // optional int64 starId = 8;
  inline bool has_starid() const;
  inline void clear_starid();
  static const int kStarIdFieldNumber = 8;
  inline ::google::protobuf::int64 starid() const;
  inline void set_starid(::google::protobuf::int64 value);

  // optional string starNum = 9;
  inline bool has_starnum() const;
  inline void clear_starnum();
  static const int kStarNumFieldNumber = 9;
  inline const ::std::string& starnum() const;
  inline void set_starnum(const ::std::string& value);
  inline void set_starnum(const char* value);
  inline void set_starnum(const char* value, size_t size);
  inline ::std::string* mutable_starnum();
  inline ::std::string* release_starnum();
  inline void set_allocated_starnum(::std::string* starnum);

  // optional int32 starUp = 10;
  inline bool has_starup() const;
  inline void clear_starup();
  static const int kStarUpFieldNumber = 10;
  inline ::google::protobuf::int32 starup() const;
  inline void set_starup(::google::protobuf::int32 value);

  // optional int32 starBer = 11;
  inline bool has_starber() const;
  inline void clear_starber();
  static const int kStarBerFieldNumber = 11;
  inline ::google::protobuf::int32 starber() const;
  inline void set_starber(::google::protobuf::int32 value);

  // optional int64 skill = 12;
  inline bool has_skill() const;
  inline void clear_skill();
  static const int kSkillFieldNumber = 12;
  inline ::google::protobuf::int64 skill() const;
  inline void set_skill(::google::protobuf::int64 value);

  // optional string skillUi = 13;
  inline bool has_skillui() const;
  inline void clear_skillui();
  static const int kSkillUiFieldNumber = 13;
  inline const ::std::string& skillui() const;
  inline void set_skillui(const ::std::string& value);
  inline void set_skillui(const char* value);
  inline void set_skillui(const char* value, size_t size);
  inline ::std::string* mutable_skillui();
  inline ::std::string* release_skillui();
  inline void set_allocated_skillui(::std::string* skillui);

  // optional int32 artifactType = 14;
  inline bool has_artifacttype() const;
  inline void clear_artifacttype();
  static const int kArtifactTypeFieldNumber = 14;
  inline ::google::protobuf::int32 artifacttype() const;
  inline void set_artifacttype(::google::protobuf::int32 value);

  // repeated .proto_ff.artifactartifactattributeDesc attribute = 15;
  inline int attribute_size() const;
  inline void clear_attribute();
  static const int kAttributeFieldNumber = 15;
  inline const ::proto_ff::artifactartifactattributeDesc& attribute(int index) const;
  inline ::proto_ff::artifactartifactattributeDesc* mutable_attribute(int index);
  inline ::proto_ff::artifactartifactattributeDesc* add_attribute();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifactattributeDesc >&
      attribute() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifactattributeDesc >*
      mutable_attribute();

  // @@protoc_insertion_point(class_scope:proto_ff.artifactartifact)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_resource();
  inline void clear_has_resource();
  inline void set_has_previewres();
  inline void clear_has_previewres();
  inline void set_has_professionid();
  inline void clear_has_professionid();
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_activedesc();
  inline void clear_has_activedesc();
  inline void set_has_quality();
  inline void clear_has_quality();
  inline void set_has_starid();
  inline void clear_has_starid();
  inline void set_has_starnum();
  inline void clear_has_starnum();
  inline void set_has_starup();
  inline void clear_has_starup();
  inline void set_has_starber();
  inline void clear_has_starber();
  inline void set_has_skill();
  inline void clear_has_skill();
  inline void set_has_skillui();
  inline void clear_has_skillui();
  inline void set_has_artifacttype();
  inline void clear_has_artifacttype();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 id_;
  ::std::string* resource_;
  ::std::string* previewres_;
  ::std::string* name_;
  ::google::protobuf::int32 professionid_;
  ::google::protobuf::int32 quality_;
  ::std::string* activedesc_;
  ::google::protobuf::int64 starid_;
  ::std::string* starnum_;
  ::google::protobuf::int32 starup_;
  ::google::protobuf::int32 starber_;
  ::google::protobuf::int64 skill_;
  ::std::string* skillui_;
  ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifactattributeDesc > attribute_;
  ::google::protobuf::int32 artifacttype_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(15 + 31) / 32];

  friend void  protobuf_AddDesc_artifact_2eproto();
  friend void protobuf_AssignDesc_artifact_2eproto();
  friend void protobuf_ShutdownFile_artifact_2eproto();

  void InitAsDefaultInstance();
  static artifactartifact* default_instance_;
};
// -------------------------------------------------------------------

class Sheet_artifactartifact : public ::google::protobuf::Message {
 public:
  Sheet_artifactartifact();
  virtual ~Sheet_artifactartifact();

  Sheet_artifactartifact(const Sheet_artifactartifact& from);

  inline Sheet_artifactartifact& operator=(const Sheet_artifactartifact& from) {
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
  static const Sheet_artifactartifact& default_instance();

  void Swap(Sheet_artifactartifact* other);

  // implements Message ----------------------------------------------

  Sheet_artifactartifact* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Sheet_artifactartifact& from);
  void MergeFrom(const Sheet_artifactartifact& from);
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

  // repeated .proto_ff.artifactartifact artifactartifact_List = 1;
  inline int artifactartifact_list_size() const;
  inline void clear_artifactartifact_list();
  static const int kArtifactartifactListFieldNumber = 1;
  inline const ::proto_ff::artifactartifact& artifactartifact_list(int index) const;
  inline ::proto_ff::artifactartifact* mutable_artifactartifact_list(int index);
  inline ::proto_ff::artifactartifact* add_artifactartifact_list();
  inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifact >&
      artifactartifact_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifact >*
      mutable_artifactartifact_list();

  // @@protoc_insertion_point(class_scope:proto_ff.Sheet_artifactartifact)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifact > artifactartifact_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_artifact_2eproto();
  friend void protobuf_AssignDesc_artifact_2eproto();
  friend void protobuf_ShutdownFile_artifact_2eproto();

  void InitAsDefaultInstance();
  static Sheet_artifactartifact* default_instance_;
};
// ===================================================================


// ===================================================================

// artifactartifactattributeDesc

// optional int32 type = 1;
inline bool artifactartifactattributeDesc::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void artifactartifactattributeDesc::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void artifactartifactattributeDesc::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void artifactartifactattributeDesc::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 artifactartifactattributeDesc::type() const {
  return type_;
}
inline void artifactartifactattributeDesc::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// optional int32 value = 2;
inline bool artifactartifactattributeDesc::has_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void artifactartifactattributeDesc::set_has_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void artifactartifactattributeDesc::clear_has_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void artifactartifactattributeDesc::clear_value() {
  value_ = 0;
  clear_has_value();
}
inline ::google::protobuf::int32 artifactartifactattributeDesc::value() const {
  return value_;
}
inline void artifactartifactattributeDesc::set_value(::google::protobuf::int32 value) {
  set_has_value();
  value_ = value;
}

// -------------------------------------------------------------------

// artifactartifact

// optional int64 id = 1;
inline bool artifactartifact::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void artifactartifact::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void artifactartifact::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void artifactartifact::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::int64 artifactartifact::id() const {
  return id_;
}
inline void artifactartifact::set_id(::google::protobuf::int64 value) {
  set_has_id();
  id_ = value;
}

// optional string resource = 2;
inline bool artifactartifact::has_resource() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void artifactartifact::set_has_resource() {
  _has_bits_[0] |= 0x00000002u;
}
inline void artifactartifact::clear_has_resource() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void artifactartifact::clear_resource() {
  if (resource_ != &::google::protobuf::internal::kEmptyString) {
    resource_->clear();
  }
  clear_has_resource();
}
inline const ::std::string& artifactartifact::resource() const {
  return *resource_;
}
inline void artifactartifact::set_resource(const ::std::string& value) {
  set_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    resource_ = new ::std::string;
  }
  resource_->assign(value);
}
inline void artifactartifact::set_resource(const char* value) {
  set_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    resource_ = new ::std::string;
  }
  resource_->assign(value);
}
inline void artifactartifact::set_resource(const char* value, size_t size) {
  set_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    resource_ = new ::std::string;
  }
  resource_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* artifactartifact::mutable_resource() {
  set_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    resource_ = new ::std::string;
  }
  return resource_;
}
inline ::std::string* artifactartifact::release_resource() {
  clear_has_resource();
  if (resource_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = resource_;
    resource_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void artifactartifact::set_allocated_resource(::std::string* resource) {
  if (resource_ != &::google::protobuf::internal::kEmptyString) {
    delete resource_;
  }
  if (resource) {
    set_has_resource();
    resource_ = resource;
  } else {
    clear_has_resource();
    resource_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string previewRes = 3;
inline bool artifactartifact::has_previewres() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void artifactartifact::set_has_previewres() {
  _has_bits_[0] |= 0x00000004u;
}
inline void artifactartifact::clear_has_previewres() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void artifactartifact::clear_previewres() {
  if (previewres_ != &::google::protobuf::internal::kEmptyString) {
    previewres_->clear();
  }
  clear_has_previewres();
}
inline const ::std::string& artifactartifact::previewres() const {
  return *previewres_;
}
inline void artifactartifact::set_previewres(const ::std::string& value) {
  set_has_previewres();
  if (previewres_ == &::google::protobuf::internal::kEmptyString) {
    previewres_ = new ::std::string;
  }
  previewres_->assign(value);
}
inline void artifactartifact::set_previewres(const char* value) {
  set_has_previewres();
  if (previewres_ == &::google::protobuf::internal::kEmptyString) {
    previewres_ = new ::std::string;
  }
  previewres_->assign(value);
}
inline void artifactartifact::set_previewres(const char* value, size_t size) {
  set_has_previewres();
  if (previewres_ == &::google::protobuf::internal::kEmptyString) {
    previewres_ = new ::std::string;
  }
  previewres_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* artifactartifact::mutable_previewres() {
  set_has_previewres();
  if (previewres_ == &::google::protobuf::internal::kEmptyString) {
    previewres_ = new ::std::string;
  }
  return previewres_;
}
inline ::std::string* artifactartifact::release_previewres() {
  clear_has_previewres();
  if (previewres_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = previewres_;
    previewres_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void artifactartifact::set_allocated_previewres(::std::string* previewres) {
  if (previewres_ != &::google::protobuf::internal::kEmptyString) {
    delete previewres_;
  }
  if (previewres) {
    set_has_previewres();
    previewres_ = previewres;
  } else {
    clear_has_previewres();
    previewres_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 professionID = 4;
inline bool artifactartifact::has_professionid() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void artifactartifact::set_has_professionid() {
  _has_bits_[0] |= 0x00000008u;
}
inline void artifactartifact::clear_has_professionid() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void artifactartifact::clear_professionid() {
  professionid_ = 0;
  clear_has_professionid();
}
inline ::google::protobuf::int32 artifactartifact::professionid() const {
  return professionid_;
}
inline void artifactartifact::set_professionid(::google::protobuf::int32 value) {
  set_has_professionid();
  professionid_ = value;
}

// optional string name = 5;
inline bool artifactartifact::has_name() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void artifactartifact::set_has_name() {
  _has_bits_[0] |= 0x00000010u;
}
inline void artifactartifact::clear_has_name() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void artifactartifact::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& artifactartifact::name() const {
  return *name_;
}
inline void artifactartifact::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void artifactartifact::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void artifactartifact::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* artifactartifact::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* artifactartifact::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void artifactartifact::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string activeDesc = 6;
inline bool artifactartifact::has_activedesc() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void artifactartifact::set_has_activedesc() {
  _has_bits_[0] |= 0x00000020u;
}
inline void artifactartifact::clear_has_activedesc() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void artifactartifact::clear_activedesc() {
  if (activedesc_ != &::google::protobuf::internal::kEmptyString) {
    activedesc_->clear();
  }
  clear_has_activedesc();
}
inline const ::std::string& artifactartifact::activedesc() const {
  return *activedesc_;
}
inline void artifactartifact::set_activedesc(const ::std::string& value) {
  set_has_activedesc();
  if (activedesc_ == &::google::protobuf::internal::kEmptyString) {
    activedesc_ = new ::std::string;
  }
  activedesc_->assign(value);
}
inline void artifactartifact::set_activedesc(const char* value) {
  set_has_activedesc();
  if (activedesc_ == &::google::protobuf::internal::kEmptyString) {
    activedesc_ = new ::std::string;
  }
  activedesc_->assign(value);
}
inline void artifactartifact::set_activedesc(const char* value, size_t size) {
  set_has_activedesc();
  if (activedesc_ == &::google::protobuf::internal::kEmptyString) {
    activedesc_ = new ::std::string;
  }
  activedesc_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* artifactartifact::mutable_activedesc() {
  set_has_activedesc();
  if (activedesc_ == &::google::protobuf::internal::kEmptyString) {
    activedesc_ = new ::std::string;
  }
  return activedesc_;
}
inline ::std::string* artifactartifact::release_activedesc() {
  clear_has_activedesc();
  if (activedesc_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = activedesc_;
    activedesc_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void artifactartifact::set_allocated_activedesc(::std::string* activedesc) {
  if (activedesc_ != &::google::protobuf::internal::kEmptyString) {
    delete activedesc_;
  }
  if (activedesc) {
    set_has_activedesc();
    activedesc_ = activedesc;
  } else {
    clear_has_activedesc();
    activedesc_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 quality = 7;
inline bool artifactartifact::has_quality() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void artifactartifact::set_has_quality() {
  _has_bits_[0] |= 0x00000040u;
}
inline void artifactartifact::clear_has_quality() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void artifactartifact::clear_quality() {
  quality_ = 0;
  clear_has_quality();
}
inline ::google::protobuf::int32 artifactartifact::quality() const {
  return quality_;
}
inline void artifactartifact::set_quality(::google::protobuf::int32 value) {
  set_has_quality();
  quality_ = value;
}

// optional int64 starId = 8;
inline bool artifactartifact::has_starid() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void artifactartifact::set_has_starid() {
  _has_bits_[0] |= 0x00000080u;
}
inline void artifactartifact::clear_has_starid() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void artifactartifact::clear_starid() {
  starid_ = GOOGLE_LONGLONG(0);
  clear_has_starid();
}
inline ::google::protobuf::int64 artifactartifact::starid() const {
  return starid_;
}
inline void artifactartifact::set_starid(::google::protobuf::int64 value) {
  set_has_starid();
  starid_ = value;
}

// optional string starNum = 9;
inline bool artifactartifact::has_starnum() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void artifactartifact::set_has_starnum() {
  _has_bits_[0] |= 0x00000100u;
}
inline void artifactartifact::clear_has_starnum() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void artifactartifact::clear_starnum() {
  if (starnum_ != &::google::protobuf::internal::kEmptyString) {
    starnum_->clear();
  }
  clear_has_starnum();
}
inline const ::std::string& artifactartifact::starnum() const {
  return *starnum_;
}
inline void artifactartifact::set_starnum(const ::std::string& value) {
  set_has_starnum();
  if (starnum_ == &::google::protobuf::internal::kEmptyString) {
    starnum_ = new ::std::string;
  }
  starnum_->assign(value);
}
inline void artifactartifact::set_starnum(const char* value) {
  set_has_starnum();
  if (starnum_ == &::google::protobuf::internal::kEmptyString) {
    starnum_ = new ::std::string;
  }
  starnum_->assign(value);
}
inline void artifactartifact::set_starnum(const char* value, size_t size) {
  set_has_starnum();
  if (starnum_ == &::google::protobuf::internal::kEmptyString) {
    starnum_ = new ::std::string;
  }
  starnum_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* artifactartifact::mutable_starnum() {
  set_has_starnum();
  if (starnum_ == &::google::protobuf::internal::kEmptyString) {
    starnum_ = new ::std::string;
  }
  return starnum_;
}
inline ::std::string* artifactartifact::release_starnum() {
  clear_has_starnum();
  if (starnum_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = starnum_;
    starnum_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void artifactartifact::set_allocated_starnum(::std::string* starnum) {
  if (starnum_ != &::google::protobuf::internal::kEmptyString) {
    delete starnum_;
  }
  if (starnum) {
    set_has_starnum();
    starnum_ = starnum;
  } else {
    clear_has_starnum();
    starnum_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 starUp = 10;
inline bool artifactartifact::has_starup() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void artifactartifact::set_has_starup() {
  _has_bits_[0] |= 0x00000200u;
}
inline void artifactartifact::clear_has_starup() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void artifactartifact::clear_starup() {
  starup_ = 0;
  clear_has_starup();
}
inline ::google::protobuf::int32 artifactartifact::starup() const {
  return starup_;
}
inline void artifactartifact::set_starup(::google::protobuf::int32 value) {
  set_has_starup();
  starup_ = value;
}

// optional int32 starBer = 11;
inline bool artifactartifact::has_starber() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void artifactartifact::set_has_starber() {
  _has_bits_[0] |= 0x00000400u;
}
inline void artifactartifact::clear_has_starber() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void artifactartifact::clear_starber() {
  starber_ = 0;
  clear_has_starber();
}
inline ::google::protobuf::int32 artifactartifact::starber() const {
  return starber_;
}
inline void artifactartifact::set_starber(::google::protobuf::int32 value) {
  set_has_starber();
  starber_ = value;
}

// optional int64 skill = 12;
inline bool artifactartifact::has_skill() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void artifactartifact::set_has_skill() {
  _has_bits_[0] |= 0x00000800u;
}
inline void artifactartifact::clear_has_skill() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void artifactartifact::clear_skill() {
  skill_ = GOOGLE_LONGLONG(0);
  clear_has_skill();
}
inline ::google::protobuf::int64 artifactartifact::skill() const {
  return skill_;
}
inline void artifactartifact::set_skill(::google::protobuf::int64 value) {
  set_has_skill();
  skill_ = value;
}

// optional string skillUi = 13;
inline bool artifactartifact::has_skillui() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void artifactartifact::set_has_skillui() {
  _has_bits_[0] |= 0x00001000u;
}
inline void artifactartifact::clear_has_skillui() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void artifactartifact::clear_skillui() {
  if (skillui_ != &::google::protobuf::internal::kEmptyString) {
    skillui_->clear();
  }
  clear_has_skillui();
}
inline const ::std::string& artifactartifact::skillui() const {
  return *skillui_;
}
inline void artifactartifact::set_skillui(const ::std::string& value) {
  set_has_skillui();
  if (skillui_ == &::google::protobuf::internal::kEmptyString) {
    skillui_ = new ::std::string;
  }
  skillui_->assign(value);
}
inline void artifactartifact::set_skillui(const char* value) {
  set_has_skillui();
  if (skillui_ == &::google::protobuf::internal::kEmptyString) {
    skillui_ = new ::std::string;
  }
  skillui_->assign(value);
}
inline void artifactartifact::set_skillui(const char* value, size_t size) {
  set_has_skillui();
  if (skillui_ == &::google::protobuf::internal::kEmptyString) {
    skillui_ = new ::std::string;
  }
  skillui_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* artifactartifact::mutable_skillui() {
  set_has_skillui();
  if (skillui_ == &::google::protobuf::internal::kEmptyString) {
    skillui_ = new ::std::string;
  }
  return skillui_;
}
inline ::std::string* artifactartifact::release_skillui() {
  clear_has_skillui();
  if (skillui_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = skillui_;
    skillui_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void artifactartifact::set_allocated_skillui(::std::string* skillui) {
  if (skillui_ != &::google::protobuf::internal::kEmptyString) {
    delete skillui_;
  }
  if (skillui) {
    set_has_skillui();
    skillui_ = skillui;
  } else {
    clear_has_skillui();
    skillui_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 artifactType = 14;
inline bool artifactartifact::has_artifacttype() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void artifactartifact::set_has_artifacttype() {
  _has_bits_[0] |= 0x00002000u;
}
inline void artifactartifact::clear_has_artifacttype() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void artifactartifact::clear_artifacttype() {
  artifacttype_ = 0;
  clear_has_artifacttype();
}
inline ::google::protobuf::int32 artifactartifact::artifacttype() const {
  return artifacttype_;
}
inline void artifactartifact::set_artifacttype(::google::protobuf::int32 value) {
  set_has_artifacttype();
  artifacttype_ = value;
}

// repeated .proto_ff.artifactartifactattributeDesc attribute = 15;
inline int artifactartifact::attribute_size() const {
  return attribute_.size();
}
inline void artifactartifact::clear_attribute() {
  attribute_.Clear();
}
inline const ::proto_ff::artifactartifactattributeDesc& artifactartifact::attribute(int index) const {
  return attribute_.Get(index);
}
inline ::proto_ff::artifactartifactattributeDesc* artifactartifact::mutable_attribute(int index) {
  return attribute_.Mutable(index);
}
inline ::proto_ff::artifactartifactattributeDesc* artifactartifact::add_attribute() {
  return attribute_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifactattributeDesc >&
artifactartifact::attribute() const {
  return attribute_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifactattributeDesc >*
artifactartifact::mutable_attribute() {
  return &attribute_;
}

// -------------------------------------------------------------------

// Sheet_artifactartifact

// repeated .proto_ff.artifactartifact artifactartifact_List = 1;
inline int Sheet_artifactartifact::artifactartifact_list_size() const {
  return artifactartifact_list_.size();
}
inline void Sheet_artifactartifact::clear_artifactartifact_list() {
  artifactartifact_list_.Clear();
}
inline const ::proto_ff::artifactartifact& Sheet_artifactartifact::artifactartifact_list(int index) const {
  return artifactartifact_list_.Get(index);
}
inline ::proto_ff::artifactartifact* Sheet_artifactartifact::mutable_artifactartifact_list(int index) {
  return artifactartifact_list_.Mutable(index);
}
inline ::proto_ff::artifactartifact* Sheet_artifactartifact::add_artifactartifact_list() {
  return artifactartifact_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifact >&
Sheet_artifactartifact::artifactartifact_list() const {
  return artifactartifact_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::proto_ff::artifactartifact >*
Sheet_artifactartifact::mutable_artifactartifact_list() {
  return &artifactartifact_list_;
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

#endif  // PROTOBUF_artifact_2eproto__INCLUDED