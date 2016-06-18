#ifndef _S16_DLIST_H__
#define _S16_DLIST_H__
#include <cstddef>
#include <iostream>

template <typename T>
class dlist {
public:
  dlist();
  ~dlist();

  struct Node {
    Node(T v, Node* n, Node* p) : value(v), next(n), prev(p) { }
    T value;
    Node* next;
    Node* prev;
  };

  void push_back(T x);
  void push_front(T x);
  void pop_back();
  void pop_front();
  int size();
  Node* tail() { return tail_; }
  Node* head() { return head_; }

  bool empty() { return head_ == nullptr; }

  void print() { print_recursive(head_); }
  void print_reverse();

private:
  Node* head_;
  Node* tail_;

  void print_recursive(Node* n) {
    if (n == nullptr) {
      std::cout << std::endl;
    } else {
      std::cout << n->value << " ";
      print_recursive(n->next);
    }
  }
};

// Print Out
template <typename T>
std::ostream& operator<<(std::ostream& os, dlist<T>& list) {
  typename dlist<T>::Node* node = list.head();
  while(node) {
    os << node->value << "  ";
    node = node->next;
  }
  return os;
}

// Print Reverse
template <typename T>
void dlist<T>::print_reverse() {
  Node* n = tail_;
  while (n != nullptr) {
    std::cout << n->value << " ";
    n = n->prev;
  }
  std::cout << std::endl;
}

// template <typename T>
// std::ostream& operator<<(std::ostream& os, typename::dlist<T>::Node& node) {
//   std::cout << "Node: value = " << node.value
//             << ", " << (node.next == nullptr ? "null" : node.next->value);
// }

// Constructor
template <typename T>
dlist<T>::dlist() : head_(nullptr), tail_(nullptr) { }

// Destructor
template <typename T>
dlist<T>::~dlist() {
  Node* n = head_;
  while (n != nullptr) {
    Node* next = n->next;
    delete n;
    n = next;
  }
}

// Size
template <typename T>
int dlist<T>::size() {
  int count = 0;
  Node* n = head_;
  while (n != nullptr) {
    count++;
    n = n->next;
  }
  return count;
}

// Push Front
template <typename T>
void dlist<T>::push_front(T x) {
  Node* n = head_;
  head_ = new Node(x, head_, nullptr);
  if (tail_ == nullptr) {
    tail_ = head_;
  } else {
    n->prev = head_;
  }
}

// Push Back
template <typename T>
void dlist<T>::push_back(T x) {
  Node* n = new Node(x, nullptr, tail_);
  if (head_ == nullptr) {
    head_ = tail_ = n;
  } else {
    tail_->next = n;
    tail_ = n;
    if (head_ == nullptr) {
      head_ = n;
    }
  }
}

// Pop Back
template <typename T>
void dlist<T>::pop_back() {
  if (head_ == nullptr) {
    return;
  } else if (head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
  } else {
    Node* n = tail_->prev;
    delete tail_;
    tail_ = n;
    tail_->next = nullptr;
  }
}

// Pop Front
template <typename T>
void dlist<T>::pop_front() {
  if (head_ == nullptr) {
    return;
  } else if (head_ == tail_) {
    delete head_;
    head_ = tail_ = nullptr;
  } else {
    Node* n = head_->next;
    delete head_;
    head_ = n;
    head_->prev = nullptr;
  }
}

#endif // _S16_DLIST_H__