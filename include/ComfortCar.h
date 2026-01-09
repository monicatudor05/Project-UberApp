#ifndef OOP_COMFORTCLASS_H
#define OOP_COMFORTCLASS_H
#include "Car.h"

class ComfortCar: public Car
{
private:
    int nrSeats;
public:
    ComfortCar();
    ComfortCar(const std::string& brand, const std::string& model, const std::string& plate, int seats);
    ~ComfortCar() override=default;

    double priceMultiplier() const override;
    CarType getTypeCar() const override;

    void print(std::ostream& out) const override;
    void read(std::istream& in) override;

    [[maybe_unused]]
    int getNrSeats() const;
    [[maybe_unused]]
    void setNrSeats(int number);
};

#endif //OOP_COMFORTCLASS_H