#pragma once
#include <cmath>

constexpr auto PI = 3.14159265;

namespace Lilac::Utils
{
	class Math
	{
	public:
		// std::sin but returns the degree result instead of angle
		template<typename T = double>
		double sind(const T param);
	};

	template<typename T>
	inline double Math::sind(const T param)
	{
		T result = 0;
		result = std::sin(param * PI / 180);

		return result;
	}
}