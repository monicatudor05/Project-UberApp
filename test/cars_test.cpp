#include <gtest/gtest.h>

#include <memory>
#include <sstream>
#include <type_traits>
#include <vector>

#include "Car.h"
#include "StandardCar.h"
#include "ElectricCar.h"
#include "Location.h"

TEST(CarBase, CarIsAbstract) {
    EXPECT_TRUE(std::is_abstract_v<Car>);
}

TEST(CarBase, ToString_WorksForAllEnums) {
    EXPECT_FALSE(Car::toString(CarType::StandardCar).empty());
    EXPECT_FALSE(Car::toString(CarType::ElectricCar).empty());
    EXPECT_FALSE(Car::toString(CarType::ComfortCar).empty());
}

TEST(StandardCar, TypeAndACGetterSetter) {
    StandardCar s("Toyota", "Corolla", "B-123-ABC", true);

    EXPECT_EQ(s.getTypeCar(), CarType::StandardCar);
    EXPECT_TRUE(s.getHasAC());

    s.setHasAC(false);
    EXPECT_FALSE(s.getHasAC());
}

TEST(ElectricCar, TypeAndBatteryGetterSetter) {
    ElectricCar e("Tesla", "Model 3", "B-999-EV", 80);

    EXPECT_EQ(e.getTypeCar(), CarType::ElectricCar);
    EXPECT_EQ(e.getBatteryPercent(), 80);

    e.setBatteryPercent(15);
    EXPECT_EQ(e.getBatteryPercent(), 15);
}

TEST(CarPolymorphism, VectorOfCarPointers_WorksAndCallsOverrides) {
    std::vector<std::shared_ptr<Car>> cars;
    cars.push_back(std::make_shared<StandardCar>("Dacia", "Logan", "B-101-STD", true));
    cars.push_back(std::make_shared<ElectricCar>("Tesla", "Y", "B-202-EV", 90));

    ASSERT_EQ(cars.size(), 2u);

    for (const auto& c : cars) {
        ASSERT_NE(c, nullptr);
        EXPECT_GT(c->priceMultiplier(), 0.0);
        EXPECT_NE(Car::toString(c->getTypeCar()), "");
    }
}


TEST(ElectricCar, PriceMultiplierDoesNotCrashAndIsPositive) {
    ElectricCar e("Nissan", "Leaf", "B-EV-01", 50);
    EXPECT_GT(e.priceMultiplier(), 0.0);
}

TEST(CarIO, OperatorOutput_DoesNotCrash) {
    StandardCar s("BMW", "320d", "B-OUT-01", true);
    std::ostringstream out;
    out << s;
    EXPECT_FALSE(out.str().empty());
}

TEST(Location, DistanceTo_IsCorrectFor_3_4_5) {
    Location a(0.0, 0.0);
    Location b(3.0, 4.0);
    EXPECT_DOUBLE_EQ(a.distanceTo(b), 5.0);
}
