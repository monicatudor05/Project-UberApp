
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
    menu.run();




}