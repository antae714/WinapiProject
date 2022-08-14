#include "Math.h"
#include "Matrix3x3.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Rect.h"
#include "GameData.h"
#include <algorithm>
#include <random>

Vector2 Math::CarttoScreen(const Vector2& p_vec)
{
    GameData* gameData = GameData::getInstance();
    float windowX = gameData->getIngamewindowX();
    float windowY = gameData->getIngamewindowY();
    Vector2 pivot = gameData->getcameraPivot();
    Vector2 tempVec = p_vec - pivot;

    tempVec.addx(windowX / 2);
    tempVec.sety(windowY - (tempVec.gety() + windowY / 2));
    return tempVec;
}
Vector2 Math::ScreentoCart(const Vector2& p_vec)
{
    GameData* gameData = GameData::getInstance();
    float windowX = gameData->getIngamewindowX();
    float windowY = gameData->getIngamewindowY();
    Vector2 pivot = gameData->getcameraPivot();

    Vector2 tempVec;
    tempVec.setx(p_vec.getx() + pivot.getx());
    tempVec.sety(p_vec.gety() - pivot.gety());
    tempVec.addx(-windowX / 2);
    tempVec.sety(-tempVec.gety() + windowY / 2);
    //tempVec.sety(-tempVec.gety() + windowY / 2);
    return tempVec;
}
Matrix3x3 Math::affinTransform(float weight, float height, float Degree, Vector2 Position)
{
    // ���� ��ȯ ��� ( ũ�� ) 
    Vector3 sBasis1(weight, 0.f, 0.f);
    Vector3 sBasis2(0.f, height, 0.f);
    Vector3 sBasis3 = Vector3::UnitZ;
    Matrix3x3 sMatrix(sBasis1, sBasis2, sBasis3);

    // ���� ��ȯ ��� ( ȸ�� ) 
    float sin = 0.f, cos = 0.f;
    Math::GetSinCos(sin, cos, Degree);
    Vector3 rBasis1(cos, sin, 0.f);
    Vector3 rBasis2(-sin, cos, 0.f);
    Vector3 rBasis3 = Vector3::UnitZ;
    Matrix3x3 rMatrix(rBasis1, rBasis2, rBasis3);

    // ���� ��ȯ ��� ( �̵� ) 
    Vector3 tBasis1 = Vector3::UnitX;
    Vector3 tBasis2 = Vector3::UnitY;
    Vector3 tBasis3(Position.getx(), Position.gety(), 1.f);
    Matrix3x3 tMatrix(tBasis1, tBasis2, tBasis3);

    // ��� ���� ��ȯ�� ���� �ռ� ���. ũ��-ȸ��-�̵� ������ ����
    return tMatrix * rMatrix * sMatrix;
}

Vector2 Math::getaffinTransform(float scale, float Degree, Vector2 Position, Vector2 in_vector)
{
    return affinTransform(scale, scale, Degree, Position) * in_vector;
}   

Vector2 Math::getaffinTransform(float weight, float height, float Degree, Vector2 Position, Vector2 in_vector)
{
    return affinTransform(weight, height, Degree, Position) * in_vector;
}

void Math::GetSinCos(float& out_sin, float& out_cos, float in_degree)
{
    out_sin = sin(in_degree);
    out_cos = cos(in_degree);
}

float Math::InvSqrt(float p_float)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = p_float * 0.5F;
    y = p_float;
    i = *(long*)&y;
    i = 0x5f375a86 - (i >> 1);
    y = *(float*)&i;
    y = y * (threehalfs - (x2 * y * y));
    y = y * (threehalfs - (x2 * y * y));;

    return y;
}

bool Math::Betwwen(float left, float right, float standard)
{
    return left <= standard ? (standard <= right) : false;
}

