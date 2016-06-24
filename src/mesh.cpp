#include "mesh.h"

#include <iostream>

Mesh::Mesh(unsigned int number_of_vertices, unsigned int number_of_faces) {
	_number_of_vertices = number_of_vertices;
	_number_of_faces = number_of_faces;
	_vertices.reserve(_number_of_vertices);
	_faces.reserve(_number_of_faces);
	_name = "";
}

Mesh::~Mesh() {
    for(unsigned int i=0;i<_vertices.size();i++){
		delete _vertices[i];
	}

    for(unsigned int i=0;i<_faces.size();i++){
		delete _faces[i];
	}

    for(unsigned int i=0;i<_vertex_normals.size();i++){
		delete _vertex_normals[i];
	}

    for(unsigned int i=0;i<_face_normals.size();i++){
		delete _face_normals[i];
	}
}

void Mesh::calculate_face_normals(){
	_face_normals.reserve(_faces.size());
    for(unsigned int i=0;i<_faces.size();i++){
		Face* tmp_face = _faces[i];
		unsigned int a = tmp_face->a();
		unsigned int b = tmp_face->b();
		unsigned int c = tmp_face->c();

		Vector* va = _vertices[a];
		Vector* vb = _vertices[b];
		Vector* vc = _vertices[c];

		Vector n_tmp = Vector::cross(*vb-*va,*vc-*va);

		Vector* n = new Vector(n_tmp.x(),n_tmp.y(),n_tmp.z());
		n->normalize();
		_face_normals.push_back(n);
	}

}

float Mesh::intersect( Ray& r, unsigned int index_of_face){

	float t= INFINITY;
	Face* tmp_face = _faces[index_of_face];
	unsigned int f_a = tmp_face->a();
	unsigned int f_b = tmp_face->b();
	unsigned int f_c = tmp_face->c();

	Vector* va = _vertices[f_a];
	Vector* vb = _vertices[f_b];
	Vector* vc = _vertices[f_c];
	//Vector* n = _face_normals[index_of_face];
	Vector n_tmp = Vector::cross(*vb-*va,*vc-*va);
	//std::cout << "reached," << _name << std::endl;
	Vector* n = new Vector(n_tmp.x(),n_tmp.y(),n_tmp.z());
	float va_dot_n_ori_dot_n = Vector::dot(*va,*n) - Vector::dot(r.get_origin(),*n);
	float dir_dot_n = Vector::dot(r.get_direction(),*n);

	t=va_dot_n_ori_dot_n / dir_dot_n;

	if(t<0.001){t=INFINITY;}

	if(t!=INFINITY){
		Vector n_not_normalized = Vector::cross(*vb-*va,*vc-*va);
		float area = n_not_normalized.abs2();
		Vector point = r.at(t);
		Vector na = Vector::cross(*vc-*vb,point-*vb);
		Vector nb = Vector::cross(*va-*vc,point-*vc);
		Vector nc = Vector::cross(*vb-*va,point-*va);
		float alpha = Vector::dot(*n,na);
		alpha/=area;
		float beta = Vector::dot(*n,nb);
		beta/=area;
		float gamma = 1-beta-alpha;

		if(alpha<0 || alpha >1 || beta <0 || beta>1 || gamma>1 || gamma <0){
		        t=INFINITY;
		    }
	}

	delete n;

	return t;
}
