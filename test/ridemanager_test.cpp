#include <gtest/gtest.h>
#include <memory>
#include <vector>

#include "RideManager.h"
#include "User.h"
#include "Driver.h"
#include "StandardCar.h"
#include "ElectricCar.h"
#include "Location.h"
static std::shared_ptr<User> makeUser(
        const std::string& name,
        const std::string& email,
        int id,
        const Location& loc
) {
    return std::make_shared<User>(name, email, id, loc);
}


static std::shared_ptr<Driver> makeDriver(
        const std::string& name,
        const Location& loc,
        const std::shared_ptr<Car>& car,
        bool available
) {
    return std::make_shared<Driver>(name, loc, car, available);
}

TEST(RideManager_FindBestDriverIndex, ReturnsIndexOfAvailableDriver) {
    auto u = makeUser("Ana", "ana@mail.com", 1, Location(0, 0));

    auto car1 = std::make_shared<StandardCar>("Dacia", "Logan", "B-1", true);
    auto car2 = std::make_shared<ElectricCar>("Tesla", "3", "B-2", 80);

    auto d0 = makeDriver("Busy Driver", Location(0, 0), car1, false);
    auto d1 = makeDriver("Available Driver", Location(1, 1), car2, true);

    std::vector<std::shared_ptr<Driver>> drivers{d0, d1};

    int idx = RideManager::findBestDriverIndex(*u, drivers);

    EXPECT_EQ(idx, 1);
}

TEST(RideManager_FindBestDriverIndex, ReturnsMinus1IfNoAvailableDrivers) {
    auto u = makeUser("Maria", "maria@mail.com", 2, Location(0, 0));

    auto car1 = std::make_shared<StandardCar>("VW", "Polo", "B-3", true);
    auto car2 = std::make_shared<ElectricCar>("Nissan", "Leaf", "B-4", 60);

    auto d0 = makeDriver("Busy 1", Location(1, 1), car1, false);
    auto d1 = makeDriver("Busy 2", Location(2, 2), car2, false);

    std::vector<std::shared_ptr<Driver>> drivers{d0, d1};

    int idx = RideManager::findBestDriverIndex(*u, drivers);

    EXPECT_EQ(idx, -1);
}

TEST(RideManager_FindBestDriverIndex, HandlesEmptyDriversVector) {
    auto u = makeUser("Ioana", "ioana@mail.com", 3, Location(0, 0));
    std::vector<std::shared_ptr<Driver>> drivers;

    int idx = RideManager::findBestDriverIndex(*u, drivers);

    EXPECT_EQ(idx, -1);
}

TEST(RideManager_CreateRide, CreatesRideWithPositiveDistanceAndPrice) {

    auto u = makeUser("Elena", "elena@mail.com", 4, Location(0, 0));
    Location destination(3, 4);

    auto car = std::make_shared<StandardCar>("Toyota", "Yaris", "B-5", true);
    auto d  = makeDriver("Driver 1", Location(0, 0), car, true);

    std::vector<std::shared_ptr<Driver>> drivers{d};

    Ride r = RideManager::createRide(u, drivers, destination);

    EXPECT_GT(r.getDistance(), 0.0);
    EXPECT_GT(r.getPrice(), 0.0);
}

TEST(RideManager_CreateRide, RideDistanceMatchesUserToDestinationIfThatIsYourLogic) {
    auto u = makeUser("Andreea", "a@mail.com", 5, Location(0, 0));
    Location destination(3, 4);

    auto car = std::make_shared<StandardCar>("Skoda", "Fabia", "B-6", true);
    auto d  = makeDriver("Driver 2", Location(100, 100), car, true);

    std::vector<std::shared_ptr<Driver>> drivers{d};

    Ride r = RideManager::createRide(u, drivers, destination);

    EXPECT_DOUBLE_EQ(r.getDistance(), 5.0);
}

TEST(RideManager_CreateRide, ThrowsOrFailsWhenNoDriversAvailable) {

    auto u = makeUser("Daria", "d@mail.com", 6, Location(0, 0));
    Location destination(1, 1);

    auto car = std::make_shared<ElectricCar>("Tesla", "Y", "B-7", 50);
    auto d  = makeDriver("Busy", Location(0, 0), car, false);

    std::vector<std::shared_ptr<Driver>> drivers{d};

    EXPECT_ANY_THROW({
        (void)RideManager::createRide(u, drivers, destination);
    });
}
