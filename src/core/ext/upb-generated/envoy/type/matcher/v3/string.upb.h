/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/type/matcher/v3/string.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#ifndef ENVOY_TYPE_MATCHER_V3_STRING_PROTO_UPB_H_
#define ENVOY_TYPE_MATCHER_V3_STRING_PROTO_UPB_H_

#include "upb/collections/array_internal.h"
#include "upb/collections/map_gencode_util.h"
#include "upb/message/accessors.h"
#include "upb/message/internal.h"
#include "upb/mini_table/enum_internal.h"
#include "upb/wire/decode.h"
#include "upb/wire/decode_fast.h"
#include "upb/wire/encode.h"

// Must be last. 
#include "upb/port/def.inc"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct envoy_type_matcher_v3_StringMatcher envoy_type_matcher_v3_StringMatcher;
typedef struct envoy_type_matcher_v3_ListStringMatcher envoy_type_matcher_v3_ListStringMatcher;
extern const upb_MiniTable envoy_type_matcher_v3_StringMatcher_msg_init;
extern const upb_MiniTable envoy_type_matcher_v3_ListStringMatcher_msg_init;
struct envoy_type_matcher_v3_RegexMatcher;
extern const upb_MiniTable envoy_type_matcher_v3_RegexMatcher_msg_init;



/* envoy.type.matcher.v3.StringMatcher */

