#ifndef _S16_set_H__
#define _S16_set_H__

#include "./dlistNico.h"
#include <iostream>

using std::cout;
using std::endl;

template <typename T> class set { // set is a container adapter

public:
  set() {}
  ~set() {}
  class iter {
  public:
    iter() : node_(nullptr) {}
    iter(typename dlist<T>::Node* n) : node_(n) {}
    ~iter() {}
    bool operator==(const iter& other) { return node_ == other.node_; }
    bool operator!=(const iter& other) { return node_ != other.node_; }
    T value() { return node_->value; }
    iter next() { return iter(node_ != nullptr ? node_->next : nullptr); }

  private:
    typename dlist<T>::Node* node_;
  };

  iter begin();   // construct an iterator to the first element
  iter end();     // construct an iterator one past the last element
  iter find(T x); // return iterator with value x
  bool remove(iter it);
  iter insert(T x); // insert x and return the iter for x. Return end() if
                    // already in set
  int size() { return c_.size(); }

  bool empty() { return c_.empty(); }

private:
  dlist<T> c_;
};

template <typename T> typename set<T>::iter set<T>::begin() {
  return iter(c_.head());
}

template <typename T> typename set<T>::iter set<T>::end() {
  return iter(nullptr);
}

template <typename T> typename set<T>::iter set<T>::find(T x) {
  iter i = begin();
  while (i != end()) {
    if (i.value() == x) {
      return i;
    }
    i = i.next();
  }
  return end();
}

template <typename T> typename set<T>::iter set<T>::insert(T x) {
  iter i = find(x);
  if (i != end()) { // WE FOUND x
    return i;
  } else {
    c_.push_back(x);
    return iter(c_.tail());
  }
}

template <typename T> std::ostream& operator<<(std::ostream& os, set<T>& s) {
  typename set<T>::iter i = s.begin();
  while (i != s.end()) {
    os << i.value() << " ";
    i = i.next();
  }
  os << endl;
  return os;
}

#endif // _S16_set_H__
