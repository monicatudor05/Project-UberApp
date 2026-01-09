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
    const User& user;
    const Driver& driver;
    const Location& start;
    const Location& destination;
    double price{0.0};
    double distance{0.0};

public:
    Ride(const User& usr, const Driver& driver, const Location& dest);
    ~Ride()=default;

    [[maybe_unused]] double getDistance() const;
    [[maybe_unused]] double getPrice() const;

    void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& out, const Ride& r);


#endif //OOP_RIDE_H