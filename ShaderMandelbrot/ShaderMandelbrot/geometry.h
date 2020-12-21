#pragma once
#include "Vec2.h"
#include <vector>

# define M_PI   3.14159265358979323846  /* pi */
# define EPS    0.0001

namespace geom {
	bool isCross(Vec2 a, Vec2 b, Vec2 c, Vec2 d);
	Vec2 getCross(Vec2 a, Vec2 b, Vec2 c, Vec2 d);
	Vec2 direction(long double a);
	Vec2 direction(Vec2  a, Vec2  b);
	long double angle(Vec2 p);
	long double angle(Vec2 a, Vec2 b, Vec2 c);
	long double distance(Vec2  a, Vec2 b);
	long double distance(Vec2  p, Vec2 a, Vec2 b);
	Vec2 rotate(Vec2 p, long double angle);
	long double square(std::vector<Vec2> polygon);
	bool inPolygon(Vec2 point, std::vector<Vec2> polygon);
	std::vector<long double> angleDistribution(long double direction, long double width, int n);
}