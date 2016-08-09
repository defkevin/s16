#include "../../test/logging.h"
#include "stackint.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  BEGIN_TESTS();
  StackInt stk;
  stk.push(5);
  CHECK_EQ(stk.top(), 5);
  stk.pop();
  stk.push(10);
  CHECK_EQ(stk.top(), 10);
  stk.pop();
  stk.push(15);
  CHECK_EQ(stk.top(), 15);
  stk.pop();
  CHECK_EQ(stk.empty(), true);
}