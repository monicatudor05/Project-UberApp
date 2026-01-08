#ifndef LOCATION_H
#define LOCATION_H

#include<iosfwd>

class Location
{
private:
    double x{0.0};
    double y{0.0};

public:
    Location()=default;
    Location(double x, double y);
    Location(const Location& other)=default;
    ~Location()=default;

    //getters
    double getX() const;
    double getY() const ;
    //setters
    void setX(double x);
    void setY(double y);

    double distanceTo(const Location& location) const;

    //operators
    Location& operator=(const Location&)=default;

    //friend functions
    friend std::ostream& operator<<(std::ostream& out, const Location& loc );
    friend std::istream& operator>>(std::istream& in,  Location& loc);

};

#endif

