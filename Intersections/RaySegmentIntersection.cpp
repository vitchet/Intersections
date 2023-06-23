#include "RaySegmentIntersection.h"

#include "LineRay.h"
#include "LineSegment.h"
#include "SegmentsIntersection.h"

namespace Intersections
{
    RaySegmentIntersection::RaySegmentIntersection(const LineRay& lr, const LineSegment& ls) noexcept
    {
        result = calculate(lr, ls);
    }

    bool RaySegmentIntersection::calculate(const LineRay& lr, const LineSegment& ls)
    {
        SegmentsIntersection si(lr.getInfinitySegment(), ls);

        return si.doIntersect();
    }
}