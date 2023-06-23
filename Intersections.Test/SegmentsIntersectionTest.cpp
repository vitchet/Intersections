#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/LineSegment.h"
#include "../Intersections/SegmentsIntersection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Intersections;

namespace IntersectionsTest
{

	TEST_CLASS(SegmentsIntersectionTest)
	{
		LineSegment ls1 = LineSegment::create(Point(1, 2), Point(4, 2));
		LineSegment ls2 = LineSegment::create(Point(2, 1), Point(2, 4));
		LineSegment ls3 = LineSegment::create(Point(5, 5), Point(10, 10));
		LineSegment ls4 = LineSegment::create(Point(0, 2), Point(3, 2));
		LineSegment ls5 = LineSegment::create(Point(0, 3), Point(3, 3));

		TEST_METHOD(calculateTest1)
		{
			bool result = SegmentsIntersection(ls1, ls2).doIntersect();
			Assert::IsTrue(result);
		}

		TEST_METHOD(calculateTest2)
		{
			bool result = SegmentsIntersection(ls1, ls3).doIntersect();
			Assert::IsFalse(result);
		}

		TEST_METHOD(calculateTest3)
		{
			bool result = SegmentsIntersection(ls1, ls4).doIntersect();
			Assert::IsTrue(result);
		}

		TEST_METHOD(calculateTest4)
		{
			bool result = SegmentsIntersection(ls1, ls5).doIntersect();
			Assert::IsFalse(result);
		}
	};

}