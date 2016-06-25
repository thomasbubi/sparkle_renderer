#include "scene.h"
#include <iostream>

#ifndef TRACE_SHADE_H_
#define TRACE_SHADE_H_

Color trace(Ray& ray, Scene& scn,int x, int y);
Color shade(Scene& scene,Vector& surface_point, Vector* n,
            unsigned int mesh_index, unsigned int face_index,int x, int y);

#endif
