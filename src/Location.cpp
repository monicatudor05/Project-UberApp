#include "Location.h"
#include <cmath>
Location::Location():x(0.0),y(0.0){}
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
void Location::setX(double x)
{
    this->x = x;
}
void Location::setY(double y)
{
    this->y = y;
}
double Location::distanceTo(const Location &loc) const
{
    double dx = x - loc.x;
    double dy = y - loc.y;
    return sqrt(dx*dx + dy*dy);
}

Location& Location::operator=(const Location& other)
{
    x=other.x;
    y=other.y;
    return *this;
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