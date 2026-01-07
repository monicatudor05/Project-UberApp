
#ifndef OOP_STANDARDCAR_H
#define OOP_STANDARDCAR_H
#include "Car.h"
#include<iostream>
using namespace std;

class StandardCar:public Car
{
private:
    bool hasAC;
public:
    StandardCar(const string& brand, const string& model, const string& plate, bool hasAC);
    ~ StandardCar() override=default;

    double priceMultiplier() const override;
    CarType getTypeCar() const override;

    void print(ostream& out) const override;

    bool getHasAC() const;
    void setHasAC(bool hasAC);




};

#endif //OOP_STANDARDCAR_H