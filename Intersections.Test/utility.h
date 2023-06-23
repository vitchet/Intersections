#ifndef UTILITY_H
#define UTILITY_H

#include "pch.h"
#include "CppUnitTest.h"

#include "../Intersections/LineSegment.h"
#include "../Intersections/Point.h"

namespace Microsoft { namespace VisualStudio { namespace CppUnitTestFramework {

	template<>
	std::wstring ToString<Intersections::Point>(const Intersections::Point& t)
	{
		std::wstringstream ss;
		ss << t.x << L";" << t.y;
		RETURN_WIDE_STRING(ss.str());
	}

	template<>
	std::wstring ToString<Intersections::LineSegment>(const Intersections::LineSegment& t)
	{
		const Intersections::Point& p1 = *t.getPoints()[0];
		const Intersections::Point& p2 = *t.getPoints()[1];

		std::wstringstream ss;
		ss << L"p1(" << p1.x << ";" << p1.y << L"), "
			<< L"p2(" << p2.x << ";" << p2.y << L")";
		RETURN_WIDE_STRING(ss.str());
	}

}}}

#endif 