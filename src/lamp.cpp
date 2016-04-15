#include "lamp.h"

Lamp::Lamp(Vector position, Color color,float intensity) {
	_color = color;
	_position=position;
	_intensity=intensity;

}

Lamp::~Lamp() {
	// TODO Auto-generated destructor stub
}

