#ifndef _S16_dlist_H__
#define _S16_dlist_H__

#include <cstddef>
#include <iostream>
using std::cout;
using std::endl;

template <typename T> class dlist {
public:
  dlist();
  ~dlist();

  struct Node {
    Node(const T &v, Node *n, Node *p) : value(v), next(n), prev(p) {}
    T value;
    Node *next;
    Node *prev;
  };

  void push_back(const T &n);
  void push_front(const T &n);
  void pop_front();
  void pop_back();

  int size() const;
  const Node *head() const { return head_; }
  const Node *tail() const { return tail_; }

  bool empty() const { return head_ == nullptr; }
  void print() const { print_recursive(head_); }
  void print_reverse() const;
  // void print_backwards();

protected:
  void print_recursive(const Node *n) const {
    if (n == nullptr) {
      cout << endl; // prints at very end
    } else {
      cout << n->value << " ";
      print_recursive(n->next);
    }
  }
  Node *head_;
  Node *tail_;
};

template <typename T> void dlist<T>::print_reverse() const {
  Node *n = tail_;
  while (n != nullptr) {
    cout << n->value << " ";
    n = n->prev;
  }
  cout << endl;
}

// constructor
template <typename T> dlist<T>::dlist() : head_(nullptr), tail_(nullptr) {}

// deconstructor
template <typename T> dlist<T>::~dlist() {
  Node *n = head_;
  while (n != nullptr) {
    Node *next = n->next;
    delete n;
    n = next;
  }
}

template <typename T> int dlist<T>::size() const {
  Node *n = head_;
  int count = 0;
  while (n != nullptr) {

    count++;
    n = n->next;
  }
  return count;
}

template <typename T> void dlist<T>::push_front(const T &x) {
  Node *n = head_;
  head_ = new Node(x, head_, nullptr);
  if (tail_ == nullptr) {
    tail_ = head_;
  } else {
    n->prev = head_;
  }
}

template <typename T> void dlist<T>::pop_front() {
  if (head_ == nullptr) {
    return;
  } else if (head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
  }
  if (head_ != nullptr) // same as if(head==nullpointer)
  {
    Node *p = head_->next;
    delete head_;
    head_ = p;
    head_->prev = nullptr;
  }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const dlist<T> &list) {
  const typename dlist<T>::Node *node = list.head();
  while (node) {
    os << node->value << "  ";
    node = node->next;
  }
  return os;
}

template <typename T> void dlist<T>::push_back(const T &x) {
  Node *n = new Node(x, nullptr, tail_);
  if (head_ == nullptr && tail_ == nullptr) {
    head_ = n;
    tail_ = n;
  } else {
    tail_->next = n;
    tail_ = n;
  }
  if (head_ == nullptr) {
    head_ = n;
  }
}

template <typename T> void dlist<T>::pop_back() {
  if (head_ == nullptr) {

  } else if (head_ == tail_) {
    delete head_;
    head_ = nullptr;
    tail_ = nullptr;
  } else {
    Node *n = tail_->prev;
    delete tail_;
    n->next = nullptr;
    tail_ = n;
  }
}

#endif // _S16_dlist_H__