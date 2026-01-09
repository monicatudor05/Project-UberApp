#include <gtest/gtest.h>
#include <memory>

#include "Driver.h"
#include "Location.h"
#include "StandardCar.h"
#include "ElectricCar.h"



TEST(DriverTest, DriverStartsAvailable) {
    auto car = std::make_shared<StandardCar>("Dacia", "Logan", "B-111-STD", true);
    Driver d("Ion Popescu", Location(0, 0), car, true);

    EXPECT_TRUE(d.isAvailable());
}

TEST(DriverTest, SetAvailabilityWorks) {
    auto car = std::make_shared<StandardCar>("VW", "Golf", "B-222-STD", true);
    Driver d("Alex Ionescu", Location(1, 1), car, true);

    d.setAvailable(false);
    EXPECT_FALSE(d.isAvailable());
}

TEST(DriverTest, DriverHasCar) {
    auto car = std::make_shared<ElectricCar>("Tesla", "Model 3", "B-333-EV", 80);
    Driver d("Mihai EV", Location(0, 0), car, true);

    EXPECT_EQ(d.getCar().getTypeCar(), CarType::ElectricCar);
}
