#ifndef POLY_INTERSECTION_H
#define POLY_INTERSECTION_H

#include "IntersectionBase.h"

namespace Intersections
{
	class Poly;

	class PolyIntersection : public IntersectionBase
	{
	public:
		PolyIntersection(const Poly&, const Poly&) noexcept;
	private:
		static bool calculate(const Poly&, const Poly&);
	};

}

#endif