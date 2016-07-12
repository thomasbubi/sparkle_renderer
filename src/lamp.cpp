#include "lamp.h"

Lamp::Lamp(Vector position, Color color,float intensity) {
	_color = color;
	_position=position;
	_intensity=intensity;
    _number_of_shadow_samples = 5;
}

Lamp::~Lamp() {
	// TODO Auto-generated destructor stub
}

