// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tech.proto

#ifndef PROTOBUF_tech_2eproto__INCLUDED
#define PROTOBUF_tech_2eproto__INCLUDED

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "common.pb.h"
// @@protoc_insertion_point(includes)

namespace slg {
namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_tech_2eproto();
void protobuf_AssignDesc_tech_2eproto();
void protobuf_ShutdownFile_tech_2eproto();

class SkillDTO;
class TechDTO;
class TechUpgradeRequest;
class TechUpgradeResponse;
class UseSkillRequest;
class UseSkillResponse;
class TechPush;
class SkillPush;

enum TechCommandId {
  TECH_UPGRADE = 1001,
  PLAYER_USE_SKILL = 1002
};
bool TechCommandId_IsValid(int value);
const TechCommandId TechCommandId_MIN = TECH_UPGRADE;
const TechCommandId TechCommandId_MAX = PLAYER_USE_SKILL;
const int TechCommandId_ARRAYSIZE = TechCommandId_MAX + 1;

const ::google::protobuf::EnumDescriptor* TechCommandId_descriptor();
inline const ::std::string& TechCommandId_Name(TechCommandId value) {
  return ::google::protobuf::internal::NameOfEnum(
    TechCommandId_descriptor(), value);
}
inline bool TechCommandId_Parse(
    const ::std::string& name, TechCommandId* value) {
  return ::google::protobuf::internal::ParseNamedEnum<TechCommandId>(
    TechCommandId_descriptor(), name, value);
}
enum TechPushId {
  TECH_LIST_PUSH = 51001,
  TECH_SKILL_PUSH = 51002
};
bool TechPushId_IsValid(int value);
const TechPushId TechPushId_MIN = TECH_LIST_PUSH;
const TechPushId TechPushId_MAX = TECH_SKILL_PUSH;
const int TechPushId_ARRAYSIZE = TechPushId_MAX + 1;

const ::google::protobuf::EnumDescriptor* TechPushId_descriptor();
inline const ::std::string& TechPushId_Name(TechPushId value) {
  return ::google::protobuf::internal::NameOfEnum(
    TechPushId_descriptor(), value);
}
inline bool TechPushId_Parse(
    const ::std::string& name, TechPushId* value) {
  return ::google::protobuf::internal::ParseNamedEnum<TechPushId>(
    TechPushId_descriptor(), name, value);
}
// ===================================================================

class SkillDTO : public ::google::protobuf::Message {
 public:
  SkillDTO();
  virtual ~SkillDTO();

  SkillDTO(const SkillDTO& from);

  inline SkillDTO& operator=(const SkillDTO& from) {
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
  static const SkillDTO& default_instance();

  void Swap(SkillDTO* other);

  // implements Message ----------------------------------------------

  SkillDTO* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SkillDTO& from);
  void MergeFrom(const SkillDTO& from);
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

  // required int32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // required int32 lastCanUseTime = 2;
  inline bool has_lastcanusetime() const;
  inline void clear_lastcanusetime();
  static const int kLastCanUseTimeFieldNumber = 2;
  inline ::google::protobuf::int32 lastcanusetime() const;
  inline void set_lastcanusetime(::google::protobuf::int32 value);

  // required int32 keepEnd = 3;
  inline bool has_keepend() const;
  inline void clear_keepend();
  static const int kKeepEndFieldNumber = 3;
  inline ::google::protobuf::int32 keepend() const;
  inline void set_keepend(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:slg.protocol.SkillDTO)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_lastcanusetime();
  inline void clear_has_lastcanusetime();
  inline void set_has_keepend();
  inline void clear_has_keepend();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 type_;
  ::google::protobuf::int32 lastcanusetime_;
  ::google::protobuf::int32 keepend_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_tech_2eproto();
  friend void protobuf_AssignDesc_tech_2eproto();
  friend void protobuf_ShutdownFile_tech_2eproto();

  void InitAsDefaultInstance();
  static SkillDTO* default_instance_;
};
// -------------------------------------------------------------------

class TechDTO : public ::google::protobuf::Message {
 public:
  TechDTO();
  virtual ~TechDTO();

  TechDTO(const TechDTO& from);

  inline TechDTO& operator=(const TechDTO& from) {
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
  static const TechDTO& default_instance();

  void Swap(TechDTO* other);

  // implements Message ----------------------------------------------

  TechDTO* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TechDTO& from);
  void MergeFrom(const TechDTO& from);
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

