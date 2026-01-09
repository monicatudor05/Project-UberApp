#ifndef OOP_RIDEMANAGER_H
#define OOP_RIDEMANAGER_H
#include<vector>
#include<memory>
#include "Ride.h"

class User;
class Driver;
class Location;

class RideManager
{
public:
    static int findBestDriverIndex(const User& user, const std::vector<std::shared_ptr<Driver>>& drivers);

    static Ride createRide(const std::shared_ptr<User>& user, const std::vector<std::shared_ptr<Driver>>& drivers, const Location& destination);

};

#endif //OOP_RIDEMANAGER_H