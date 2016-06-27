#include "vector.h"

#ifndef SRC_RAY_H_
#define SRC_RAY_H_

class Ray {
	Vector _origin;
	Vector _direction;
public:
	Ray(const Vector& origin, const Vector& direction);
	virtual ~Ray();

    inline Vector get_direction() {
		return _direction;
	}

    inline void set_direction(const Vector& direction) {
		_direction = direction;
	}

    inline Vector get_origin() {
		return _origin;
	}

    inline void set_origin(const Vector& origin) {
		_origin = origin;
	}

    inline Vector at(float t) {
		return _origin + _direction*t;
	}
};

#endif /* SRC_RAY_H_ */