  // required int32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // required int32 level = 2;
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 2;
  inline ::google::protobuf::int32 level() const;
  inline void set_level(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:slg.protocol.TechDTO)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_level();
  inline void clear_has_level();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 type_;
  ::google::protobuf::int32 level_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_tech_2eproto();
  friend void protobuf_AssignDesc_tech_2eproto();
  friend void protobuf_ShutdownFile_tech_2eproto();

  void InitAsDefaultInstance();
  static TechDTO* default_instance_;
};
// -------------------------------------------------------------------

class TechUpgradeRequest : public ::google::protobuf::Message {
 public:
  TechUpgradeRequest();
  virtual ~TechUpgradeRequest();

  TechUpgradeRequest(const TechUpgradeRequest& from);

  inline TechUpgradeRequest& operator=(const TechUpgradeRequest& from) {
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
  static const TechUpgradeRequest& default_instance();

  void Swap(TechUpgradeRequest* other);

  // implements Message ----------------------------------------------

  TechUpgradeRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TechUpgradeRequest& from);
  void MergeFrom(const TechUpgradeRequest& from);
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

  // required int32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // required bool oper = 2;
  inline bool has_oper() const;
  inline void clear_oper();
  static const int kOperFieldNumber = 2;
  inline bool oper() const;
  inline void set_oper(bool value);

  // required bool quick = 3;
  inline bool has_quick() const;
  inline void clear_quick();
  static const int kQuickFieldNumber = 3;
  inline bool quick() const;
  inline void set_quick(bool value);

  // @@protoc_insertion_point(class_scope:slg.protocol.TechUpgradeRequest)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_oper();
  inline void clear_has_oper();
  inline void set_has_quick();
  inline void clear_has_quick();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 type_;
  bool oper_;
  bool quick_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_tech_2eproto();
  friend void protobuf_AssignDesc_tech_2eproto();
  friend void protobuf_ShutdownFile_tech_2eproto();

  void InitAsDefaultInstance();
  static TechUpgradeRequest* default_instance_;
};
// -------------------------------------------------------------------

class TechUpgradeResponse : public ::google::protobuf::Message {
 public:
  TechUpgradeResponse();
  virtual ~TechUpgradeResponse();

  TechUpgradeResponse(const TechUpgradeResponse& from);

  inline TechUpgradeResponse& operator=(const TechUpgradeResponse& from) {
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
  static const TechUpgradeResponse& default_instance();

  void Swap(TechUpgradeResponse* other);

  // implements Message ----------------------------------------------

  TechUpgradeResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TechUpgradeResponse& from);
  void MergeFrom(const TechUpgradeResponse& from);
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

  // required int32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // required bool quick = 2;
  inline bool has_quick() const;
  inline void clear_quick();
  static const int kQuickFieldNumber = 2;
  inline bool quick() const;
  inline void set_quick(bool value);

  // @@protoc_insertion_point(class_scope:slg.protocol.TechUpgradeResponse)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_quick();
  inline void clear_has_quick();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 type_;
  bool quick_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_tech_2eproto();
  friend void protobuf_AssignDesc_tech_2eproto();
  friend void protobuf_ShutdownFile_tech_2eproto();

  void InitAsDefaultInstance();
  static TechUpgradeResponse* default_instance_;
};
// -------------------------------------------------------------------

class UseSkillRequest : public ::google::protobuf::Message {
 public:
  UseSkillRequest();
  virtual ~UseSkillRequest();

  UseSkillRequest(const UseSkillRequest& from);

  inline UseSkillRequest& operator=(const UseSkillRequest& from) {
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
  static const UseSkillRequest& default_instance();

  void Swap(UseSkillRequest* other);

  // implements Message ----------------------------------------------

  UseSkillRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UseSkillRequest& from);
  void MergeFrom(const UseSkillRequest& from);
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

  // required int32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:slg.protocol.UseSkillRequest)
 private:
  inline void set_has_type();
  inline void clear_has_type();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_tech_2eproto();
  friend void protobuf_AssignDesc_tech_2eproto();
  friend void protobuf_ShutdownFile_tech_2eproto();

  void InitAsDefaultInstance();
  static UseSkillRequest* default_instance_;
};
// -------------------------------------------------------------------

class UseSkillResponse : public ::google::protobuf::Message {
 public:
  UseSkillResponse();
  virtual ~UseSkillResponse();

  UseSkillResponse(const UseSkillResponse& from);

