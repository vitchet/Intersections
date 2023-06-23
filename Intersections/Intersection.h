#ifndef INTERSECTION_INTERFACE_H
#define INTERSECTION_INTERFACE_H

namespace Intersections
{

    class Intersection
    {
    public:
        virtual bool doIntersect() const noexcept = 0; 

    protected:
        Intersection() {};
    };

}

#endif