#include "ExpressionTree.h"
#include <iostream>
#include <string>
using namespace std;

void testBadRPN(string s) {
  // string s = "3 4 + 5 * 7 -";
  // string s = "2 2 + 9 3 / ^";
  try {
    // Construct tree from rpn string.
    ExpressionTree t(s);

    // Print it out in order.
    t.infix();

    // Evaluate.
    double value = t.eval();
    cout << "t.eval(\"" << s << "\") = " << value << endl;
    cout << "t.infix: " << t.infix() << " = " << value << endl;
  } catch (invalid_argument e) {
    cerr << "Could not construct tree: " << e.what() << endl;
  } catch (std::overflow_error e) {
    cerr << "Could not evaluate tree: " << e.what() << endl;
  }
  cout << endl;
}

int main() {
  testBadRPN("3 4 + 5 /");
  testBadRPN("9 5 -");
  testBadRPN("4 3 *");
  testBadRPN("10 2 /");
  testBadRPN("77 23 +");
  testBadRPN("-10 abs");
  testBadRPN("68 69 max");
  testBadRPN("68 69 min");
  testBadRPN("2 3 ^");
  testBadRPN("+");
  testBadRPN("10.2 floor");
  testBadRPN("10.2 ceil");
  testBadRPN("10.2 round");
  testBadRPN("60 sin");
  testBadRPN("60 cos");
  testBadRPN("60 tan");
  testBadRPN("5 !");
}