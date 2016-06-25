#include "texture.h"
#include <math.h>

Texture::Texture(std::string path){
    _path=path;
}

Texture::~Texture(){

}

void Texture::load_texture(){

    unsigned image = lodepng::decode(_data, _width, _height, _path);

}

Color Texture::get_texture_value_at(float u, float v){

    u = roundf(u*_width)/_width;
    v = roundf(v*_height)/_height;

    unsigned int number_of_color_channels = 4;
    unsigned int index = number_of_color_channels*(u*_width + _height*_width*(1-v));

    if(index>262140){
        return Color();
    } else {
        Color c = Color((int)_data[index],(int)_data[index+1],(int)_data[index+2]);
        c = c *(1.0f/255);
        return c;
    }
}
