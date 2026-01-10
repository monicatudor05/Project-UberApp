#include "User.h"
#include<istream>
#include<ostream>
#include<iostream>
User::User():fullname("Unknown"),email("Unknown"), id(0),location(0.0, 0.0){}
User::User(const std::string& fullname, const std::string& email, int id, const Location& location):
fullname(fullname), email(email), id(id), location(location){}


const std::string& User::getFullName() const
{
    return fullname;
}

const std::string& User::getEmail() const
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
std::ostream& operator<<(std::ostream& out, const User& usr)
{
    out<<"Name: "<<usr.fullname
        <<"\nEmail: "<<usr.email
        <<"\nID: "<<usr.id
    <<"\nLocation: \n"<<usr.location;
    return out;
}

std::istream& operator>>(std::istream& in, User& usr)
{
    std::cout<<"Fullname: ";
    getline(in>>std::ws, usr.fullname);
    std::cout<<"Email: ";
    in>>usr.email;
    std::cout<<"ID: ";
    in>>usr.id;
    std::cout<<"Location: ";
    in>>usr.location;
    return in;
}



