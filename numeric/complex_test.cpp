#include "../test/logging.h"
#include "complex.h"
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

int main(){
	complex a(1,2);
	complex b(-1, 2);
	CHECK_EQ(a+b, complex(0,4));
	CHECK_EQ(a-b, complex(2,0));
	CHECK_EQ(a*b, complex(-5,0));
	CHECK_EQ(a/b, complex(.6,-.8));

    cout << exp(complex(0,M_PI));

	// CHECK_EQ((a.simplify()), rational(5,4));
 //  	CHECK_EQ((a +b), rational(7,4));
  //  	CHECK_EQ((a -b), rational(1,1));
 //  	CHECK_EQ((a *b), rational(5,8));
 //  	CHECK_EQ((a /b), rational(5,2));
 //  	CHECK_NE(a==b, 1);
 //  	a+=b;
 //  	CHECK_EQ(a,rational(7,4)); 
}