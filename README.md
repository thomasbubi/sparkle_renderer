Sparkle Render

just a simple raytracer, written for learning purposes

features:
* loads *.obj-files (by now, only very basic import)
* miauing when rendering finishes
* uses lodepng for reading textures, including transparency

under linux, compiles with:
g++ camera.cpp color.cpp face.cpp lamp.cpp material.cpp mesh.cpp ray.cpp scene.cpp vector.cpp shade.cpp trace.cpp load_obj.cpp uv.cpp lodepng.h texture.cpp main.cpp -std=c++0x

Licensed under the MIT-License
