#ifndef _S16_SLIST_H__
#define _S16_SLIST_H__

#include <cstddef>
#include <iostream>
using std::cout;
using std::endl;

template <typename T> class slist {
public:
  slist();
  ~slist();

  struct Node {
    Node(T v, Node* n) : data(v), next(n) {}
    T data;
    Node* next;
  };

  void push_back(T n);
  void pop_front();
  void push_front(T n);
  void pop_back();
  void reverse();
  void removeAllRecursive(T x) { head_ = recurse(head_, x); }
  Node* recurse(Node* n, T x);

  int size();
  Node* head() { return head_; }
  Node* tail();

  T sum() { return sum_recursive(head_); }

  void print() { print_recursive(head_); }
  void print_backwards() {
    print_backwards_recursive(head_);
    cout << endl;
  }

protected:
  void print_recursive(Node* n) {
    if (n == nullptr) {
      cout << endl; // prints at very end
    } else {
      cout << n->data << " ";
      print_recursive(n->next);
    }
  }
  void print_backwards_recursive(Node* n) {
    if (n == nullptr) {
      return;
    } else {
      print_backwards_recursive(n->next);
      cout << n->data << " ";
    }
  }
  T sum_recursive(Node* n) {
    if (n == nullptr) {
      cout << endl;
      return T(0);

    } else {
      return n->data + sum_recursive(n->next);
    }
  }
  Node* head_;
};

template <typename T> typename slist<T>::Node* slist<T>::tail() {
  if (head_ == nullptr) {
    return nullptr;
  }
  Node* n = head_;
  while (n->next != nullptr) {
    n = n->next;
  }
  return n;
}

template <typename T> typename slist<T>::Node* slist<T>::recurse(Node* n, T x) {
  if (n == nullptr) {
    return nullptr; // base case
  }
  Node* t = recurse(n->next, x); // first node with list of no x's
  if (n->data != x) {
    n->next = t;
    return n;
  } else {
    delete n;
    return t;
  }
}

template <typename T> void slist<T>::reverse() {
  if (head_ == nullptr) {
    return;
  }
  Node* prev = nullptr;
  Node* current = nullptr;
  Node* next = nullptr;
  current = head_;
  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head_ = prev;
}

// constructor
template <typename T> slist<T>::slist() : head_(nullptr) {}

// deconstructor
template <typename T> slist<T>::~slist() {
  Node* n = head_;
  while (n != nullptr) {
    Node* next = n->next;
    delete n;
    n = next;
  }
}

template <typename T> int slist<T>::size() {
  Node* n = head_;
  int count = 0;
  while (n != nullptr) {

    count++;
    n = n->next;
  }
  return count;
}

template <typename T> void slist<T>::push_front(T x) {
  head_ = new Node(x, head_);
}

template <typename T> void slist<T>::pop_front() {
  if (head_ != nullptr) // same as if(head==nullpointer)
  {
    Node* p = head_->next;
    delete head_;
    head_ = p;
  }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, slist<T>& list) {
  const typename slist<T>::Node* node = list.head();
  while (node) {
    os << node->data << "  ";
    node = node->next;
  }
  return os;
}

template <typename T> void slist<T>::push_back(T x) {
  Node* n = new Node(x, nullptr);
  if (head_ == nullptr) {
    head_ = n;
  } else {
    tail()->next = n;
  }
}

template <typename T> void slist<T>::pop_back() {
  Node* t = tail();
  if (head_ == t) {
    delete t;
    head_ = nullptr;
  } else if (head_ != nullptr) {
    Node* n = head_;
    cout << "head_ = " << head()->data << endl;

    cout << "tail_ = " << tail()->data << endl;
    cout << "check1" << endl;
    while (n->next != t) {
      cout << "test" << endl;
      n = n->next;
    }
    delete t;
    n->next = nullptr;
    cout << "check2" << endl;
  }
}

#endif // _S16_SLIST_H__