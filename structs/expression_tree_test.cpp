#include "../test/logging.h"
#include "expression_tree.h"
#include <iostream>

using namespace std;

void TestExpressionTree() {
  string s = "3 4 + 5 * 7 -";
  ExpressionTree t(s);
  t.PrintInOrder();
  cout << "t.eval(\"" << s << "\") = " << t.eval() << endl;
}

void TestAbstractExpressionTree() {
  string s = "3 4 + 5 * 7 -";
  AbstractExpressionTree t(s);
  t.PrintInOrder();
  cout << "t.eval(\"" << s << "\") = " << t.eval() << endl;
}

int main() {
  BEGIN_TESTS();

  TestAbstractExpressionTree();
}
