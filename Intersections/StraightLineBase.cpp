#include "StraightLineBase.h"

#include "LineInitException.h"

using namespace std;

namespace Intersections
{

    void StraightLineBase::validatePoints(const Point& p1, const Point& p2) 
    {
        if (p1 == p2)
            throw LineInitException();
    }

    vector<const Point*> StraightLineBase::getPoints() const noexcept
    {
        return { &p1, &p2 };
    }

    StraightLineBase::StraightLineBase(const Point& aP1, const Point& aP2) : p1(aP1), p2(aP2)
    {
    }

}