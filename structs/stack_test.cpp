#include "../test/logging.h"
#include "stack.h"
#include "slist.h"
#include <iostream>
#include <cmath>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T>
void reverse_print(slist<T>& list) {
	stack<T> stack;
	typename slist<T>::Node* n = list.head();
	while(n!=nullptr){
		stack.push(n->value);
		n = n->next;
	}

	while(!stack.empty()) {
		cout << stack.top() << "   ";
		stack.pop();
	}
		cout << endl;
}

int main() {

	BEGIN_TESTS();

	stack<int> intstack;
	intstack.push(4);
	CHECK_EQ(intstack.top(),4);
	intstack.push(10);
	intstack.pop();
	intstack.pop();
	intstack.empty();

	slist<string> strstack;
	strstack.push_back("Kevin");
	strstack.push_back("Nico");
	strstack.push_back("Daniel");
	reverse_print(strstack);
}