#include "Point.h"

#include <cmath>
#include <utility>

using namespace std;

namespace Intersections
{

    Point::Point() : x(0.0), y(0.0)
    {
    }

    Point::Point(double aX, double aY) : x(aX), y(aY)
    {
    }

    Point Point::operator-(const Point& other) const
    {
        return Point(abs(x - other.x), abs(y - other.y));
    }

    Point& Point::operator-=(const Point& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    bool Point::operator==(const Point& other) const
    {
        return (x == other.x) && (y == other.y);
    }

    bool Point::operator!=(const Point& other) const
    {
        return !(*this == other);
    }

}