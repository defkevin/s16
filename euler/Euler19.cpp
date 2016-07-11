#include <iostream>
using namespace std;

int daysinmonth(int month, int year){
	if(month == 4 || month ==6 || month ==9 || month ==11){
		return 30;
	}
	else if(month==2){
			if( (year%4==1000) || ((year%4==0) &&(year%100!=0)) ){
				return 29;
			}
			else{
				return 28;
			}
		}
	return 31;
	}

int calculateSundays(){
	int startyear = 1900;
	int endyear = 2000;
	int startmonth = 1; 
	int endmonth = 12;
	int sundaycount = 0;
	int day =1;
	for(int y = startyear;y<=endyear;y++){
		for(int m = startmonth;m<=endmonth;m++){
			if(day%7==0 &&y>1900){
				cout << "day: " << day << " month: " <<m <<" year: " <<y <<endl;
				cout << "IT IS A FIRST SUNDAY!"<<endl <<endl;
				sundaycount++;
			}
			day += daysinmonth(m,y);
			
		}
	}
	cout << endl <<endl;
	return sundaycount;
}

int main(){
	cout << calculateSundays();
}