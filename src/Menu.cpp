#include "Menu.h"
#include "Ride.h"
#include "Driver.h"
#include "User.h"
#include "Car.h"
#include "Location.h"
#include<RideManager.h>
using namespace std;

Menu::Menu(vector<User>& users, vector<Driver>& drivers, vector<Ride>& rides):
users(users), drivers(drivers), rides(rides){}


void Menu::showMainMenu() const
{
    cout<<"=====================\n";
    cout<<"MINI UBER - MAIN MENU \n";
    cout<<"=====================\n";
    cout<<"1. Show all users\n ";
    cout<<"2. Show all drivers \n";
    cout<<"3. Show all available drivers\n ";
    cout<<"4. Show all rides \n";
    cout<<"5. Add user \n";
    cout<<"6. Add driver \n";
    cout<<"7. Request ride \n";
    cout<<"0. Exit \n";

}

void Menu::listUsers() const
{
    cout<<"----  USERS ----\n";
    if (users.empty())
    {
        cout<<"No users yet.\n";
        return;
    }
    for (int i=0; i<(int)users.size();i++)
    {
        cout<<i<<")"<<users[i]<<"\n";
    }

}

void Menu::listDrivers() const
{
    cout<<"---- DRIVERS ----\n";
    if (drivers.empty())
    {
        cout<<"No drivers yet.\n";
        return;
    }
    for (int i=0; i<(int)drivers.size();i++)
    {
        cout<<i<<")"<<drivers[i]<<"\n";
    }
}

void Menu::listAvailableDrivers() const
{
    cout<<"---- AVAILABLE DRIVERS -----\n";
    if (drivers.empty())
    {
        cout<<"No drivers yet.\n";
        return;
    }
    int ok=1;
    for (int i=0; i<(int)drivers.size();i++)
    {
        if (drivers[i].isAvailable())
        {
            cout<<ok++<<")"<<drivers[i]<<"\n";
        }
    }
    if (ok==1)
    {
        cout<<"No available drivers.\n";
        return;
    }
}

void Menu::listRides() const
{
    cout<<"---- RIDES -----\n";
    if (rides.empty())
    {
        cout<<"No rides yet.\n";
        return;
    }
    for (int i=0;i<(int)rides.size();i++)
    {
        cout<<i<<")"<<rides[i]<<"\n";
    }

}

void Menu::addUser()
{
    cout<<"----- ADD USER -----\n";
    User user;
    cin>>user;
    users.push_back(user);
    cout<<"User add successfully!\n";

}

void Menu::addDriver()
{
    cout<<"------ADD DRIVER -----\n";
    Driver driver;
    cin>>driver;
    drivers.push_back(driver);
    cout<<"Driver add successfully!\n";
}

void Menu::requestRide()
{
    cout<<"----- REQUEST RIDE -----\n";
    if (drivers.empty() || users.empty())
    {
        cout<<"No users or drivers yet.\n";
        return;

    }
    cout<<"Choose a user: \n";
    listUsers();
    int usrIndex;
    cin>>usrIndex;
    if (usrIndex<0 || usrIndex>=(int)users.size())
    {
        cout<<"Invalid user index.\n";
        return;
    }
    double x, y;
    cout<<"Enter Destination:\n";
    cout<<"Enter coordinate X: \n";
    cin>>x;
    cout<<"Enter coordinate Y: \n";
    cin>>y;
    Location destination(x,y);

    try
    {
        Ride r = RideManager::createRide(users[usrIndex], drivers,destination);
        cout<<"Ride created successfully!\n";
        cout<<r;
        rides.push_back(r);
    }catch(const exception& e)
    {
        cout<<e.what()<<"\n";
    }
}


void Menu::run()
{
    int option;
    while (true)
    {
        showMainMenu();
        cout<<"Choose an option!\n";
        cin>>option;

        switch (option)
        {
        case 1: listUsers(); break;
        case 2: listDrivers(); break;
        case 3: listAvailableDrivers(); break;
        case 4: listRides(); break;
        case 5: addUser(); break;
        case 6: addDriver(); break;
        case 7: requestRide(); break;
        case 0:
            cout<<"Exit menu.\n";
            return;

        default:
            cout<<"Invalid option.\n";
        }

    }
}