#include "material.h"
#include <iostream>

Material::Material(const Color& diffuse_color) {
	_diffuse = diffuse_color;
	_specular = diffuse_color;
	_ambient = diffuse_color;
	_exponent = 100;
    _has_texture = false;
}

Material::~Material() {
        //delete _tex;//TODO rework memory management
}

Color Material::get_texture_color_at(float u, float v,int x,int y){
    return _tex->get_texture_value_at(u,v);
}
