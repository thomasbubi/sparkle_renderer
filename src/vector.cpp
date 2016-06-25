#include "vector.h"

Vector::Vector() {
	_x=0.0f;
	_y=0.0f;
	_z=0.0f;
}

Vector::Vector(float x, float y, float z) {
	_x=x;
	_y=y;
	_z=z;
}

Vector::~Vector() {

}

void Vector::operator += (const Vector& rhs){
       this->_x+=rhs._x;
       this->_y+=rhs._y;
       this->_z+=rhs._z;
   }

void Vector::operator-= (const Vector& rhs) {
    this->_x-=rhs._x;
    this->_y-=rhs._y;
    this->_z-=rhs._z;
}

void Vector::operator*= (const float& scalar){
    this->_x*=scalar;
    this->_y*=scalar;
    this->_z*=scalar;
}

Vector Vector::cross(const Vector& lhs, const Vector& rhs) {
    return Vector(
            lhs._y*rhs._z - lhs._z*rhs._y,
            -(lhs._x*rhs._z)+lhs._z*rhs._x,
            lhs._x*rhs._y - lhs._y*rhs._x
    );
}

void Vector::normalize(){
    float abs = this->abs();
    _x/=abs;
    _y/=abs;
    _z/=abs;
}
