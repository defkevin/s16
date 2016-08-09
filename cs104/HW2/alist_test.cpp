#include "alist.h"
#include <iostream>

using std::cout;

int main() {
  AListInt ali(5);
  ali.insert(0, 4);
  ali.insert(1, 6);
  ali.print();
  ali.insert(0, 7);
  ali.print();
}