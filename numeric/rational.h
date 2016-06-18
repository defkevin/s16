#ifndef _S16_RATIONAL_H__
#define _S16_RATIONAL_H__

#include <iostream> 
#include "gcd.h"

using std::ostream;

class rational{
public: 
	rational(int n, int d): n_(n), d_(d) {}
	~rational(){}
	rational simplify();
	void simplifyInPlace();
	rational operator+(rational other);
	rational operator-(rational other);
	rational operator*(rational other);
	rational operator/(rational other);
	void operator+=(rational other);
	void operator-=(rational other);
	void operator*=(rational other);
	void operator/=(rational other);
	bool operator==(rational other);
	int n() {return n_; }
	int d() {return d_; }
	double to_double();




private:
	int n_;
	int d_;
};

ostream& operator << (ostream& os, rational r){
	if(r.n() == r.d()){
		os << 1;
	}
	else if(r.d()==1){
		os << r.n();
	}
	else{
		os << r.n() <<"/"<<r.d();
	}	
	return os;
}

rational rational::simplify(){
	int multiple = gcd(n(),d());
	n_ = n_/multiple;
	d_ = d_/multiple;
	return rational(n_,d_);
};

void rational::simplifyInPlace(){
	int multiple = gcd(n(),d());
	n_ = n_/multiple;
	d_ = d_/multiple;
}

rational rational::operator+(rational other){
	return rational(n_*other.d_+other.n_*d_, d_*other.d_).simplify();
}

rational rational::operator-(rational other){
	return rational(n_*other.d_-other.n_*d_, d_*other.d_).simplify();
}

rational rational::operator*(rational other){
	return rational(n_*other.n_, d_*other.d_).simplify();
}

rational rational::operator/(rational other){
	return rational(n_*other.d_, d_*other.n_).simplify();
}

void rational::operator+=(rational other){
	n_ = (n_*other.d_+other.n_*d_);
	d_ = (d_*other.d_);
	simplifyInPlace();
}

void rational::operator-=(rational other){
	n_ = (n_*other.d_-other.n_*d_);
	d_ = (d_*other.d_);
	simplifyInPlace();
}

void rational::operator*=(rational other){
	n_ = n_*other.n_;
	d_ = d_*other.d_;
	simplifyInPlace();
}

void rational::operator/=(rational other){
	n_ = n_*other.d_;
	d_ = d_*other.n_;
	simplifyInPlace();
}

bool rational::operator==(rational other){
	return (n_==other.n_) && (d_==other.d_);
}

double rational::to_double(){
	double answer = (n_*1.0)/d_;
	return answer;
}



#endif // _S16_RATIONAL_H__