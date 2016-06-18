#ifndef _S16_VECTOR_H__
#define _S16_VECTOR_H__

#include <cstddef> 

template <typename T>
class vector {
public: 
	vector();
	~vector();
	void push_back(T n);
	void pop_back();

	T& operator[](int i);
	int size() { return size_;}
	int capacity() {return capacity_;}
	T& back() { return data_[size_ -1]; }
	bool empty() {return size()==0;}

private:
	T* data_;
	int size_; // current size
	int  capacity_;	// num elements allocated
};

template <typename T>
vector<T>::vector() {
	data_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

template <typename T>
vector<T>::~vector() {
	delete[] data_;
}

template <typename T>
T& vector<T>::operator[](int i){
	return data_[i];
}

template <typename T>
void vector<T>::push_back(T n){
	
	if(!data_){
	data_ = new T[1]; 
	capacity_ = 1; 
	}
	else if(size_ == capacity_){
		// Add some room for new element by doubling the size
		capacity_*=2; // capacity*=2
		T* new_data = new T[capacity_];
		// Copy old data to new data
		for(int i = 0; i <size_;i++){
			new_data[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data;
	}
	data_[size_] = n;
	size_++;
}
template <typename T>
void vector<T>::pop_back(){
	size_--;
	//delete data_[size_];
}


#endif // _S16_VECTOR_H__