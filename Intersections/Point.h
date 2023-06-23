#ifndef POINT_H
#define POINT_H

namespace Intersections
{

    struct Point
    {
        double x, y;

        Point();
        Point(double, double);

        Point operator-(const Point&) const;
        Point& operator-=(const Point&);

        bool operator==(const Point&) const;
        bool operator!=(const Point&) const;
    };

}

#endif 