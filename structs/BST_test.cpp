#include "../test/logging.h"
#include "bst.h"
#include <cstddef>

#include <iostream>
using namespace std;

int main() {
  BEGIN_TESTS();

  // BST<string> bst;
  // bst.insert("car");
  // bst.insert("ford");
  // bst.insert("gmc");
  // cout << bst.dot() << endl;

  BST<int> bst_num;
  bst_num.insert(50);
  // cout << bst_num.dot() << endl;
  bst_num.insert(20);
  // cout << bst_num.dot() << endl;
  bst_num.insert(60);
  // cout << bst_num.dot() << endl;
  bst_num.insert(10);
  // cout << bst_num.dot() << endl;
  bst_num.insert(30);
  // cout << bst_num.dot() << endl;
  bst_num.insert(25);
  bst_num.remove(20);
  cout << bst_num.dot() << endl << endl;
  // cout << bst_num.dot() << endl;
}