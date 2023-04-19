#include "../include/Circle2.h"
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;


Circle2::Circle2(Point2 np1, float nr){
    this->p1 = np1;
    this->r = (nr >= 0) ? nr : 0;
}


float Circle2::circumference(){
    return (this->r) * M_PI * 2; 
}


float Circle2::area(){
    return pow(this->r, 2) * M_PI;
}


bool Circle2::contains(Point2 p){
    return (this->p1).distanceFrom(p) <= this->r;
}


bool Circle2::contains(Line2 l){
    return ((this->p1).distanceFrom(l.p1) <= this->r) &&
            ((this->p1).distanceFrom(l.p2) <= this->r);
}


void Circle2::scale(float factor){
    if (factor < 0) return;
    (this->r) *= factor;
}


ostream& operator<< (ostream& os, const Circle2& c){
    return os << "(" << c.p1 << ", " << c.r << ")" << "\n";
}