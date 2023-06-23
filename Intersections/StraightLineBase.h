#ifndef STRAIGHT_LINE_BASE_H
#define STRAIGHT_LINE_BASE_H

#include <vector>

#include "Point.h"

namespace Intersections
{

    class StraightLineBase
    {
    public:
        // Returns both points of the line as an array of two pointers
        std::vector<const Point*> getPoints() const noexcept;
    protected:
        static void validatePoints(const Point&, const Point&);

        Point p1, p2;

        StraightLineBase(const Point&, const Point&);
    };

}

#endif