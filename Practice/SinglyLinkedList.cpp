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
	int pop_back();
	void push_front();
	int pop_front(int x);
	void reverse();
	
	int size();
	Node* head() {return head_;}
	Node* tail();

	int sum();

	void print();


protected:
	Node* head_;

};

void SLL::push_back(int x){
	cout << "Hello" <<endl;
}






#endif // _S16_Singly_H__