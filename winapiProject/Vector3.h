#pragma once

#include<array>

using namespace std;

class Vector2;
class Vector3
{
public:
	static constexpr int Dimension = 3;
	static const Vector3 UnitX;
	static const Vector3 UnitY;
	static const Vector3 UnitZ;
	static const Vector3 One;
	static const Vector3 Zero;
private:
	float x;
	float y;
	float z;
	array<float, Dimension> scalar;
public:
	Vector3();
	Vector3(float, float, float);
	Vector3(const Vector2&, bool);

public:
	float Dot(const Vector3&);
	Vector2 toVector2();
	float getx();
	float gety();
	float getz();
public:
};

