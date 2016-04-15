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

	float x() const {
		return _x;
	}

	void set_x(float x) {
		_x = x;
	}

	float y() const {
		return _y;
	}

	void set_y(float y) {
		_y = y;
	}

	float z() const {
		return _z;
	}

	void set_z(float z) {
		_z = z;
	}

	Vector operator + (const Vector& rhs) {
		return Vector(this->_x+rhs._x,this->_y+rhs._y,this->_z+rhs._z);
	}

	void operator += (const Vector& rhs) {
		this->_x+=rhs._x;
		this->_y+=rhs._y;
		this->_z+=rhs._z;
	}

	Vector operator - (const Vector& rhs) {
		return Vector(this->_x-rhs._x,this->_y-rhs._y,this->_z-rhs._z);
	}

	void operator-= (const Vector& rhs) {
		this->_x-=rhs._x;
		this->_y-=rhs._y;
		this->_z-=rhs._z;
	}

	Vector operator* (const float& scalar){
		return Vector(this->_x*scalar,this->_y*scalar,this->_z*scalar);
	}

	void operator*= (const float& scalar){
		this->_x*=scalar;
		this->_y*=scalar;
		this->_z*=scalar;
	}

	static Vector cross(const Vector& lhs, const Vector& rhs) {
		return Vector(
				lhs._y*rhs._z - lhs._z*rhs._y,
				-(lhs._x*rhs._z)+lhs._z*rhs._x,
				lhs._x*rhs._y - lhs._y*rhs._x
		);
	}
	static float dot(const Vector& lhs, const Vector& rhs) {
		return lhs._x*rhs._x + lhs._y*rhs._y + lhs._z*rhs._z;
	}

	float abs() {
		return sqrt(this->abs2());
	}

	float abs2() {
		return this->_x*this->_x + this->_y*this->_y + this->_z*this->_z;
	}

	void normalize(){
		float abs = this->abs();
		_x/=abs;
		_y/=abs;
		_z/=abs;
	}

};

#endif /* VECTOR_H_ */
