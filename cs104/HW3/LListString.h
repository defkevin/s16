#ifndef LLISTSTRING_H
#define LLISTSTRING_H
#include <list>
#include <string>

using std::string;

class LListString {
public:
  /**
   * Default constructor - default to a list of capacity = 10
   */
  LListString() : head_(nullptr), tail_(nullptr) {}

  /**
   * Destructor
   */
  ~LListString() {
    while (head_ != nullptr) {
      Node* temp = head_->next;
      delete head_;
      head_ = temp;
    }
  }

  /**
    * Copy constructor
    */
  LListString(const LListString& other);

  /**
   * Assignment Operator
   */
  LListString& operator=(const LListString& other);

  /**
   * Standard List interface
   */

  void clear();

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
  void insert(int pos, const string& val);

  void push_front(string value);

  /**
   * Removes the value at index, pos
   */

  void push_back(string value);
  void pop_front();
  void pop_back();
  void remove(int pos);

  /**
   * Overwrites the old value at index, pos, with val
   */
  void set(int position, const string& val);

  /**
   * Returns the value at index, pos
   */
  string& get(int position);

  /**
   * Returns the value at index, pos
   */
  string const& get(int position) const;

  void print();

private:
  struct Node {
    Node(string v, Node* n, Node* p) : val(v), next(n), prev(p) {}
    string val;
    Node* next;
    Node* prev;
  };

  // Get the ith Node.
  Node* getNodeAt(int i);

  /* Add necessary data members here */
  Node* head_;
  Node* tail_;
  int size_;
};

#endif
