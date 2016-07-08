#include "material.h"
#include <iostream>

DiffuseMaterial::DiffuseMaterial(const Color& color) {
    _color = color;
    _has_texture = false;
    _type = 1;
}

DiffuseMaterial::~DiffuseMaterial() {
        //delete _tex;//TODO rework memory management
}

Color DiffuseMaterial::get_texture_color_at(float u, float v,int x,int y){
    if(_has_texture){
        return _tex->get_texture_value_at(u,v);
    } else {
        return _color;
    }
}
