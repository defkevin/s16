#ifndef _S16_HASH_MAP_H_
#define _S16_HASH_MAP_H_

#include "./vector.h"
#include "./slist.h"
#include "./key_value.h"
#include <string>
#include <ostream>

unsigned int DJBHash(const std::string& str) {
   unsigned int hash = 5381;

   for(int i = 0; i < str.size(); i++) {   
      hash = ((hash << 5) + hash) + str[i];
   }   

   return hash;
}

template <typename V> 
class hash_map {
public:
  hash_map(int n) {
    v_.resize(n);
  }
  ~hash_map() { }

  V& operator[](std::string key);  
  V* find(std::string key);

private:
  typedef key_value<std::string, V> KV;
  typedef slist<KV> ListType;

  vector<ListType> v_;
};

template <typename V>
V& hash_map<V>::operator[](std::string key){
  int bucket = DJBHash(key)%v_.size();
  ListType& list = v_[bucket];

  typename ListType::Node* node = v_[bucket].head();
  while(node!=nullptr){
    if(node->data.key== key){
      return node->data.value;
    }
    node = node->next;
  }
  list.push_front(KV(key, V()));
    return list.head()->data.value;
}

template <typename V>
V* hash_map<V>::find(std::string key){
  int bucket = DJBHash(key)%v_.size();
  ListType& list = v_[bucket];

  typename ListType::Node* node = v_[bucket].head();
  while(node!=nullptr){
    if(node->data.key== key){
      return &node->data.value;
    }
    node = node->next;
  }
  return nullptr;
}

#endif // _S16_HASH_MAP_H_