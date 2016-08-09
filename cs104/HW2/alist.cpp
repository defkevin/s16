#include "alist.h"
#include <cassert>
#include <list>
using std::list;
using std::cout;
using std::endl;

AListInt::AListInt() {
  capacity_ = 10;
  size_ = 0;
  data_ = new int[capacity_];
}

AListInt::AListInt(int cap) {
  capacity_ = cap;
  size_ = 0;
  data_ = new int[capacity_];
}

AListInt::~AListInt() {}

int AListInt::size() const { return size_; }

bool AListInt::empty() const {
  if (size_ == 0) {
    return true;
  } else {
    return false;
  }
}

void AListInt::insert(int pos, const int& val) {
  assert(pos >= 0 && pos <= size_);
  if (size_ == capacity_) {
    resize();
  } else if (pos < size_) {
    for (int i = size_ - 1; i >= pos; i--) {
      data_[i + 1] = data_[i];
    }
  }
  data_[pos] = val;
  size_++;
}

void AListInt::remove(int pos) {
  assert(pos >= 0 && pos <= size_);
  for (int i = pos; i < size_ - 1; i++) {
    data_[i] = data_[i + 1];
  }
  size_--;
}

void AListInt::set(int position, const int& val) {
  assert(position >= 0 && position <= size_);
  data_[position] = val;
}

int& AListInt::get(int position) {
  assert(position >= 0 && position <= size_);
  return data_[position];
}

const int& AListInt::get(int position) const {
  assert(position >= 0 && position <= size_);
  return data_[position];
}

void AListInt::print() const {
  for (int i = 0; i < size_; i++) {
    cout << data_[i] << " ";
  }
  cout << endl;
}
