#ifndef OOP_RIDEMANAGER_H
#define OOP_RIDEMANAGER_H
#include<vector>
#include "Ride.h"
using namespace std;


class RideManager
{
public:
    static int findBestDriverIndex(const User& user, const vector<Driver>& drivers);

    static Ride createRide(const User& user, vector<Driver>& driverr, const Location& destination);

};

#endif //OOP_RIDEMANAGER_H