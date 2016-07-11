#include <iostream>
#include <vector>
using namespace std;

vector<int> a(300);

void initilizeArray(){
	for(int i = 0; i<a.size();i++){
		a[i] = 0;
	}
	a[0] = 1;
}

// 

void print(){
	int first = a.size()-1;
	while(a[first]== 0){
		first--;
	}
	for(int i = first; i>=0; i--){
		 cout << a[i] << "";
	}
	cout <<endl;
}

void multiply(int x){
	int carry =0;
	for(int i =0;i<a.size();i++){
		int temp = a[i]*x + carry;
		a[i] = temp%10;
		carry = temp/10;
	}
}

void factorial(int n){
	for(int i = 2;i<=n;i++){
		multiply(i);
	}
	cout << "Factorial of " << n << " is: "<<endl;
	print();
}

int sum(){
	int sum = 0;
	for(int i =0;i <a.size();i++){
		sum = sum +a[i];
	}
	return sum;
}

int main() {
	initilizeArray();
	factorial(100);
	cout << sum() <<endl;
}