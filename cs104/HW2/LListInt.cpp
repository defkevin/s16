#include "LListInt.h"
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

int LListInt::size() const {
  Node* temp = head_;
  int counter = 0;
  while (temp != nullptr) {
    temp = temp->next;
    counter++;
  }
  return counter;
}

bool LListInt::empty() const { return head_ == nullptr; }

LListInt::Node* LListInt::getNodeAt(int i) {
  int s = size();
  assert(i < s);
  Node* n = head_;
  int count = 0;
  while (count != i) {
    count++;
    n = n->next;
  }
  return n;
}

int& LListInt::get(int position) {
  int count = 0;
  int s = size();
  assert(position < s);
  Node* n = head_;
  while (count != position) {
    count++;
    n = n->next;
  }
  return n->val;
}

int const& LListInt::get(int position) const {
  int count = 0;
  int s = size();
  assert(position < s);
  Node* n = head_;
  while (count != position) {
    count++;
    n = n->next;
  }
  return n->val;
}

void LListInt::insert(int pos, const int& val) {
  if (pos > size() || pos < 0) {
    cout << "Number cannot be inserted since it is out of range." << endl;
    return;
  }
  if (pos == 0) {
    push_front(val);
  } else if (pos == size()) {
    push_back(val);
  } else {

    Node* p = getNodeAt(pos - 1);
    Node* n = p->next;
    Node* node = new Node(val, n, p);
    p->next = n->prev = node;
  }
}

void LListInt::push_front(int value) {
  Node* front = new Node(value, head_, nullptr);
  if (head_ != nullptr) {
    head_->prev = front;
    head_ = front;
  } else {
    head_ = tail_ = front;
  }
}

void LListInt::pop_front() {
  if (empty()) {
    return;
  } else if (size() == 1) {
    delete head_;
    head_ = tail_ = nullptr;
  } else {
    Node* newHead = head_->next;
    delete head_;
    newHead->prev = nullptr;
    head_ = newHead;
  }
}

void LListInt::pop_back() {
  if (empty()) {
    return;
  } else if (size() == 1) {
    delete tail_;
    tail_ = head_ = nullptr;
  } else {
    Node* newTail = tail_->prev;
    delete tail_;
    newTail->next = nullptr;
    tail_ = newTail;
  }
}

void LListInt::remove(int pos) {
  if (pos < 0 || pos > size() || size() == 0) {
    cout
        << "Number cannot be removed since it is out of range or already empty."
        << endl;
    return;
  } else if (pos == 0) {
    pop_front();
  } else if (pos == size() - 1) {
    pop_back();
  } else {
    Node* nodeToRemove = getNodeAt(pos);
    Node* next = nodeToRemove->next;
    Node* prev = nodeToRemove->prev;
    prev->next = next;
    next->prev = prev;
    delete nodeToRemove;
  }
}

void LListInt::push_back(int value) {
  Node* last = new Node(value, nullptr, tail_);
  if (tail_ != nullptr) {
    tail_->next = last;
    tail_ = last;
  } else {
    head_ = tail_ = last;
  }
}

void LListInt::print() {
  Node* temp = head_;
  if (head_ == nullptr || tail_ == nullptr) {
    cout << "Empty List" << endl;
  }
  while (temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}
