#ifndef OOP_CAR_H
#define OOP_CAR_H
#include<iostream>
using namespace std;

enum class CarType{ElectricCar, StandardCar, ComfortCar};

class Car
{
protected:
    string brand;
    string model;
    string plateNumber;

public:
    Car();
    Car(const string &brand, const string& model, const string& plate);
    virtual ~Car();

    //getters
    const string& getBrand() const;
    const string& getModel() const;
    const string& getPlateNumber() const;

    //setters
    void setBrand(const string& b);
    void setModel(const string& m);
    void setPlateNumber(const string& p);

    virtual double priceMultiplier() const=0;
    virtual CarType getTypeCar() const=0;
    virtual void print(ostream& out) const;
    virtual void read(istream& in);

    static string toString(CarType type);

};
ostream& operator<<(ostream& out, const Car& car);

istream& operator>>(istream& in, Car& car);
#endif //OOP_CAR_H