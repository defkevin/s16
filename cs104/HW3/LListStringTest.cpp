#include "../../test/logging.h"
#include "LListString.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  BEGIN_TESTS();
  LListString DLS;
  DLS.push_back("hello");
  DLS.push_back("my");
  DLS.push_back("name");
  DLS.push_back("is");
  DLS.push_back("Kevin");
  cout << DLS.size() << endl;
  DLS.print();
}