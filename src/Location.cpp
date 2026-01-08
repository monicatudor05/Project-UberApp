#include "Location.h"
#include<iostream>
#include <cmath>
using namespace std;
Location::Location(double x, double y):x(x),y(y){}


//getters
double Location::getX() const
{
    return x;
}
double Location::getY() const
{
    return y;
}

//setters
void Location::setX(double newX)
{
    x=newX;
}
void Location::setY(double newY)
{
    y=newY;
}
double Location::distanceTo(const Location& loc) const
{
    double dx = x - loc.x;
    double dy = y - loc.y;
    return sqrt(dx*dx + dy*dy);
}

ostream& operator<<(ostream& out, const  Location& loc)
{
    out<<"("<<loc.x<<","<<loc.y<<")";
    return out;
}

istream& operator>>(istream& in, Location& loc)
{
    cout<<"Enter x: ";
    in>>loc.x;
    cout<<"Enter y: ";
    in>>loc.y;
    return in;

}