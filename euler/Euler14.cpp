#include <iostream>
using namespace std;

long arr[1000000];

long Collatz(long first){
	long temp = first;
	long counter = 0;
	while(temp!=1){
		if(temp<first){
			counter = counter + arr[temp];
			// cout << "counter: " << counter <<endl;
			// cout << "arr[temp]: " << arr[temp] <<endl;
			return counter;
		}
		 if(temp%2==0){
			temp= temp/2;
			// cout << "divide by 2, temp: "<<temp <<endl;
			counter++;
		}
		else{
			temp = 3*temp +1;
			// cout << "multiply by 3+1, temp: "<<temp <<endl;
			counter++;
		}
	}
	return counter;
}

long findMax(){
	long largest = 0;
	for(long i =1;i<1000000;i++){
		// cout << "Find max of: "<< i <<endl;
		// if(i%100 ==0){
		// 	cout << i <<endl;
		// }
		long size =Collatz(i);
		arr[i] = size;
		if(size>largest){
			largest = size;
		}
	}
	return largest;
}

int main(){
	cout <<findMax();
	return 0;
}