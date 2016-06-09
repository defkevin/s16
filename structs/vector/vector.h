#ifndef _S16_VECTOR_H__
#define _S16_VECTOR_H__

class IntVector {
public: 
	IntVector();
	~IntVector();
	void push_back(int n);
	void pop_back();

	int operator[](int i);
	int size();

private:
	int* data_;
	int length;
	int reserve;	
}}

#endif  _S16_VECTOR_H__