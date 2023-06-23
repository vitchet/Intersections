#ifndef STRAIGHT_LINE_H
#define STRAIGHT_LINE_H

#include "StraightLineBase.h"

#include "LineSegment.h"

namespace Intersections
{
    class Poly;

    class LineRay : public StraightLineBase
    {
    public:
        static LineRay create(const Point&, const Point&);

        bool doesIntersectSegment(const LineSegment&) const noexcept;

        bool doesIntersectPoly(const Poly&) const noexcept;

        const LineSegment& getInfinitySegment() const noexcept { return infinitySegment; }

    protected:
        static constexpr double INFINITY_LENGTH = 10000.0;

        LineSegment infinitySegment = createInfinitySegment();

        LineRay(const Point&, const Point&);

        LineSegment createInfinitySegment() const;
    };

}

#endif