#ifndef OOP_RIDE_H
#define OOP_RIDE_H
#include<iosfwd>
#include "User.h"
#include "Driver.h"
#include "Location.h"

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

    void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& out, const Ride& r);


#endif //OOP_RIDE_H