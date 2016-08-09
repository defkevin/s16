#include "../../test/logging.h"
#include "setstr.h"
#include <iostream>
using namespace std;

void print(const SetStr& set) {
  const string* s = set.first();
  while (s != nullptr) {
    cout << *s << " ";
    s = set.next();
  }
  cout << endl;
}

int main() {
  BEGIN_TESTS();

  SetStr set;
  CHECK_EQ(set.empty(), true);
  set.insert("pizza");
  set.insert("bagel");
  set.insert("donut");
  set.insert("burger");
  set.insert("burger");
  CHECK_EQ(set.size(), 4);
  print(set);
  set.remove("bagel");
  set.remove("fries");
  print(set);
  CHECK_EQ(*set.first(), "pizza");
  CHECK_EQ(*set.next(), "donut");
  CHECK_EQ(set.exists("bagel"), false);
  CHECK_EQ(set.exists("burger"), true);
  CHECK_EQ(set.empty(), false);
}