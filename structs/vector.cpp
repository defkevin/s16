#include "vector.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template<typename T>
void print(vector<T>& v){
	cout << "Back: "<<  v.back() << endl;
	cout << "Size: "<<v.size() << endl;
	cout << "Capacity: "<<v.capacity() << endl;
	cout << "Elements: " <<  " ";

	for(int i = 0; i<v.size();i++){
		cout << v[i] <<" ";
	}
	cout <<endl <<endl;
}

int main(){
	vector<int> v;
	v.push_back(17);
	print(v);

	vector<double> vd; 
	vd.push_back(3.14);
		vd.push_back(5.5);
		print(vd);

	vector<string> vstr; 
	vstr.push_back("Daniel");
		vstr.push_back("Nico");
		print(vstr);


	return 0;
}