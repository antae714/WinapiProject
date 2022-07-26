#pragma once

#include<array>

using namespace std;
typedef struct tagPOINT POINT;
class Vector2
{
public:
	static constexpr int dimension = 2;
	static const Vector2 UnitX;
	static const Vector2 UnitY;
	static const Vector2 One;
	static const Vector2 Zero;
private:
	float x;
	float y;
	array<float, Vector2::dimension> scalar;
public:
	Vector2();
	Vector2(float, float);

public:
	float getx() const;
	float gety() const;

	void setx(float);
	void sety(float);

	void addx(float);
	void addy(float);
	float at(int);

	Vector2 GetRotate(float rad) const;
	Vector2 Getabs() const;
	Vector2 GetNormalize() const;
	void Normalize();
	float SizeSquared() const;
	//벡터사이의 cos(각도)
	float Dot(const Vector2&) const;
	POINT toPOINT() const;
public:
	bool operator==(const Vector2&);
	Vector2 operator-(const Vector2&) const;
	Vector2 operator+(const Vector2&) const;
	Vector2 operator*(const float&) const;
	Vector2 operator/(const float&) const;
	void operator-=(const Vector2&);
	void operator+=(const Vector2&);
	void operator*=(const Vector2&);
	bool operator>(const Vector2&) const;
	bool operator<(const Vector2&) const;

};
