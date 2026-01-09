#ifndef OOP_MENU_H
#define OOP_MENU_H
#include<vector>
#include<memory>
class User;
class Driver;
class Ride;

class Menu
{
private:
    std::vector<std::shared_ptr<User>>& users;
    std::vector<std::shared_ptr<Driver>>& drivers;
    std::vector<Ride>& rides;

    void showMainMenu() const;
    void listUsers() const;
    void listDrivers() const;
    void listRides() const;
    void listAvailableDrivers() const;

    void requestRide();
    void addUser();
    void addDriver();

public:
    Menu(std::vector<std::shared_ptr<User>>& users, std::vector<std::shared_ptr<Driver>>& drivers, std::vector<Ride>& rides);
    void run();

};

#endif //OOP_MENU_H