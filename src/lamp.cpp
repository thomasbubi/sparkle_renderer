#include "lamp.h"

Lamp::Lamp(Vector position, Vector direction, Color color, float length, float width, float intensity){
	_color = color;
    _direction = direction;
    _length = length;
    _width = width;
    _position=position;
	_intensity=intensity;
    _number_of_shadow_samples = 5;
    //setup an orthonormal basis
    _up = Vector(0,0,1);
    _w = Vector(direction.x(),direction.y(),direction.z());
    _w.normalize();
    if(_w.x() == 0.0f && _w.y() == 0.0f){
        _up = Vector(0,1,0);
    }
    _u = Vector::cross(_direction,_up);
    _u.normalize();
    _v = Vector::cross(_u,_w);
    _v.normalize();
    _u = _u * length;
    _v = _v * width;
}

Lamp::~Lamp() {}

Vector Lamp::get_sample_point(){
    //create u- and v-coordinate in the range between 0 and 1
    float rand_u = float(rand() % 1000) / 1000;
    float rand_v = float(rand() % 1000) / 1000;
    //
    rand_u -= 0.5;
    rand_v -= 0.5;

    Vector result = Vector();
    result = result + _position;
    result = result + (_u * rand_u);
    result = result + (_v * rand_v);

    return result;

}
