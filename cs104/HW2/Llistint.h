#ifndef LLISTINT_H
#define LLISTINT_H
#include <list>

class LListInt {
public:
  /**
   * Default constructor - default to a list of capacity = 10
   */
  LListInt() : head_(nullptr), tail_(nullptr) {}

  /**
   * Destructor
   */
  ~LListInt() {
    while (head_ != nullptr) {
      Node* temp = head_->next;
      delete head_;
      head_ = temp;
    }
  }

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

  void push_front(int value);

  /**
   * Removes the value at index, pos
   */

  void push_back(int value);
  void pop_front();
  void pop_back();
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
  int const& get(int position) const;

  void print();

private:
  struct Node {
    Node(int v, Node* n, Node* p) : val(v), next(n), prev(p) {}
    int val;
    Node* next;
    Node* prev;
  };

  // Get the ith Node.
  Node* getNodeAt(int i);

  /* Add necessary data members here */
  Node* head_;
  Node* tail_;
};

#endif
