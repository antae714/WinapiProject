#pragma once
#include "Component.h"

template <typename T> class EventList1;
class Vector2;
class TransformComponent : public Component
{
private:
	Vector2* pivot;
	float rotate;
public:
	TransformComponent();
	virtual ~TransformComponent();
public:

	Vector2	getpivot();
	const Vector2* getpivotptr();
	const float* getrotateptr();
	float	getrotate	();
	void	setpivot	(const Vector2&);
	void	setrotate	(const float&);
};

