#include "SegmentsIntersection.h"

#include "LineSegment.h"
#include "PointSegmentIntersection.h"

namespace Intersections
{
    SegmentsIntersection::SegmentsIntersection(const LineSegment& ls1, const LineSegment& ls2) noexcept
    {
        result = calculate(ls1, ls2);
    }
   
    bool SegmentsIntersection::calculate(const LineSegment& ls1, const LineSegment& ls2)
    {
        const Point& ls1P1 = *ls1.getPoints()[0];
        const Point& ls1P2 = *ls1.getPoints()[1];
        const Point& ls2P1 = *ls2.getPoints()[0];
        const Point& ls2P2 = *ls2.getPoints()[1];

        const PointOrientation o1 = getOrientation(ls1P1, ls1P2, ls2P1);
        const PointOrientation o2 = getOrientation(ls1P1, ls1P2, ls2P2);
        const PointOrientation o3 = getOrientation(ls2P1, ls2P2, ls1P1);
        const PointOrientation o4 = getOrientation(ls2P1, ls2P2, ls1P2);

        if (o1 != o2 && o3 != o4)
            return true;

        const Intersection& pointSeg1 = PointSegmentIntersection(ls2P1, ls1);
        if (o1 == PointOrientation::Collinear && pointSeg1.doIntersect())
            return true;

        const Intersection& pointSeg2 = PointSegmentIntersection(ls2P2, ls1);
        if (o2 == PointOrientation::Collinear && pointSeg2.doIntersect())
            return true;

        const Intersection& pointSeg3 = PointSegmentIntersection(ls1P1, ls2);
        if (o3 == PointOrientation::Collinear && pointSeg3.doIntersect())
            return true;

        const Intersection& pointSeg4 = PointSegmentIntersection(ls1P2, ls2);
        if (o4 == PointOrientation::Collinear && pointSeg4.doIntersect())
            return true;

        return false;
    }

    SegmentsIntersection::PointOrientation SegmentsIntersection::getOrientation(const Point& p1, const Point& p2, const Point& p3)
    {
        auto val = static_cast<int>((p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y));

        if (val == 0)
            return PointOrientation::Collinear;

        return (val > 0) ? PointOrientation::Clockwise
                         : PointOrientation::CounterClockwise;
    }
}