Sparkle Render

just a simple raytracer, written for learning purposes

features:
* loads *.obj-files (by now, only very basic import)
* uses lodepng for reading textures, including transparency
* miauing when rendering finishes

under linux, compiles with:
src/camera.cpp src/color.cpp src/face.cpp src/lamp.cpp src/material.cpp src/mesh.cpp src/ray.cpp src/scene.cpp src/vector.cpp src/shade.cpp src/trace.cpp src/load_obj.cpp src/uv.cpp src/lodepng.cpp src/texture.cpp src/main.cpp -std=c++0x -g

Licensed under the MIT-License

features in planning
* camera with adjustable focal length
* Reflection & Refraction
* decent import for obj-files
* Path Tracing
* Phong Shading
* bvh
