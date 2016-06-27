#include "camera.h"
#include "material.h"
#include "mesh.h"
#include "lamp.h"
#ifndef SRC_SCENE_H_
#define SRC_SCENE_H_

class Scene {
	unsigned int _number_of_meshes;
	unsigned int _number_of_materials;
	Camera* _camera;
	std::vector<Mesh*> _meshes;
	std::vector<Material*> _materials;
	std::vector<Lamp*> _lamps;
	Color _background_color;
public:
	void set_camera(Camera* c){_camera=c;}
	void set_background_color(const Color& bgc){
		_background_color=bgc;
	}
	Color& get_background_color(){return _background_color;}
	Camera* get_camera(){return _camera;}
    inline void add_mesh(Mesh* m){
		_meshes.push_back(m);
		_number_of_meshes+=1;
	}

    inline unsigned int add_material(Material* mat){
		_materials.push_back(mat);
		_number_of_materials+=1;
		return _number_of_materials -1;
	}

    inline void add_lamp(Lamp* l){
		_lamps.push_back(l);
	}
    inline unsigned int get_number_of_meshes(){
		return _meshes.size();
	}
    inline unsigned int get_number_of_lamps(){
		return _lamps.size();
	}
    inline Mesh* get_mesh(int i){
		return _meshes[i];
	}

    inline Material* get_material(int i){
		return _materials[i];
	}

    inline Lamp* get_lamp(int i){
		return _lamps[i];
	}

	Scene();
	virtual ~Scene();
};

#endif /* SRC_SCENE_H_ */
