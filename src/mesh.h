#include <memory>
#include <utility>
#include <vector>
#include <iostream>

#include "face.h"
#include "ray.h"
#include "vector.h"
#include "uv.h"

#ifndef SRC_MESH_H_
#define SRC_MESH_H_

class Mesh {
	std::vector<Vector *> _vertices;

	std::vector<Face *> _faces;
	std::vector<Vector *> _vertex_normals;
	std::vector<Vector *> _face_normals;
    std::vector<UV*> _uvs;

	unsigned int _number_of_vertices;
	unsigned int _number_of_faces;
	std::string _name;
public:
	Mesh(unsigned int number_of_vertices, unsigned int number_of_faces);
	virtual ~Mesh();
    inline unsigned int get_number_of_vertices(){return _vertices.size();}
    inline unsigned int get_number_of_faces(){return _faces.size();}

    Vector* get_face_normal(unsigned int index){return _face_normals[index];}
	Vector* get_vertex_normal(unsigned int index){return _vertex_normals[index];}
    UV* get_uv(unsigned int index){return _uvs[index];}

    inline void add_vertex(Vector* vertex){
		_vertices.push_back(vertex);
	}

    inline void add_face(Face* face){
		_faces.push_back(face);
	}

    inline void add_uv(UV* uv){
        _uvs.push_back(uv);
    }

	void calculate_face_normals();
	void calculate_vertex_normals();
	float intersect( Ray& r,unsigned int index_of_face);
    inline Face* get_face(int i){
		return _faces[i];
	}

    inline const std::string& get_name() const {
		return _name;
	}

    inline void set_name(const std::string& name) {
		_name = name;
	}

    std::vector<float> calculate_baryzentric_coordinates(Vector point,
                                                     unsigned int index_of_face);
};

#endif /* SRC_MESH_H_ */
