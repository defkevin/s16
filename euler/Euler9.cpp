#include <iostream>

using namespace std;

bool findSum(int n, int m, int d){
	
	int a = d*(n*n -m*m);
	int b = 2*d*n*m;
	int c = d*(n*n + m*m);

	int sum = a+b+c;
	
	cout << "Sum is " << sum <<endl;
	if(1000%sum==0){
		int multiple = 1000/sum;
		a = a*multiple;
		b = b*multiple; 
		c = c*multiple;
		sum = 1000;
	}
	if(sum == 1000){
			cout << "A is " << a <<endl;
	cout << "B is " << b <<endl;
	cout << "C is " << c << endl;
	cout << "sum is " << a+b +c <<endl;
	cout << "Product is " << a*b*c <<endl;
		return true;
	}
	return false;
}

void tryNumbers(){
	int m =1;
	int n =2;
	int d =1;
	for(int i = 0; i<15; i++){
			cout << "A is " << n*n -m*m <<endl;
	cout << "B is " << 2*n*m <<endl;
	cout << "C is " << n*n + m*m << endl;

		if(findSum(n,m,d)){
			break;
		}
		n++;
	
	}
}

int main(){
	tryNumbers();
}

