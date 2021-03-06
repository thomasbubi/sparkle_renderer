#include "load_obj.h"

int detect_obj_format(const char* line){
	int face_format;
	int number_of_slashes=0;
	int double_slash = false;

    for(unsigned int i=1;i<std::strlen(line)-1;i++){
		if(line[i]=='/'){
			number_of_slashes++;
            if(line[i+1]=='/'){
				double_slash=true;
			}
		}
	}

	if(number_of_slashes == 6 && double_slash){
		face_format = 1;
	} else if(number_of_slashes == 6 && !double_slash){
		face_format = 2;
	} else if(number_of_slashes == 3){
		face_format = 3;
	} else {
		face_format = 0;
	}

	return face_format;
}

void load_obj(Scene* scene, std::string path){
	std::ifstream file(path);
	if(!file.is_open()){
        std::cerr << "error loading file " + path << std::endl;
		return;
	}

	bool format_detected = false;
	int face_format = -1;//-1: not detected yet, 0: v, 1: v//vn, 2:v/vt/vn 3: v/vt

    int number_of_lines = 0;
    int difference = 0;

	std::string line_content_string;
	Mesh* m;
    std::vector<Mesh*> mesh_pointers;
	while(std::getline(file,line_content_string)){
		const char* lc =line_content_string.c_str();

		if(!format_detected && lc[0]=='f') {
			format_detected=true;
			face_format = detect_obj_format(lc);

		}

		if(lc[0]=='o'){//new object in obj file, new mesh is created

			m = new Mesh(3,1);
			scene->add_mesh(m);

            size_t num_char = line_content_string.size();
            if(num_char<3){num_char=3;}
            char* mesh_name_cstr = new char[line_content_string.size() - 2];
            sscanf(lc, "%*s %s",mesh_name_cstr);
            m->set_name(std::string(mesh_name_cstr));

            mesh_pointers.push_back(m);
            format_detected=false;
            difference = number_of_lines;
            continue;
		//read vertex data
		} else if(lc[0]=='v' && lc[1]==' '){
			float x,y,z;
			sscanf(lc,"%*s %f %f %f",&x,&z,&y);//z-axis shows upwards
			if(m!=nullptr){
				m->add_vertex(new Vector(x,y,z));
			}
            number_of_lines++;
		} else if(lc[0]=='f'){
			//face_format= -1: not detected yet, 0: v, 1: v//vn, 2:v/vt/vn 3: v/vt
            int va=0;
            int vb=0;
            int vc=0;

            int vta=0;int vtb=0;int vtc=0;
            int vna=0;int vnb=0;int vnc=0;

			if(face_format==0){
				sscanf(lc,"%*s %i %i %i",&va,&vb,&vc);
			} else if(face_format==1){
				sscanf(lc,"%*s %i//%i %i//%i %i//%i",&va,&vna,&vb,&vnb,&vc,&vnc);
			} else if(face_format==2){
				sscanf(lc,"%*s %i/%i/%i %i/%i/%i %i/%i/%i",&va,&vta,&vna,&vb,&vtb,&vnb,&vc,&vtc,&vnc);
			} else {
				sscanf(lc,"%*s %i/%i %i/%i %i/%i",&va,&vta,&vb,&vtb,&vc,&vtc);
			}

            if(difference>0){
                va -= difference; vb-= difference; vc -= difference;
            }

            va--;  vb--;  vc--;//indices in obj start with 1, in here, it starts with 0

            if(vta!=0 || vtb!=0 || vtc!=0){
                vta--; vtb--; vtc--;
            }

			if(m!=nullptr){
                if(vta!=0 || vtb!=0 || vtc!=0){
                    m->add_face(new Face(va,vb,vc,vta,vtb,vtc,0));
                } else {
                    m->add_face(new Face(va,vb,vc,0,0,0,0));
                }

			}
        }
    }

    for(size_t i =0;i<mesh_pointers.size();i++){
        Mesh* tmp_mesh = mesh_pointers[i];
        tmp_mesh->calculate_face_normals();
    }
}
