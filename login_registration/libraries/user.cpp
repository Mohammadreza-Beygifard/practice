#include "user.h"

namespace credentials
{

User::User(const std::string username, const std::string password)
    : username_(username), password_(password)
{
}

std::string User::GetUserName() { return username_; }
std::string User::GetPassword() { return password_; }

} // namespace credentials
