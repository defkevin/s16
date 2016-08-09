#include "expression_tree.h"
#include <cmath>
#include <iostream>
#include <math.h>
#include <sstream>
#include <stack>

using namespace std;

typedef ExpressionTree::Node
    Node; // saves us time of not having to type out ExpressionTree::Node

string ExpressionTree::rpn() const { return root_->rpn(); }
double ExpressionTree::eval() const { return root_->eval(); }
string ExpressionTree::infix() const { return root_->infix(); }

struct UnaryFunc : public Node {
  UnaryFunc(Node* a) : arg(a) {}
  string rpn() const {
    string rpn = arg->rpn() + " " + symbol();
    return rpn;
  };
  virtual string infix() const {
    string infix = symbol() + "(" + arg->infix() + ")";
    return infix;
  }
  Node* arg;
};

struct BinaryFunc : public Node {
  BinaryFunc(Node* a, Node* b) : left(a), right(b) {}
  string rpn() const {
    string rpn = left->rpn() + " " + right->rpn() + " " + symbol();
    return rpn;
  };
  string infix() const {
    string infix = symbol() + "(" + right->infix() + "," + left->infix() + ")";
    return infix;
  }
  Node* left;
  Node* right;
};

struct BinaryOp : public BinaryFunc {
  BinaryOp(Node* l, Node* r) : BinaryFunc(l, r) {}
  virtual string infix() const {
    string infix =
        "(" + left->infix() + " " + symbol() + " " + right->infix() + ")";
    return infix;
  }
};

struct Number : public Node {
  double value;
  Number(double v) : value(v) {}
  double eval() const { return value; }
  string rpn() const {
    ostringstream strs;
    strs << value;
    string str = strs.str();
    return str;
  }
  string symbol() const { return rpn(); }
  string infix() const { return rpn(); }
};

struct Abs : public UnaryFunc {
  Abs(Node* arg) : UnaryFunc(arg) {}
  string symbol() const { return "abs"; }
  double eval() const { return abs(arg->eval()); }
};

struct Round : public UnaryFunc {
  Round(Node* arg) : UnaryFunc(arg) {}
  string symbol() const { return "round"; }
  double eval() const { return round(arg->eval()); }
};

struct Floor : public UnaryFunc {
  Floor(Node* arg) : UnaryFunc(arg) {}
  string symbol() const { return "floor"; }
  double eval() const { return floor(arg->eval()); }
};

struct Ceiling : public UnaryFunc {
  Ceiling(Node* arg) : UnaryFunc(arg) {}
  string symbol() const { return "ceil"; }
  double eval() const { return ceil(arg->eval()); }
};

struct Cos : public UnaryFunc {
  Cos(Node* arg) : UnaryFunc(arg) {}
  string symbol() const { return "cos"; }
  double eval() const { return cos((arg->eval() * M_PI) / 180); }
};

struct Sin : public UnaryFunc {
  Sin(Node* arg) : UnaryFunc(arg) {}
  string symbol() const { return "sin"; }
  double eval() const { return sin((arg->eval() * M_PI) / 180); }
};

struct Tan : public UnaryFunc {
  Tan(Node* arg) : UnaryFunc(arg) {}
  string symbol() const { return "tan"; }
  double eval() const { return tan((arg->eval() * M_PI) / 180); }
};

struct Fact : public UnaryFunc {
  int factorial(int num) const {
    int product;
    if (num <= 1) {
      return 1;
    } else {
      product = num * factorial(num - 1);
    }
    return product;
  }
  Fact(Node* arg) : UnaryFunc(arg) {}
  string symbol() const { return "!"; }
  double eval() const { return factorial(arg->eval()); }
  virtual string infix() const {
    string infix = arg->infix() + "!";
    return infix;
  }
};

struct Max : public BinaryFunc {
  Max(Node* arg1, Node* arg2) : BinaryFunc(arg1, arg2) {}
  string symbol() const { return "max"; }
  double eval() const { return max(left->eval(), right->eval()); }
};

struct Min : public BinaryFunc {
  Min(Node* arg1, Node* arg2) : BinaryFunc(arg1, arg2) {}
  string symbol() const { return "min"; }
  double eval() const { return min(left->eval(), right->eval()); }
};

