#include <cmath>

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
	float _x;
	float _y;
	float _z;
public:
	Vector();
	Vector(float x, float y, float z);
	virtual ~Vector();

    inline float x() const {
		return _x;
	}

    inline void set_x(float x) {
		_x = x;
	}

    inline float y() const {
		return _y;
	}

    inline void set_y(float y) {
		_y = y;
	}

    inline float z() const {
		return _z;
	}

    inline void set_z(float z) {
		_z = z;
	}

    inline Vector operator + (const Vector& rhs) {
		return Vector(this->_x+rhs._x,this->_y+rhs._y,this->_z+rhs._z);
	}

    void operator += (const Vector& rhs);

    inline Vector operator - (const Vector& rhs) {
		return Vector(this->_x-rhs._x,this->_y-rhs._y,this->_z-rhs._z);
	}

    void operator-= (const Vector& rhs);

    inline Vector operator* (const float& scalar){
		return Vector(this->_x*scalar,this->_y*scalar,this->_z*scalar);
	}

    void operator*= (const float& scalar);

    static Vector cross(const Vector& lhs, const Vector& rhs);

    inline static float dot(const Vector& lhs, const Vector& rhs) {
		return lhs._x*rhs._x + lhs._y*rhs._y + lhs._z*rhs._z;
	}

    inline float abs() {
		return sqrt(this->abs2());
	}

    inline float abs2() {
		return this->_x*this->_x + this->_y*this->_y + this->_z*this->_z;
	}

    void normalize();

};

#endif /* VECTOR_H_ */
