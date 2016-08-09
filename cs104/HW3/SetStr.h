#ifndef SETSTR_H
#define SETSTR_H
#include "LListString.h"
#include <string>

class SetStr {
public:
  /**
   * Default constructor
   */
  SetStr(); // DONE

  /**
   * Destructor
   */
  ~SetStr(); // DONE

  /**
   * Returns the current number of items in the list
   */
  int size() const; // DONE

  /**
   * Returns true if the list is empty, false otherwise
   */
  bool empty() const; // DONE

  /**
   * Inserts val into the set, do nothing if val already exists
   */
  void insert(const std::string& val); // DONE

  /**
   * Removes the value from the set, does nothing if val does not exist
   */
  void remove(const std::string& val); // DONE

  /**
   * Returns true if the item is in the set
   */
  bool exists(const std::string& val) const; // DONE

  /**
   * Return a pointer to the first item
   *  and support future calls to next()
   */
  const std::string* first() const; // DONE

  /**
   * Return a pointer to the next item
   *  after the previous call to next
   *  and NULL if you reach the end
   */
  const std::string* next() const; // DONE

  /**
   * Returns another (new) set that contains
   * the union of this set and "other"
   */
  SetStr setUnion(const SetStr& other) const;

  /**
   * Returns another (new) set that contains
   * the intersection of this set and "other"
   */
  SetStr setIntersection(const SetStr& other) const;

  SetStr operator|(const SetStr& other) const;

  SetStr operator&(const SetStr& other) const;

private:
  LListString list_;

  // Data member can be modified within a const method
  // This is needed for first and next since they are
  // const methods that modify iterations_.
  mutable int iterations_;
};

#endif