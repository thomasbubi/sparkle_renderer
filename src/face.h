#ifndef SRC_FACE_H_
#define SRC_FACE_H_

class Face {
	unsigned int _a;
	unsigned int _b;
	unsigned int _c;
	unsigned int _m;
public:
	Face(unsigned int a,unsigned int b,unsigned int c, unsigned int material_index);
	virtual ~Face();

	unsigned int a() const {
		return _a;
	}

	unsigned int b() const {
		return _b;
	}

	unsigned int c() const {
		return _c;
	}
	unsigned int material_index() const {
		return _m;
	}
};

#endif /* SRC_FACE_H_ */
