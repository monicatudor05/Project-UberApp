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

int ElectricCar::getBatteryPercent() const
{
    return batteryPercent;
}
void ElectricCar::setBatteryPercent(int bat)
{
    if (bat<0) bat=0;
    if (bat>100) bat=100;
    batteryPercent = bat;
}

