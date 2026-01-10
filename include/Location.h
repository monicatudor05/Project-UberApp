#ifndef LOCATION_H
#define LOCATION_H

#include<iosfwd>

class Location
{
private:
    double x;
    double y;

public:
    Location()=default;
    Location(double x, double y);
    Location(const Location& other)=default;
    ~Location()=default;


    double distanceTo(const Location& location) const;

    Location& operator=(const Location&)=default;


    friend std::ostream& operator<<(std::ostream& out, const Location& loc );
    friend std::istream& operator>>(std::istream& in,  Location& loc);

};

#endif

