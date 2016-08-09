#include "../../test/logging.h"
#include "SetStr.h"
#include <iostream>
using namespace std;

void print(const SetStr& set) {
  const string* s = set.first();
  while (s) {
    cout << *s << " ";
    s = set.next();
  }
  cout << endl;
}

int main() {
  BEGIN_TESTS();

  SetStr set;
  CHECK_EQ(set.size(), 0);
  CHECK_EQ(set.empty(), true);
  set.insert("pizza");
  CHECK_EQ(set.size(), 1);
  set.insert("bagel");
  print(set);

  CHECK_EQ(set.size(), 2);
  set.insert("donut");
  set.insert("burger");
  set.insert("burger");
  CHECK_EQ(set.size(), 4);
  print(set);
  set.remove("fries");
  cout << set.size() <<endl;

  
  CHECK_EQ(set.size(), 4);
  print(set);
  

  CHECK_EQ(*set.first(), "pizza");
  CHECK_EQ(*set.next(), "bagel");
  CHECK_EQ(set.exists("fries"), false);
  CHECK_EQ(set.exists("burger"), true);
  CHECK_EQ(set.empty(), false);
  cout << endl;

  SetStr s1;
  s1.insert("apple");
  s1.insert("raspberry");
  s1.insert("watermelon");
  s1.insert("lemon");
  print(s1);

  SetStr s2;
  s2.insert("apple");
  s2.insert("pear");
  s2.insert("peach");
  s2.insert("lemon");
  print(s2);
  SetStr s3 = s1 | s2;
  print(s3);
  cout << endl;

  SetStr s4;
  s4.insert("cat");
  s4.insert("dog");
  s4.insert("fish");
  s4.insert("bird");
  print(s4);
  SetStr s5;
  s5.insert("bear");
  s5.insert("dog");
  s5.insert("fish");
  s5.insert("tiger");
  print(s5);
  SetStr s6 = s4 & s5;
  print(s6);
  cout << endl;
}