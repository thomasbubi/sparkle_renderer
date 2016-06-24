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

	float b() const {
		return _b;
	}

	void set_b(float b) {
		this->_b = b;
	}

	float g() const {
		return _g;
	}

	void set_g(float g) {
		this->_g = g;
	}

	float r() const {
		return _r;
	}

	void set_r(float r) {
		this->_r = r;
	}

	void clamp(){
		if(_r>1){_r=1;}
		if(_g>1){_g=1;}
		if(_b>1){_b=1;}
		if(_r<0){_r=0;}
		if(_g<0){_g=0;}
        if(_b<0){_b=0;}
        if(_alpha>1){_alpha=1;}
        if(_alpha<0){_alpha=0;}
	}

	void operator+=(Color rhs){
		this->_b+=rhs._b;
		this->_r+=rhs._r;
		this->_g+=rhs._g;
        this->_alpha+=rhs._alpha;
	}

	void operator-=(Color rhs){
		this->_b-=rhs._b;
		this->_r-=rhs._r;
		this->_g-=rhs._g;
        this->_alpha-=rhs._alpha;
	}

	void operator*=(Color rhs){
		this->_b*=rhs._b;
		this->_r*=rhs._r;
		this->_g*=rhs._g;
        this->_alpha*=rhs._alpha;
	}
    void operator*=(float scalar){
        this->_b*=scalar;
        this->_r*=scalar;
        this->_g*=scalar;
        this->_alpha*=scalar;
	}


	Color operator+(Color rhs){
        return Color(this->_r+rhs._r,this->_g+rhs._g,this->_b+rhs._b,this->_alpha+rhs._alpha);
	}

	Color operator-(Color rhs){
        return Color(this->_r-rhs._r,this->_g-rhs._g,this->_b-rhs._b,this->_alpha-rhs._alpha);
	}

	Color operator*(Color rhs){
        return Color(this->_r*rhs._r,this->_g*rhs._g,this->_b*rhs._b,this->_alpha*rhs._alpha);
	}

    Color operator*(float scalar){
        return Color(this->_r*scalar,this->_g*scalar,this->_b*scalar,this->_alpha*scalar);
	}

};

#endif /* SRC_COLOR_H_ */
