#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/LineSegment.h"
#include "../Intersections/Point.h"
#include "../Intersections/PointSegmentIntersection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Intersections;

namespace IntersectionsTest
{

	TEST_CLASS(PointSegmentIntersectionTest)
	{
		Point p1 = Point(3.0, 3.0);
		Point p2 = Point(1.5, 6);
		LineSegment ls = LineSegment::create(Point(2.0, 2.0), Point(4.0, 4.0));
		TEST_METHOD(calculateTest1)
		{
			bool result = PointSegmentIntersection(p1, ls).doIntersect();
			Assert::IsTrue(result);
		}

		TEST_METHOD(calculateTest2)
		{
			bool result = PointSegmentIntersection(p2, ls).doIntersect();
			Assert::IsFalse(result);
		}
	};

}