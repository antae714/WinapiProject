#include "Vector3.h"
#include "Vector2.h"

const Vector3 Vector3::UnitX(1.f, 0.f, 0.f);
const Vector3 Vector3::UnitY(0.f, 1.f, 0.f);
const Vector3 Vector3::UnitZ(0.f, 0.f, 1.f);
const Vector3 Vector3::Zero(0.f, 0.f, 0.f);
const Vector3 Vector3::One(1.f, 1.f, 1.f);

Vector3::Vector3() : x(0), y(0), z(0)
{
	Vector3(x, y, z);
}

Vector3::Vector3(float p_x, float p_y, float p_z) : x(p_x), y(p_y), z(p_z)
{
	scalar.at(0) = x;
	scalar.at(1) = y;
	scalar.at(2) = z;
}

Vector3::Vector3(const Vector2& p_vec, bool ispoint) : x(p_vec.getx()), y(p_vec.gety()), z(ispoint ? 1.f : 0.f)
{
}

float Vector3::Dot(const Vector3& otherVec)
{
	return (this->x * otherVec.x) + (this->y * otherVec.y) + (this->z * otherVec.z);
}

Vector2 Vector3::toVector2()
{
	return Vector2(x, y);
}

float Vector3::getx()
{
	return x;
}

float Vector3::gety()
{
	return y;
}

float Vector3::getz()
{
	return z;
}
