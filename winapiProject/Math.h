#pragma once

#include <array>
#include <vector>

using namespace std;
class Vector2;
class Matrix3x3;
class Rect;
typedef array<Vector2, 3> Triange;
namespace Math {;
//��ǥ�� => ȭ����ǥ
Vector2 CarttoScreen(const Vector2& p_vec);
//ȭ����ǥ => ��ǥ��
Vector2 ScreentoCart(const Vector2& p_vec);

//���� ��ȯ �Լ�
Matrix3x3 affinTransform(float weight, float height, float Degree, Vector2 Position);
//in_vector�� ���� ��ȯ�� ���
Vector2 getaffinTransform(float scale, float Degree, Vector2 Position, Vector2 in_vector);
//in_vector�� ���� ��ȯ�� ���
Vector2 getaffinTransform(float weight, float height, float Degree, Vector2 Position, Vector2 in_vector);
//���� �޾Ƽ� �ﰢ�Լ� ���
void GetSinCos(float& out_sin, float& out_cos, float in_degree);
//��� ��������
float InvSqrt(float);

bool Betwwen(float left, float right, float standard);


bool isin(const Rect& p_rect, const Vector2& p_point);
bool isin(const Triange& p_Tri, const Vector2& p_point);

template<class T>
T Max(const T A, const T B);
template<class T>
T Min(const T A, const T B);
template<class T>
T Max3(const T A, const T B, const T C);
template<class T>
T Min3(const T A, const T B, const T C);
};