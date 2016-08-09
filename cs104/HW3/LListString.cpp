#include "LListString.h"
#include <cassert>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

LListString::LListString(const LListString& other) {
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;

  Node* node = other.head_;
  while (node) {
    push_back(node->val);
    node = node->next;
  }
}

LListString& LListString::operator=(const LListString& other) {
  if (this == &other)
    return *this;

  if (!empty())
    clear();

  Node* node = other.head_;
  while (node) {
    push_back(node->val);
    node = node->next;
  }
  return *this;
}

void LListString::clear() {
  while (head_ != nullptr) {
    Node* temp = head_->next;
    delete head_;
    head_ = temp;
  }
  size_ = 0;
}

int LListString::size() const { return size_; }

bool LListString::empty() const { return head_ == nullptr; }

LListString::Node* LListString::getNodeAt(int i) {
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

string& LListString::get(int position) {
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

string const& LListString::get(int position) const {
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

void LListString::insert(int pos, const string& val) {
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
    size_++;
  }
}

void LListString::push_front(string value) {
  Node* front = new Node(value, head_, nullptr);
  size_++;
  if (head_ != nullptr) {
    head_->prev = front;
    head_ = front;
  } else {
    head_ = tail_ = front;
  }
}

void LListString::pop_front() {
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
  size_--;
}

void LListString::pop_back() {
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
  size_--;
}

void LListString::remove(int pos) {
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
    size_--;
  }
}

void LListString::push_back(string value) {
  Node* last = new Node(value, nullptr, tail_);
  size_++;
  cout << "INSERTED! Size: " <<size_ <<endl;
  if (tail_ != nullptr) {
    tail_->next = last;
    tail_ = last;
  } else {
    head_ = tail_ = last;
  }
}

void LListString::print() {
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
