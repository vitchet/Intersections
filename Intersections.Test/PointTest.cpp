#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/Point.h"

#include "utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Intersections;

namespace IntersectionsTest
{

	TEST_CLASS(PointTest)
	{
		Point p1 {5, 5};
		Point p2 {1, 3};
		Point p3 {5, 5};

		TEST_METHOD(substractTest1)
		{
			Point pSub = p1 - p2;
			Assert::AreEqual(pSub.x, 4.0);
			Assert::AreEqual(pSub.y, 2.0);
		}

		TEST_METHOD(substractTest2)
		{
			p1 -= p2;
			Assert::AreEqual(p1.x, 4.0);
			Assert::AreEqual(p1.y, 2.0);
		}

		TEST_METHOD(equalsTest1)
		{
			Assert::AreEqual(p1, p3);
		}

		TEST_METHOD(equalsTest2)
		{
			Assert::AreNotEqual(p1, p2);
		}

	};

}