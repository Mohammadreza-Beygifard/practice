#ifndef LIB_CRED
#define LIB_CRED

#include <string>

namespace credentials
{
class User
{
public:
  explicit User(const std::string username, const std::string password);
  explicit User();
  void SetUserName(std::string const username);
  void SetPassword(std::string const password);
  std::string GetUserName();
  std::string GetPassword();

private:
  std::string username_;
  std::string password_;
};
} // namespace credentials
#endif
