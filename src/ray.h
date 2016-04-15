#include "vector.h"

#ifndef SRC_RAY_H_
#define SRC_RAY_H_

class Ray {
	Vector _origin;
	Vector _direction;
public:
	Ray(const Vector& origin, const Vector& direction);
	virtual ~Ray();

	Vector get_direction() {
		return _direction;
	}

	void set_direction(const Vector& direction) {
		_direction = direction;
	}

	Vector get_origin() {
		return _origin;
	}

	void set_origin(const Vector& origin) {
		_origin = origin;
	}

	Vector at(float t) {
		return _origin + _direction*t;
	}
};

#endif /* SRC_RAY_H_ */
