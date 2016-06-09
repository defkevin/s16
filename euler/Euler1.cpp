#include <iostream>
using namespace std;

int sumOfMultiples(int x){
	int sum = 0;
	for(int i = 3;i <x; i++){
		if((i%3 == 0) || (i%5==0)){
			sum = sum +i;
			//cout << i<< endl;
		}
	}
	cout << sum <<endl;
	return sum;
}

int main(){
	sumOfMultiples(1000);
}