#include <iostream>

using namespace std;

int fib(int max){
	int sum;
	if(max==0){
		sum = 0;
		return sum;
	}
	if(max==1){
		sum = 1;
		return 1;
	}
	else{
		sum = 2;
	}
	int prevPrev = 1;
	int prev = 2; 
	int result = 0;
	while(result<=max){
		// cout << "BPrevPrev: " <<prevPrev <<endl;
		// cout << "Bprev: " <<prev <<endl;
		// cout << "Bresult: " <<result <<endl;
		result = prev + prevPrev;
		prevPrev = prev;
		prev = result;
		
		// cout << "PrevPrev: " <<prevPrev <<endl;
		// cout << "prev: " <<prev <<endl;
		// cout << "result: " <<result <<endl;

		if(prev%2==0){
			sum +=prev;
			cout << "sum is " <<sum <<endl;
		}
		cout << endl << endl;
	}
	return result;
}

int main(){
	fib(4000000);
}