#pragma once
#include "Component.h"

class Vector2;
class UITransformComponent : public Component
{
private:
	Vector2* pivot;
	float rotate;
public:
	UITransformComponent();
	UITransformComponent(const Vector2&, float);
	virtual ~UITransformComponent();

public:
	Vector2	getpivot();
	float	getrotate();
	const Vector2* getpivotptr();
	const float* getrotateptr();


	void	setpivot(const Vector2&);
	void	setrotate(const float&);
};

