#ifndef OOP_RIDE_H
#define OOP_RIDE_H
#include<iosfwd>

#include "Location.h"
#include<memory>
class User;
class Driver;
class Ride
{
private:
    std::shared_ptr<const User> user;
    std::shared_ptr<const Driver> driver;
    Location start;
    Location destination;
    double price{0.0};
    double distance{0.0};

public:
    Ride(std::shared_ptr<const User> usr, std::shared_ptr<const Driver> driver, const Location& dest);
    ~Ride()=default;

    double getDistance() const;
    double getPrice() const;

    void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& out, const Ride& r);


#endif //OOP_RIDE_H