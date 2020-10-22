#pragma once
#include <math.h>

class Vector3 {
public:

	Vector3() : x(0.0), y(0.0), z(0.0) {}
	Vector3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}
	Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

	Vector3 operator = (const Vector3& vec) const;
	Vector3 operator +  (const Vector3& vec) const;
	Vector3& operator += (const Vector3& vec);
	Vector3& operator /= (const float val);

	float	 distanceTo(const Vector3& vec) const;
	float   angleTo(const Vector3& vec) const;
	float   dotProduct(const Vector3& vec) const;
	Vector3  crossProduct(const Vector3& vec) const;
	Vector3& normalize();

	float         x, y, z;

private:

	float length() const;
};

inline Vector3
Vector3::operator = (const Vector3& vec) const
{
	Vector3 v;
	v = vec;
	return v;
}

inline Vector3&
Vector3::operator /= (float val)
{
	x /= val;
	y /= val;
	z /= val;
	return *this;
}

inline Vector3
Vector3::operator + (const Vector3& v) const
{
	Vector3 vec (x + v.x, y + v.y, z + v.z);
	return vec;
}

inline Vector3&
Vector3::operator += (const Vector3& v) 
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

inline float
Vector3::distanceTo(const Vector3& vec) const
{
	float a = (x - vec.x) * (x - vec.x);
	float b = (y - vec.y) * (y - vec.y);
	float c = (z - vec.z) * (z - vec.z);

	return sqrt(a + b + c);
}

inline float
Vector3::angleTo(const Vector3& vec) const
{
	float dot = dotProduct(vec);

	const float len = length() * vec.length();

	return acos(dot / len);
}

inline float
Vector3::dotProduct(const Vector3& vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

inline Vector3
Vector3::crossProduct(const Vector3& vec) const
{	
	Vector3 v (y * vec.z - z * vec.y,
		z * vec.x - x * vec.z,
		x * vec.y - y * vec.x);
	return v;
}

inline Vector3&
Vector3::normalize() 
{
	const float len = length();
	 //Should check if len is positive
	*this /= len;

	return *this;
}

inline float
Vector3::length() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}