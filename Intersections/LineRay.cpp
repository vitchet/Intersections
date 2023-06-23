#include "LineRay.h"

#include "Poly.h"
#include "RayPolyIntersection.h"
#include "RaySegmentIntersection.h"

namespace Intersections
{

    LineRay LineRay::create(const Point& aP1, const Point& aP2)
    {
        validatePoints(aP1, aP2);

        return LineRay(aP1, aP2);
    }

    bool LineRay::doesIntersectSegment(const LineSegment& ls) const noexcept
    {
        return RaySegmentIntersection(*this, ls).doIntersect();
    }

    bool LineRay::doesIntersectPoly(const Poly& pl) const noexcept
    {
        return RayPolyIntersection(*this, pl).doIntersect();
    }

    LineRay::LineRay(const Point& aP1, const Point& aP2) : StraightLineBase(aP1, aP2)
    {
        infinitySegment = createInfinitySegment();
    }

    LineSegment LineRay::createInfinitySegment() const
    {
        LineSegment diff = LineSegment::create(p1, p2);
        double ratio = INFINITY_LENGTH / diff.getLength();
        Point newPoint(p1.x + ratio * (p2.x - p1.x),
                       p1.y + ratio * (p2.y - p1.y));

        return LineSegment::create(p1, newPoint);
    }

}