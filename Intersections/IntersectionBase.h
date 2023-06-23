#ifndef INTERSECTION_BASE_H
#define INTERSECTION_BASE_H

#include "Intersection.h"

namespace Intersections
{

    class IntersectionBase : public Intersection
    {
    public:
        bool doIntersect() const noexcept override { return result; }

    protected:
        bool result = false;
    };

}

#endif