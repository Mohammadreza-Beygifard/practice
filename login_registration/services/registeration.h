#ifndef SERV_REG
#define SERV_REG
#include "libraries/user.h"
#include <fstream>

namespace services
{
class Registeration
{
public:
  explicit Registeration();
  void RegisterUser(credentials::User &user_to_register);

private:
  std::string username_;
  std::string password_;
  credentials::User user_to_register_{};
};
} // namespace services
#endif
