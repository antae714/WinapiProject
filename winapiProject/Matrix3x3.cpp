#include "Matrix3x3.h"
#include "Vector3.h"
#include "Vector2.h"

Matrix3x3::Matrix3x3(const Vector3& p_vec1, const Vector3& p_vec2, const Vector3& p_vec3)
{
	vectors = { p_vec1, p_vec2,  p_vec3 };
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other)
{

	Matrix3x3 transposedMatrix = Transpose();
	return Matrix3x3(
		Vector3(transposedMatrix.at(0).Dot(other.at(0)), transposedMatrix.at(1).Dot(other.at(0)), transposedMatrix.at(2).Dot(other.at(0))),
		Vector3(transposedMatrix.at(0).Dot(other.at(1)), transposedMatrix.at(1).Dot(other.at(1)), transposedMatrix.at(2).Dot(other.at(1))),
		Vector3(transposedMatrix.at(0).Dot(other.at(2)), transposedMatrix.at(1).Dot(other.at(2)), transposedMatrix.at(2).Dot(other.at(2)))
	);
}
Vector3 Matrix3x3::operator*(const Vector3& other) {
	Matrix3x3 transposedMatrix = Transpose();

	Vector3 v1 = Vector3(
		transposedMatrix.at(0).Dot(other),
		transposedMatrix.at(1).Dot(other),
		transposedMatrix.at(2).Dot(other)
	);

	return v1;
	/*return Vector3(
		transposedMatrix.at(0).Dot(other),
		transposedMatrix.at(1).Dot(other),
		transposedMatrix.at(2).Dot(other)
	);*/
}
Vector2 Matrix3x3::operator*(const Vector2& other) {
	Vector3 v3(other, true);
	v3 = *this * v3;


	return v3.toVector2();
}

Matrix3x3 Matrix3x3::Transpose()
{
	return Matrix3x3(
		Vector3(vectors.at(0).getx(), vectors.at(1).getx(), vectors.at(2).getx()),
		Vector3(vectors.at(0).gety(), vectors.at(1).gety(), vectors.at(2).gety()),
		Vector3(vectors.at(0).getz(), vectors.at(1).getz(), vectors.at(2).getz())
	);
}

Vector3 Matrix3x3::at(int p_index) const
{
	return vectors.at(p_index);
}
