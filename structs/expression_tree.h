#ifndef _S16_ExpressionTree_H__
#define _S16_ExpressionTree_H__
#include <string>

class ExpressionTree {
public:
  // throws invalid argumetn for invalid RPN strings
  ExpressionTree(const std::string& rpn);

  std::string rpn() const;
  std::string infix() const;
  // return value of expression tree. Throws out of range
  // and overflow exceptions
  double eval() const;

  struct Node {
    virtual double eval() const = 0; // pure virtual is equal to zero
    virtual std::string rpn() const = 0;
    virtual std::string infix() const = 0;
    virtual std::string symbol() const = 0;
  };

  Node* root_;
};

#endif // _S16_Expressiontree_H__