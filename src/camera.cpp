#include "camera.h"

Camera::Camera(const Vector& position, const Vector& direction, float resolution_x, float resolution_y) {
	_position = position;
	_w = direction;
	_w.normalize();
	Vector up(0,0,1);
	_u = Vector::cross(_w,up);
	_u.normalize();
	_v = Vector::cross(_w,_u);
	_resolution_x = resolution_x;
	_resolution_y = resolution_y;
}

Camera::~Camera() {

}

const Ray Camera::create_view_ray(int i, int j) {

	float aspect_ratio = _resolution_x/_resolution_y;
	float l = -aspect_ratio;
	float r = aspect_ratio;
	int b=-1;
	int t=1;

    float u=l+(r-l)*(i+0.5)/_resolution_x;
    float v=b+(t-b)*(j+0.5)/_resolution_y;

    Vector ww = _w * 1;
    Vector uu = _u * u;
    Vector vv = _v * v;
    Vector view_ray_direction = uu + vv +ww;
    view_ray_direction.normalize();
    return Ray(_position,view_ray_direction);
}
