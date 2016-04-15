#include "scene.h"
#include <iostream>

#ifndef TRACE_SHADE_H_
#define TRACE_SHADE_H_


Color trace(Ray& ray, Scene& scn,int x,int y);
Color shade(Scene& scene, Material* mat,Vector& surface_point, Vector* n);

#endif
