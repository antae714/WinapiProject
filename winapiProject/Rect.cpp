#include "Rect.h"
#include "Vector2.h"
#include "Math.h"
#include "Macro.h"
#include <algorithm>
#include <string>
#include <iterator>

Rect::Rect() :
	pivot(nullptr), rotate(0), weight(10), height(10)
{
	Awake();
}

Rect::Rect(const Vector2* p_pivot, const float& p_rotate, const float& p_weight, const float& p_height) :
	pivot(p_pivot), rotate(&p_rotate), weight(p_weight), height(p_height)
{
	Awake();
}

Rect::Rect(const float& p_rotate, const float& p_weight, const float& p_height) :
	pivot(nullptr), rotate(&p_rotate), weight(p_weight), height(p_height)
{
	Awake();
}

Rect::~Rect()
{
	for (int i = 0; i < Vectors.size(); ++i) {
		delete Vectors.at(i);
	}
}

void Rect::Awake()
{
	scale = 1;
	float hlafHe = height / 2;
	float hlafWe = weight / 2;
	Vectors.at(0) = new Vector2(-hlafWe, -hlafHe);
	Vectors.at(1) = new Vector2(hlafWe, -hlafHe);
	Vectors.at(2) = new Vector2(-hlafWe, hlafHe);
	Vectors.at(3) = new Vector2(hlafWe, hlafHe);

	index.at(0) = 0;
	index.at(1) = 1;
	index.at(2) = 2;
	index.at(3) = 1;
	index.at(4) = 2;
	index.at(5) = 3;
}

vector<Vector2> Rect::getVectors() const
{
	vector<Vector2> returnVec;

	for (Vector2* item : Vectors)
	{
		returnVec.push_back(Math::getaffinTransform(scale, *rotate, getpivot(), *item));
	}

	return returnVec;
}

Vector2 Rect::getpivot() const
{
	if (ispivotset()) return *pivot;
	_ASSERT(ispivotset() && "존재하지 않는 피벗 사용");
	return Vector2();
}

float Rect::getrotate()
{
	return *rotate;
}

float Rect::getheight() const
{
	return height;
}

float Rect::gethalfheight() const
{
	return height / 2;
}

float Rect::getweight() const
{
	return weight;
}

float Rect::gethalfweight() const
{
	return weight / 2;
}

Triange Rect::getTriangle(int p_index) const
{
	array<Vector2, 3> returnarr;
	p_index *= 3;
	returnarr.at(0) = *Vectors.at(index.at(p_index));
	returnarr.at(1) = *Vectors.at(index.at(p_index + 1));
	returnarr.at(2) = *Vectors.at(index.at(p_index + 2));
	return returnarr;
}

void Rect::setpivotptr(const Vector2* p_pivot)
{
	pivot = p_pivot;
}

void Rect::setrotateptr(const float* p_rotate)
{
	rotate = p_rotate;
}

void Rect::operator=(const Rect& other)
{
	*this->Vectors.at(0) = *other.Vectors.at(0);
	*this->Vectors.at(1) = *other.Vectors.at(1);
	*this->Vectors.at(2) = *other.Vectors.at(2);
	*this->Vectors.at(3) = *other.Vectors.at(3);
	if (other.ispivotset()) {
		this->pivot = other.pivot;
	}

	this->index = other.index;
	this->rotate = other.rotate;
	this->scale = other.scale;
	this->weight = other.weight;
	this->height = other.height;
}

bool Rect::ispivotset() const
{
	return nullptr != pivot;
}

