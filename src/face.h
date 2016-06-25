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

    inline unsigned int a() const {
		return _a;
	}

    inline unsigned int b() const {
		return _b;
	}

    inline unsigned int c() const {
		return _c;
	}
    inline unsigned int material_index() const {
		return _m;
	}
};

#endif /* SRC_FACE_H_ */
