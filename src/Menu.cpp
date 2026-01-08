#include "Menu.h"
#include "Ride.h"
#include "Driver.h"
#include "User.h"
#include "Location.h"
#include "RideManager.h"
#include<iostream>
#include<limits>

using namespace std;

Menu::Menu(vector<shared_ptr<User>>& users, vector<shared_ptr<Driver>>& drivers, vector<Ride>& rides):
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
    cout<<"---- USERS ----\n";
    if (users.empty())
    {
        cout<<"No users yet.\n";
        return;
    }
    for (size_t i=0; i<users.size();i++)
    {
        cout<<i+1<<")"<<*users[i]<<"\n";
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
    for (size_t i=0; i<drivers.size();i++)
    {
        cout<<i+1<<")"<<*drivers[i]<<"\n";
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
    for (size_t i=0; i<drivers.size();i++)
    {
        if ((*drivers[i]).isAvailable())
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
    for (size_t i=0;i<rides.size();i++)
    {
        cout<<i<<")"<<rides[i]<<"\n";
    }

}

void Menu::addUser()
{
    cout<<"----- ADD USER -----\n";
    auto usr = make_shared<User>();
    cin>>*usr;
    users.push_back(usr);
    cout<<"User add successfully!\n";

}

void Menu::addDriver()
{
    cout<<"------ADD DRIVER -----\n";
    auto dr =make_shared<Driver>();
    cin>>*dr;
    drivers.push_back(dr);
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
    if (usrIndex-1<0 || usrIndex-1>=static_cast<int>(users.size()))
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
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }


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