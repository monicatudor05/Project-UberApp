#include "ComfortCar.h"

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

int ComfortCar::getNrSeats() const
{
    return nrSeats;
}

void ComfortCar::setNrSeats(int number)
{
    nrSeats=number;
}
