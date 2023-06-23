#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include "StraightLineBase.h"

#include "PointSegmentIntersection.h"
#include "Point.h"
#include "SegmentsIntersection.h"

namespace Intersections
{

    class LineSegment : public StraightLineBase
    {
    public:
        static LineSegment create(const Point&, const Point&);

        double getLength() const noexcept;

        bool doesIntersectSegment(const LineSegment&) const noexcept;

        bool operator==(const LineSegment&) const;
        bool operator!=(const LineSegment&) const;
    private:
        LineSegment(const Point&, const Point&);
    };

}

#endif