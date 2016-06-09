#include <iostream> 
using namespace std;



bool isPalindrome(string str){
	int length = str.length();
	int half = length/2;
	for(int i =0;i<=half;i++){
		cout << str[i] << " " << str[length-(i+1)] <<endl;
		if(str[i]!=str[length-(i+1)]){
			return false;
		}
	}
	return true;
}

int largestPalindrome(int x){
	int first = 999; 
	int second = 999; 
	int maxProd =1;
	int product;
	string str = to_string((first*second));
	while(!isPalindrome(str)) {
		for(int i = first; i>=100;i++){
		product = first*second;
		if(product>maxProd){
			maxProd = product;
		}
	}
	cout << "First is " << first << endl;
	cout << "Second is " << second << endl;
}
return product;
}

int main(){
	cout << largestPalindrome(100301);
}