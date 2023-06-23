#ifndef SEGMENTS_INTERSECTION_H
#define SEGMENTS_INTERSECTION_H

#include "IntersectionBase.h"

#include "Point.h"

namespace Intersections
{
    class LineSegment;

    class SegmentsIntersection : public IntersectionBase
    {
    public:
        SegmentsIntersection(const LineSegment&, const LineSegment&) noexcept;
    private:
        enum class PointOrientation
        {
            Collinear,
            Clockwise,
            CounterClockwise
        };

        static bool calculate(const LineSegment&, const LineSegment&);
        static PointOrientation getOrientation(const Point&, const Point&, const Point&);
    };

}

#endif