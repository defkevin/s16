#include "../test/logging.h"
#include "slist.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;


int main() {

	BEGIN_TESTS();

	slist<int> slr;
	slr.push_back(3);
	slr.push_back(4);
	slr.print();
	slr.removeAllRecursive(3);
	slr.print();


}