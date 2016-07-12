#include "color.h"
#include "texture.h"

#ifndef SRC_MATERIAL_H_
#define SRC_MATERIAL_H_

class Material {
protected:
    Color _color;
    float _roughness;
    int _type;//1-> diffuse; 2-> glass; 3-> glossy; 4-> Mix
    std::string _name;
public:
    virtual ~Material(){}

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

    inline std::string get_name(){
        return _name;
    }

    inline void set_string(std::string s){
        _name = s;
    }
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

class GlassMaterial : public Material {
    float _ior;
public:
    GlassMaterial(const Color& color, float ior);
    virtual ~GlassMaterial();

    inline float get_ior(){
        return _ior;
    }

    inline void set_ior(float ior){
        _ior = ior;
    }
};

class GlossyMaterial : public Material {
public:
    GlossyMaterial(const Color& color, float roughness);
    virtual ~GlossyMaterial();
};

class MixMaterial : public Material {
    //use smart pointer
    Material* _mat_1;
    Material* _mat_2;
    float _blend_value;
public:
    MixMaterial(Material* m1, Material* m2, float blend);
    virtual ~MixMaterial();
    Material* get_material_1();
    Material* get_material_2();
};

#endif /* SRC_MATERIAL_H_ */
