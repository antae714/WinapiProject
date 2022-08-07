#pragma once

#include <array>
#include <vector>

using namespace std;
class Vector2;
class Matrix3x3;
class Rect;
typedef array<Vector2, 3> Triange;
namespace Math {;
//좌표계 => 화면좌표
Vector2 CarttoScreen(const Vector2& p_vec);
//화면좌표 => 좌표계
Vector2 ScreentoCart(const Vector2& p_vec);

//아핀 변환 함수
Matrix3x3 affinTransform(float weight, float height, float Degree, Vector2 Position);
//in_vector를 아핀 변환한 결과
Vector2 getaffinTransform(float scale, float Degree, Vector2 Position, Vector2 in_vector);
//in_vector를 아핀 변환한 결과
Vector2 getaffinTransform(float weight, float height, float Degree, Vector2 Position, Vector2 in_vector);
//라디안 받아서 삼각함수 계산
void GetSinCos(float& out_sin, float& out_cos, float in_degree);
//고속 역제곱근
float InvSqrt(float);

bool Betwwen(float left, float right, float standard);

//OBB충돌
bool isin(const Rect& firstRect, const Rect& secondRect);
bool isin(const Rect& prect, const Vector2& point);
bool isin(const Triange& Tri, const Vector2& point);

bool OBBtest(const Vector2& unit, const Vector2& axisvec, const Vector2& othervec, const Vector2& bitweenvec);

float Distance(const Vector2& first, const Vector2& second);
//가까우면 참
bool iscolose(const Vector2& first, const Vector2& second, float distance);
bool lpts(const Vector2& first, const Vector2& second, float distance);

template<class T>
void Swap(T& p_first, T& p_second)
{
    T temp = p_first;
    p_first = p_second;
    p_second = temp;
}
template<class T>
T Max(const T A, const T B);
template<class T>
T Min(const T A, const T B);
template<class T>
T Max3(const T A, const T B, const T C);
template<class T>
T Min3(const T A, const T B, const T C);
};