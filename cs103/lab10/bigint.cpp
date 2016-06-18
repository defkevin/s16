#include "bigint.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

BigInt::BigInt(string s){
	for(int i = 0; i <s.size(); i++){
		int digit = s[i] - '0';
		v.push_back(digit);
	}
	reverse(v.begin(), v.end());
}

string BigInt::to_string(){
	int size = v.size();
	string str;
	for(int i = 0; i<size;i++){
		int value = v[size-i-1];	
		std::string s = std::to_string(value);
		str.append(s);
	}
	return str;
}

void BigInt::add(BigInt b){
	cout << "Adding: " <<endl;
	cout << "A: " << to_string() << endl;
	cout << "B: " << b.to_string() <<endl;

	int bsize = b.to_string().size();
	int asize = to_string().size();
	// line up with zeroes
	if(bsize>asize){ // b is longer
		int zeroes = bsize-asize;
		for(int i = 0;i<zeroes;i++){
			v.push_back(0);
		}
	}
	else{
		int zeroes = asize-bsize;
		for(int i = 0;i<zeroes;i++){
			b.v.push_back(0);
		}
	}
	int remainder = 0;
	for(int i =0;i <b.v.size();i++){
		v[i] = b.v[i]+ v[i] + remainder;
		cout << "Remainder is " <<remainder <<endl;
		if(v[i]>=10){
			v[i] = v[i]%10;
			remainder = 1;
		}
		else{
			remainder =0;
		}
	}
	if(remainder==1){
		v.push_back(1);
	}
	cout << "Answer: " <<endl;
	cout << to_string() << endl;

}

// int main(){
// 	BigInt big("10000");
// 	BigInt bigger("01");
// 	big.add(bigger);
// 	//cout << big.to_string() << endl;
// 	return 0;
// }