#ifndef SRC_LAMP_H_
#define SRC_LAMP_H_

#include "vector.h"
#include "color.h"
#include <cstdlib>

class Lamp {
	Vector _position;
	Color _color;
	float _intensity;
    unsigned int _number_of_shadow_samples;
    Vector _direction;
    float _length;
    float _width;
    Vector _up;
    Vector _w;
    Vector _u;
    Vector _v;

public:
    Lamp(Vector position, Vector direction, Color color, float lenght, float width, float intensity);
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

    Vector get_sample_point();

    inline unsigned int get_number_of_shadow_samples(){
        return _number_of_shadow_samples;
    }
};

#endif /* SRC_LAMP_H_ */
