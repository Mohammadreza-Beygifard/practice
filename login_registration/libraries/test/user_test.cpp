#include "libraries/user.h"
#include <gtest/gtest.h>

class UserTestFixture : public ::testing::Test
{
protected:
  credentials::User user1{"user_name_1", "password_1"};
  credentials::User user2{};
};

TEST_F(UserTestFixture, UserConstrucotr)
{
  EXPECT_EQ(user1.GetUserName(), "user_name_1");
  EXPECT_EQ(user1.GetPassword(), "password_1");
}

TEST_F(UserTestFixture, UserSetter)
{
  user2.SetUserName("user_name_2");
  user2.SetPassword("password_2");
  EXPECT_EQ(user2.GetUserName(), "user_name_2");
  EXPECT_EQ(user2.GetPassword(), "password_2");
}
