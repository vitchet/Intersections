#include "LineSegment.h"

#include <cmath>

#include "LineInitException.h"

using namespace std;

namespace Intersections
{
    
    LineSegment LineSegment::create(const Point& aP1, const Point& aP2)
    {
        validatePoints(aP1, aP2);

        return LineSegment(aP1, aP2);
    }

    double LineSegment::getLength() const noexcept
    {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }

    bool LineSegment::doesIntersectSegment(const LineSegment& other) const noexcept {
        return SegmentsIntersection(*this, other).doIntersect();
    }

    bool LineSegment::operator==(const LineSegment& other) const
    {
        return ((p1 == other.p1) && (p2 == other.p2)) || 
               ((p2 == other.p1) && (p1 == other.p2));
    }

    bool LineSegment::operator!=(const LineSegment& other) const
    {
        return !(*this == other);
    }

    LineSegment::LineSegment(const Point& aP1, const Point& aP2) : StraightLineBase(aP1, aP2)
    {
    }
}