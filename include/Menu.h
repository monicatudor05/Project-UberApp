#ifndef OOP_MENU_H
#define OOP_MENU_H
#include<vector>
using namespace std;
class User;
class Driver;
class Ride;

class Menu
{
private:
    vector<User>& users;
    vector<Driver>& drivers;
    vector<Ride>& rides;

    void showMainMenu() const;
    void listUsers() const;
    void listDrivers() const;
    void listRides() const;
    void listAvailableDrivers() const;
    void requestRide();
    void addUser();
    void addDriver();

public:
    Menu(vector<User>& users, vector<Driver>& drivers, vector<Ride>& rides);
    void run();


};



#endif //OOP_MENU_H