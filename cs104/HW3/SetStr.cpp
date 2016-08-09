#include "SetStr.h"
#include <iostream>
using namespace std;

SetStr::SetStr() {}

SetStr::~SetStr() {}

int SetStr::size() const { return list_.size(); }

bool SetStr::empty() const { return list_.empty(); }

bool SetStr::exists(const string& val) const {
  for (int i = 0; i < size(); i++) {
    cout << "i: " <<i <<endl;
    cout << "size: " <<size() <<endl;

    if (list_.get(i) == val) {
      return true;
    }
  }

  return false;
}

void SetStr::insert(const string& val) {
  cout << "Before Insert of " <<val << ": " << list_.size() <<endl;
  if (!exists(val)) {
    list_.push_back(val);
  }
  cout << "After Insert of " <<val << ": " << list_.size() <<endl;
}

void SetStr::remove(const string& val) {
  cout << "Before Remove of " <<val << ": " << list_.size() <<endl;

  for (int i = 0; i < size(); i++) {
    if (list_.get(i) == val) {
      list_.remove(i);
    }
  }
  cout << "After Remove of " <<val << ": " << list_.size() <<endl;

}

const string* SetStr::first() const {
  if (empty()) {
    return nullptr;
  } else {
    iterations_ = 1;
    return &list_.get(0);
  }
}

const string* SetStr::next() const {
  if (iterations_ < size()) {
    const string* val = &list_.get(iterations_);
    iterations_++;
    return val;
  } else {
    return nullptr;
  }
}

SetStr SetStr::setUnion(const SetStr& other) const {
  SetStr unionSet;
  unionSet.list_ = list_;
  const string* s = other.first();
  while (s != nullptr) {
    unionSet.insert(*s);
    s = other.next();
  }
  return unionSet;
}

SetStr SetStr::setIntersection(const SetStr& other) const {
  SetStr intersectionSet;
  const string* s = other.first();
  while (s != nullptr) {
    if (exists(*s)) {
      intersectionSet.insert(*s);
    }
    s = other.next();
  }
  return intersectionSet;
}

SetStr SetStr::operator|(const SetStr& other) const { return setUnion(other); }

SetStr SetStr::operator&(const SetStr& other) const {
  return setIntersection(other);
}