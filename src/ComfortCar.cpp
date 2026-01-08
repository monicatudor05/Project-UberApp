#include "ComfortCar.h"
#include<iostream>
using namespace std;
ComfortCar::ComfortCar():Car(),nrSeats(4){}
ComfortCar::ComfortCar(const string& brand, const string& model, const string& plate, int number ):
Car(brand, model, plate), nrSeats(number){}

double ComfortCar::priceMultiplier() const
{
    return 3.5;
}

CarType ComfortCar::getTypeCar() const
{
    return CarType::ComfortCar;
}

void ComfortCar::print(ostream& out) const
{
    Car::print(out);
    out<<"Number seats: "<<nrSeats;
}

void ComfortCar::read(istream& in)
{
    Car::read(in);
    in>>nrSeats;

}

int ComfortCar::getNrSeats() const
{
    return nrSeats;
}

void ComfortCar::setNrSeats(int number)
{
    nrSeats=number;
}
