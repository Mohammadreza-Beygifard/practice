#ifndef LIB_CRED
#define LIB_CRED

#include <string>

namespace credentials
{
class User
{
public:
  // TODO add default constructor
  explicit User(const std::string username, const std::string password);
  // TODO add setters
  std::string GetUserName();
  std::string GetPassword();

private:
  std::string username_;
  std::string password_;
};
} // namespace credentials
#endif
