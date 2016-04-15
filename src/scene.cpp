#include "scene.h"

Scene::Scene() {
	_camera = nullptr;
	_number_of_meshes=0;
	_number_of_materials=0;
	_background_color = Color(0.1,0.1,0.1);
}

Scene::~Scene() {
	delete _camera;
	for(int i=0;i<_meshes.size();i++){
		delete _meshes[i];
	}
	for(int i=0;i<_materials.size();i++){
			delete _materials[i];
		}
}
