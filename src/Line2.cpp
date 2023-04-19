#include "../include/Line2.h"
#include <cmath>
using namespace std;

Line2::Line2(Point2 np1, Point2 np2) : p1 {np1}, p2 {np2} {}

float Line2::length() {
	return (this->p1).distanceFrom(this->p2);
}

ostream& operator << (ostream& os, const Line2& l){
	os << "(" << l.p1 << " - " << l.p2 << ")";
	return os;
}