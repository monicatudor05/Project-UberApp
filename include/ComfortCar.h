#ifndef OOP_COMFORTCLASS_H
#define OOP_COMFORTCLASS_H
#include<string>
#include<iostream>
#include "Car.h"
using namespace std;

class ComfortCar: public Car
{
private:
    int nrSeats;
public:
    ComfortCar();
    ComfortCar(const string& brand, const string& model, const string& plate, int seats);
    ~ComfortCar() override=default;

    double priceMultiplier() const override;
    CarType getTypeCar() const override;

    void print(ostream& out) const override;
    void read(istream& in) override;

    int getNrSeats() const;
    void setNrSeats(int number);
};

#endif //OOP_COMFORTCLASS_H