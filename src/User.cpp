#include "User.h"

User::User():fullname("Unknown"),email("Unknown"), id(0),location(0.0, 0.0){}
User::User(const string& fullname, const string& email, int id, const Location& location):
fullname(fullname), email(email), id(id), location(location){}
User::~User(){}

const string& User::getFullName() const
{
    return fullname;
}

const string& User::getEmail() const
{
    return email;
}
int User::getId() const
{
    return id;
}
const Location& User::getLocation() const
{
    return location;
}
ostream& operator<<(ostream& out, const User& usr)
{
    out<<"Name: "<<usr.fullname
        <<"\nEmail: "<<usr.email
        <<"\nID: "<<usr.id
    <<"\nLocation: "<<usr.location;
    return out;
}

istream& operator>>(istream& in, User& usr)
{
    cout<<"Fullname: ";
    in>>usr.fullname;
    cout<<"Email: ";
    in>>usr.email;
    cout<<"ID: ";
    in>>usr.id;
    cout<<"Location: ";
    in>>usr.location;
    return in;
}



