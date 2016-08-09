#ifndef ALISTINT_H
#define ALISTINT_H

#include <iostream>
#include <list>
using std::list;

class AListInt {
public:
  /**
   * Default constructor - default to a list of capacity = 10
   */
  AListInt();

  /**
   * Another constructor - default to a list to the indicated capacity
   */
  AListInt(int cap);

  /**
   * Destructor
   */
  ~AListInt();

  /**
   * Standard List interface
   */

  /**
   * Returns the current number of items in the list
   */
  int size() const;

  /**
   * Returns true if the list is empty, false otherwise
   */
  bool empty() const;

  /**
   * Inserts val so it appears at index, pos
   */
  void insert(int pos, const int& val);

  /**
   * Removes the value at index, pos
   */
  void remove(int pos);

  /**
   * Overwrites the old value at index, pos, with val
   */
  void set(int position, const int& val);

  /**
   * Returns the value at index, pos
   */
  int& get(int position);

  /**
   * Returns the value at index, pos
   */
  const int& get(int position) const;

  void print() const;

private:
  /**
   * Should double the size of the list maintaining its contents
   */
  void resize() {
    capacity_ = capacity_ * 2;
    int* a = new int[capacity_];
    for (int i = 0; i < size_; i++) {
      a[i] = data_[i];
    }
    delete[] data_;
    data_ = a;
  }

  /* Add necessary data members here */

  int* data_;
  int size_;     // current number of elements
  int capacity_; // how much space is allocated
};

#endif