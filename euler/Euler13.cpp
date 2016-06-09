/* 
	Work out the first 10 digits of the sum of the following one-hundred 50-digit numbers
*/ 

	#include <iostream>
	#include <fstream>
	#include <string>
	#include <sstream>
	#include <math.h>
	#include <iomanip>
	using namespace std;

	long double totalSum = 0;

	int calculateNumDigits(long double x){
		int counter = 0;
		while(x!=0){
			if(x<10){
				x= (int) x;
			}
			//cout << x << endl;
			x/=10;
			counter++;
		}
		//cout << counter -1<< " digits." <<endl;
		return counter -1 ; //excess count
	}

	int readLine(){
		string line;
		ifstream myfile ("e13.txt");
		if(!myfile){
			cout << "Text not found " <<endl;
		}
		while(getline(myfile, line)){
		//	cout << line <<endl;
			long double num = 0;
			stringstream convert(line);
			convert >> num;
		//	cout << num <<endl;
			totalSum+=num;
		}
		//cout << totalSum << endl;
		int numDigits = calculateNumDigits(totalSum);
		for(int i = 0; i<numDigits-10;i++){
			totalSum/=10;
		}
		totalSum = (long ) totalSum;
		cout << fixed << setprecision(0)<<totalSum <<endl;
		return 1;
	}

	

	int main(){
		readLine();
		return 0;
	}