#ifndef OOP_DRIVER_H
#define OOP_DRIVER_H
#include "Location.h"
#include<string>
#include<memory>
#include<iosfwd>

class Car;
class Driver
{
private:
    std::string fullname;
    Location location;
    std::shared_ptr<Car> car;
    bool available;

public:
    Driver();
    Driver(const std::string& fullname, const Location& loc, const std::shared_ptr<Car>& car, bool available);
    ~Driver() =default;

    //setters
    void setAvailable(bool available);
    [[maybe_unused]] void setLocation(const Location& loc);

    //getters
    const std::string& getFullName() const;
    const Location& getLocation() const;
    const Car& getCar() const;
    bool isAvailable() const;

    void print(std::ostream& out) const;
    void read(std::istream& in);

};

std::ostream& operator<<(std::ostream& out, const Driver& driver);
std::istream& operator>>(std::istream& in,  Driver& driver);
#endif //OOP_DRIVER_H