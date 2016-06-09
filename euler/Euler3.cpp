#include <iostream>
#include <cmath> 
using namespace std;

bool isPrime(int x){
	int y = sqrt(x) +1;
	for(int i = 2; i<y;i++){
		if(x%i ==0){
			return false;
		}
	}
	return true;
}

int nextLargestPrime(int prime){
	int x = prime++;
	while(!isPrime(x)){
		x++;
	}
	return x;
}

int largestPrimeFactor(int input){
	int largestPrime = 1;
	int maxFactor = sqrt(input) +1;
	// while(tempPrime < (sqrt(input) +1)){
	// 	cout << "TempPrime: " << tempPrime << endl;
	// 	tempPrime = nextLargestPrime(tempPrime);
	// 	cout << "Next Largest Prime " << endl;
	// 	if(input%tempPrime==0){
	// 		cout << largestPrime <<endl;
	// 		largestPrime = tempPrime;
	// 	}
	// 	cout << tempPrime << endl;
	// }
	for( int i = 1; i <=maxFactor; i++){
		if(isPrime(i) == true && input%i==0){
				largestPrime = i;
			}
		}
	return largestPrime;
}

int main(){
	cout << largestPrimeFactor(13195) <<endl;
}