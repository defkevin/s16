#include "../../test/logging.h"
#include "LListInt.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  BEGIN_TESTS();
  LListInt DL;
  DL.push_front(5);
  DL.push_front(10);
  DL.insert(1, 2);
  DL.print();
  CHECK_EQ(DL.get(0), 10);
  CHECK_EQ(DL.get(1), 2);
  CHECK_EQ(DL.get(2), 5);
  DL.remove(0);
  CHECK_EQ(DL.get(0), 2);
  CHECK_EQ(DL.size(), 2);
}