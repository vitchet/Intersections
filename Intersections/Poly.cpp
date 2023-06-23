#include "Poly.h"

#include "PolyInitException.h"
#include "PolyIntersection.h"

using namespace std;

namespace Intersections
{
    Poly Poly::create(const vector<Point>& points)
    {
        validatePoints(points);
       
        return Poly(points, createSegments(points));
    }

    bool Poly::doesIntersectPoly(const Poly& other) const noexcept
    {
        return PolyIntersection(*this, other).doIntersect();
    }

    Poly::Poly(const vector<Point>& aPoints, const vector<LineSegment>& aSegments) : points(aPoints), segments(aSegments)
    {
    }

    vector<LineSegment> Poly::createSegments(const vector<Point>& points)
    {
        vector<LineSegment> segments;

        for (auto it = points.begin(); it != prev(points.end()); it++) 
            segments.push_back(LineSegment::create(*it, *next(it)));
        segments.push_back(LineSegment::create(*points.begin(), *prev(points.end())));

        return segments;
    }

    void Poly::validatePoints(const vector<Point>& points)
    {
        if (points.size() < 3) 
            throw PolyInitException();

        for (auto it = points.begin(); it < points.end(); it++)
            if (find(next(it), points.end(), *it) != points.end())
                throw PolyInitException();
    }
}