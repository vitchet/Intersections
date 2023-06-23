#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/LineSegment.h"
#include "../Intersections/Poly.h"
#include "../Intersections/PolyInitException.h"

#include "utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Intersections;

namespace IntersectionsTest
{

	TEST_CLASS(PolyTest)
	{
		TEST_METHOD(createTest1)
		{
			Poly pl = Poly::create({ Point(1,1), Point(3, 3), Point(5,1) });

			const auto& segments = pl.getSegments();

			Assert::AreEqual(3, static_cast<int>(segments.size()));

			LineSegment ls1 = LineSegment::create(Point(1, 1), Point(3, 3));
			LineSegment ls2 = LineSegment::create(Point(3, 3), Point(5, 1));
			LineSegment ls3 = LineSegment::create(Point(1, 1), Point(5, 1));
			Assert::AreEqual(ls1, segments[0]);
			Assert::AreEqual(ls2, segments[1]);
			Assert::AreEqual(ls3, segments[2]);
		}

		TEST_METHOD(createTest2)
		{
			try {
				Poly pl = Poly::create({ Point(1, 1) });

				Assert::Fail();
			}
			catch (PolyInitException)
			{
			}
		}

		TEST_METHOD(createTest3)
		{
			try {
				Poly pl = Poly::create({ Point(1, 1), Point(1, 1), Point(2, 2) });

				Assert::Fail();
			}
			catch (PolyInitException)
			{
			}
		}
	};

}