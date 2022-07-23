#pragma once

#include <array>
#include <vector>

using namespace std;


class Vector2;
typedef array<Vector2, 3> Triange;

class Rect
{
private:
	array<Vector2*, 4> Vectors;
	array<int, 6>index;
	//포지션
	const Vector2* pivot;
	//로테이션
	const float* rotate;
	//스케일
	float scale;
	float weight;
	float height;
	
public:
	Rect();
	Rect(const Vector2* p_pivot, const float& p_rotate, const float& p_weight, const float& p_height);
	Rect(const float& p_rotate, const float& p_weight, const float& p_height);
	virtual ~Rect(); 
private:
	void Awake();
public:
	vector<Vector2> getVertexes() const;
	vector<Vector2> getVectorS() const;
	Vector2 getpivot() const;
	float getrotate() const;
	float getheight() const;
	float gethalfheight() const;
	float getweight() const;
	float gethalfweight() const;

	Triange getTriangle(int) const;

	Rect* setpivotptr(const Vector2*);
	Rect* setrotateptr(const float*);
	Rect* setheight(float);
	Rect* setweight(float);

	Vector2 at(int) const;
	void operator=(const Rect& other);

private:
	//세팅되었으면 참
	bool ispivotset() const;
};