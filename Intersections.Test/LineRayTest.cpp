#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/LineInitException.h"
#include "../Intersections/LineRay.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Intersections;

namespace IntersectionsTest
{
	TEST_CLASS(LineRayTest)
	{
		TEST_METHOD(createTest1)
		{
			
			try {
				LineRay lr = LineRay::create(Point(1, 1), Point(1, 1));

				Assert::Fail();
			}
			catch (LineInitException)
			{
			}
		}
	};

}