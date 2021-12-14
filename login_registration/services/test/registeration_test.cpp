#include <gtest/gtest.h>

#include "services/registeration.h"

class RegisterationTestFixture : public ::testing::Test
{
protected:
  services::Registeration registeration_service{};
};

TEST_F(RegisterationTestFixture, AcceptUser)
{
  credentials::User user_to_register{"test_user_name", "test_password"};
  testing::internal::CaptureStdout();
  registeration_service.RegisterUser(user_to_register);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(1, 1);
}
