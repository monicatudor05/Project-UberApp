#include "CarFactory.h"
#include "ComfortCar.h"
#include "ElectricCar.h"
#include "StandardCar.h"
#include<iostream>
#include<stdexcept>
#include<memory>
#include<string>
using namespace std;
shared_ptr<Car> readCarptr(istream& in)
{
    int op;
    cout<<"Car Type(0 = Standard, 1= Comfort, 2= Electric)\n";
    in>>op;
    string brand, model, plate;
    cout<<"Enter brand: ";
    in>>brand;
    cout<<"Enter model: ";
    in>>model;
    cout<<"Enter plate: ";
    in>>plate;

    if (op==0)
    {
        bool hasAC;
        cout<<"Enter has AC:(true/false) \n";
        in>>boolalpha>>hasAC;
        return make_shared<StandardCar>(brand, model, plate, hasAC);
    }
    if (op==1)
    {
        int nrSeats;
        cout<<"Enter number of seats: \n";
        in>>nrSeats;
        return make_shared<ComfortCar>(brand, model, plate,nrSeats);
    }
    if (op==2)
    {
        int battery;
        cout<<"Enter battery: \n";
        in>>battery;
        return make_shared<ElectricCar>(brand, model, plate,battery);
    }

    throw runtime_error("Invalid Car Type");
}