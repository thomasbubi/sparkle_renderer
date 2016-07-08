#ifndef SRC_FACE_H_
#define SRC_FACE_H_

class Face {
	unsigned int _a;
	unsigned int _b;
	unsigned int _c;
	unsigned int _m;
    unsigned int _uva;
    unsigned int _uvb;
    unsigned int _uvc;
public:
	Face(unsigned int a,unsigned int b,unsigned int c, unsigned int material_index);
    Face(unsigned int a,unsigned int b,unsigned int c,
         unsigned int uva, unsigned int uvb, unsigned int uvc, unsigned int material_index);

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
    inline unsigned int uva() const {
        return _uva;
    }

    inline unsigned int uvb() const {
        return _uvb;
    }

    inline unsigned int uvc() const {
        return _uvc;
    }

    inline unsigned int material_index() const {
		return _m;
	}
};

#endif /* SRC_FACE_H_ */