struct Pow : public BinaryFunc {
  Pow(Node* arg1, Node* arg2) : BinaryFunc(arg1, arg2) {}
  string symbol() const { return "^"; }
  double eval() const { return pow(right->eval(), left->eval()); }
};

struct AddOp : public BinaryOp {
  AddOp(Node* l, Node* r) : BinaryOp(l, r) {}
  string symbol() const { return "+"; }
  double eval() const { return left->eval() + right->eval(); }
};

struct SubtractOp : public BinaryOp {
  SubtractOp(Node* l, Node* r) : BinaryOp(l, r) {}
  string symbol() const { return "-"; }
  double eval() const { return left->eval() - right->eval(); }
};
struct MultiplyOp : public BinaryOp {
  MultiplyOp(Node* l, Node* r) : BinaryOp(l, r) {}
  string symbol() const { return "*"; }
  double eval() const { return left->eval() * right->eval(); }
};
struct DivideOp : public BinaryOp {
  DivideOp(Node* l, Node* r) : BinaryOp(l, r) {}
  string symbol() const { return "/"; }
  double eval() const { return left->eval() / right->eval(); }
};

ExpressionTree::Node* pop_top(stack<ExpressionTree::Node*>& rpn,
                              string symbol) {
  if (rpn.empty()) {
    if (symbol.empty()) {
      throw invalid_argument("bad expression");
    } else {
      throw invalid_argument("bad expression for symbol " + symbol);
    }
  }
  ExpressionTree::Node* t = rpn.top();
  rpn.pop();
  return t;
}

ExpressionTree::ExpressionTree(const string& s) {
  stack<Node*> stk;
  string symbol = s;
  istringstream iss(symbol);
  while (iss >> symbol) {
    istringstream num(symbol);
    double value;
    if (num >> value) {
      stk.push(new Number(value));
    }
    if (symbol == "+") {
      Node* r = pop_top(stk, symbol);
      Node* l = pop_top(stk, symbol);
      stk.push(new AddOp(l, r));
    }
    if (symbol == "-") {
      Node* r = pop_top(stk, symbol);
      Node* l = pop_top(stk, symbol);
      stk.push(new SubtractOp(l, r));
    }
    if (symbol == "*") {
      Node* r = pop_top(stk, symbol);
      Node* l = pop_top(stk, symbol);
      stk.push(new MultiplyOp(l, r));
    }
    if (symbol == "/") {
      Node* r = pop_top(stk, symbol);
      Node* l = pop_top(stk, symbol);
      stk.push(new DivideOp(l, r));
    }
    if (symbol == "abs") {
      Node* args = pop_top(stk, symbol);
      stk.push(new Abs(args));
    }
    if (symbol == "round") {
      Node* args = pop_top(stk, symbol);
      stk.push(new Round(args));
    }
    if (symbol == "floor") {
      Node* args = pop_top(stk, symbol);
      stk.push(new Floor(args));
    }
    if (symbol == "cos") {
      Node* args = pop_top(stk, symbol);
      stk.push(new Cos(args));
    }
    if (symbol == "sin") {
      Node* args = pop_top(stk, symbol);
      stk.push(new Sin(args));
    }
    if (symbol == "tan") {
      Node* args = pop_top(stk, symbol);
      stk.push(new Tan(args));
    }
    if (symbol == "!") {
      Node* args = pop_top(stk, symbol);
      stk.push(new Fact(args));
    }
    if (symbol == "max") {
      Node* arg1 = pop_top(stk, symbol);
      Node* arg2 = pop_top(stk, symbol);
      stk.push(new Max(arg1, arg2));
    }
    if (symbol == "min") {
      Node* arg1 = pop_top(stk, symbol);
      Node* arg2 = pop_top(stk, symbol);
      stk.push(new Min(arg1, arg2));
    }
    if (symbol == "^") {
      Node* arg1 = pop_top(stk, symbol);
      Node* arg2 = pop_top(stk, symbol);
      stk.push(new Pow(arg1, arg2));
    }
  }
  root_ = pop_top(stk, "");
  if (!stk.empty()) {
    throw invalid_argument("stack is not empty!");
  }
}