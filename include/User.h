#ifndef OOP_USER_H
#define OOP_USER_H
#include "Location.h"
#include <iostream>
using namespace std;
class User
{
private:
    string fullname;
    string email;
    int id;
    Location location;

public:
    User();
    User(const string& fullname, const string& email, int id,  const Location& loc);
    ~User();

    const string& getFullName() const;
    const string& getEmail() const;
    int getId() const;
    const Location& getLocation() const;

    friend ostream& operator<<(ostream& out, const User& usr);
    friend istream& operator>>(istream& in, User& usr);


};


#endif //OOP_USER_H