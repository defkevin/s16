#ifndef _S16_hanoi_H__
#define _S16_hanoi_H__


#include "../structs/vector.h"
#include <iostream>

using namespace std;

struct Hanoi { 
	Hanoi(int size);
	vector<int> a;
	vector<int> b;
	vector<int> c; 
	int numMoves;
	int numDisks;
	void run();

	void print();
	void moveTower(int disk, vector<int>& source, vector<int>& dest, vector<int>& spare){
		if(disk==0){
			source.pop_back();
			dest.push_back(disk);
			numMoves++;
		}
		else{
			moveTower(disk-1,source,spare,dest);
			source.pop_back();
			dest.push_back(disk);
			numMoves++;
			moveTower(disk-1,spare,dest,source);
		}
	}
};

Hanoi::Hanoi(int size) {
	for(int i =size;i>=0;i--){
		a.push_back(i);
	}
}

// void Hanoi::run(){
// 	movetower(size,a,b,c);
// }

void Hanoi::print(){
	vector<int> a_cp(a);
	vector<int> b_cp(b);
	vector<int> c_cp(c);
	while(a_cp.size()!=6){
		a_cp.push_back(-1);
	}
	while(b_cp.size()!=6){
		b_cp.push_back(-1);
	}
	while(c_cp.size()!=6){
		c_cp.push_back(-1);
	}

	for(int i = 5;i>=0;i--){
		if(a_cp[i]!=-1){
			cout << a_cp[i] << "   |   ";
		}
		else{
			cout << " " << "   |   ";
		}
		if(b_cp[i]!=-1){
			cout << b_cp[i] << "   |   ";
		}
		else{
			cout << " " << "   |   ";
		}		
		if(c_cp[i]!=-1){
			cout << c_cp[i] << "   |   ";
		}
		else{
			cout << " " << "   |   " <<endl;
		}
	}
	cout << endl;
}

int main(){
	int size =5;
	Hanoi hanoi(size);
	hanoi.moveTower(size, hanoi.a, hanoi.b, hanoi.c);
	hanoi.print();
}
#endif // _S16_hanoi_H__
