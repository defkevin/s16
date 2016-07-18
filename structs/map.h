#ifndef _S16_map_H__
#define _S16_map_H__

#include "./dlistNico.h"
#include "./key_value.h"
#include <iostream>

using std::cout;
using std::endl;

template <typename K, typename V> class map { // map is a container adapter

public:
  map() {}
  ~map() {}
  class iter {
  public:
    iter() : node_(nullptr) {}
    iter(typename dlist<key_value<K, V> >::Node* n) : node_(n) {}
    ~iter() {}
    bool operator==(const iter& other) { return node_ == other.node_; }
    bool operator!=(const iter& other) { return node_ != other.node_; }
    key_value<K, V>& data() { return node_->value; }
    iter next() { return iter(node_ != nullptr ? node_->next : nullptr); }

  private:
    typename dlist<key_value<K, V> >::Node* node_;
  };

  iter begin();   // construct an iterator to the first element
  iter end();     // construct an iterator one past the last element
  iter find(K x); // return iterator with value x
  bool remove(iter it);
  iter insert(key_value<K, V> kv); // insert x and return the iter for x. Return
                                   // end() if already in map
  int size() { return c_.size(); }

  bool empty() { return c_.empty(); }

private:
  dlist<key_value<K, V> > c_;
};

template <typename K, typename V> typename map<K, V>::iter map<K, V>::begin() {
  return iter(c_.head());
}

template <typename K, typename V> typename map<K, V>::iter map<K, V>::end() {
  return iter(nullptr);
}

template <typename K, typename V>
typename map<K, V>::iter map<K, V>::find(K key) {
  iter i = begin();
  while (i != end()) {
    if (i.data().key == key) {
      return i;
    }
    i = i.next();
  }
  return end();
}

template <typename K, typename V>
typename map<K, V>::iter map<K, V>::insert(key_value<K, V> kv) {
  iter i = find(kv.key);
  if (i != end()) { // WE FOUND x
    return i;
  } else {
    c_.push_back(kv);
    return iter(c_.tail());
  }
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, map<K, V>& m) {
  typename map<K, V>::iter i = m.begin();
  while (i != m.end()) {
    os << i.data().key << "-->" << i.data().value;
    i = i.next();
    cout << "    ";
  }
  os << endl;
  return os;
}

#endif // _S16_map_H__
