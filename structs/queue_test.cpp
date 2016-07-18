#include "../test/logging.h"
#include "dlist.h"
#include "queue.h"
#include <cmath>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// template <typename T>
// void reverse_print(dlist<T>& list) {
// 	queue<T> queue;
// 	typename dlist<T>::Node* n = list.head();
// 	while(n!=nullptr){
// 		queue.push(n->value);
// 		n = n->next;
// 	}

// 	while(!queue.empty()) {
// 		cout << queue.front() << "   ";
// 		queue.pop();
// 	}
// 		cout << endl;
// }

int main() {

  BEGIN_TESTS();

  queue<string> s;
  CHECK_EQ(s.empty(), true);

  s.push("Daniel");
  CHECK_EQ(s.empty(), false);
  CHECK_EQ(s.front(), "Daniel");
  s.push("Kevin");
  CHECK_EQ(s.front(), "Daniel");
  s.push("Nico");
  CHECK_EQ(s.front(), "Daniel");

  CHECK_EQ(s.front(), "Daniel");
  s.pop();
  CHECK_EQ(s.front(), "Kevin");

  s.pop();

  CHECK_EQ(s.front(), "Nico");
  s.pop();
}