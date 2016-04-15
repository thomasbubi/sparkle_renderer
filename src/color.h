#ifndef SRC_COLOR_H_
#define SRC_COLOR_H_

class Color {
	float _r;
	float _g;
	float _b;
public:
	Color();
	Color(float r, float g, float b);
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
	}

	void operator+=(Color rhs){
		this->_b+=rhs._b;
		this->_r+=rhs._r;
		this->_g+=rhs._g;
	}

	void operator-=(Color rhs){
		this->_b-=rhs._b;
		this->_r-=rhs._r;
		this->_g-=rhs._g;
	}

	void operator*=(Color rhs){
		this->_b*=rhs._b;
		this->_r*=rhs._r;
		this->_g*=rhs._g;
	}
	void operator*=(float sc){
		this->_b*=sc;
		this->_r*=sc;
		this->_g*=sc;
	}


	Color operator+(Color rhs){
		return Color(this->_r+rhs._r,this->_g+rhs._g,this->_b+rhs._b);
	}

	Color operator-(Color rhs){
		return Color(this->_r-rhs._r,this->_g-rhs._g,this->_b-rhs._b);
	}

	Color operator*(Color rhs){
			return Color(this->_r*rhs._r,this->_g*rhs._g,this->_b*rhs._b);
	}

	Color operator*(float sc){
				return Color(this->_r*sc,this->_g*sc,this->_b*sc);
	}

};

#endif /* SRC_COLOR_H_ */
