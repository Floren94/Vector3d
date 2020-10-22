#pragma once
#include <math.h>

class Vector3 {
public:

	Vector3();
	Vector3(double x, double y, double z);
	Vector3(const Vector3& v);
	~Vector3();

	Vector3 operator = (const Vector3& vec) const;
	Vector3 operator +  (const Vector3& vec) const;
	Vector3& operator += (const Vector3& vec);
	Vector3& operator /= (const double val);

	double	 distanceTo(const Vector3& vec) const;
	double   angleTo(const Vector3& vec) const;
	double   dotProduct(const Vector3& vec) const;
	Vector3  crossProduct(const Vector3& vec) const;
	Vector3& normalize();

	double         x, y, z;

private:
	double length() const;
};

inline
Vector3::Vector3() : x(0.0), y(0.0), z(0.0)
{
}

inline
Vector3::Vector3(double xx, double yy, double zz) : x(xx), y(yy), z(zz) 
{
}

inline
Vector3::Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z)
{
}

inline
Vector3::~Vector3()
{
}

inline Vector3
Vector3::operator = (const Vector3& vec) const
{
	Vector3 v;
	v = vec;
	return v;
}

inline Vector3&
Vector3::operator /= (double val)
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

inline double
Vector3::distanceTo(const Vector3& vec) const
{
	double a = (x - vec.x) * (x - vec.x);
	double b = (y - vec.y) * (y - vec.y);
	double c = (z - vec.z) * (z - vec.z);

	return sqrt(a + b + c);
}

inline double
Vector3::angleTo(const Vector3& vec) const
{
	double dot = dotProduct(vec);

	const double len = length() * vec.length();

	return acos(dot / len);
}

inline double
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
	const double len = length();
	 //Should check if len is positive
	*this /= len;

	return *this;
}

inline double
Vector3::length() const
{
	return sqrt((x * x) + (y * y) + (z * z));
}