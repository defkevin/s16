#include <iostream>
#include <stdio.h>
#include <math.h>

using std::cout;
using std::endl;

double exp(double x){
	double sum = 0;
	double term =1; 
	for(int i = 1;i <30;i++){
		sum +=term;
		term*=x/i;
	}
	return sum;
}

