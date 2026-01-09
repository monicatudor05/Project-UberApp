#ifndef OOP_MENU_H
#define OOP_MENU_H
#include<vector>
#include<memory>
class User;
class Driver;
class Ride;
class Location;//aici am modif

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
    void sortDriversByDistance(std::vector<std::shared_ptr<Driver>>& list, Location& userLocation);
    void showDriversByDistance();
    //trb sa implementez sortare cu lambda pt driverii available si  cei mai apropiati de user
    //trb sa implementez o cautare dupa un anumit user, adica sa mi afisezee isstoricul unui user
    void requestRide();
    void addUser();
    void addDriver();

public:
    Menu(std::vector<std::shared_ptr<User>>& users, std::vector<std::shared_ptr<Driver>>& drivers, std::vector<Ride>& rides);
    void run();

};

#endif //OOP_MENU_H