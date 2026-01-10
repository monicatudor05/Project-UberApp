#ifndef OOP_CAR_H
#define OOP_CAR_H
#include<iosfwd>
#include<string>


enum class CarType{StandardCar, ComfortCar, ElectricCar};

class Car
{
protected:
    std::string brand;
    std::string model;
    std::string plateNumber;

public:
    Car();
    Car(const std::string &brand, const std::string& model, const std::string& plate);
    virtual ~Car();


    virtual double priceMultiplier() const=0;
    virtual CarType getTypeCar() const=0;
    virtual void print(std::ostream& out) const;
    virtual void read(std::istream& in);


    static std::string toString(CarType type);

};
std::ostream& operator<<(std::ostream& out, const Car& car);

#endif //OOP_CAR_H