bool Math::isin(const Rect& p_firstRect, const Rect& p_secondRect)
{
    Vector2 distanceVec = p_firstRect.getpivot() - p_secondRect.getpivot();
    array<Vector2, 4> axisVector;
    axisVector.at(0) = ((p_firstRect.at(0) + p_firstRect.at(1)));
    axisVector.at(1) = ((p_firstRect.at(1) + p_firstRect.at(3)));
    axisVector.at(2) = ((p_secondRect.at(0) + p_secondRect.at(1)));
    axisVector.at(3) = ((p_secondRect.at(1) + p_secondRect.at(3)));

    for (Vector2 item : axisVector) {
        //if (OBBtest(item, p_firstRect.at(0), p_secondRect.at(0), distanceVec)) continue;
        if (OBBtest(item, p_firstRect.at(0), p_secondRect.at(1), distanceVec)) continue;
        if (OBBtest(item, p_firstRect.at(1), p_secondRect.at(0), distanceVec)) continue;
        //if (OBBtest(item, p_firstRect.at(1), p_secondRect.at(1), distanceVec)) continue;
        return false;
    }
    return true;
}

bool Math::isin(const Rect& p_rect, const Vector2& p_point) {
    for (int i = 0; i < 2; ++i) {
        if (isin(p_rect.getTriangle(i), p_point - p_rect.getpivot())) return true;
    }
    return false;
}

bool Math::isin(const Triange& p_Tri, const Vector2& p_point)
{
    Vector2 minPos(Math::Min3(p_Tri.at(0).getx(), p_Tri.at(1).getx(), p_Tri.at(2).getx()), Math::Min3(p_Tri.at(0).gety(), p_Tri.at(1).gety(), p_Tri.at(2).gety()));
    Vector2 maxPos(Math::Max3(p_Tri.at(0).getx(), p_Tri.at(1).getx(), p_Tri.at(2).getx()), Math::Max3(p_Tri.at(0).gety(), p_Tri.at(1).gety(), p_Tri.at(2).gety()));

    // �����߽���ǥ�� ���� �غ��۾�
    Vector2 u = p_Tri.at(1) - p_Tri.at(0);
    Vector2 v = p_Tri.at(2) - p_Tri.at(0);

    // ���� �и� ( uu * vv - uv * uv )
    float udotv = u.Dot(v);
    float vdotv = v.Dot(v);
    float udotu = u.Dot(u);
    float denominator = udotv * udotv - vdotv * udotu;
    if (denominator == 0.0f) return false;
    float invDenominator = 1.f / denominator;
    Vector2 w = p_point - p_Tri.at(0);


    float wdotu = w.Dot(u);
    float wdotv = w.Dot(v);

    // ���� ���� ���ϰ� ���� �����߽���ǥ ����
    float s = (wdotv * udotv - wdotu * vdotv) * invDenominator;
    float t = (wdotu * udotv - wdotv * udotu) * invDenominator;
    float oneMinusST = 1.f - s - t;
    return (Betwwen(0, 1, s) && Betwwen(0, 1, t) && Betwwen(0, 1, oneMinusST));
}

bool Math::OBBtest(const Vector2& unit, const Vector2& axisvec, const Vector2& othervec, const Vector2& bitweenvec)
{
    float length1 = axisvec.Dot(unit);
    float length2 = othervec.Dot(unit);
    float distancelength = bitweenvec.Dot(unit);

    return abs(length1) + abs(length2) > abs(distancelength);
}

float Math::Distance(const Vector2& first, const Vector2& second)
{
    return sqrt(first.getx() * second.getx() + first.gety() * second.gety());
}

bool Math::iscolose(const Vector2& first, const Vector2& second, float distance)
{
    return first.getx() * second.getx() + first.gety() * second.gety() <= distance * distance;
}

bool Math::lpts(const Vector2& first, const Vector2& second, float distance)
{
    int x1 = first.getx();
    int x2 = second.getx();
    int y1 = first.gety();
    int y2 = second.gety();
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= distance * distance;
}

int Math::randint(int first, int second)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dis(first, second);
    return dis(gen);
}




template<class T>
T Math::Max(const T A, const T B)
{
    return (A >= B) ? A : B;
}

template<class T>
T Math::Min(const T A, const T B)
{
    return (A <= B) ? A : B;
}

template< class T >
T Math::Max3(const T A, const T B, const T C)
{
    return Max(Max(A, B), C);
}

template< class T >
T Math::Min3(const T A, const T B, const T C)
{
    return Min(Min(A, B), C);
}