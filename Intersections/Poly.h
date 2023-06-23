#ifndef POLY_H
#define POLY_H

#include <vector>

#include "LineSegment.h"
#include "Point.h"

namespace Intersections
{

    class Poly
    {
    public:
        static Poly create(const std::vector<Point>& aPoints);

        bool doesIntersectPoly(const Poly&) const noexcept;

        const std::vector<Point>& getPoints() const noexcept { return points; }
        const std::vector<LineSegment>& getSegments() const noexcept { return segments; }
        
    protected:
        Poly(const std::vector<Point>&, const std::vector<LineSegment>&);

        std::vector<Point> points;
        std::vector<LineSegment> segments;

        static std::vector<LineSegment> createSegments(const std::vector<Point>&);
        static void validatePoints(const std::vector<Point>&);
    };

}

#endif