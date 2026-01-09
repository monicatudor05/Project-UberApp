
#ifndef OOP_STANDARDCAR_H
#define OOP_STANDARDCAR_H
#include "Car.h"

class StandardCar:public Car
{
private:
    bool hasAC;
public:
    StandardCar();
    StandardCar(const std::string& brand, const std::string& model, const std::string& plate, bool hasAC);
    ~ StandardCar() override=default;

    double priceMultiplier() const override;
    CarType getTypeCar() const override;

    void print(std::ostream& out) const override;
    void read(std::istream& in) override;

    [[maybe_unused]]
    bool getHasAC() const;
    [[maybe_unused]]
    void setHasAC(bool hasAC);




};

#endif //OOP_STANDARDCAR_H