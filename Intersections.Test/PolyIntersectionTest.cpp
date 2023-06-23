#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/Poly.h"
#include "../Intersections/PolyIntersection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Intersections;

namespace IntersectionsTest
{

	TEST_CLASS(PolyIntersectionTest)
	{
		Poly pl1 = Poly::create({ Point(1,1), Point(2, 3), Point(4, 2), Point(3, 0) });
		Poly pl2 = Poly::create({ Point(2, 2), Point(3, 4), Point(5, 4) });
		Poly pl3 = Poly::create({ Point(1, -1), Point(3, -1), Point(2, -2) });

		TEST_METHOD(calculateTest1) {
			bool result = PolyIntersection(pl1, pl2).doIntersect();
			Assert::IsTrue(result);
		}

		TEST_METHOD(calculateTest2) {
			bool result = PolyIntersection(pl1, pl3).doIntersect();
			Assert::IsFalse(result);
		}
	};

}