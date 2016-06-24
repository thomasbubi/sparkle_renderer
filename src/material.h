#include "color.h"
#include "texture.h"

#ifndef SRC_MATERIAL_H_
#define SRC_MATERIAL_H_

class Material {
	Color _diffuse;
	Color _specular;
	Color _ambient;
	unsigned int _exponent;
	bool _has_texture;
	Texture* _tex;
public:
	Material(const Color& diffuse_color);
	virtual ~Material();
	//virtual Color& shade()=0;

	const Color& get_ambient_color() const {
		return _ambient;
	}

	const Color& get_diffuse_color() const {
		return _diffuse;
	}

	const Color& get_specular_color() const {
		return _specular;
	}

	const float get_exponent(){
		return _exponent;
	}

	void set_ambient_color(const Color& ambient) {
		_ambient = ambient;
	}

	void set_diffuse_color(const Color& diffuse) {
		_diffuse = diffuse;
	}

	void set_specular_color(const Color& specular) {
		_specular = specular;
	}
	bool has_texture() {
	    return _has_texture;
	}

    void add_texture(Texture* tex){
        _tex=tex;
        _has_texture=true;
    }

    Color get_texture_color_at(float u, float v);


};

#endif /* SRC_MATERIAL_H_ */
