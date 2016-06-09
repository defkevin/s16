#include <iostream> 
using namespace std; 

bool isDivisible(long x){
	if(x%11 == 0 && x%12 ==0 && x%13 == 0 && x%14 ==0 && x%15 ==0 && x%16 ==0 && x%17 ==0 && x%18==0 && x%19 ==0 && x%20==0){
		return true;
	}
	return false;
}

int getSmallestNumber(){
	long count = 20;
	while(!isDivisible(count)){
		if(count%100000==0){
			cout << count << endl;
	}
		count++;
	}
	return count;
}

int main(){
	cout << getSmallestNumber();
}