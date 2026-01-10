#ifndef OOP_USER_H
#define OOP_USER_H
#include "Location.h"
#include <iosfwd>
#include <string>
class User
{
private:
    std::string fullname;
    std::string email;
    int id;
    Location location;

public:
    User();
    User(const std::string& fullname, const std::string& email, int id,  const Location& loc);
    ~User()=default;

    const std::string& getFullName() const;

    const Location& getLocation() const;

    friend std::ostream& operator<<(std::ostream& out, const User& usr);
    friend std::istream& operator>>(std::istream& in, User& usr);

};


#endif //OOP_USER_H