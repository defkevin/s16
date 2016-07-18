#ifndef _S16_stack_H__
#define _S16_stack_H__

#include "./vector.h"

template <typename T> class stack { // Stack is a container adapter

public:
  void push(T x_) { c_.push_back(x_); }
  void pop() { c_.pop_back(); }
  T& top() { return c_[c_.size() - 1]; }
  bool empty() { return c_.empty(); }

private:
  vector<T> c_;
};

#endif // _S16_stack_H__
