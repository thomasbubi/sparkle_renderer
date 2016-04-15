#include "material.h"

Material::Material(const Color& diffuse_color) {
	_diffuse = diffuse_color;
	_specular = diffuse_color;
	_ambient = diffuse_color;
	_exponent = 100;
}

Material::~Material() {

}
