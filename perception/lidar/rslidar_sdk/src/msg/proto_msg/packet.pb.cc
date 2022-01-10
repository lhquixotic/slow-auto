// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: packet.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "packet.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto_msg {

namespace {

const ::google::protobuf::Descriptor* LidarPacket_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LidarPacket_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_packet_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_packet_2eproto() {
  protobuf_AddDesc_packet_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "packet.proto");
  GOOGLE_CHECK(file != NULL);
  LidarPacket_descriptor_ = file->message_type(0);
  static const int LidarPacket_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LidarPacket, data_),
  };
  LidarPacket_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      LidarPacket_descriptor_,
      LidarPacket::default_instance_,
      LidarPacket_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LidarPacket, _has_bits_[0]),
      -1,
      -1,
      sizeof(LidarPacket),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LidarPacket, _internal_metadata_),
      -1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_packet_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      LidarPacket_descriptor_, &LidarPacket::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_packet_2eproto() {
  delete LidarPacket::default_instance_;
  delete LidarPacket_reflection_;
}

void protobuf_AddDesc_packet_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_packet_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014packet.proto\022\tproto_msg\"\033\n\013LidarPacket"
    "\022\014\n\004data\030\001 \001(\014", 54);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "packet.proto", &protobuf_RegisterTypes);
  LidarPacket::default_instance_ = new LidarPacket();
  LidarPacket::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_packet_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_packet_2eproto {
  StaticDescriptorInitializer_packet_2eproto() {
    protobuf_AddDesc_packet_2eproto();
  }
} static_descriptor_initializer_packet_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int LidarPacket::kDataFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

LidarPacket::LidarPacket()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto_msg.LidarPacket)
}

void LidarPacket::InitAsDefaultInstance() {
}

LidarPacket::LidarPacket(const LidarPacket& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:proto_msg.LidarPacket)
}

void LidarPacket::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  data_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LidarPacket::~LidarPacket() {
  // @@protoc_insertion_point(destructor:proto_msg.LidarPacket)
  SharedDtor();
}

void LidarPacket::SharedDtor() {
  data_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void LidarPacket::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LidarPacket::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LidarPacket_descriptor_;
}

const LidarPacket& LidarPacket::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_packet_2eproto();
  return *default_instance_;
}

LidarPacket* LidarPacket::default_instance_ = NULL;

LidarPacket* LidarPacket::New(::google::protobuf::Arena* arena) const {
  LidarPacket* n = new LidarPacket;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void LidarPacket::Clear() {
// @@protoc_insertion_point(message_clear_start:proto_msg.LidarPacket)
  if (has_data()) {
    data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool LidarPacket::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto_msg.LidarPacket)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes data = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto_msg.LidarPacket)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto_msg.LidarPacket)
  return false;
#undef DO_
}

void LidarPacket::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto_msg.LidarPacket)
  // optional bytes data = 1;
  if (has_data()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      1, this->data(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto_msg.LidarPacket)
}

::google::protobuf::uint8* LidarPacket::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto_msg.LidarPacket)
  // optional bytes data = 1;
  if (has_data()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        1, this->data(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto_msg.LidarPacket)
  return target;
}

int LidarPacket::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:proto_msg.LidarPacket)
  int total_size = 0;

  // optional bytes data = 1;
  if (has_data()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->data());
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void LidarPacket::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:proto_msg.LidarPacket)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const LidarPacket* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const LidarPacket>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:proto_msg.LidarPacket)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:proto_msg.LidarPacket)
    MergeFrom(*source);
  }
}

void LidarPacket::MergeFrom(const LidarPacket& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto_msg.LidarPacket)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_data()) {
      set_has_data();
      data_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.data_);
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void LidarPacket::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:proto_msg.LidarPacket)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LidarPacket::CopyFrom(const LidarPacket& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto_msg.LidarPacket)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LidarPacket::IsInitialized() const {

  return true;
}

void LidarPacket::Swap(LidarPacket* other) {
  if (other == this) return;
  InternalSwap(other);
}
void LidarPacket::InternalSwap(LidarPacket* other) {
  data_.Swap(&other->data_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata LidarPacket::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LidarPacket_descriptor_;
  metadata.reflection = LidarPacket_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// LidarPacket

// optional bytes data = 1;
bool LidarPacket::has_data() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void LidarPacket::set_has_data() {
  _has_bits_[0] |= 0x00000001u;
}
void LidarPacket::clear_has_data() {
  _has_bits_[0] &= ~0x00000001u;
}
void LidarPacket::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_data();
}
 const ::std::string& LidarPacket::data() const {
  // @@protoc_insertion_point(field_get:proto_msg.LidarPacket.data)
  return data_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void LidarPacket::set_data(const ::std::string& value) {
  set_has_data();
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:proto_msg.LidarPacket.data)
}
 void LidarPacket::set_data(const char* value) {
  set_has_data();
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:proto_msg.LidarPacket.data)
}
 void LidarPacket::set_data(const void* value, size_t size) {
  set_has_data();
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:proto_msg.LidarPacket.data)
}
 ::std::string* LidarPacket::mutable_data() {
  set_has_data();
  // @@protoc_insertion_point(field_mutable:proto_msg.LidarPacket.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* LidarPacket::release_data() {
  // @@protoc_insertion_point(field_release:proto_msg.LidarPacket.data)
  clear_has_data();
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void LidarPacket::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    set_has_data();
  } else {
    clear_has_data();
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:proto_msg.LidarPacket.data)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto_msg

// @@protoc_insertion_point(global_scope)