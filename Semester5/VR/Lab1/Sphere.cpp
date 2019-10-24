#include "Sphere.h"
#include <cmath>
using namespace rt;

Intersection Sphere::getIntersection(const Line& line, float minDist, float maxDist) {
	Intersection in;
	Vector oc = line.x0() - this->center();
	double a = line.dx() * line.dx();
	double b = (oc * line.dx()) * 2.0;
	double c = oc * oc - this->radius() * this->radius();

	double delta = b*b - 4 * a*c;
	double num = -b - std::sqrt(delta);
	double num1 = -b + std::sqrt(delta);
	double t = -1.0;
	if(delta < 0){
        return {};
	}
	if(num > 0.0){
	    t = num / (2.0 * a);
	}
	else if(num1 > 0.0){
	    t = num1 / (2.0 * a);
	}
	if(t == -1.0){
	    return {};
	}
	Vector lineVal = line.vec(t);
	auto dist = (lineVal - line.x0()) * (lineVal - line.x0());
	if(!(dist >= minDist*minDist && dist <= maxDist*maxDist)){
	    return {};
	}
	in = Intersection(true, this, &line, t);
	return in;
}


const Vector Sphere::normal(const Vector& vec) const {
    Vector n = vec - _center;
    n.normalize();
    return n;
}
