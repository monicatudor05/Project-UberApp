#include "Ride.h"
#include "Car.h"
#include "Driver.h"
#include "User.h"
#include<ostream>


Ride::Ride(std::shared_ptr<const User> usr, std::shared_ptr<const Driver> drv, const Location& destination):
user(std::move(usr)),driver(std::move(drv)),start((*usr).getLocation()),destination(destination), price(0.0),distance(0.0)
{
    distance=start.distanceTo(destination);
    price=distance * (*driver).getCar().priceMultiplier();
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
    out<<"User: "<<(*user).getFullName()<<"\n";
    out<<"Driver: "<<(*driver).getFullName()<<"\n";
    out<<"Car: "<<(*driver).getCar()<<"\n";
    out<<"From: "<<start<<"\n";
    out<<"To: "<<destination<<"\n";
    out<<"Price: "<<price<<"\n";
}
std::ostream& operator<<(std::ostream& out, const Ride& ride)
{
    ride.print(out);
    return out;
}