#ifndef OOP_CARFACTORY_H
#define OOP_CARFACTORY_H
#include "Car.h"
#include<memory>
#include<iostream>
#include<concepts>
#include "StandardCar.h"
#include "ElectricCar.h"
#include "ComfortCar.h"
template<typename T>
concept IsCar = std::derived_from<T,Car> && requires(T t, std::istream& in)
{
    {t.read(in)}->std::same_as<void>;
};

template<IsCar T>
class GenericFactory
{
public:
    static std::shared_ptr<T> createFromStream(std::istream& in)
    {
        auto obj = std::make_shared<T>();
        obj->read(in);
        return obj;
    }

};

template<IsCar T>
std::shared_ptr<T> buildCar(std::istream& in)
{
    return GenericFactory<T>::createFromStream(in);
}

inline auto buildCar(CarType type, std::istream& in) -> std::shared_ptr<Car>
{
    switch(type)
    {
        case CarType::ElectricCar:
        return buildCar<ElectricCar>(in);
        case CarType::ComfortCar:
        return buildCar<ComfortCar>(in);
        case CarType::StandardCar:
        return buildCar<StandardCar>(in);
        default: return nullptr;
    }


}


#endif //OOP_CARFACTORY_H
