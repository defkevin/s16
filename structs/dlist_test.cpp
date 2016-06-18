#include "../test/logging.h"
#include "dlist.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;


int main() {

	BEGIN_TESTS();

	dlist<int> dlr;
	dlr.push_back(9);
	dlr.push_front(3);
	dlr.push_front(4);
	dlr.pop_front();

	 dlr.push_back(5);
	 
	 cout << "Tail: " << dlr.tail()->value << endl; 
	 cout << "Head: " << dlr.head()->value << endl; 
	 cout << "Size: " << dlr.size() << endl;
	 dlr.print();
	dlr.push_back(9);
	dlr.print();
	// dlr.pop_back();
	dlr.print();
	dlr.print_reverse();
	cout << dlr.size() << endl;
	cout << dlr.head()->next->prev <<endl;

	
}