  inline UseSkillResponse& operator=(const UseSkillResponse& from) {
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
  static const UseSkillResponse& default_instance();

  void Swap(UseSkillResponse* other);

  // implements Message ----------------------------------------------

  UseSkillResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const UseSkillResponse& from);
  void MergeFrom(const UseSkillResponse& from);
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

  // required int32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // repeated .slg.protocol.PropertyDTO properties = 2;
  inline int properties_size() const;
  inline void clear_properties();
  static const int kPropertiesFieldNumber = 2;
  inline const ::slg::protocol::PropertyDTO& properties(int index) const;
  inline ::slg::protocol::PropertyDTO* mutable_properties(int index);
  inline ::slg::protocol::PropertyDTO* add_properties();
  inline const ::google::protobuf::RepeatedPtrField< ::slg::protocol::PropertyDTO >&
      properties() const;
  inline ::google::protobuf::RepeatedPtrField< ::slg::protocol::PropertyDTO >*
      mutable_properties();

  // optional .slg.protocol.PositionDTO position = 3;
  inline bool has_position() const;
  inline void clear_position();
  static const int kPositionFieldNumber = 3;
  inline const ::slg::protocol::PositionDTO& position() const;
  inline ::slg::protocol::PositionDTO* mutable_position();
  inline ::slg::protocol::PositionDTO* release_position();
  inline void set_allocated_position(::slg::protocol::PositionDTO* position);

  // @@protoc_insertion_point(class_scope:slg.protocol.UseSkillResponse)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_position();
  inline void clear_has_position();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::slg::protocol::PropertyDTO > properties_;
  ::slg::protocol::PositionDTO* position_;
  ::google::protobuf::int32 type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_tech_2eproto();
  friend void protobuf_AssignDesc_tech_2eproto();
  friend void protobuf_ShutdownFile_tech_2eproto();

  void InitAsDefaultInstance();
  static UseSkillResponse* default_instance_;
};
// -------------------------------------------------------------------

class TechPush : public ::google::protobuf::Message {
 public:
  TechPush();
  virtual ~TechPush();

  TechPush(const TechPush& from);

  inline TechPush& operator=(const TechPush& from) {
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
  static const TechPush& default_instance();

  void Swap(TechPush* other);

  // implements Message ----------------------------------------------

  TechPush* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TechPush& from);
  void MergeFrom(const TechPush& from);
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

  // repeated .slg.protocol.TechDTO techs = 1;
  inline int techs_size() const;
  inline void clear_techs();
  static const int kTechsFieldNumber = 1;
  inline const ::slg::protocol::TechDTO& techs(int index) const;
  inline ::slg::protocol::TechDTO* mutable_techs(int index);
  inline ::slg::protocol::TechDTO* add_techs();
  inline const ::google::protobuf::RepeatedPtrField< ::slg::protocol::TechDTO >&
      techs() const;
  inline ::google::protobuf::RepeatedPtrField< ::slg::protocol::TechDTO >*
      mutable_techs();

  // @@protoc_insertion_point(class_scope:slg.protocol.TechPush)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::slg::protocol::TechDTO > techs_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_tech_2eproto();
  friend void protobuf_AssignDesc_tech_2eproto();
  friend void protobuf_ShutdownFile_tech_2eproto();

  void InitAsDefaultInstance();
  static TechPush* default_instance_;
};
// -------------------------------------------------------------------

class SkillPush : public ::google::protobuf::Message {
 public:
  SkillPush();
  virtual ~SkillPush();

  SkillPush(const SkillPush& from);

  inline SkillPush& operator=(const SkillPush& from) {
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
  static const SkillPush& default_instance();

  void Swap(SkillPush* other);

  // implements Message ----------------------------------------------

  SkillPush* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SkillPush& from);
  void MergeFrom(const SkillPush& from);
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

  // repeated .slg.protocol.SkillDTO skills = 1;
  inline int skills_size() const;
  inline void clear_skills();
  static const int kSkillsFieldNumber = 1;
  inline const ::slg::protocol::SkillDTO& skills(int index) const;
  inline ::slg::protocol::SkillDTO* mutable_skills(int index);
  inline ::slg::protocol::SkillDTO* add_skills();
  inline const ::google::protobuf::RepeatedPtrField< ::slg::protocol::SkillDTO >&
      skills() const;
  inline ::google::protobuf::RepeatedPtrField< ::slg::protocol::SkillDTO >*
      mutable_skills();

  // @@protoc_insertion_point(class_scope:slg.protocol.SkillPush)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::slg::protocol::SkillDTO > skills_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_tech_2eproto();
  friend void protobuf_AssignDesc_tech_2eproto();
  friend void protobuf_ShutdownFile_tech_2eproto();

