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

GlassMaterial::GlassMaterial(const Color& color, float ior){
    _color = color;
    _ior = ior;
    _type = 2;
}

GlassMaterial::~GlassMaterial(){}

GlossyMaterial::GlossyMaterial(const Color &color, float roughness){
    _color = color;
    _roughness = roughness;
    _type = 3;
}

GlossyMaterial::~GlossyMaterial(){}

MixMaterial::MixMaterial(Material *m1, Material *m2, float blend){
    _mat_1=m1;
    _mat_2=m2;
    _blend_value=blend;
    _type = 4;
}

MixMaterial::~MixMaterial(){
    delete _mat_1;
    delete _mat_2;
}

Material* MixMaterial::get_material_1(){
    return _mat_1;
}

Material* MixMaterial::get_material_2(){
    return _mat_2;
}

float MixMaterial::get_blend_value(){
    return _blend_value;
}
