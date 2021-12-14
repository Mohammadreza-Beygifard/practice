
#ifndef SERV_REG
#define SERV_REG
#include "libraries/user.h"

namespace services
{
class Login
{
public:
  explicit Login();

  // TODO implement the check existense of the user in the file
  // authorized_ = false;
  // for (lines in the file)
  // if line == user
  //{
  // string username;
  // string password;
  //}
  // if line == username
  //{
  // username = username; find a way to tokenize and study the JSON
  //}
  // if line == password
  //{
  // password = password; find a way to tokenize and study the JSON
  //}
  // if enteredUserName == username && enteredPassword == password
  //{
  // authorized_ = true;
  // break;
  //}
  // if authorized_ == true
  //{
  // std::cout<< "Welcome" + suername << std::endl;
  // return;
  //}
  // std::cout<< "you are not authorized" << std::endl;
private:
  std::string username_;
  std::string password_;
  std::bool authorized_;
};
} // namespace services
#endif
