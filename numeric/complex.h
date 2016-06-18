#ifndef _S16_COMPLEX_H__
#define _S16_COMPLEX_H__

#include <iostream> 
#include "gcd.h"

using std::ostream;

class complex{
public: 
	complex(double re, double im): re_(re), im_(im) {}
	~complex(){}
	complex operator+(complex other);
	complex operator-(complex other);
	complex operator*(complex other);
	complex operator/(complex other);
	void operator+=(complex other);
	void operator-=(complex other);
	void operator*=(complex other);
	void operator/=(complex other);
	bool operator==(complex other);
	double re() {return re_; }
	double im() {return im_; }




private:
	double re_; // real number
	double im_; // imaginary number
};

complex exp(complex x){
	complex term(1,0);
    complex sum(1,0);
    for(int i = 1;i<100;i++)
    {
        term = (term*x)/complex(i,0);
        sum = sum +term;
    }
    return sum;
}

ostream& operator << (ostream& os, complex r){
	os << r.re() << "+" << r.im() << "i";
	return os;	
}

complex complex::operator+(complex other){
	return complex(re_+other.re_, im_+other.im_);
}

complex complex::operator-(complex other){
	return complex(re_ - other.re_, im_-other.im_);
}

complex complex::operator*(complex other){
	return complex( (re_*other.re_) -im_*other.im_, other.im_*re_ + other.re_*im_ );
}

complex complex::operator/(complex other){
	double d = other.im_;
    double c = other.re_;
    double denom = d*d+c*c;
    double realC = (c*re_ + d*im_)/denom;
    
    double imagC = (c*im_ - d*re_)/denom;
    return complex(realC, imagC);
}

bool complex::operator==(complex other){
	return (re_==other.re_) && (im_==other.im_);
}



#endif // _S16_COMPLEX_H__