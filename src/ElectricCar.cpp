#include "ElectricCar.h"
#include<iostream>
using namespace std;

ElectricCar::ElectricCar():Car(),batteryPercent(0){}
ElectricCar::ElectricCar(const string& brand, const string& model, const string& plate, int bat):
Car(brand, model, plate), batteryPercent(bat) {}

double ElectricCar::priceMultiplier() const
{
    return 2.5;
}

CarType ElectricCar::getTypeCar() const
{
    return CarType::ElectricCar;
}

void ElectricCar::print(ostream& out) const
{
    Car::print(out);
    out<<"Battery Percent: "<<batteryPercent<<"%";
}

void ElectricCar::read(istream& in)
{
    Car::read(in);
    cout<<"Enter battery percent: "<<endl;
    in>>batteryPercent;
}


