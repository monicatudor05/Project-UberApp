#include "StandardCar.h"
#include<iostream>
using namespace std;

StandardCar::StandardCar(const string& brand, const string& model, const string& plate, bool hasAC):
Car(brand, model, plate), hasAC(hasAC) {}

double StandardCar::priceMultiplier() const
{
    return 1.0;
}

CarType StandardCar::getTypeCar() const
{
    return CarType::StandardCar;
}

void StandardCar::print(ostream& out) const
{
    Car::print(out);
    out<<"AC: "<<(hasAC? "Yes": "No");

}

bool StandardCar::getHasAC() const
{
    return (hasAC? "Yes": "No");
}
void StandardCar::setHasAC(bool ac)
{
    hasAC = ac;
}


