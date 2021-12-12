#include "libraries/user.h"
#include <iostream>

int main(int argc, char **argv)
{
  std::cout << "Hello App! \n" << std::endl;

  credentials::User new_user{"test_userName", "test_password"};

  std::cout << new_user.GetUserName() + " " + new_user.GetPassword()
            << std::endl;

  return 0;
}
