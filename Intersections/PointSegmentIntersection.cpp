#include "PointSegmentIntersection.h"

#include <cmath>

#include "LineSegment.h"

using namespace std;

namespace Intersections
{

    PointSegmentIntersection::PointSegmentIntersection(const Point& p, const LineSegment& ls) noexcept
    {
        result = calculate(p, ls);
    }

    bool PointSegmentIntersection::calculate(const Point& p, const LineSegment& ls)
    {
        const Point& lsP1 = *ls.getPoints()[0];
        const Point& lsP2 = *ls.getPoints()[1];

        return p.x <= fmax(lsP1.x, lsP2.x) &&
               p.x >= fmin(lsP1.x, lsP2.x) &&
               p.y <= fmax(lsP1.y, lsP2.y) &&
               p.y >= fmin(lsP1.y, lsP2.y);
    }

}