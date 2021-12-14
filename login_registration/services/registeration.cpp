#include "registeration.h"
#include <iostream>
namespace services
{
Registeration::Registeration(){};

void Registeration::RegisterUser(credentials::User &user_to_register)
{
  // TODO check if it can write on the file
  std::ofstream userFile;
  userFile.open("services/user.txt");
  userFile << "Hello World!";
  userFile.close();
  // TODO add the users to the file like this
  // User
  //{
  //"username" : username,
  //"password" : password
  //}
  std::cout << user_to_register.GetUserName() + " " +
                   user_to_register.GetPassword();
}
} // namespace services
