#include "ray.h"

#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

class Camera {
protected:
	Vector _position;
	Vector _w;
	Vector _u;
	Vector _v;
	float _resolution_x;
	float _resolution_y;
public:
	Camera(const Vector& position, const Vector& direction, float resolution_x, float resolution_y);
	virtual ~Camera();
	const Ray create_view_ray(int i, int j);
	Vector& get_position(){return _position;}
	unsigned int get_render_resolution_x(){return _resolution_x;}
	unsigned int get_render_resolution_y(){return _resolution_y;}
};

#endif /* SRC_CAMERA_H_ */
