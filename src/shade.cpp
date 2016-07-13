#include "trace_shade.h"

Color shade(Scene& scene,Vector& surface_point, Vector* n,
            unsigned int mesh_index, unsigned int face_index,int x, int y){

    unsigned int material_index = scene.get_mesh(mesh_index)->get_face(face_index)->material_index();
    Material* material = scene.get_material(material_index);
    Mesh* mesh = scene.get_mesh(mesh_index);
    Face* face = scene.get_mesh(mesh_index)->get_face(face_index);

    int material_type = material->get_type();
    //1-> diffuse; 2-> glass; 3-> glossy; 4-> Mix

    Color pixel_color = Color(0,0,0);

    if(material_type == 1){//diffuse
        DiffuseMaterial* diff = dynamic_cast<DiffuseMaterial*>(material);
        Color diffuse = diff->get_color();
        //texture overwrites the color and transparency of the material
        if(diff->has_texture()){

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

            diffuse = diff->get_texture_color_at(u,v,x,y);

        }

        Vector cam_pos = scene.get_camera()->get_position();
        Vector v = surface_point-cam_pos;

        for(int i=0;i<scene.get_number_of_lamps();i++){
            Lamp* lamp_i = scene.get_lamp(i);
            int times_in_shadow = 0;

            for(int j=0;j<lamp_i->get_number_of_shadow_samples();j++){


            }

            Vector lamp_position = lamp_i->get_position();
            Vector l = lamp_position - surface_point;
            l.normalize();
            Vector h = v+l;
            h.normalize();
            float n_dot_l = std::fabs(Vector::dot(*n,l));
            float n_dot_h = std::fabs(Vector::dot(*n,h));

            float shadow_value = 1 - (times_in_shadow / lamp_i->get_number_of_shadow_samples());
            pixel_color += diffuse  * lamp_i->get_intensity() * n_dot_l * shadow_value;//diffuse
            pixel_color += diffuse * lamp_i->get_intensity() * std::pow(n_dot_h,100) * shadow_value; //specular
        }

        pixel_color.clamp();

    }

    return pixel_color;
}
