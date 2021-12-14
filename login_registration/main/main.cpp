#include "libraries/user.h"
#include "services/registeration.h"
#include <iostream>

int main(int argc, char **argv)
{
  std::cout << "Hello App! \n" << std::endl;
  credentials::User testUser{"test_user_name", "test_password"};
  services::Registeration registeration_service{};
  registeration_service.RegisterUser(testUser);
  // TODO check if registeration_service can write on a file
  return 0;
}
