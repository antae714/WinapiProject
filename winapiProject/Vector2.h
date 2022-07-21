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

	Vector2 GetNormalize();
	void Normalize();
	float SizeSquared();
	float Dot(const Vector2&) const;
	POINT toPOINT() const;
public:
	bool operator==(const Vector2&);
	Vector2 operator-(const Vector2&) const;
	Vector2 operator+(const Vector2&) const;
	void operator+=(const Vector2&);
	Vector2 operator*(const float&);
	void operator*=(const Vector2&);

};
