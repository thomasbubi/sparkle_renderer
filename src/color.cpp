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

