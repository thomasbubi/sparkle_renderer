#include "lodepng.h"
#include "color.h"

#ifndef TEXTURE_H
#define TEXTURE_H


class Texture
{
    unsigned int _width;
    unsigned int _height;
    std::vector<unsigned char> _data;
    std::string _path;
public:
    Texture(std::string path);
    virtual ~Texture();
    void load_texture();
    unsigned int get_width(){return _width;}
    unsigned int get_height(){return _height;}
    Color get_texture_value_at(float u, float v);
};

#endif // TEXTURE_H
