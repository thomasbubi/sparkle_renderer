#include "trace_shade.h"
#include "load_obj.h"

void render(Scene& scn){

	std::ofstream image_file;
	image_file.open("image.ppm");

	Camera* cam = scn.get_camera();
	unsigned int width = cam->get_render_resolution_x();
	unsigned int height = cam->get_render_resolution_y();

	//header for ppm writing
	image_file << "P3\n" << width <<" " << height << "\n 255 \n";

    for(unsigned int j=0;j<height;j++){
        for(unsigned int i=0;i<width;i++){
			Ray ray =cam->create_view_ray(i,j);
            Color c = trace(ray,scn,i,j);
			image_file << int(c.r()*255) << " " << int(c.g()*255)
					<< " " << int(c.b()*255) << "\n";
        }
    }

	image_file.close();
}

int main()
{
	int width = 640;
	int height = 480;

    Camera* cam = new Camera(Vector(0,-1.5,0.2),Vector(0,1,0),width,height);
	Scene scn = Scene();
	scn.set_camera(cam);

    Mesh* cornell_box = new Mesh(8,10);

	cornell_box->add_vertex(new Vector(-1,-1,-1));
	cornell_box->add_vertex(new Vector(-1,-1,1));
	cornell_box->add_vertex(new Vector(-1,1,-1));
	cornell_box->add_vertex(new Vector(-1,1,1));
	cornell_box->add_vertex(new Vector(1,1,-1));
	cornell_box->add_vertex(new Vector(1,1,1));
	cornell_box->add_vertex(new Vector(1,-1,-1));
	cornell_box->add_vertex(new Vector(1,-1,1));

    cornell_box->add_face(new Face(0, 1, 2, 0, 1, 2, 0));
    cornell_box->add_face(new Face(1, 2, 3, 1, 2, 3, 0));
    cornell_box->add_face(new Face(2, 3, 4, 2, 3, 4, 1));
    cornell_box->add_face(new Face(3, 4, 5, 3, 4, 5, 1));
    cornell_box->add_face(new Face(0, 2, 6, 0, 2, 6, 1));
    cornell_box->add_face(new Face(2, 4, 6, 2, 4, 6, 1));
    cornell_box->add_face(new Face(1, 3, 7, 1, 3, 7, 1));
    cornell_box->add_face(new Face(3, 5, 7, 3, 5, 7, 1));
    cornell_box->add_face(new Face(4, 5, 6, 4, 5, 6, 2));
    cornell_box->add_face(new Face(5, 6, 7, 5, 6, 7, 2));

    cornell_box->add_uv(new UV(0,0));
    cornell_box->add_uv(new UV(0,0));
    cornell_box->add_uv(new UV(0,1));
    cornell_box->add_uv(new UV(0,0));
    cornell_box->add_uv(new UV(1,1));
    cornell_box->add_uv(new UV(1,0));
    cornell_box->add_uv(new UV(1,0));
    cornell_box->add_uv(new UV(0,0));

	cornell_box->calculate_face_normals();

    Texture* tex = new Texture("texture.png");
    tex->load_texture();

    DiffuseMaterial* textured_material = new DiffuseMaterial(Color(1,1,1));
    textured_material->add_texture(tex);

    scn.add_material(new DiffuseMaterial(Color(1,0,0)));
    scn.add_material(textured_material);
    scn.add_material(new DiffuseMaterial(Color(0,1,0)));

    scn.add_mesh(cornell_box);

    scn.add_lamp(new Lamp(Vector(0.8,0.8,0.8),Color(0.5,0.5,0.5),1));
    scn.add_material(new DiffuseMaterial(Color(1,1,1)));
    load_obj(&scn,"untitled42.obj");

    render(scn);

	std::cout << "😻  \"miau\" 😻" << std::endl;

}
