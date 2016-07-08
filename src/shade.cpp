#include "trace_shade.h"

Color shade(Scene& scene,Vector& surface_point, Vector* n,
            unsigned int mesh_index, unsigned int face_index,int x, int y){

    unsigned int material_index = scene.get_mesh(mesh_index)->get_face(face_index)->material_index();
    Material* material = scene.get_material(material_index);
    Mesh* mesh = scene.get_mesh(mesh_index);
    Face* face = scene.get_mesh(mesh_index)->get_face(face_index);

    Color diffuse = material->get_diffuse_color();

    //texture overwrites the color and transparency of the material
    if(material->has_texture()){

        std::vector<float>baryzentric_coords = mesh->calculate_baryzentric_coordinates(surface_point,face_index);

        float alpha = baryzentric_coords[0];
        float beta = baryzentric_coords[1];
        float gamma = baryzentric_coords[2];

        unsigned int face_index_a = face->a();
        unsigned int face_index_b = face->b();
        unsigned int face_index_c = face->c();

        unsigned int uv_index_a = face->uva();
        unsigned int uv_index_b = face->uvb();
        unsigned int uv_index_c = face->uvc();


        float u = alpha*mesh->get_uv(uv_index_a)->u()+
                beta*mesh->get_uv(uv_index_b)->u()+
                gamma*mesh->get_uv(uv_index_c)->u();

        float v = alpha*mesh->get_uv(uv_index_a)->v()+
                beta*mesh->get_uv(uv_index_b)->v()+
                gamma*mesh->get_uv(uv_index_c)->v();

        diffuse = material->get_texture_color_at(u,v,x,y);

    }
    Color ambient = material->get_ambient_color();
    Color specular = material->get_specular_color();

    Color pixel_color = Color(0,0,0,1);

    pixel_color+=ambient*0.1;

	Vector cam_pos = scene.get_camera()->get_position();
	Vector v = surface_point-cam_pos;

	for(int i=0;i<scene.get_number_of_lamps();i++){
		Lamp* lamp_i = scene.get_lamp(i);
		Vector lamp_position = lamp_i->get_position();
		Vector l = lamp_position - surface_point;
		l.normalize();
		Vector h = v+l;
		h.normalize();
		float n_dot_l = std::fabs(Vector::dot(*n,l));
		float n_dot_h = std::fabs(Vector::dot(*n,h));

        pixel_color += diffuse  * lamp_i->get_intensity() * n_dot_l;//diffuse
        pixel_color += specular * lamp_i->get_intensity() * std::pow(n_dot_h,material->get_exponent());
	}

    pixel_color.clamp();
    return pixel_color;
}
