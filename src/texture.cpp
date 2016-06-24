#include "texture.h"

Texture::Texture(std::string path){
    _path=path;
}

Texture::~Texture(){}

void Texture::load_texture(){
    unsigned error = lodepng::decode(_data, _width, _height, _path);
    //if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

Color Texture::get_texture_value_at(float u, float v){

}
