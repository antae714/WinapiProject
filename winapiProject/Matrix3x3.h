#pragma once

#include<array>

using namespace std;

class Vector3;
class Vector3;
#include "Vector3.h"
class Matrix3x3
{
private:
	std::array<Vector3, 3> vectors;
public:
	Matrix3x3(const Vector3&, const Vector3&, const Vector3&);
public:
	Vector3 at(int) const;
	Matrix3x3 Transpose();
public:
	Matrix3x3 operator*(const Matrix3x3&);
	Vector3 operator*(const Vector3&);
	Vector2 operator*(const Vector2&);
};

