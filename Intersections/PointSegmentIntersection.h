#ifndef POINT_SEGMENT_INTERSECTION_H
#define POINT_SEGMENT_INTERSECTION_H

#include "IntersectionBase.h"

#include "Point.h"

namespace Intersections
{

    class LineSegment;

    class PointSegmentIntersection : public IntersectionBase
    {
    public:
        PointSegmentIntersection(const Point&, const LineSegment&) noexcept;

    private:
        static bool calculate(const Point&, const LineSegment&);
    };

}

#endif