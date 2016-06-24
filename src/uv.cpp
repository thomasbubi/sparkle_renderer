#include "uv.h"

UV::UV(float u, float v){
    _u=u;
    _v=v;
}

UV::~UV(){}

void UV::set_u(float u){
    _u=u;
}

void UV::set_v(float v){
   _v=v;
}
