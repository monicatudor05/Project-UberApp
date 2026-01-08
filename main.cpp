
#include<vector>
#include "Driver.h"
#include "User.h"
#include "Ride.h"
#include "Menu.h"
#include<memory>
#include<iostream>
using namespace std;
int main()
{
    vector<shared_ptr<User>> users;
    vector<Ride> rides;
    vector<shared_ptr<Driver>> drivers;
    Menu menu(users,drivers,rides);
    //menu.run();

    Location l(8.0,9.0);
    Location l2(10.0,11.0);
    Location l3;
    cout<<l.distanceTo(l2);
    return 0;



}