#ifndef OOP_APP_H
#define OOP_APP_H

#pragma once
#include <vector>
#include <memory>

class User;
class Driver;
class Ride;
class Menu;

class App {
private:
    std::vector<std::shared_ptr<User>> users;
    std::vector<std::shared_ptr<Driver>> drivers;
    std::vector<Ride> rides;

public:
    App()=default;
    void run();

};

#endif //OOP_APP_H