#ifndef OOP_DRIVER_H
#define OOP_DRIVER_H
#include "Car.h"
#include "Location.h"
#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Driver
{
private:
    string fullname;
    Location location;
    shared_ptr<Car> car;
    bool available;

public:
    Driver();
    Driver(const string& fullname, const Location& loc, shared_ptr<Car> car, bool available);
    ~Driver() =default;

    //setters
    void setAvailable(bool available);
    void setLocation(const Location& loc);

    //getters
    const string& getFullName() const;
    const Location& getLocation() const;
    const Car& getCar() const;
    bool isAvailable() const;

    void print(ostream& out) const;
    void read(istream& in);

};

ostream& operator<<(ostream& out, const Driver& driver);
istream& operator>>(istream& in,  Driver& driver);
#endif //OOP_DRIVER_H