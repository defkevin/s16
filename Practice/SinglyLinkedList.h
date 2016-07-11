#ifndef _S16_Singly_H__
#define _S16_Singly_H__

#include <iostream>
#include "Node.h"
using std::cout;
using std::endl;

class SLL{

public: 
	SLL();
	~SLL();
	void push_back(int x);
	void pop_back();
	void push_front(int x);
	void pop_front();
	void reverse();
	
	int size();
	Node* head() {return head_;}
	Node* tail();

	int sum();

	void print();


protected:
	Node* head_;

};

SLL::SLL(): head_(nullptr) {}

SLL::~SLL(){
	Node* n = head_;
	while(n!=nullptr){
		Node* next = n->next;
		delete n;
		n = next;
	}
}

void SLL::print(){
	if(head_==nullptr){
		cout << "Empty List." <<endl;
	}
	else{
		Node*h = head_;
		while(h!=nullptr){
			cout << h->value <<"--> ";
			h = h->next;
		}
		cout << "nullptr" <<endl;
	}
}

Node* SLL::tail(){
	if(head_==nullptr){
		return nullptr;
	}
	Node* n = head_;
	while(n!=nullptr){
		n = n->next;
	}
	return n;
}

void SLL::push_back(int x){
	Node *n = new Node(x, nullptr);
	if(head_==nullptr){
		head_ = n;
	}
	else{
		tail()->next = n;
	}
}

void SLL::push_front(int x){
	head_ = new Node(x, head_);
}

void SLL::pop_back(){
	Node* t = tail();
	if(head_==t){
		delete t;
		head_ = nullptr;
	}
	else if(head_!=nullptr){
		Node* h = head_;
		while(h->next!=nullptr){
			h = h->next;
		}
		h->next = nullptr;
		delete t;
	}
}
// void SLL:pop_back(){
// 	Node* n = tail();

// }







#endif // _S16_Singly_H__