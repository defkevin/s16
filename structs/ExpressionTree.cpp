#include "ExpressionTree.h"
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

typedef ExpressionTree::Node
    Node; // saves us time of not having to type out ExpressionTree::Node

string ExpressionTree::rpn() { return root_->rpn(); }
double ExpressionTree::eval() { return root_->eval(); }
string ExpressionTree::infix() { return root_->infix(); }

struct BinaryOp : public Node {
  BinaryOp(Node* l, Node* r) : left(l), right(r) {}
  string rpn() {
    string rpn = left->rpn() + " " + right->rpn() + " " + symbol();
    return rpn;
  };
  string infix() {
    string infix =
        "(" + left->infix() + " " + symbol() + " " + right->infix() + ")";
    return infix;
  }
  Node* left;
  Node* right;
};

struct AddOp : public BinaryOp {
  AddOp(Node* l, Node* r) : BinaryOp(l, r) {}
  string symbol() { return "+"; }
  double eval() { return left->eval() + right->eval(); }
};

struct SubtractOp : public BinaryOp {
  string symbol() { return "-"; }
  double eval() { return left->eval() - right->eval(); }
};
struct MultiplyOp : public BinaryOp {
  string symbol() { return "*"; }
  double eval() { return left->eval() * right->eval(); }
};
struct DivideOp : public BinaryOp {
  string symbol() { return "/"; }
  double eval() { return left->eval() / right->eval(); }
};

ExpressionTree::ExpressionTree(string s) {
  stack<Node*> stk;
  string symbol;
  istringstream iss;
  while (iss >> symbol) {
    if (symbol == "+") {
      Node* left = stk.top();
      stk.pop();
      Node* right = stk.top();
      stk.pop();
      stk.push(new AddOp(left, right));
    }
  }
}