#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::endl;
using std::cout;

vector<int> a(500);

void initilizeArray(){
	for(int i = 0; i<a.size();i++){
		a[i] = 0;
	}
	a[0] = 1;
}

void timesTwo(){
	int carry = 0;
	for(int i = 0; i<500;i++){
		a[i] = 2*a[i] +carry;
		if(a[i]>=10){
			//cout << "greater than: " <<a[i] <<endl;
			carry = a[i]/10;
			a[i] = a[i]%10;
			//cout << "carry is " << carry <<endl;
		}
		else{
			carry = 0;
		}
		if(carry!=0){
			//cout << "CAarry is " << carry <<endl;
		}
	}
}

void print(){
	int first = a.size()-1;
	while(a[first]== 0){
		first--;
	}
	for(int i = first; i>=0; i--){
		 cout << a[i] << " ";
	}
	cout <<endl;
}

void multiply1000(){
	for(int i = 1; i<=1000;i++) {// 2^n 
		timesTwo();
		//print();
	}
}

int sum(){
	int sum = 0;
	for(int i =0;i <a.size();i++){
		sum = sum +a[i];
	}
	return sum;
}

int main(){
	initilizeArray();
	multiply1000();
	print();
	cout << sum() << endl;
}