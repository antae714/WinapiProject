#include "Rect.h"
#include "Vector2.h"
#include "Math.h"
#include "TransformComponent.h"
#include "UITransformComponent.h"
#include "Macro.h"
#include <algorithm>
#include <string>
#include <iterator>

Rect::Rect() :
	pivot(nullptr), rotate(nullptr), weight(10), height(10)
{
	Awake();
}

Rect::Rect(const float& p_weight, const float& p_height) :
	pivot(nullptr), rotate(nullptr), weight(p_weight), height(p_height)
{
	Awake();
}

Rect::Rect(const float& p_weight, const float& p_height, TransformComponent* comp) :
	pivot(comp->getpivotptr()), rotate(comp->getrotateptr()), weight(p_weight), height(p_height)
{
	Awake();
}

Rect::Rect(const float& p_weight, const float& p_height, UITransformComponent* comp) :
	pivot(comp->getpivotptr()), rotate(comp->getrotateptr()), weight(p_weight), height(p_height)
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
	Vectors.at(0) = new Vector2(-hlafWe, hlafHe);
	Vectors.at(1) = new Vector2(hlafWe, hlafHe);
	Vectors.at(2) = new Vector2(-hlafWe, -hlafHe);
	Vectors.at(3) = new Vector2(hlafWe, -hlafHe);

	index.at(0) = 0;
	index.at(1) = 1;
	index.at(2) = 2;
	index.at(3) = 1;
	index.at(4) = 2;
	index.at(5) = 3;
}

vector<Vector2> Rect::getVertexes() const
{
	vector<Vector2> returnVec;

	for (Vector2* item : Vectors)
	{
		returnVec.push_back(Math::getaffinTransform(scale, *rotate, getpivot(), *item));
	}

	return returnVec;
}

vector<Vector2> Rect::getVectorS() const
{
	vector<Vector2> returnVec(4);

	for (int i = 0 ; i < 4 ; ++i)
	{
		returnVec.at(i) = Rect::at(i);
	}
	return returnVec;
}

Vector2 Rect::getpivot() const
{
	if (ispivotset()) return *pivot;
	_ASSERT(ispivotset() && "존재하지 않는 피벗 사용");
	return Vector2();
}

float Rect::getrotate() const
{
	if(rotate) return *rotate;
	return 0.f;
}

float Rect::getheight() const
{
	return height;
}

float Rect::gethalfheight() const
{
	return height * 0.5f;
}

float Rect::getweight() const
{
	return weight;
}

float Rect::gethalfweight() const
{
	return weight * 0.5f;
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

Rect* Rect::setpivotptr(const Vector2* p_pivot)
{
	pivot = p_pivot;
	return this;
}

Rect* Rect::setrotateptr(const float* p_rotate)
{
	rotate = p_rotate;
	return this;
}

Rect* Rect::setheight(float p_height)
{
	height = p_height;
	return this;
}

Rect* Rect::setweight(float p_weight)
{
	weight = p_weight;
	return this;
}

Vector2 Rect::at(int p_val) const
{
	return Vectors.at(p_val)->GetRotate(*rotate);
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

