#include "../test/logging.h"
#include "vector.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

int main() {
	BEGIN_TESTS(); 
	
	vector<int> v;
	CHECK_EQ(v.size(),0);
	v.push_back(3);
	v.push_back(5);
	CHECK_EQ(v.size(),2);
	CHECK_EQ(v.back(),5);
	v.pop_back();
	CHECK_EQ(v.size(),1);
	CHECK_GE(v.capacity(),2);
	v.pop_back();
	CHECK_GE(v.capacity(),2);
	CHECK_EQ(v.size(),0);
	v[1] = 6;
	CHECK_EQ(v[1], 6);
}