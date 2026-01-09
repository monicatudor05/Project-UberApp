#include "StandardCar.h"
#include<iostream>
using namespace std;

StandardCar::StandardCar():Car(),hasAC(false){}
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
    out<<" | AC: "<<(hasAC? "Yes": "No");

}

void StandardCar::read(istream& in)
{
    Car::read(in);
    int ac=0;
    cout<<"Has AC(0/1): \n";
    in>>ac;
    hasAC=(ac==1);

}

bool StandardCar::getHasAC() const
{
    return hasAC;
}
void StandardCar::setHasAC(bool ac)
{
    hasAC = ac;
}


