#pragma once
class Vec2 {
public:
	long double x=0, y=0;
	Vec2() {};
	Vec2(long double x1, long double y1);
};

Vec2 operator+(const Vec2& a, const Vec2& b);
Vec2 operator-(const Vec2& a, const Vec2& b);
Vec2 operator*(const Vec2& a, long double k);
Vec2 operator/(const Vec2& a, long double k);
Vec2 operator+=(Vec2& a, const Vec2& b);
Vec2 operator-=(Vec2& a, const Vec2& b);