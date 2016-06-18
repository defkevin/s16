#include "../test/logging.h"
#include "rational.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
	rational a(1,2);
	rational b(-1, 2);
	// CHECK_EQ((a.simplify()), rational(5,4));
 //  	CHECK_EQ((a +b), rational(7,4));
    	CHECK_EQ((a -b), rational(1,1));
 //  	CHECK_EQ((a *b), rational(5,8));
 //  	CHECK_EQ((a /b), rational(5,2));
 //  	CHECK_NE(a==b, 1);
 //  	a+=b;
 //  	CHECK_EQ(a,rational(7,4)); 
}