  void InitAsDefaultInstance();
  static SkillPush* default_instance_;
};
// ===================================================================


// ===================================================================

// SkillDTO

// required int32 type = 1;
inline bool SkillDTO::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SkillDTO::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SkillDTO::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SkillDTO::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 SkillDTO::type() const {
  return type_;
}
inline void SkillDTO::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// required int32 lastCanUseTime = 2;
inline bool SkillDTO::has_lastcanusetime() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SkillDTO::set_has_lastcanusetime() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SkillDTO::clear_has_lastcanusetime() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SkillDTO::clear_lastcanusetime() {
  lastcanusetime_ = 0;
  clear_has_lastcanusetime();
}
inline ::google::protobuf::int32 SkillDTO::lastcanusetime() const {
  return lastcanusetime_;
}
inline void SkillDTO::set_lastcanusetime(::google::protobuf::int32 value) {
  set_has_lastcanusetime();
  lastcanusetime_ = value;
}

// required int32 keepEnd = 3;
inline bool SkillDTO::has_keepend() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SkillDTO::set_has_keepend() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SkillDTO::clear_has_keepend() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SkillDTO::clear_keepend() {
  keepend_ = 0;
  clear_has_keepend();
}
inline ::google::protobuf::int32 SkillDTO::keepend() const {
  return keepend_;
}
inline void SkillDTO::set_keepend(::google::protobuf::int32 value) {
  set_has_keepend();
  keepend_ = value;
}

// -------------------------------------------------------------------

// TechDTO

// required int32 type = 1;
inline bool TechDTO::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TechDTO::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TechDTO::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TechDTO::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 TechDTO::type() const {
  return type_;
}
inline void TechDTO::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// required int32 level = 2;
inline bool TechDTO::has_level() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TechDTO::set_has_level() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TechDTO::clear_has_level() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TechDTO::clear_level() {
  level_ = 0;
  clear_has_level();
}
inline ::google::protobuf::int32 TechDTO::level() const {
  return level_;
}
inline void TechDTO::set_level(::google::protobuf::int32 value) {
  set_has_level();
  level_ = value;
}

// -------------------------------------------------------------------

// TechUpgradeRequest

// required int32 type = 1;
inline bool TechUpgradeRequest::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TechUpgradeRequest::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TechUpgradeRequest::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TechUpgradeRequest::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 TechUpgradeRequest::type() const {
  return type_;
}
inline void TechUpgradeRequest::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// required bool oper = 2;
inline bool TechUpgradeRequest::has_oper() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TechUpgradeRequest::set_has_oper() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TechUpgradeRequest::clear_has_oper() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TechUpgradeRequest::clear_oper() {
  oper_ = false;
  clear_has_oper();
}
inline bool TechUpgradeRequest::oper() const {
  return oper_;
}
inline void TechUpgradeRequest::set_oper(bool value) {
  set_has_oper();
  oper_ = value;
}

// required bool quick = 3;
inline bool TechUpgradeRequest::has_quick() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void TechUpgradeRequest::set_has_quick() {
  _has_bits_[0] |= 0x00000004u;
}
inline void TechUpgradeRequest::clear_has_quick() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void TechUpgradeRequest::clear_quick() {
  quick_ = false;
  clear_has_quick();
}
inline bool TechUpgradeRequest::quick() const {
  return quick_;
}
inline void TechUpgradeRequest::set_quick(bool value) {
  set_has_quick();
  quick_ = value;
}

// -------------------------------------------------------------------

// TechUpgradeResponse

// required int32 type = 1;
inline bool TechUpgradeResponse::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TechUpgradeResponse::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TechUpgradeResponse::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TechUpgradeResponse::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 TechUpgradeResponse::type() const {
  return type_;
}
inline void TechUpgradeResponse::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// required bool quick = 2;
inline bool TechUpgradeResponse::has_quick() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TechUpgradeResponse::set_has_quick() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TechUpgradeResponse::clear_has_quick() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TechUpgradeResponse::clear_quick() {
  quick_ = false;
  clear_has_quick();
}
inline bool TechUpgradeResponse::quick() const {
  return quick_;
}
inline void TechUpgradeResponse::set_quick(bool value) {
  set_has_quick();
  quick_ = value;
}

// -------------------------------------------------------------------

// UseSkillRequest

// required int32 type = 1;
inline bool UseSkillRequest::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void UseSkillRequest::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void UseSkillRequest::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void UseSkillRequest::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 UseSkillRequest::type() const {
  return type_;
}
inline void UseSkillRequest::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// -------------------------------------------------------------------

// UseSkillResponse

// required int32 type = 1;
inline bool UseSkillResponse::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void UseSkillResponse::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void UseSkillResponse::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void UseSkillResponse::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 UseSkillResponse::type() const {
  return type_;
}
inline void UseSkillResponse::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}

