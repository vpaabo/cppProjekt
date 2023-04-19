#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include "../include/geometry.h"

using namespace std;

int testcount = 0;
#define TEST2(a,b,b2,c,c2) cout << "Test " << ++testcount << ". " << a << ": " << ((cmpf(b,b2) && cmpf(c,c2)) ? "OK" :"FAIL") << '\n'

bool cmpf (float a, float b) {
	if (fabs (a - b) < 0.001f) 
		return true;
	return false;
}

int main (int argc, char* argv[]) {

	// Point2
	cout << "--Testi klassi Point2" << '\n';
	// Require default constructor 
	Point2 v1;
	// Require public coordinates x and y
	cout << v1.x << " " << v1.y << '\n';
	// Testi Point2 vaikekonstruktorit
	TEST2("Point2 vaikekonstruktor v1(0,0)", v1.x, 0, v1.y, 0);
	// Require constructor with two parameters
	Point2 v2 {4.0, -3.0}; // c++11 
	TEST2("Point2 konstruktor v2(1,-1)", v2.x, 1, v2.y, -1);
	// TODO: lisa oma testid
	// Require distanceFrom method
	cout << v1.distanceFrom(v2) << '\n';
	// Require operator <<
	cout << v1 << '\n';

	// Line2
	// Require default constructor
	Line2 l1;
	// Require public points p1 and p2
	cout << l1.p1 << "-" << l1.p2 << '\n';
	// Require constructor with two parameters
	Line2 l2 {v1, v2};
	// Require method length
	cout << l1.length() << '\n';
	// Require operator <<
	cout << "joon: " << l2 << '\n'; 

	// Circle2
	// Require default constructor
	Circle2 c1;
	// Require variable p1
	cout << c1.p1 << '\n';
	// Require variable r
	cout << c1.r << '\n';
	// Require constructor with point and a radius
	Circle2 c2 {v2, 1.0};
	// Require method circumference
	float f = c1.circumference();
	// Require method area
	f = c1.area();
	// Require method contains(Point2)
	bool b = c1.contains(v1);
	// Require method contains(Line2)
	b = c1.contains(l1);
	// Require method scale
	c1.scale(1.0); 
	// Require operator <<
	cout << "ring: " << c2 << '\n';

	/* Remove this comment to test the bonus task

	// Point3
	// Require default constructor
	Point3 v3_1;
	// Require public coordinates x, y and z
	cout << v3_1.x << " " << v3_1.y << " " << v3_1.z << '\n';
	// Require constructor with three parameters
	Point3 v3_2 {1.0, 0.0, -1.0};
	// Requre method distanceFrom
	f = v3_1.distanceFrom (v3_2);
	// Require operator <<
	cout << v3_1 << '\n';

	// Line3
	// Require default constructor
	Line3 l3_1;
	// Require constructor with two parameters
	Line3 l3_2 {v3_1, v3_2};
	// Require method length
	f = l3_1.length();
	// Require operator <<
	cout << l3_1 << '\n';

	// Sphere3
	// Require default constructor
	Sphere3 s3_1;
	// Require constructor with point and a radius
	Sphere3 s3_2 {v3_1, 1.0};
	// Require method circumference
	f = s3_1.circumference();
	// Require method volume
	f = s3_1.volume();
	// Require method contains(Point3)
	b = s3_1.contains(v3_1);
	// Require method contains(Line3)
	b = s3_1.contains(l3_1);
	// Require method scale
	s3_1.scale(1.0);
	// Require operator <<
	cout << s3_1 << '\n';

	Remove this comment to test the bonus task */   

	cout << "Testide arv: " << testcount << '\n';
	return EXIT_SUCCESS;
}
