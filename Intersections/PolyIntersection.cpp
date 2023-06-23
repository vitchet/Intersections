#include "PolyIntersection.h"

#include "LineSegment.h"
#include "Poly.h"

namespace Intersections
{
	PolyIntersection::PolyIntersection(const Poly& pl1, const Poly& pl2) noexcept
	{
		result = calculate(pl1, pl2);
	}

	bool PolyIntersection::calculate(const Poly& pl1, const Poly& pl2)
	{
		for (const auto& pl1_seg : pl1.getSegments())
		{
			for (const auto& pl2_seg : pl2.getSegments())
			{
				if (pl1_seg.doesIntersectSegment(pl2_seg))
				{
					return true;
				}
			}
		}

		return false;
	}
}