#include "ElectricCar.h"

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
int ElectricCar::getBatteryPercent() const
{
    return batteryPercent;
}
void ElectricCar::setBatteryPercent(int bat)
{
    batteryPercent = bat;
}

