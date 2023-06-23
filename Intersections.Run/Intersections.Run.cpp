#include <iostream>
#include <sstream>
#include <vector>

#include "../Intersections/LineInitException.h"
#include "../Intersections/LineRay.h"
#include "../Intersections/PolyInitException.h"
#include "../Intersections/Poly.h"

using namespace std;
using namespace Intersections;

string printIntersection(const LineRay&, const Poly&);
string printIntersection(const Poly&, const Poly&);
string print(const Poly&);
string print(const LineRay&);
string print(const vector<Point>&);
string print(const Point&);

int main()
{
    try 
    {
        LineRay lr1 = LineRay::create(Point(2, 10), Point(3, 9));
        Poly pl1 = Poly::create({ Point(2, 2), Point(4, 8), Point(12, 6), Point(9, 2) });
        Poly pl2 = Poly::create({ Point(9, 5), Point(9, 9), Point(16, 9) });
        Poly pl3 = Poly::create({ Point(11, 9), Point(11, 12), Point(14, 12), Point(14, 9) });

        cout << printIntersection(lr1, pl1) << endl;
        cout << printIntersection(lr1, pl2) << endl;
        cout << printIntersection(lr1, pl3) << endl;
        cout << printIntersection(pl1, pl2) << endl;
        cout << printIntersection(pl1, pl3) << endl;
        cout << printIntersection(pl2, pl3) << endl;
        
    }
    catch (LineInitException) 
    {
        cout << "Incorrect LineRay initialization attempt." << endl;
    }
    catch (PolyInitException) 
    {
        cout << "Incorrect Poly initialization attempt." << endl;
    }
}

string printIntersection(const Poly& poly1, const Poly& poly2)
{
    stringstream ss;

    ss << print(poly1) << (poly1.doesIntersectPoly(poly2) ? " intersects " : " does not intersect ") << print(poly2) << ".";

    return ss.str();
}

string printIntersection(const LineRay& ray, const Poly& poly)
{
    stringstream ss;

    ss << print(ray) << (ray.doesIntersectPoly(poly) ? " intersects " : " does not intersect ") << print(poly) << ".";

    return ss.str();
}

string print(const Poly& poly)
{
    stringstream ss;

    ss << "Poly { " << print(poly.getPoints()) << " }";

    return ss.str();
}

string print(const LineRay& ray)
{
    stringstream ss;

    ss << "Ray { " << print(*ray.getPoints()[0]) << ", " << print(*ray.getPoints()[1]) << " }";

    return ss.str();
}

string print(const vector<Point>& points)
{
    stringstream ss;

    for (auto it = points.begin(); it < points.end(); it++)
    {
        const auto& point = *it;
        ss << print(point);
        if (it != prev(points.end()))
            ss << ", ";
    }

    return ss.str();
}

string print(const Point& point)
{
    stringstream ss;

    ss << "(" << point.x << "; " << point.y << ")";
    
    return ss.str();
}