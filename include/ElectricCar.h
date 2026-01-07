
#ifndef OOP_ELECTRICCAR_H
#define OOP_ELECTRICCAR_H
#include "Car.h"

class ElectricCar: public Car
{
private:
    int batteryPercent;

public:
    ElectricCar(const string& brand, const string& model, const string& plate, int bat);
    ~ElectricCar() override=default;

    double priceMultiplier() const override;
    CarType getTypeCar() const override;

    void print(ostream& out) const override;

    int getBatteryPercent() const;
    void setBatteryPercent(int bat);

};

#endif //OOP_ELECTRICCAR_H