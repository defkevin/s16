#include <iostream> 
using namespace std; 

int fib(int max){
	int prevprev = 1; 
	int prev = 2; 
	int result = 0;;
	int sum = 2;

	while(result<max){
		result = prevprev + prev;
		prevprev = prev;
		prev = result; 
		if(result%2==0){
			sum = sum + result;
		}
	}
	return sum;
}

int main() {
	 cout << fib(4000000) <<endl;
}