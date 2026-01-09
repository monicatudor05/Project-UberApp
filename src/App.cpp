#include "App.h"
#include "Menu.h"


void App::run() {
    Menu menu(users, drivers, rides);
    menu.run();
}

