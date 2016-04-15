#ifndef SRC_LAMP_H_
#define SRC_LAMP_H_

#include "vector.h"
#include "color.h"

class Lamp {
	Vector _position;
	Color _color;
	float _intensity;
public:
	Lamp(Vector position, Color color,float intensity);
	virtual ~Lamp();

	const Color& get_color() const {
		return _color;
	}

	float get_intensity() const {
		return _intensity;
	}

	const Vector& get_position() const {
		return _position;
	}
};

#endif /* SRC_LAMP_H_ */
