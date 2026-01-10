#ifndef OOP_ELECTRICCAR_H
#define OOP_ELECTRICCAR_H
#include "Car.h"
#include<string>
#include<iosfwd>

class ElectricCar: public Car
{
private:
    int batteryPercent;

public:
    ElectricCar();
    ElectricCar(const std::string& brand, const std::string& model, const std::string& plate, int bat);
    ~ElectricCar() override=default;

    double priceMultiplier() const override;
    CarType getTypeCar() const override;

    void print(std::ostream& out) const override;
    void read(std::istream& in) override;

    [[maybe_unused]] int getBatteryPercent() const;
    [[maybe_unused]] void setBatteryPercent(int bat);

};

#endif //OOP_ELECTRICCAR_H