#include "face.h"

Face::Face(unsigned int a,unsigned int b,unsigned int c,unsigned int material_index) {
	_a=a;
	_b=b;
	_c=c;
	_m=material_index;
    _uva = 0;
    _uvb = 0;
    _uvc = 0;
}

Face::Face(unsigned int a,unsigned int b,unsigned int c,
            unsigned int uva, unsigned int uvb, unsigned int uvc,unsigned int material_index) {
    _a=a;
    _b=b;
    _c=c;
    _m=material_index;
    _uva = uva;
    _uvb = uvb;
    _uvc = uvc;
}

Face::~Face() {

}

