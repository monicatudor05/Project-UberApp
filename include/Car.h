#ifndef OOP_CAR_H
#define OOP_CAR_H
#include<iosfwd>
#include<string>


enum class CarType{ElectricCar, StandardCar, ComfortCar};

class Car
{
protected:
    std::string brand;
    std::string model;
    std::string plateNumber;

public:
    Car();
    Car(const std::string &brand, const std::string& model, const std::string& plate);
    virtual ~Car();

    //getters
    [[maybe_unused]] const std::string& getBrand() const;
    [[maybe_unused]] const std::string& getModel() const;
    [[maybe_unused]] const std::string& getPlateNumber() const;

    //setters
    [[maybe_unused]] void setBrand(const std::string& b);
    [[maybe_unused]] void setModel(const std::string& m);
    [[maybe_unused]] void setPlateNumber(const std::string& p);

    virtual double priceMultiplier() const=0;
    virtual CarType getTypeCar() const=0;
    virtual void print(std::ostream& out) const;
    virtual void read(std::istream& in);


    static std::string toString(CarType type);

};
std::ostream& operator<<(std::ostream& out, const Car& car);

#endif //OOP_CAR_H