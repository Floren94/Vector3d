#include "vector3.h"
#include <iostream>
using namespace std;

// debug_new.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_new.cpp
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int main(int argc, char** argv) 
{
	double x = 0, y = 0, z = 0;
	Vector3 origin;

	cout << "Enter x,y,z for first vector. Ex: " 
		<< "(" << origin.x << "," << origin.y << "," << origin.z << ")" <<endl;
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	cout << "Z: ";
	cin >> z;

	Vector3 v(x, y, z);
	Vector3 norm (v);
	norm.normalize();
	cout << "Normalized: " << "(" << norm.x <<"," << norm.y << "," << norm.z << ")" << endl;

	cout << "Enter x,y,z for second vector " << endl;
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	cout << "Z: ";
	cin >> z;

	Vector3 v2(x, y, z);
	Vector3 cross = v.crossProduct(v2);
	Vector3 sum = v + v2;

	cout << "Distance: " << v.distanceTo(v2) << endl;
	cout << "Dot porduct: " << v.dotProduct(v2) << endl;
	cout << "Angle between: " << v.angleTo(v2) << " Rad" << endl;
	cout << "Cross: " << "(" << cross.x << "," << cross.y << "," << cross.z << ")" << endl;
	cout << "Sum: " << "(" << sum.x << "," << sum.y << "," << sum.z << ")" << endl;

	_CrtDumpMemoryLeaks();
}
