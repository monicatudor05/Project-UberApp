#ifndef OOP_CARFACTORY_H
#define OOP_CARFACTORY_H
#include "Car.h"
#include<memory>
#include<iosfwd>


std::shared_ptr<Car> readCarptr(std::istream& in);



#endif //OOP_CARFACTORY_H
