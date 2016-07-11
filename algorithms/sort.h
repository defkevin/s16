#ifndef _S16_SORT_H_
#define _S16_SORT_H_

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; 
using std::endl;
using std::swap;
using std::vector;

template <typename T>
void bubbleSort(vector<T>& v){
	int size = v.size();
	for(int i = size-1;i>0;i--){
		for(int j =0;j<i;j++){
			if(v[j]>v[j+1]){
				swap(v[j],v[j+1]);
			}
		}
	}
}

template <typename T>
void printVector(vector<T>& v){
	for(int i =0;i<v.size();i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename T>
void selectionSort(vector<T>& v){
	int size = v.size();
	for(int i =0;i<size;i++){
		int minIndex = i;
		for(int j = i+1; j<size;j++){
			if(v[j]<v[minIndex]){
				minIndex = j;
			}
		}
		cout << "minindex: " << minIndex <<endl;
		if(v[minIndex]<v[i]){
			swap(v[i],v[minIndex]);
		}
		printVector(v);
	}
}

template <typename T>
void insertionSort(vector<T>& v){
	int size = v.size();
	for(int i = 1; i <size;i++){
		int element = v[i];
		int j = i;
		while(j>0 && v[j-1]>element){
			v[j] = v[j-1];
			j = j-1;
		}
		v[j] = element;
	}
}

template <typename T> 
void print(vector<T>& v, int left, int right){
	if(left<=right){
		for(int i = left; i<=right;i++){
			cout <<v[i] <<" ";
		}
		cout << endl;
	}
}

hello my name is kevin
nivek si eman ym olleh
kevin is name my hello 

template <typename T>
void merge(vector<T> &arr, int left, int middle, int right){
	vector<T> leftarray(middle - left + 1);
	vector<T> rightarray(right - middle);

	for(int i = left; i<=middle; i++){
		leftarray[i - left] = arr[i];
	}
	for(int i = middle+1; i<=right;i++){
		rightarray[i - (middle+1)] = arr[i];
	}

	int i = 0;
	int j = 0;
	int k = left;

	while(i<leftarray.size() && j< rightarray.size()){
		if(leftarray[i]<=rightarray[j]){
			arr[k] = leftarray[i];
			i++;
		} else{
			arr[k] = rightarray[j];
			j++;
		}
		k++;
	}

	while(i<leftarray.size()){
		arr[k] = leftarray[i];
		i++;
		k++;
	}

	while(j<rightarray.size()){
		arr[k] = rightarray[j];
		j++;
		k++;
	}
}


template <typename T>
void mergeSortRange(vector<T>& arr, int left, int right){
	if (left<right){
		cout << "Before merge: ";
		print(arr, left, right);
		int middle = (left + right)/2;
		mergeSortRange(arr, left, middle);
		mergeSortRange(arr, middle+1, right);
		merge(arr, left, middle, right);
		cout << "After merge: ";
		print(arr, left, right);
	}
	else if(left == right){
		print(arr, left, right);
	}
}

template <typename T>
int partition(vector<T>&v, const int left, const int right){
	const int mid = left + (right -left)/2; // shorthand to prevent overflow
	const T pivot = v[mid]; // setting the pivot as the middle index
	swap(v[mid],v[left]); // swapping middle index (pivot) with the first value 
	int i = left + 1; // i is one index greater than pivot
	int j = right;
	while(i<=j){ // keep going until i and j meet or intersect
		while(v[i]<=pivot && i<=j){
			i++; // keep incrementing i until v[i] is greater than pivot value 
		}
		while(v[j]>pivot && i<=j){
			j--; // keep decrementing j until v[j] is less than pivot value 
		}
		if(i<j){
			swap(v[i],v[j]); // swap the v[i] that is greater than pivot value
								// and the v[j] that is less than pivot value 
								// if index i is less than j
		}
	}
	swap(v[i-1], v[left]); // swap the left value (pivot) with the value [i-1], which is guaranteed less than pivot
	return i-1; // return position of pivot
}

template <typename T>
void print(vector<T>& v){
	for(int i = 0;i<v.size();i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename T> 
void quickSort(vector<T>& v, int left, int right){
	if(left>=right){
		return;
	}
	int part = partition(v, left, right);
	quickSort(v, left, part-1);
	quickSort(v, part+1, right);
}




template<typename T>
void mergeSort(vector<T> & v){
	mergeSortRange(v, 0, v.size()-1);
}

#endif // _S16_SORT_