#ifndef _S16_HASH_MAP_H_
#define _S16_HASH_MAP_H_

#include "./vector.h"
#include "./slist.h"
#include "./key_value.h"
#include <ostream>
using std::string;

unsigned int DJBHash(const string& str) {
   unsigned int hash = 5381;

   for(int i = 0; i < str.size(); i++) {   
      hash = ((hash << 5) + hash) + str[i];
   }   

   return hash;
}

template <typename V> 
class hash_map {
public:
  hash_map() { }
  ~hash_map() { }

  V* find(std::string k);  
  bool insert(std::string k, V v);  

private:
  typedef key_value<string, V> KV;
  typedef slist<KV> ListType;

  vector<ListType> c_;
};

template <typename V>
    bool hash_map<V>::insert(string key, V value){
    int bucket = DJBHash(key) % c_.size();
    (ListType& )list = c_[bucket];

    // Go through list and see if list contains key
    typename ListType::Node* node = list.head();
    while(node!=nullptr){
      if(node->data().key == key){
        return false;
      }
      node = node->next;
    }
    c_.push_front(value);
    return true;
}


template <typename V>
    V* hash_map<V>::find(string key){
    int bucket = DJBHash(key) % c_.size();
    ListType& list = c_[bucket];

    // Go through list and see if list contains key
    typename ListType::Node* node = list.head();
    while(node!=nullptr){
      if(node->data().key == key){
        return &node->data_.value;
      }
      node = node->next;
    }
    return nullptr;
}

#endif // _S16_HASH_MAP_H_