#include <iostream>
#include <math.h>

using namespace std;

int isPrime(int num){
	if(num<2)
		{
			return false;
		}
	if(num ==2)
		{
			return true;
		}

	if(num %2 == 0 || num %2 == 2 || num %2 == 4|| num %2 == 6|| num %2 == 8)
		{
			return false;
		}
	int max =((int) sqrt(num)) +1;
		for(int i = 3; i <max; i+=2)
		{
			if(num%i==0)
			{
				//System.out.println("Not Prime");
				return false;
			}
		}
		//System.out.println("Prime");
		return true;
}

double findNPrimes(int n){
	double largestPrime = 2;
	double sum = 2; // 2 because 2 is the first smallest prime number that we are not accounting for
	double value =1;
	while(value<n){
		if(isPrime(value)){
			//cout << value <<endl;
			sum+=value;
			largestPrime = value;
		}
		value = value +2;
	}
	return sum;
}

int main(){
	cout << "hello World" << endl;
	// cout << isPrime(23);
	 cout << findNPrimes(2000000) <<endl;
}