#ifndef CIRCLE2_H
#define CIRCLE2_H

#include <iostream>
#include "point2.h"
#include "Line2.h"



using std::ostream;

class Circle2 {

public:
	Point2 p1{};
    float r{};

	Circle2() = default;
	Circle2(Point2 np1, float nr);
	float circumference();
    float area();
    bool contains(Point2 p);
    bool contains(Line2 l);
    void scale(float factor);
	friend ostream& operator<< (ostream& os, const Circle2& c);
};
#endif
