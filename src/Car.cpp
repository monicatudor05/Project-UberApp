#include "Car.h"
#include <iostream>


Car::Car():brand("Unknown"), model("Unknown"), plateNumber("Unknown"){}
Car::Car(const std::string& b, const std::string& m, const std::string& plate):
brand(b), model(m), plateNumber(plate){}

Car::~Car()=default;

const std::string& Car::getBrand() const
{
    return brand;
}

const std::string& Car::getModel() const
{
    return model;
}
const std::string& Car::getPlateNumber() const
{
    return plateNumber;
}

void Car::setBrand(const std::string& b)
{
    brand=b;
}
void Car::setModel(const std::string& m)
{
    model=m;
}
void Car::setPlateNumber(const std::string& p)
{
    plateNumber=p;
}

std::string Car::toString(CarType type)
{
    switch (type)
    {
    case CarType::ComfortCar:  return "Comfort";
    case CarType::ElectricCar: return "Electric";
    case CarType::StandardCar: return "Standard";
    }
    return "Unknown";

}

void Car::read(std::istream& in)
{
    std::cout<<"Enter brand:\n";
    getline(in>>std::ws, brand);
    //in>>brand;
    std::cout<<"Enter model:\n";
    getline(in>>std::ws, model);
    //in>>model;
    std::cout<<"Enter plate number:\n";
    //in>>plateNumber;
    getline(in>>std::ws, plateNumber);
}
void Car::print(std::ostream& out) const
{
    out<<Car::toString(getTypeCar())<<": "
    <<brand<<", "<<model<<", ["
    <<plateNumber<<"] x"<<priceMultiplier();
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    car.print(out);
    return out;
}
