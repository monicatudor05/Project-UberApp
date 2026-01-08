#include "Driver.h"

#include "CarFactory.h"

Driver::Driver():fullname("Unknown"),location(0.0,0.0), car(NULL), available(false){}
Driver::Driver(const string& fullname, const Location& location, shared_ptr<Car> car, bool available):
fullname(fullname), location(location),car(car),available(available){}

void Driver::setAvailable(bool a)
{
    available=a;
}

void Driver::setLocation(const Location& loc)
{
    location=loc;
}

const string& Driver::getFullName() const
{
    return fullname;
}
const Location& Driver::getLocation() const
{
    return location;
}
const Car& Driver::getCar() const
{
    return *car;
}
bool Driver::isAvailable() const
{
    return available;
}

void Driver::print(ostream& out) const
{
    out<<"Driver: "<<getFullName()<<"| Location: "
    <<getLocation()<<"| Car: "<<getCar()<<" | "
    <<boolalpha<<(available?"AVAILABLE":"BUSY");
}

void Driver::read(istream& in)
{
    cout<<"Fullname: \n";
    getline(in>>ws, fullname);
    cout<<"Location: \n";
    in>>location;
    cout<<"Car: \n";
    car=readCarptr(in);
    cout<<"Available: \n";
    in>>available;

}

ostream& operator<<(ostream& out, const Driver& driver)
{
    driver.print(out);
    return out;
}

istream& operator>>(istream& in, Driver& driver)
{
    driver.read(in);
    return in;
}