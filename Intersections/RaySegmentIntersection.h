#ifndef RAY_SEGMENT_INTERSECTION_H
#define RAY_SEGMENT_INTERSECTION_H

#include "IntersectionBase.h"

namespace Intersections
{
    class LineRay;
    class LineSegment;

    class RaySegmentIntersection : public IntersectionBase
    {
    public:
        RaySegmentIntersection(const LineRay&, const LineSegment&) noexcept;
    private:
        static bool calculate(const LineRay&, const LineSegment&);
    };
}

#endif