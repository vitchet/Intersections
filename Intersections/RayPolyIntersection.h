#ifndef RAY_POLY_INTERSECTION_H
#define RAY_POLY_INTERSECTION_H

#include "IntersectionBase.h"

namespace Intersections 
{
	class LineRay;
	class Poly;

	class RayPolyIntersection : public IntersectionBase
	{
	public:
		RayPolyIntersection(const LineRay&, const Poly&) noexcept;
	private:
		static bool calculate(const LineRay&, const Poly&);
	};

}

#endif