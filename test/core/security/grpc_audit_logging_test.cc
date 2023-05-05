//
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
//

#include <grpc/support/port_platform.h>

#include <memory>
#include <string>

#include <gtest/gtest.h>

#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "absl/strings/string_view.h"

#include <grpc/grpc_audit_logging.h>

#include "src/core/lib/json/json.h"
#include "src/core/lib/json/json_reader.h"
#include "src/core/lib/security/authorization/audit_logging.h"
#include "test/core/util/test_config.h"
#include "test/core/util/tls_utils.h"

namespace grpc_core {
namespace testing {

constexpr absl::string_view kName = "test_logger";

using experimental::AuditContext;
using experimental::AuditLogger;
using experimental::AuditLoggerFactory;
using experimental::AuditLoggerRegistry;
using experimental::RegisterAuditLoggerFactory;

namespace {

class TestAuditLogger : public AuditLogger {
 public:
  void Log(const AuditContext&) override {}
};

class TestAuditLoggerFactory : public AuditLoggerFactory {
 public:
  class TestConfig : public Config {
   public:
    absl::string_view name() const override { return kName; }
    std::string ToString() const override { return "test_config"; }
  };

  absl::string_view name() const override { return kName; }
  std::unique_ptr<AuditLogger> CreateAuditLogger(
      std::unique_ptr<AuditLoggerFactory::Config>) override {
    return std::make_unique<TestAuditLogger>();
  }
  absl::StatusOr<std::unique_ptr<Config>> ParseAuditLoggerConfig(
      const Json&) override {
    return std::make_unique<TestConfig>();
  }
};

class AuditLoggerRegistryTest : public ::testing::Test {
 protected:
  void SetUp() override {
    RegisterAuditLoggerFactory(std::make_unique<TestAuditLoggerFactory>());
  }
  void TearDown() override { AuditLoggerRegistry::TestOnlyResetRegistry(); }
};

}  // namespace

//
// AuditLoggerRegistryTest
//

TEST_F(AuditLoggerRegistryTest, SuccessfulLoggerCreation) {
  auto result = AuditLoggerRegistry::ParseConfig(kName, Json());
  ASSERT_TRUE(result.ok());
  ASSERT_NE(AuditLoggerRegistry::CreateAuditLogger(std::move(result.value())),
            nullptr);
}

TEST_F(AuditLoggerRegistryTest, UnknownLogger) {
  auto result = AuditLoggerRegistry::ParseConfig("unknown_logger", Json());
  EXPECT_EQ(result.status().code(), absl::StatusCode::kNotFound);
  EXPECT_EQ(result.status().message(),
            "audit logger factory for unknown_logger does not exist")
      << result.status();
}

TEST_F(AuditLoggerRegistryTest, LoggerFactoryExistenceChecks) {
  EXPECT_TRUE(AuditLoggerRegistry::FactoryExists(kName));
  EXPECT_FALSE(AuditLoggerRegistry::FactoryExists("unknown_logger"));
}

//
//  StdoutLoggerTest
//

TEST(StdoutLoggerTest, LoggerFactoryExistenceChecks) {
  EXPECT_TRUE(AuditLoggerRegistry::FactoryExists("stdout_logger"));
}

TEST(StdoutLoggerTest, BadLoggerConfig) {
  auto result =
      AuditLoggerRegistry::ParseConfig("stdout_logger", Json::FromBool(false));
  ASSERT_EQ(result.status().code(), absl::StatusCode::kInvalidArgument);
  ASSERT_EQ(result.status().message(), "config is not a json object")
      << result.status();
}

TEST(StdoutLoggerTest, StdoutLoggerCreationAndLogInvocation) {
  auto result =
      AuditLoggerRegistry::ParseConfig("stdout_logger", Json::FromObject({}));
  ASSERT_TRUE(result.ok());
  auto logger =
      AuditLoggerRegistry::CreateAuditLogger(std::move(result.value()));
  AuditContext context("method", "spiffe", "policy", "rule", true);
  ::testing::internal::CaptureStdout();
  logger->Log(context);
  auto output = ::testing::internal::GetCapturedStdout();
  std::cout << output << '\n';
  auto log_or = JsonParse(output);
  ASSERT_TRUE(log_or.ok());
  ASSERT_EQ(log_or.value().type(), Json::Type::kObject);
  auto it = log_or.value().object().find("grpc_audit_log");
  ASSERT_NE(it, log_or.value().object().end());
  ASSERT_EQ(it->second.type(), Json::Type::kObject);
  auto object = it->second.object();
  ASSERT_NE(object.find("timestamp"), object.end());
  EXPECT_EQ(object.find("timestamp")->second.type(), Json::Type::kNumber);
  // Check the value of everything except time stamp.
  std::map<std::string, std::string> fields = {{"rpc_method", "method"},
                                               {"principal", "spiffe"},
                                               {"policy_name", "policy"},
                                               {"matched_rule", "rule"}};
  for (const auto& p : fields) {
    auto it = object.find(p.first);
    ASSERT_NE(it, object.end());
    ASSERT_EQ(it->second.type(), Json::Type::kString);
    EXPECT_EQ(it->second.string(), p.second);
  }
  ASSERT_NE(object.find("authorized"), object.end());
  ASSERT_EQ(object.find("authorized")->second.type(), Json::Type::kBoolean);
  EXPECT_EQ(object.find("authorized")->second.boolean(), true);
}

}  // namespace testing
}  // namespace grpc_core

int main(int argc, char** argv) {
  grpc::testing::TestEnvironment env(&argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  grpc_init();
  int ret = RUN_ALL_TESTS();
  grpc_shutdown();
  return ret;
}
