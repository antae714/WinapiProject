#pragma once
#include "Component.h"

class Vector2;
class TransformComponent : public Component
{
private:
	Vector2* pivot;
	float rotate;
public:
	TransformComponent();
	TransformComponent(const Vector2&, const float&);
	virtual ~TransformComponent( );
public:

	Vector2	getpivot();
	const Vector2* getpivotptr();
	const float* getrotateptr();
	float	getrotate	();
	void	addpivot	(const Vector2&);
	void	setpivot	(const Vector2&);
	void	setrotate	(const float&);

	void move(const Vector2&);
};

