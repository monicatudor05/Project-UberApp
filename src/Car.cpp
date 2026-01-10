#include "Car.h"
#include <iostream>


Car::Car():brand("Unknown"), model("Unknown"), plateNumber("Unknown"){}
Car::Car(const std::string& b, const std::string& m, const std::string& plate):
brand(b), model(m), plateNumber(plate){}

Car::~Car()=default;

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

    std::cout<<"Enter model:\n";
    getline(in>>std::ws, model);

    std::cout<<"Enter plate number:\n";
    getline(in>>std::ws, plateNumber);
}
void Car::print(std::ostream& out) const
{
    out<<Car::toString(getTypeCar())<<": "
    <<brand<<", "<<model<<", ["
    <<plateNumber<<"] x"<<priceMultiplier()<<" ";
}

std::ostream& operator<<(std::ostream& out, const Car& car)
{
    car.print(out);
    return out;
}
