#include "../include/point2.h"
#include <cmath>
using namespace std;

Point2::Point2(float nx, float ny) : x {nx}, y {ny} {}

float Point2::distanceFrom (Point2 p) {
	// siia kood
	return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}

ostream& operator << (ostream& os, const Point2& p){
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

/*Line2::Line2(Point2 np1, Point2 np2) : p1 {np1}, p2 {np2} {}

float Line2::length() {
	return this->p1.distanceFrom(this->p2);
}

ostream& operator << (ostream& os, const Line2& l){
	os << "(" << l.p1 << " - " << l.p2 << ")";
	return os;
}*/