#ifndef _S16_queue_H__ // header guards
#define _S16_queue_H__

#include "./dlist.h"

template <typename T> class queue {

public:
  void push(T x_) { c_.push_back(x_); }
  void pop() { c_.pop_front(); }
  T& front() { return c_.head()->value; }
  bool empty() { return c_.empty(); }

private:
  dlist<T> c_;
};

#endif // _S16_queue_H__