#include <memory>
#include <utility>
#include <vector>
#include <iostream>

#include "face.h"
#include "ray.h"
#include "vector.h"

#ifndef SRC_MESH_H_
#define SRC_MESH_H_

class Mesh {
	std::vector<Vector *> _vertices;

	std::vector<Face *> _faces;
	std::vector<Vector *> _vertex_normals;
	std::vector<Vector *> _face_normals;

	unsigned int _number_of_vertices;
	unsigned int _number_of_faces;
	std::string _name;
public:
	Mesh(unsigned int number_of_vertices, unsigned int number_of_faces);
	virtual ~Mesh();
	unsigned int get_number_of_vertices(){return _vertices.size();}
	unsigned int get_number_of_faces(){return _faces.size();}
	Vector* get_face_normal(unsigned int index){return _face_normals[index];};
	Vector* get_vertex_normal(unsigned int index){return _vertex_normals[index];}
	void add_vertex(Vector* vertex){
		_vertices.push_back(vertex);
	}
	void add_face(Face* face){
		_faces.push_back(face);
	}
	void calculate_face_normals();
	void calculate_vertex_normals();
	float intersect( Ray& r,unsigned int index_of_face);
	Face* get_face(int i){
		return _faces[i];
	}

	const std::string& get_name() const {
		return _name;
	}

	void set_name(const std::string& name) {
		_name = name;
	}
};

#endif /* SRC_MESH_H_ */