// repeated .slg.protocol.PropertyDTO properties = 2;
inline int UseSkillResponse::properties_size() const {
  return properties_.size();
}
inline void UseSkillResponse::clear_properties() {
  properties_.Clear();
}
inline const ::slg::protocol::PropertyDTO& UseSkillResponse::properties(int index) const {
  return properties_.Get(index);
}
inline ::slg::protocol::PropertyDTO* UseSkillResponse::mutable_properties(int index) {
  return properties_.Mutable(index);
}
inline ::slg::protocol::PropertyDTO* UseSkillResponse::add_properties() {
  return properties_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::slg::protocol::PropertyDTO >&
UseSkillResponse::properties() const {
  return properties_;
}
inline ::google::protobuf::RepeatedPtrField< ::slg::protocol::PropertyDTO >*
UseSkillResponse::mutable_properties() {
  return &properties_;
}

// optional .slg.protocol.PositionDTO position = 3;
inline bool UseSkillResponse::has_position() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void UseSkillResponse::set_has_position() {
  _has_bits_[0] |= 0x00000004u;
}
inline void UseSkillResponse::clear_has_position() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void UseSkillResponse::clear_position() {
  if (position_ != NULL) position_->::slg::protocol::PositionDTO::Clear();
  clear_has_position();
}
inline const ::slg::protocol::PositionDTO& UseSkillResponse::position() const {
  return position_ != NULL ? *position_ : *default_instance_->position_;
}
inline ::slg::protocol::PositionDTO* UseSkillResponse::mutable_position() {
  set_has_position();
  if (position_ == NULL) position_ = new ::slg::protocol::PositionDTO;
  return position_;
}
inline ::slg::protocol::PositionDTO* UseSkillResponse::release_position() {
  clear_has_position();
  ::slg::protocol::PositionDTO* temp = position_;
  position_ = NULL;
  return temp;
}
inline void UseSkillResponse::set_allocated_position(::slg::protocol::PositionDTO* position) {
  delete position_;
  position_ = position;
  if (position) {
    set_has_position();
  } else {
    clear_has_position();
  }
}

// -------------------------------------------------------------------

// TechPush

// repeated .slg.protocol.TechDTO techs = 1;
inline int TechPush::techs_size() const {
  return techs_.size();
}
inline void TechPush::clear_techs() {
  techs_.Clear();
}
inline const ::slg::protocol::TechDTO& TechPush::techs(int index) const {
  return techs_.Get(index);
}
inline ::slg::protocol::TechDTO* TechPush::mutable_techs(int index) {
  return techs_.Mutable(index);
}
inline ::slg::protocol::TechDTO* TechPush::add_techs() {
  return techs_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::slg::protocol::TechDTO >&
TechPush::techs() const {
  return techs_;
}
inline ::google::protobuf::RepeatedPtrField< ::slg::protocol::TechDTO >*
TechPush::mutable_techs() {
  return &techs_;
}

// -------------------------------------------------------------------

// SkillPush

// repeated .slg.protocol.SkillDTO skills = 1;
inline int SkillPush::skills_size() const {
  return skills_.size();
}
inline void SkillPush::clear_skills() {
  skills_.Clear();
}
inline const ::slg::protocol::SkillDTO& SkillPush::skills(int index) const {
  return skills_.Get(index);
}
inline ::slg::protocol::SkillDTO* SkillPush::mutable_skills(int index) {
  return skills_.Mutable(index);
}
inline ::slg::protocol::SkillDTO* SkillPush::add_skills() {
  return skills_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::slg::protocol::SkillDTO >&
SkillPush::skills() const {
  return skills_;
}
inline ::google::protobuf::RepeatedPtrField< ::slg::protocol::SkillDTO >*
SkillPush::mutable_skills() {
  return &skills_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace slg

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::slg::protocol::TechCommandId>() {
  return ::slg::protocol::TechCommandId_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::slg::protocol::TechPushId>() {
  return ::slg::protocol::TechPushId_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_tech_2eproto__INCLUDED