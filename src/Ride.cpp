#include "Ride.h"

Ride::Ride(const User& usr, const Driver& driver, const Location& destination):
user(usr),driver(driver),start(user.getLocation()),destination(destination)
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
void Ride::print(ostream& out) const
{
    out<<"====RIDE=====";
    out<<"User: "<<user.getFullName()<<"\n";
    out<<"Driver: "<<driver.getFullName()<<"\n";
    out<<"Car: "<<driver.getCar()<<"\n";
    out<<"From: "<<start<<"\n";
    out<<"To: "<<destination<<"\n";
    out<<"Price: "<<price<<"\n";
}
ostream& operator<<(ostream& out, const Ride& ride)
{
    ride.print(out);
    return out;
}