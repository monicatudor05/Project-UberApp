#include "RideManager.h"
#include<stdexcept>
#include "Driver.h"
#include "User.h"
int RideManager::findBestDriverIndex(const User& user, const std::vector<std::shared_ptr<Driver>>& drivers)
{
    int bestIndex=-1;
    double bestDistance=0.0;
    bool found=false;

    for (std::size_t i=0; i<drivers.size();i++)
    {
        if ((*drivers[i]).isAvailable()==false) continue;
        double distance=user.getLocation().distanceTo((*drivers[i]).getLocation());

        if (found==false || distance< bestDistance)
        {
            bestDistance=distance;
            bestIndex=static_cast<int>(i);
            found = true;
        }
    }
    return bestIndex;

}

Ride RideManager::createRide(const std::shared_ptr<User>& user, const std::vector<std::shared_ptr<Driver>>& drivers, const Location& destination)
{
    int index = findBestDriverIndex(*user, drivers);
    if (index==-1)
    {
        throw std::runtime_error("No driver available.");
    }
    (*drivers[index]).setAvailable(false);
    return Ride(*user, *drivers[index], destination);

}