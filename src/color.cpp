#include "color.h"

Color::Color() {
	_r=0.0f;
	_g=0.0f;
	_b=0.0f;
    _alpha=1.0f;
}

Color::Color(float r, float g, float b) {
    _r=r;
    _g=g;
    _b=b;
    _alpha=1.0f;
}


Color::Color(float r, float g, float b, float alpha) {
	_r=r;
	_g=g;
	_b=b;
    _alpha=alpha;
}

Color::~Color() {

}

void Color::clamp(){
    if(_r>1){_r=1;}
    if(_g>1){_g=1;}
    if(_b>1){_b=1;}
    if(_r<0){_r=0;}
    if(_g<0){_g=0;}
    if(_b<0){_b=0;}
    if(_alpha>1){_alpha=1;}
    if(_alpha<0){_alpha=0;}
}

void Color::operator+=(Color rhs){
    this->_b+=rhs._b;
    this->_r+=rhs._r;
    this->_g+=rhs._g;
    this->_alpha+=rhs._alpha;
}

void Color::operator-=(Color rhs){
    this->_b-=rhs._b;
    this->_r-=rhs._r;
    this->_g-=rhs._g;
    this->_alpha-=rhs._alpha;
}

void Color::operator*=(Color rhs){
    this->_b*=rhs._b;
    this->_r*=rhs._r;
    this->_g*=rhs._g;
    this->_alpha*=rhs._alpha;
}

void Color::operator*=(float scalar){
    this->_b*=scalar;
    this->_r*=scalar;
    this->_g*=scalar;
    this->_alpha*=scalar;
}
