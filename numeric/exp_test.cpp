#include "../test/logging.h"
#include "exp.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

int main() {
	double epsilon = 1e-10; 
	CHECK_LT((fabs(exp(1))- M_E), epsilon);
	CHECK_LT((fabs(exp(.5))- sqrt(M_E)), epsilon);
	CHECK_LT((fabs(exp(2))- M_E*M_E), epsilon);
}