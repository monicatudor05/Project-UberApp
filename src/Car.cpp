#include "Car.h"
#include<iostream>
using namespace std;

Car::Car():brand("Unknown"), model("Unknown"), plateNumber("Unknown"){}
Car::Car(const string& b, const string& m, const string& plate):
brand(b), model(m), plateNumber(plate){}

Car::~Car()=default;

const string& Car::getBrand() const
{
    return brand;
}

const string& Car::getModel() const
{
    return model;
}
const string& Car::getPlateNumber() const
{
    return plateNumber;
}

void Car::setBrand(const string& b)
{
    brand=b;
}
void Car::setModel(const string& m)
{
    model=m;
}
void Car::setPlateNumber(const string& p)
{
    plateNumber=p;
}

string Car::toString(CarType type)
{
    switch (type)
    {
    case CarType::ComfortCar:  return "Comfort";
    case CarType::ElectricCar: return "Electric";
    case CarType::StandardCar: return "Standard";
    }
    return "Unknown";

}

void Car::print(ostream& out) const
{
    out<<Car::toString(getTypeCar())<<": "
    <<brand<<", "<<model<<", ["
    <<plateNumber<<"] x"<<priceMultiplier();
}

ostream& operator<<(ostream& out, const Car& car)
{
    car.print(out);
    return out;
}