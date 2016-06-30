#ifndef _S16_listmap_H__
#define _S16_listmap_H__


#include "./dlistNico.h"
#include "./key_value.h"
#include <iostream>

using std::cout;
using std::endl;

template <typename K, typename V>
class listmap { // listmap is a container adapter

public:
	listmap() { }
	~listmap() { }
	class iter {
	public:
		iter(): node_(nullptr) {}
		iter(typename dlist<key_value<K,V> >::Node* n):node_(n){ }
		~iter(){}
		bool operator ==(const iter& other) {return node_==other.node_;}
		bool operator !=(const iter& other) {return node_!= other.node_;}
		key_value<K,V>& data() {return node_->value;}
		iter next(){ 
			return iter(node_!=nullptr ? node_->next: nullptr);
		}
	private:
		typename dlist<key_value<K,V> >::Node* node_;
	};

	iter begin(); // construct an iterator to the first element
	iter end(); // construct an iterator one past the last element 
	iter find(K x); // return iterator with value x
	bool remove(iter it);
	iter insert(key_value<K,V> kv); // insert x and return the iter for x. Return end() if already in listmap
	int size() {return c_.size();}
	
	bool empty() {return c_.empty();}


private:
	 dlist<key_value<K,V> > c_; 

};

template <typename K, typename V>
typename listmap<K,V>::iter listmap<K, V>::begin() {
	return iter(c_.head());
}

template <typename K, typename V>
typename listmap<K,V>::iter listmap<K, V>::end() {
	return iter(nullptr);
}

template <typename K, typename V>
typename listmap<K,V>::iter listmap<K,V>::find(K key) {
	iter i = begin();
	while(i!=end()){
		if(i.data().key == key){
			return i;
		}
		i = i.next();
	}
	return end();
}

template <typename K, typename V>
typename listmap<K,V>::iter listmap<K,V>::insert(key_value<K,V> kv) {
	iter i = find(kv.key);
	if(i!=end()){ // WE FOUND x
		return i;
	}
	else {
		c_.push_back(kv);
		return iter(c_.tail());
	}
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, listmap<K,V>& m){
	typename listmap<K,V>::iter i = m.begin();
	while(i!=m.end()){
		os << i.data().key << "-->" <<i.data().value;
		i = i.next();
		cout <<"    ";
	}
	os << endl;
	return os;
}


#endif // _S16_listmap_H__
