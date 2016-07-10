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

    for(unsigned int i=0;i<_uvs.size();i++){
        delete _uvs[i];
    }
}

void Mesh::calculate_face_normals(){
    _face_normals.reserve(_faces.size());

    for(unsigned int i=0;i<_faces.size();i++){
		Face* tmp_face = _faces[i];
		unsigned int a = tmp_face->a();
		unsigned int b = tmp_face->b();
		unsigned int c = tmp_face->c();

        unsigned int number_of_vertices_in_vector = _vertices.size();

        if(a>= number_of_vertices_in_vector || b>= number_of_vertices_in_vector || c>= number_of_vertices_in_vector){
            //sanity check

            std::cerr << " The face #"<< i << "contains invalid indices. Face " << a << " " << b << " " << c << std::endl
                      << "Calculation of face normals aborted." << std::endl;
            std::cout << "#"<< number_of_vertices_in_vector << " a:"<<a<<" b:"<<b<<" c:"<<c<<std::endl;
            return;
        }
        Vector* va = _vertices[a];
        Vector* vb = _vertices[b];
        Vector* vc = _vertices[c];


        //std::cout << vb->x()<<vb->y()<<vb->z()<<"\n";// << " " <<va->y() << " " <<va->z() << " \n";
        //Vector n_tmp(0,0,0);
        Vector n_tmp = Vector::cross(*vb-*va,*vc-*va);

		Vector* n = new Vector(n_tmp.x(),n_tmp.y(),n_tmp.z());

		n->normalize();
		_face_normals.push_back(n);


	}

}

float Mesh::intersect( Ray& r, unsigned int index_of_face){

	float t= INFINITY;
	Face* tmp_face = _faces[index_of_face];
    unsigned int a = tmp_face->a();
    unsigned int b = tmp_face->b();
    unsigned int c = tmp_face->c();

    unsigned int number_of_vertices_in_vector = _vertices.size();

    if(a>= number_of_vertices_in_vector || b>= number_of_vertices_in_vector || c>= number_of_vertices_in_vector){
        //sanity check
        return INFINITY;
    }

    Vector* va = _vertices[a];
    Vector* vb = _vertices[b];
    Vector* vc = _vertices[c];
    //Vector* n = _face_normals[index_of_face];
    Vector n_tmp = Vector::cross(*vb-*va,*vc-*va);
    //std::cout << "reached," << _name << std::endl;
    Vector* n = new Vector(n_tmp.x(),n_tmp.y(),n_tmp.z());
    float va_dot_n_ori_dot_n = Vector::dot(*va,*n) - Vector::dot(r.get_origin(),*n);
    float dir_dot_n = Vector::dot(r.get_direction(),*n);

    t=va_dot_n_ori_dot_n / dir_dot_n;

    if(t<0.001){t=INFINITY;}

    if(t!=INFINITY){
        Vector point = r.at(t);
        std::vector<float> coords = calculate_baryzentric_coordinates(point,index_of_face);

        if(coords[0] <0 || coords[0] >1 || coords[1] <0 || coords[1]>1 || coords[2]>1 || coords[2] <0){
            t=INFINITY;
        }
    }

    delete n;

	return t;
}

std::vector<float> Mesh::calculate_baryzentric_coordinates(Vector point,
                                                 unsigned int index_of_face){
    Face* tmp_face = _faces[index_of_face];
    unsigned int f_a = tmp_face->a();
    unsigned int f_b = tmp_face->b();
    unsigned int f_c = tmp_face->c();

    Vector* va = _vertices[f_a];
    Vector* vb = _vertices[f_b];
    Vector* vc = _vertices[f_c];

    Vector n_not_normalized = Vector::cross(*vb-*va,*vc-*va);
    float area = n_not_normalized.abs2();

    Vector n_tmp = Vector::cross(*vb-*va,*vc-*va);
    //std::cout << "reached," << _name << std::endl;
    Vector* n = new Vector(n_tmp.x(),n_tmp.y(),n_tmp.z());

    Vector na = Vector::cross(*vc-*vb,point-*vb);
    Vector nb = Vector::cross(*va-*vc,point-*vc);
    Vector nc = Vector::cross(*vb-*va,point-*va);
    float alpha = Vector::dot(*n,na);
    alpha/=area;
    float beta = Vector::dot(*n,nb);
    beta/=area;
    float gamma = 1-beta-alpha;
    std::vector<float> v;
    v.reserve(3);
    v.push_back(alpha);
    v.push_back(beta);
    v.push_back(gamma);
    return v;
}

