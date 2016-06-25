#ifndef SRC_COLOR_H_
#define SRC_COLOR_H_

class Color {
	float _r;
	float _g;
	float _b;
    float _alpha;
public:
	Color();
    Color(float r, float g, float b);
    Color(float r, float g, float b, float alpha);
	virtual ~Color();

    inline float b() const {
		return _b;
	}

    inline void set_b(float b) {
		this->_b = b;
	}

    inline float g() const {
		return _g;
	}

    inline void set_g(float g) {
		this->_g = g;
	}

    inline float r() const {
		return _r;
	}

    inline void set_r(float r) {
		this->_r = r;
	}

    void clamp();

    void operator+=(Color rhs);

    void operator-=(Color rhs);

    void operator*=(Color rhs);

    void operator*=(float scalar);


    inline Color operator+(Color rhs){
        return Color(this->_r+rhs._r,this->_g+rhs._g,this->_b+rhs._b,this->_alpha+rhs._alpha);
	}

    inline Color operator-(Color rhs){
        return Color(this->_r-rhs._r,this->_g-rhs._g,this->_b-rhs._b,this->_alpha-rhs._alpha);
	}

    inline Color operator*(Color rhs){
        return Color(this->_r*rhs._r,this->_g*rhs._g,this->_b*rhs._b,this->_alpha*rhs._alpha);
	}

    inline Color operator*(float scalar){
        return Color(this->_r*scalar,this->_g*scalar,this->_b*scalar,this->_alpha*scalar);
	}

};

#endif /* SRC_COLOR_H_ */
