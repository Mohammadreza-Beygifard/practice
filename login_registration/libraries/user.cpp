#include "user.h"

namespace credentials
{

User::User(const std::string username, const std::string password)
    : username_(username), password_(password)
{
}

} // namespace credentials
