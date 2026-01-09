#include "Ride.h"
#include "Car.h"
#include "Driver.h"
#include "User.h"
#include<ostream>


Ride::Ride(const User& usr, const Driver& driver, const Location& dest):
    user(usr),
    driver(driver),
    start(usr.getLocation()),
    destination(dest),
    price(0.0),
    distance(0.0)
{
    distance=start.distanceTo(destination);
    price=distance * driver.getCar().priceMultiplier();
}

double Ride::getDistance() const
{
    return distance;
}

double Ride::getPrice() const
{
    return price;
}
void Ride::print(std::ostream& out) const
{
    out<<"====RIDE=====";
    out<<"User: "<< user.getFullName() << std::endl;
    out<<"Driver: "<< driver.getFullName()<< std::endl;
    out<<"Car: "<< driver.getCar()<< std::endl;
    out<<"From: "<< start << std::endl;
    out<<"To: "<< destination << std::endl;
    out<<"Price: "<< price << std::endl;
}
std::ostream& operator<<(std::ostream& out, const Ride& ride)
{
    ride.print(out);
    return out;
}