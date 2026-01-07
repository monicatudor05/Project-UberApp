#ifndef OOP_RIDE_H
#define OOP_RIDE_H
#include<iostream>
#include<string>
using namespace std;
#include "User.h"
#include "Driver.h"

class Ride
{
private:
    const User& user;
    const Driver& driver;
    Location start;
    Location destination;
    double price;
    double distance;

public:
    Ride(const User& usr, const Driver& driver, const Location& dest);
    ~Ride()=default;

    double getDistance() const;
    double getPrice() const;

    void print(ostream& out) const;
};

ostream& operator<<(ostream& out, const Ride& r);


#endif //OOP_RIDE_H