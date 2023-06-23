#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/LineRay.h"
#include "../Intersections/LineSegment.h"
#include "../Intersections/RaySegmentIntersection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Intersections;

namespace IntersectionsTest
{

	TEST_CLASS(RaySegmentIntersectionTest)
	{
		LineSegment ls = LineSegment::create(Point(2, 1), Point(2, 5));
		LineRay lr1 = LineRay::create(Point(1,1), Point(2, 2));
		LineRay lr2 = LineRay::create(Point(5, 5), Point(4, 4));
		LineRay lr3 = LineRay::create(Point(1, 1), Point(0, -1));
		LineRay lr4 = LineRay::create(Point(4, 4), Point(5, 5));
		LineRay lr5 = LineRay::create(Point(2, -1), Point(2, 7));
		LineRay lr6 = LineRay::create(Point(2, 7), Point(2, -1));

		TEST_METHOD(calculateTest1)
		{
			bool result = RaySegmentIntersection(lr1, ls).doIntersect();
			Assert::IsTrue(result);
		}

		TEST_METHOD(calculateTest2)
		{
			bool result = RaySegmentIntersection(lr2, ls).doIntersect();
			Assert::IsTrue(result);
		}

		TEST_METHOD(calculateTest3)
		{
			bool result = RaySegmentIntersection(lr3, ls).doIntersect();
			Assert::IsFalse(result);
		}

		TEST_METHOD(calculateTest4)
		{
			bool result = RaySegmentIntersection(lr4, ls).doIntersect();
			Assert::IsFalse(result);
		}

		TEST_METHOD(calculateTest5)
		{
			bool result = RaySegmentIntersection(lr5, ls).doIntersect();
			Assert::IsTrue(result);
		}

		TEST_METHOD(calculateTest6)
		{
			bool result = RaySegmentIntersection(lr6, ls).doIntersect();
			Assert::IsTrue(result);
		}
		
	};

}