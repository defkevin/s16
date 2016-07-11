#ifndef _S16_NODE_H__
#define _S16_NODE_H__

class Node{
	
public:
	Node(int x, Node* n) : value(x), next(n) {}
	int value; 
	Node* next;
};

#endif // _S16_NODE_H__