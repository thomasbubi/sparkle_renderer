#include "trace_shade.h"

Color shade(Scene& scene, Material* mat,Vector& surface_point, Vector* n){
	Color diffuse = mat->get_diffuse_color();
	Color ambient = mat->get_ambient_color();
	Color specular = mat->get_specular_color();

	Color tmp = Color(0,0,0);

	tmp+=ambient*0.1;

	Vector cam_pos = scene.get_camera()->get_position();
	Vector v = surface_point-cam_pos;

	for(int i=0;i<scene.get_number_of_lamps();i++){
		Lamp* lamp_i = scene.get_lamp(i);
		//std::cout << surface_point.x() <<" "<<surface_point.y()<<" "<<surface_point.z() << std::endl;
		Vector lamp_position = lamp_i->get_position();
		Vector l = lamp_position - surface_point;
		l.normalize();
		Vector h = v+l;
		h.normalize();
		float n_dot_l = std::fabs(Vector::dot(*n,l));
		float n_dot_h = std::fabs(Vector::dot(*n,h));

		tmp += diffuse * lamp_i->get_intensity() * n_dot_l;//diffuse
		tmp += specular * lamp_i->get_intensity() * std::pow(n_dot_h,mat->get_exponent());
	}

	tmp.clamp();
	return tmp;
}
