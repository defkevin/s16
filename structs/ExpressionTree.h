#ifndef _S16_ExpressionTree_H__
#define _S16_ExpressionTree_H__
#include <string>

class ExpressionTree {
public:
  // throws invalid argumetn for invalid RPN strings
  ExpressionTree(std::string rpn);

  std::string rpn();
  std::string infix();
  // return value of expression tree. Throws out of range
  // and overflow exceptions
  double eval();

  struct Node {
    virtual double eval() = 0; // pure virtual is equal to zero
    virtual std::string rpn() = 0;
    virtual std::string infix() = 0;
    virtual std::string symbol() = 0;
  };

  Node* root_;
};

#endif // _S16_Expressiontree_H__