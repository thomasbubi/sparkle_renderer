#include "color.h"
#include "texture.h"

#ifndef SRC_MATERIAL_H_
#define SRC_MATERIAL_H_

class Material {
protected:
    Color _color;
    float _roughness;
    int _type;//1-> diffuse; 2-> glass; 3-> glossy; 4-> Mix
public:
    inline const Color& get_color() const {
        return _color;
    }

    inline void set_color(const Color& c) {
        _color = c;
    }

    inline const float get_roughness(){
        return _roughness;
    }

    inline void set_roughness(float r){
        _roughness = r;
    }

    inline int get_type(){return _type;}
};

class DiffuseMaterial : public Material {
    bool _has_texture;
    Texture* _tex;
public:
    DiffuseMaterial(const Color& color);
    virtual ~DiffuseMaterial();

    inline bool has_texture() {
	    return _has_texture;
	}

    inline void add_texture(Texture* tex){
        _tex=tex;
        _has_texture=true;
    }

    Color get_texture_color_at(float u, float v,int x,int y);
};

#endif /* SRC_MATERIAL_H_ */
