//
// Copyright 2023 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "src/core/ext/xds/xds_audit_logger_registry.h"

#include "absl/strings/string_view.h"
#include "absl/types/variant.h"
#include "envoy/config/core/v3/extension.upb.h"
#include "envoy/config/rbac/v3/rbac.upb.h"
#include "xds_common_types.h"

#include "src/core/lib/gprpp/validation_errors.h"
#include "src/core/lib/json/json.h"

namespace grpc_core {

// TODO(lwge): Add stdout logger factory once the extension proto is defined in
// envoyproxy/envoy. Also define the constructor to register this factory.

Json XdsAuditLoggerRegistry::ConvertXdsAuditLoggerConfig(
    const XdsResourceType::DecodeContext& context,
    const envoy_config_rbac_v3_RBAC_AuditLoggingOptions_AuditLoggerConfig*
        logger_config,
    ValidationErrors* errors) const {
  const auto* typed_extension_config =
      envoy_config_rbac_v3_RBAC_AuditLoggingOptions_AuditLoggerConfig_audit_logger(
          logger_config);
  // It is okay if this is not present.
  if (typed_extension_config == nullptr) {
    return Json();  // A null Json object.
  } else {
    ValidationErrors::ScopedField field(errors,
                                        ".typed_extension_config.typed_config");
    const auto* typed_config =
        envoy_config_core_v3_TypedExtensionConfig_typed_config(
            typed_extension_config);
    auto extension = ExtractXdsExtension(context, typed_config, errors);
    if (!extension.has_value()) return Json();
    // Check for registered audit logger type.
    absl::string_view* serialized_value =
        absl::get_if<absl::string_view>(&extension->value);
    if (serialized_value != nullptr) {
      auto config_factory_it =
          audit_logger_config_factories_.find(extension->type);
      if (config_factory_it != audit_logger_config_factories_.end()) {
        return config_factory_it->second->ConvertXdsAuditLoggerConfig(
            context, *serialized_value, errors);
      }
    }
  }
  // TODO(lwge): Check for third-party audit logger type.
  // Add validation error only if the config is not marked optional.
  if (!envoy_config_rbac_v3_RBAC_AuditLoggingOptions_AuditLoggerConfig_is_optional(
          logger_config)) {
    errors->AddError("unsupported audit logger type");
  }
  return Json();
}
}  // namespace grpc_core
