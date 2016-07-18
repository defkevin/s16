#include "expression_tree.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using std::cout;
using std::endl;
using std::stack;
using std::istringstream;
using std::stoi;
using std::string;
using std::stoi;

ExpressionTree::Node::~Node() {
  delete left;
  delete right;
}

int test_rpn(string s) {
  stack<int> rpn;
  istringstream str(s);
  string symbol;
  while (str >> symbol) {
    if (symbol == "+") {
      int second = rpn.top();
      rpn.pop();
      int first = rpn.top();
      rpn.pop();
      rpn.push(first + second);
    } else if (symbol == "-") {
      int second = rpn.top();
      rpn.pop();
      int first = rpn.top();
      rpn.pop();
      rpn.push(first - second);
    } else if (symbol == "*") {
      int second = rpn.top();
      rpn.pop();
      int first = rpn.top();
      rpn.pop();
      rpn.push(first * second);
    } else if (symbol == "/") {
      int second = rpn.top();
      rpn.pop();
      int first = rpn.top();
      rpn.pop();
      rpn.push(first / second);
    } else {
      rpn.push(stoi(symbol));
    }
  }
  return rpn.top();
}

int main() {
  string s = "35 90 +";
  cout << s << " = " << test_rpn(s) << endl;
  s = "9 4 -";
  cout << s << " = " << test_rpn(s) << endl;
}