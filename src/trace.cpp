#include "trace_shade.h"

Color trace(Ray& ray, Scene& scn,int x,int y){
	float t=INFINITY;
	int meshnum = -1;
	int facenum = -1;

	int number_of_meshes = scn.get_number_of_meshes();
	//for every mesh
	for(int index_mesh = 0;index_mesh<number_of_meshes;index_mesh++){
		Mesh* m = scn.get_mesh(index_mesh);
		//for every triangle
		unsigned int number_of_faces = m->get_number_of_faces();
        for(unsigned int index_face=0; index_face < number_of_faces; index_face++){
			float t_tmp = m->intersect(ray,index_face);

			if(t_tmp<t){
				meshnum=index_mesh;
				facenum=index_face;
				t=t_tmp;
			}
		}
	}

	Color c;
	if(meshnum <0 || facenum <0){//ray doesn't hit any object
		c=scn.get_background_color();
	} else {

		unsigned int material_index = scn.get_mesh(meshnum)->get_face(facenum)->material_index();
		Material* mat_ptr = scn.get_material(material_index);
		Vector* n=scn.get_mesh(meshnum)->get_face_normal(facenum);
		Vector surface_point = ray.at(t);
		c = shade(scn,mat_ptr,surface_point,n);
	}
	return c;
}
