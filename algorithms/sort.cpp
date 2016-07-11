#include <iostream>
#include <string>
#include "sort.h"

using namespace std;


int main(){
	string data[] = {"dog", "cat", "elephant", "zebra", "giraffe", "lion"};
	vector<string> v(data, data+sizeof(data)/sizeof(data[0]));
	printVector(v);
	quickSort(v, 0, v.size());
	printVector(v);
}