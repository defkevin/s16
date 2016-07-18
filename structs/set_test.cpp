#include "../test/logging.h"
#include "dlistNico.h"
#include "set.h"
#include <cmath>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main() {

  BEGIN_TESTS();

  set<int> intset;
  set<int>::iter i = intset.begin();
  CHECK_EQ(i == intset.end(), true);
  CHECK_EQ(i != intset.end(), false);
  CHECK_EQ(intset.find(3) == intset.end(), true);
  CHECK_EQ(intset.insert(3) == intset.end(), false);
  CHECK_EQ(intset.insert(4) == intset.end(), false);
  CHECK_EQ(intset.find(3) != intset.end(), true);
  CHECK_EQ(intset.insert(3) == intset.end(), false);
  CHECK_EQ(intset.size(), 2);
  cout << intset;
}