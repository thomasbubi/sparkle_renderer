#include "face.h"

Face::Face(unsigned int a,unsigned int b,unsigned int c,unsigned int material_index) {
	_a=a;
	_b=b;
	_c=c;
	_m=material_index;
}

Face::~Face() {

}

