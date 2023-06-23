#include "RayPolyIntersection.h"

#include "LineRay.h"
#include "Poly.h"

namespace Intersections 
{
	RayPolyIntersection::RayPolyIntersection(const LineRay& lr, const Poly& pl) noexcept
	{
		result = calculate(lr, pl);
	}

	bool RayPolyIntersection::calculate(const LineRay& lr, const Poly& pl)
	{
		for (const auto& pl_seg : pl.getSegments())
		{

			if (lr.doesIntersectSegment(pl_seg))
			{
				return true;
			}
		}

		return false;
	}

}