#include "ray.h"

Ray::Ray(const Vector& origin, const Vector& direction) {
	_origin = origin;
	_direction = direction;
}

Ray::~Ray() {
	// TODO Auto-generated destructor stub
}

