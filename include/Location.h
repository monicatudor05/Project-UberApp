#ifndef LOCATION_H
#define LOCATION_H

#include<iostream>
using namespace std;

class Location
{
private:
    double x;
    double y;

public:
    Location();
    Location(double x, double y);
    ~Location()=default;

    //getters
    double getX() const;
    double getY() const ;
    //setters
    void setX(double x);
    void setY(double y);

    double distanceTo(const Location& location) const;

    //opeators
    Location& operator=(const Location& other);

    //friend functions
    friend ostream& operator<<(ostream& out, const Location& loc );
    friend istream& operator>>(istream& in,  Location& loc);

};

#endif