UPB_INLINE envoy_type_matcher_v3_StringMatcher* envoy_type_matcher_v3_StringMatcher_new(upb_Arena* arena) {
  return (envoy_type_matcher_v3_StringMatcher*)_upb_Message_New(&envoy_type_matcher_v3_StringMatcher_msg_init, arena);
}
UPB_INLINE envoy_type_matcher_v3_StringMatcher* envoy_type_matcher_v3_StringMatcher_parse(const char* buf, size_t size, upb_Arena* arena) {
  envoy_type_matcher_v3_StringMatcher* ret = envoy_type_matcher_v3_StringMatcher_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_StringMatcher_msg_init, NULL, 0, arena) != kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE envoy_type_matcher_v3_StringMatcher* envoy_type_matcher_v3_StringMatcher_parse_ex(const char* buf, size_t size,
                           const upb_ExtensionRegistry* extreg,
                           int options, upb_Arena* arena) {
  envoy_type_matcher_v3_StringMatcher* ret = envoy_type_matcher_v3_StringMatcher_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_StringMatcher_msg_init, extreg, options, arena) !=
      kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE char* envoy_type_matcher_v3_StringMatcher_serialize(const envoy_type_matcher_v3_StringMatcher* msg, upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &envoy_type_matcher_v3_StringMatcher_msg_init, 0, arena, &ptr, len);
  return ptr;
}
UPB_INLINE char* envoy_type_matcher_v3_StringMatcher_serialize_ex(const envoy_type_matcher_v3_StringMatcher* msg, int options,
                                 upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &envoy_type_matcher_v3_StringMatcher_msg_init, options, arena, &ptr, len);
  return ptr;
}
typedef enum {
  envoy_type_matcher_v3_StringMatcher_match_pattern_exact = 1,
  envoy_type_matcher_v3_StringMatcher_match_pattern_prefix = 2,
  envoy_type_matcher_v3_StringMatcher_match_pattern_suffix = 3,
  envoy_type_matcher_v3_StringMatcher_match_pattern_safe_regex = 5,
  envoy_type_matcher_v3_StringMatcher_match_pattern_contains = 7,
  envoy_type_matcher_v3_StringMatcher_match_pattern_NOT_SET = 0
} envoy_type_matcher_v3_StringMatcher_match_pattern_oneofcases;
UPB_INLINE envoy_type_matcher_v3_StringMatcher_match_pattern_oneofcases envoy_type_matcher_v3_StringMatcher_match_pattern_case(const envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {1, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  return (envoy_type_matcher_v3_StringMatcher_match_pattern_oneofcases)upb_Message_WhichOneofFieldNumber(msg, &field);
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_clear_exact(envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {1, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE upb_StringView envoy_type_matcher_v3_StringMatcher_exact(const envoy_type_matcher_v3_StringMatcher* msg) {
  upb_StringView default_val = upb_StringView_FromString("");
  upb_StringView ret;
  const upb_MiniTableField field = {1, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE bool envoy_type_matcher_v3_StringMatcher_has_exact(const envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {1, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  return _upb_Message_HasNonExtensionField(msg, &field);
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_clear_prefix(envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {2, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE upb_StringView envoy_type_matcher_v3_StringMatcher_prefix(const envoy_type_matcher_v3_StringMatcher* msg) {
  upb_StringView default_val = upb_StringView_FromString("");
  upb_StringView ret;
  const upb_MiniTableField field = {2, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE bool envoy_type_matcher_v3_StringMatcher_has_prefix(const envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {2, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  return _upb_Message_HasNonExtensionField(msg, &field);
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_clear_suffix(envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {3, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE upb_StringView envoy_type_matcher_v3_StringMatcher_suffix(const envoy_type_matcher_v3_StringMatcher* msg) {
  upb_StringView default_val = upb_StringView_FromString("");
  upb_StringView ret;
  const upb_MiniTableField field = {3, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE bool envoy_type_matcher_v3_StringMatcher_has_suffix(const envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {3, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  return _upb_Message_HasNonExtensionField(msg, &field);
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_clear_safe_regex(envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {5, 8, -5, 0, 11, kUpb_FieldMode_Scalar | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE const struct envoy_type_matcher_v3_RegexMatcher* envoy_type_matcher_v3_StringMatcher_safe_regex(const envoy_type_matcher_v3_StringMatcher* msg) {
  const struct envoy_type_matcher_v3_RegexMatcher* default_val = NULL;
  const struct envoy_type_matcher_v3_RegexMatcher* ret;
  const upb_MiniTableField field = {5, 8, -5, 0, 11, kUpb_FieldMode_Scalar | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE bool envoy_type_matcher_v3_StringMatcher_has_safe_regex(const envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {5, 8, -5, 0, 11, kUpb_FieldMode_Scalar | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  return _upb_Message_HasNonExtensionField(msg, &field);
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_clear_ignore_case(envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {6, 0, 0, kUpb_NoSub, 8, kUpb_FieldMode_Scalar | (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE bool envoy_type_matcher_v3_StringMatcher_ignore_case(const envoy_type_matcher_v3_StringMatcher* msg) {
  bool default_val = false;
  bool ret;
  const upb_MiniTableField field = {6, 0, 0, kUpb_NoSub, 8, kUpb_FieldMode_Scalar | (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_clear_contains(envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {7, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE upb_StringView envoy_type_matcher_v3_StringMatcher_contains(const envoy_type_matcher_v3_StringMatcher* msg) {
  upb_StringView default_val = upb_StringView_FromString("");
  upb_StringView ret;
  const upb_MiniTableField field = {7, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_GetNonExtensionField(msg, &field, &default_val, &ret);
  return ret;
}
UPB_INLINE bool envoy_type_matcher_v3_StringMatcher_has_contains(const envoy_type_matcher_v3_StringMatcher* msg) {
  const upb_MiniTableField field = {7, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  return _upb_Message_HasNonExtensionField(msg, &field);
}

UPB_INLINE void envoy_type_matcher_v3_StringMatcher_set_exact(envoy_type_matcher_v3_StringMatcher *msg, upb_StringView value) {
  const upb_MiniTableField field = {1, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_set_prefix(envoy_type_matcher_v3_StringMatcher *msg, upb_StringView value) {
  const upb_MiniTableField field = {2, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_set_suffix(envoy_type_matcher_v3_StringMatcher *msg, upb_StringView value) {
  const upb_MiniTableField field = {3, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_set_safe_regex(envoy_type_matcher_v3_StringMatcher *msg, struct envoy_type_matcher_v3_RegexMatcher* value) {
  const upb_MiniTableField field = {5, 8, -5, 0, 11, kUpb_FieldMode_Scalar | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE struct envoy_type_matcher_v3_RegexMatcher* envoy_type_matcher_v3_StringMatcher_mutable_safe_regex(envoy_type_matcher_v3_StringMatcher* msg, upb_Arena* arena) {
  struct envoy_type_matcher_v3_RegexMatcher* sub = (struct envoy_type_matcher_v3_RegexMatcher*)envoy_type_matcher_v3_StringMatcher_safe_regex(msg);
  if (sub == NULL) {
    sub = (struct envoy_type_matcher_v3_RegexMatcher*)_upb_Message_New(&envoy_type_matcher_v3_RegexMatcher_msg_init, arena);
    if (sub) envoy_type_matcher_v3_StringMatcher_set_safe_regex(msg, sub);
  }
  return sub;
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_set_ignore_case(envoy_type_matcher_v3_StringMatcher *msg, bool value) {
  const upb_MiniTableField field = {6, 0, 0, kUpb_NoSub, 8, kUpb_FieldMode_Scalar | (kUpb_FieldRep_1Byte << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}
UPB_INLINE void envoy_type_matcher_v3_StringMatcher_set_contains(envoy_type_matcher_v3_StringMatcher *msg, upb_StringView value) {
  const upb_MiniTableField field = {7, 8, -5, kUpb_NoSub, 9, kUpb_FieldMode_Scalar | (kUpb_FieldRep_StringView << kUpb_FieldRep_Shift)};
  _upb_Message_SetNonExtensionField(msg, &field, &value);
}

/* envoy.type.matcher.v3.ListStringMatcher */

UPB_INLINE envoy_type_matcher_v3_ListStringMatcher* envoy_type_matcher_v3_ListStringMatcher_new(upb_Arena* arena) {
  return (envoy_type_matcher_v3_ListStringMatcher*)_upb_Message_New(&envoy_type_matcher_v3_ListStringMatcher_msg_init, arena);
}
UPB_INLINE envoy_type_matcher_v3_ListStringMatcher* envoy_type_matcher_v3_ListStringMatcher_parse(const char* buf, size_t size, upb_Arena* arena) {
  envoy_type_matcher_v3_ListStringMatcher* ret = envoy_type_matcher_v3_ListStringMatcher_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_ListStringMatcher_msg_init, NULL, 0, arena) != kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE envoy_type_matcher_v3_ListStringMatcher* envoy_type_matcher_v3_ListStringMatcher_parse_ex(const char* buf, size_t size,
                           const upb_ExtensionRegistry* extreg,
                           int options, upb_Arena* arena) {
  envoy_type_matcher_v3_ListStringMatcher* ret = envoy_type_matcher_v3_ListStringMatcher_new(arena);
  if (!ret) return NULL;
  if (upb_Decode(buf, size, ret, &envoy_type_matcher_v3_ListStringMatcher_msg_init, extreg, options, arena) !=
      kUpb_DecodeStatus_Ok) {
    return NULL;
  }
  return ret;
}
UPB_INLINE char* envoy_type_matcher_v3_ListStringMatcher_serialize(const envoy_type_matcher_v3_ListStringMatcher* msg, upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &envoy_type_matcher_v3_ListStringMatcher_msg_init, 0, arena, &ptr, len);
  return ptr;
}
UPB_INLINE char* envoy_type_matcher_v3_ListStringMatcher_serialize_ex(const envoy_type_matcher_v3_ListStringMatcher* msg, int options,
                                 upb_Arena* arena, size_t* len) {
  char* ptr;
  (void)upb_Encode(msg, &envoy_type_matcher_v3_ListStringMatcher_msg_init, options, arena, &ptr, len);
  return ptr;
}
UPB_INLINE void envoy_type_matcher_v3_ListStringMatcher_clear_patterns(envoy_type_matcher_v3_ListStringMatcher* msg) {
  const upb_MiniTableField field = {1, 0, 0, 0, 11, kUpb_FieldMode_Array | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  _upb_Message_ClearNonExtensionField(msg, &field);
}
UPB_INLINE const envoy_type_matcher_v3_StringMatcher* const* envoy_type_matcher_v3_ListStringMatcher_patterns(const envoy_type_matcher_v3_ListStringMatcher* msg, size_t* size) {
  const upb_MiniTableField field = {1, 0, 0, 0, 11, kUpb_FieldMode_Array | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  const upb_Array* arr = upb_Message_GetArray(msg, &field);
  if (arr) {
    if (size) *size = arr->size;
    return (const envoy_type_matcher_v3_StringMatcher* const*)_upb_array_constptr(arr);
  } else {
    if (size) *size = 0;
    return NULL;
  }
}
UPB_INLINE bool envoy_type_matcher_v3_ListStringMatcher_has_patterns(const envoy_type_matcher_v3_ListStringMatcher* msg) {
  size_t size;
  envoy_type_matcher_v3_ListStringMatcher_patterns(msg, &size);
  return size != 0;
}

UPB_INLINE envoy_type_matcher_v3_StringMatcher** envoy_type_matcher_v3_ListStringMatcher_mutable_patterns(envoy_type_matcher_v3_ListStringMatcher* msg, size_t* size) {
  upb_MiniTableField field = {1, 0, 0, 0, 11, kUpb_FieldMode_Array | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  upb_Array* arr = upb_Message_GetMutableArray(msg, &field);
  if (arr) {
    if (size) *size = arr->size;
    return (envoy_type_matcher_v3_StringMatcher**)_upb_array_ptr(arr);
  } else {
    if (size) *size = 0;
    return NULL;
  }
}
UPB_INLINE envoy_type_matcher_v3_StringMatcher** envoy_type_matcher_v3_ListStringMatcher_resize_patterns(envoy_type_matcher_v3_ListStringMatcher* msg, size_t size, upb_Arena* arena) {
  upb_MiniTableField field = {1, 0, 0, 0, 11, kUpb_FieldMode_Array | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  return (envoy_type_matcher_v3_StringMatcher**)upb_Message_ResizeArray(msg, &field, size, arena);
}
UPB_INLINE struct envoy_type_matcher_v3_StringMatcher* envoy_type_matcher_v3_ListStringMatcher_add_patterns(envoy_type_matcher_v3_ListStringMatcher* msg, upb_Arena* arena) {
  upb_MiniTableField field = {1, 0, 0, 0, 11, kUpb_FieldMode_Array | (UPB_SIZE(kUpb_FieldRep_4Byte, kUpb_FieldRep_8Byte) << kUpb_FieldRep_Shift)};
  upb_Array* arr = upb_Message_GetOrCreateMutableArray(msg, &field, arena);
  if (!arr || !_upb_Array_ResizeUninitialized(arr, arr->size + 1, arena)) {
    return NULL;
  }
  struct envoy_type_matcher_v3_StringMatcher* sub = (struct envoy_type_matcher_v3_StringMatcher*)_upb_Message_New(&envoy_type_matcher_v3_StringMatcher_msg_init, arena);
  if (!arr || !sub) return NULL;
  _upb_Array_Set(arr, arr->size - 1, &sub, sizeof(sub));
  return sub;
}

extern const upb_MiniTableFile envoy_type_matcher_v3_string_proto_upb_file_layout;

#ifdef __cplusplus
}  /* extern "C" */
#endif

#include "upb/port/undef.inc"

#endif  /* ENVOY_TYPE_MATCHER_V3_STRING_PROTO_UPB_H_ */
