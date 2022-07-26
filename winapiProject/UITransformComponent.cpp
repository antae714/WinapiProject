#include "UITransformComponent.h"
#include "Vector2.h"
#include "EventList1.h"
#include "Rect.h"
#include "GameObject.h"
#include "Macro.h"
#include "CollisonCompoenet.h"
#include "E_Component.h"
#include "GameData.h"
#include "Math.h"

UITransformComponent::UITransformComponent() :
    pivot(new Vector2()), rotate(0.f)
{
}

UITransformComponent::UITransformComponent(const Vector2& p_vec, float p_rot):
    pivot(new Vector2(p_vec)), rotate(p_rot)
{
}

UITransformComponent::~UITransformComponent()
{
    delete pivot;
}

Vector2 UITransformComponent::getpivot()
{
    return *pivot;
}

float UITransformComponent::getrotate()
{
    return rotate;
}

const Vector2* UITransformComponent::getpivotptr()
{
    return pivot;
}

const float* UITransformComponent::getrotateptr()
{
    return &rotate;
}
void UITransformComponent::setpivot(const Vector2& p_pivot)
{
    *pivot = p_pivot;
}

void UITransformComponent::setrotate(const float& p_rotate)
{
    rotate = p_rotate;
}