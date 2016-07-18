#include "expression_tree.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

//
// AbstractExpressionTree
//
AbstractExpressionTree::AbstractExpressionTree(std::string s) {
  std::istringstream str(s);
  std::stack<Node*> rpn;

  std::string symbol;
  while (str >> symbol) {
    if (symbol == "+") {
      Node* r = rpn.top();
      rpn.pop();
      Node* l = rpn.top();
      rpn.pop();
      rpn.push(new AddNode(l, r));
    } else if (symbol == "-") {
      Node* r = rpn.top();
      rpn.pop();
      Node* l = rpn.top();
      rpn.pop();
      rpn.push(new SubtractNode(l, r));
    } else if (symbol == "*") {
      Node* r = rpn.top();
      rpn.pop();
      Node* l = rpn.top();
      rpn.pop();
      rpn.push(new MultiplyNode(l, r));
    } else if (symbol == "/") {
      Node* r = rpn.top();
      rpn.pop();
      Node* l = rpn.top();
      rpn.pop();
      rpn.push(new DivideNode(l, r));
    } else {
      int value = stoi(symbol);
      rpn.push(new ValueNode(value));
    }
  }

  root_ = rpn.top();
}

AbstractExpressionTree::~AbstractExpressionTree() { delete root_; }

void AbstractExpressionTree::PrintPreOrder() {
  root_->PrintPreOrder();
  cout << endl;
}
void AbstractExpressionTree::PrintInOrder() {
  root_->PrintInOrder();
  cout << endl;
}
void AbstractExpressionTree::PrintPostOrder() {
  root_->PrintPostOrder();
  cout << endl;
}

int AbstractExpressionTree::eval() {
  assert(root_ != nullptr);
  return root_->eval();
}

void AbstractExpressionTree::BinaryNode::PrintInOrder() {
  cout << "(";
  left->PrintInOrder();
  cout << " " << symbol() << " ";
  right->PrintInOrder();
  cout << ")";
}
void AbstractExpressionTree::BinaryNode::PrintPreOrder() {
  cout << " " << symbol() << " ";
  left->PrintPreOrder();
  cout << " ";
  right->PrintPreOrder();
}
void AbstractExpressionTree::BinaryNode::PrintPostOrder() {
  left->PrintPreOrder();
  cout << " ";
  right->PrintPreOrder();
  cout << " " << symbol() << " ";
}

AbstractExpressionTree::AddNode::AddNode(Node* l, Node* r) : BinaryNode(l, r) {}
int AbstractExpressionTree::AddNode::eval() {
  return left->eval() + right->eval();
}

AbstractExpressionTree::SubtractNode::SubtractNode(Node* l, Node* r)
    : BinaryNode(l, r) {}
int AbstractExpressionTree::SubtractNode::eval() {
  return left->eval() - right->eval();
}

AbstractExpressionTree::DivideNode::DivideNode(Node* l, Node* r)
    : BinaryNode(l, r) {}
int AbstractExpressionTree::DivideNode::eval() {
  return left->eval() / right->eval();
}

AbstractExpressionTree::MultiplyNode::MultiplyNode(Node* l, Node* r)
    : BinaryNode(l, r) {}
int AbstractExpressionTree::MultiplyNode::eval() {
  return left->eval() * right->eval();
}

int AbstractExpressionTree::ValueNode::eval() { return value; }
void AbstractExpressionTree::ValueNode::PrintInOrder() { cout << value; }
void AbstractExpressionTree::ValueNode::PrintPreOrder() { PrintInOrder(); }
void AbstractExpressionTree::ValueNode::PrintPostOrder() { PrintInOrder(); }

// Ouput a dot file to give to WebGraphViz.com
void AbstractExpressionTree::output_dot(std::string filename) {}

//
// ExpressionTree
//
ExpressionTree::ExpressionTree(std::string s) {
  std::istringstream str(s);
  std::stack<Node*> rpn;

  std::string symbol;
  while (str >> symbol) {
    if (symbol == "+") {
      Node* r = rpn.top();
      rpn.pop();
      Node* l = rpn.top();
      rpn.pop();
      rpn.push(new Node(Node::Add, l, r));
    } else if (symbol == "-") {
      Node* r = rpn.top();
      rpn.pop();
      Node* l = rpn.top();
      rpn.pop();
      rpn.push(new Node(Node::Subtract, l, r));
    } else if (symbol == "*") {
      Node* r = rpn.top();
      rpn.pop();
      Node* l = rpn.top();
      rpn.pop();
      rpn.push(new Node(Node::Multiply, l, r));
    } else if (symbol == "/") {
      Node* r = rpn.top();
      rpn.pop();
      Node* l = rpn.top();
      rpn.pop();
      rpn.push(new Node(Node::Divide, l, r));
    } else {
      int value = stoi(symbol);
      rpn.push(new Node(value));
    }
  }

  root_ = rpn.top();
}

ExpressionTree::~ExpressionTree() { delete root_; }

void ExpressionTree::PrintPreOrder() {
  root_->PrintPreOrder();
  cout << endl;
}
void ExpressionTree::PrintInOrder() {
  root_->PrintInOrder();
  cout << endl;
}
void ExpressionTree::PrintPostOrder() {
  root_->PrintPostOrder();
  cout << endl;
}

int ExpressionTree::eval() {
  assert(root_ != nullptr);
  return root_->eval();
}
ExpressionTree::Node::~Node() {
  delete left;
  delete right;
}

void ExpressionTree::Node::PrintInOrder() {
  if (op == Value) {
    cout << value;
  } else {
    cout << "(";
    left->PrintInOrder();
    switch (op) {
    case Add:
      cout << " + ";
      break;
    case Subtract:
      cout << " - ";
      break;
    case Multiply:
      cout << " * ";
      break;
    case Divide:
      cout << " / ";
      break;
    default:
      cout << " BadType ";
      break;
    }
    right->PrintInOrder();
    cout << ")";
  }
}
void ExpressionTree::Node::PrintPreOrder() {}
void ExpressionTree::Node::PrintPostOrder() {}

int ExpressionTree::Node::eval() {
  switch (op) {
  case Add:
    return left->eval() + right->eval();
    break;

  case Subtract:
    return left->eval() - right->eval();

  case Multiply:
    return left->eval() * right->eval();
    break;

  case Divide:
    return left->eval() / right->eval();
    break;

  case Value:
    return value;
    break;

  default:
    std::cout << "Bad enum value " << op << std::endl;
    break;
  }
}

// Ouput a dot file to give to WebGraphViz.com
void ExpressionTree::output_dot(std::string filename) {}
