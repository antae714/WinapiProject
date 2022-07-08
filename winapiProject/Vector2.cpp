#include "Vector2.h"
#include "Math.h"
#include <Windows.h>

const Vector2 Vector2::UnitX(1.f, 0.f);
const Vector2 Vector2::UnitY(0.f, 1.f);
const Vector2 Vector2::Zero(0.f, 0.f);
const Vector2 Vector2::One(1.f, 1.f);

Vector2::Vector2() : x(0),y(0)
{
	scalar.at(0) = 0;
	scalar.at(1) = 0;
}

Vector2::Vector2(float p_x, float p_y) : x(p_x), y(p_y)
{
	scalar.at(0) = p_x;
	scalar.at(1) = p_y;
}

float Vector2::getx() const
{
	return x;
}

float Vector2::gety() const
{
	return y;
}

void Vector2::setx(float p_x)
{
	x = p_x;
}

void Vector2::sety(float p_y)
{
	y = p_y;
}

void Vector2::addx(float p_x)
{
	x += p_x;
}

void Vector2::addy(float p_y)
{
	y = p_y;
}

Vector2 Vector2::GetNormalize()
{
	float squareSum = SizeSquared();
	if (squareSum == 1.f)
	{
		return *this;
	}
	else if (squareSum == 0.f)
	{
		return Vector2::Zero;
	}

	float invLength = Math::InvSqrt(squareSum);
	return Vector2(x, y) * invLength;
}

void Vector2::Normalize()
{
	*this =  GetNormalize();
}

float Vector2::SizeSquared()
{
	return x * x + y * y;
}

float Vector2::Dot(const Vector2& other) const
{
	return x * other.x + y * other.y;
}

POINT Vector2::toPOINT() const
{
	POINT tempPOINT;
	tempPOINT.x = this->x;
	tempPOINT.y = this->y;
	return tempPOINT;
}

bool Vector2::operator==(const Vector2& p_other)
{
	return this->x == p_other.x ? (this->y == p_other.y ? true : false) : (false);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(this->x - other.x, this->y - other.y);
}
Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(this->x + other.x, this->y + other.y);
}


Vector2 Vector2::operator*(const float& p_scalar)
{
	return Vector2(x * p_scalar, y * p_scalar);
}

