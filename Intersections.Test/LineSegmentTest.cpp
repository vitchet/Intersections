#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/LineInitException.h"
#include "../Intersections/LineSegment.h"

#include "utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Intersections;

namespace IntersectionsTest
{

	TEST_CLASS(LineSegmentTest)
	{
		LineSegment ls1 = LineSegment::create(Point(1.0, 1.0), Point(4.0, 5.0));
		LineSegment ls2 = LineSegment::create(Point(1.0, 1.0), Point(5.0, 6.0));
		LineSegment ls3 = LineSegment::create(Point(1.0, 1.0), Point(4.0, 5.0));
		LineSegment ls4 = LineSegment::create(Point(4.0, 5.0), Point(1.0, 1.0));
		TEST_METHOD(getLengthTest1)
		{
			double length = ls1.getLength();
			Assert::AreEqual(length, 5.0);
		}

		TEST_METHOD(equalsTest1)
		{
			Assert::AreEqual(ls1, ls3);
		}

		TEST_METHOD(equalsTest2)
		{
			Assert::AreNotEqual(ls1, ls2);
		}

		TEST_METHOD(equalsTest3)
		{
			Assert::AreEqual(ls1, ls4);
		}

		TEST_METHOD(createTest)
		{
			try {
				LineSegment ls = LineSegment::create(Point(1, 1), Point(1, 1));

				Assert::Fail();
			}
			catch (LineInitException)
			{
			}
		}
	};

}