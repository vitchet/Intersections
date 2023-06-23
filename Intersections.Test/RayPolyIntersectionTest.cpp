#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/LineRay.h"
#include "../Intersections/Poly.h"
#include "../Intersections/RayPolyIntersection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Intersections;

namespace IntersectionsTest
{

	TEST_CLASS(RayPolyIntersectionTest)
	{
		LineRay lr1 = LineRay::create(Point(1, 1), Point(2, 2));
		LineRay lr2 = LineRay::create(Point(1, 6), Point(0, 5));
		Poly pl = Poly::create({ Point(3, 3), Point(3, 5), Point(6, 5), Point(1, 7) });

		TEST_METHOD(calculateTest1) 
		{
			bool result = RayPolyIntersection(lr1, pl).doIntersect();
			Assert::IsTrue(result);
		}

		TEST_METHOD(calculateTest2) 
		{
			bool result = RayPolyIntersection(lr2, pl).doIntersect();
			Assert::IsFalse(result);
		}
	};

}