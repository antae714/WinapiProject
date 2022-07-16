#include "TransformComponent.h"
#include "Vector2.h"
#include "EventList1.h"
#include "Rect.h"

TransformComponent::TransformComponent()
{
    pivot = new Vector2();
    rotate = 0;
}

TransformComponent::TransformComponent(const Vector2& p_vec, const float& p_rot)
{
    pivot = new Vector2(p_vec);
    rotate = p_rot;
}

TransformComponent::~TransformComponent()
{
    delete pivot;
}

Vector2 TransformComponent::getpivot()
{
    return *pivot;
}

const Vector2* TransformComponent::getpivotptr()
{
    return pivot;
}

const float* TransformComponent::getrotateptr()
{
    return &rotate;
}

float TransformComponent::getrotate()
{
    return rotate;
}

void TransformComponent::addpivot(const Vector2& p_pivot)
{
    *pivot += p_pivot;
}

void TransformComponent::setpivot(const Vector2& p_pivot)
{
    *pivot = p_pivot;
}

void TransformComponent::setrotate(const float& p_rotate)
{
    rotate = p_rotate;
}