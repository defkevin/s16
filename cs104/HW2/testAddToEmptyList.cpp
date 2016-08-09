#include "llistint.h"
#include <iostream>

using namespace std;

int main() {
  LListInt* list = new LListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // push_back an item at the head.
  list->push_back(3);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one push_backion." << endl;
  } else {
    cout << "FAIL: List is empty after one push_backion." << endl;
  }

  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one push_backion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size()
         << " after one push_backion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 3) {
    cout << "SUCCESS: 3 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  // Clean up memory.
  delete list;
}