#include "../test/logging.h"
#include "slist.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;


int main() {

	BEGIN_TESTS();

	slist<int> slr;
	slr.push_front(3);
	slr.push_front(4);
	slr.push_front(5);
	slr.print();
	slr.reverse();
	slr.print();


}