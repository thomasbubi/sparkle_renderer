#ifndef SRC_LAMP_H_
#define SRC_LAMP_H_

#include "vector.h"
#include "color.h"

class Lamp {
	Vector _position;
	Color _color;
	float _intensity;
    unsigned int _number_of_shadow_samples;

public:
	Lamp(Vector position, Color color,float intensity);
	virtual ~Lamp();

    inline const Color& get_color() const {
		return _color;
	}

    inline float get_intensity() const {
		return _intensity;
	}

    inline const Vector& get_position() const {
		return _position;
	}
};

#endif /* SRC_LAMP_H_ */
