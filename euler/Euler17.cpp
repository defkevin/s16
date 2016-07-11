#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> numbers(1001);
vector<string>words(1001);

void initializeNumbers(){
	for(int i = 0; i<=1000;i++){
		numbers[i] = i;
	}
}

void printWords(){
	for(int i =0;i<1000;i++){
		cout << words[i] <<" ";
	}
	cout << "Done" <<endl;
	cout <<endl;
}

void initializeWords(){
	int counter = 0;
	string value;
	while(counter < 1002){
		int x = numbers[counter];
		if(x<20){
			if(x==19){
				value = "nineteen";
			}
			else if(x==18 ){
				value = "eighteen";
			}
			else if(x==17){
				value = "seventeen";
			}
			else if(x==16 ){
				value = "sixteen";
			}
			else if(x==15){
				value = "fifteen";
			}
			else if(x==14){
				value = "fourteen";
			}
			else if(x==13){
				value = "thirteen";
			}
			else if(x==12){
				value = "twelve";
			}
			else if(x==11){
				value = "eleven";
			}
			else if(x==10){
				value = "ten";
			}
			else if(x==9){
				value = "nine";
			}
			else if(x==8){
				value = "eight";
			}
			else if(x==7){
				value = "seven";
			}
			else if(x==6){
				value = "six";
			}
			else if(x==5){
				value = "five";
			}
			else if(x==4){
				value = "four";
			}
			else if(x==3){
				value = "three";
			}
			else if(x==2){
				value = "two";
			}
			else if(x==1){
				value = "one";
			}
			else{
				value = "zero";
			}
		}
		else if(x>=20 && x <=99){
			int temp = x/10;
			int remainder = x%10;
			if(remainder==9){
				value = "nine";
			}
			else if(remainder==8){
				value = "eight";
			}
			else if(remainder==7){
				value = "seven";
			}
			else if(remainder==6){
				value = "six";
			}
			else if(remainder==5){
				value = "five";
			}
			else if(remainder==4){
				value = "four";
			}
			else if(remainder==3){
				value = "three";
			}
			else if(remainder==2){
				value = "two";
			}
			else if(remainder==1){
				value = "one";
			}
			else{
				value = "";
			}
			//
			if(temp==9){
				value = "ninety" +value;
			}
			else if(temp==8){
				value = "eighty" +value;
			}
			else if(temp==7){
				value = "seventy"+value;
			}
			else if(temp==6){
				value = "sixty"+value;
			}
			else if(temp==5){
				value = "fifty"+value;
			}
			else if(temp==4){
				value = "fourty"+value;
			}
			else if(temp==3){
				value = "thirty"+value;
			}
			else if(temp==2){
				value = "twenty"+value;
			}
		}
		else if(x>=100 && x <=999){
			int hundreds = x/100;
			int temp = (x/10) %10;
			int remainder = x%10;
			int last2 = temp*10 +remainder;
			if(hundreds ==1){
				value = "onehundred";
			}
			else if(hundreds==2){
				value = "twohundred";
			}
			else if(hundreds==3){
				value = "threehundred";
			}
			else if(hundreds==4){
				value = "fourhundred";
			}
			else if(hundreds==5){
				value = "fivehundred";
			}
			else if(hundreds==6){
				value = "sixhundred";
			}
			else if(hundreds==7){
				value = "sevenhundred";
			}
			else if(hundreds==8){
				value = "eighthundred";
			}
			else if(hundreds==9){
				value = "ninehundred";
			}
			if(hundreds>=1 && (remainder!=0 || temp!=0)){
				value = value +"and";
			}

			if(last2<=19){
				if(last2==19){
					value = value +"nineteen";
				}
				else if(last2==18 ){
					value = value +"eighteen";
				}
				else if(last2==17){
					value = value +"seventeen";
				}
				else if(last2==16 ){
					value = value +"sixteen";
				}
				else if(last2==15){
					value = value +"fifteen";
				}
				else if(last2==14){
					value = value +"fourteen";
				}
				else if(last2==13){
					value = value +"thirteen";
				}
				else if(last2==12){
					value = value +"twelve";
				}
				else if(last2==11){
					value = value +"eleven";
				}
				else if(last2==10){
					value = value +"ten";
				}
				else if(last2==9){
					value = value +"nine";
				}
				else if(last2==8){
					value = value +"eight";
				}
				else if(last2==7){
					value = value +"seven";
				}
				else if(last2==6){
					value = value +"six";
				}
				else if(last2==5){
					value = value +"five";
				}
				else if(last2==4){
					value = value +"four";
				}
				else if(last2==3){
					value = value +"three";
				}
				else if(last2==2){
					value = value +"two";
				}
				else if(last2==1){
					value = value +"one";
				}
			}
			if(last2>=20){
				if(temp==9){
				value =  value+"ninety";
				}
				else if(temp==8){
					value = value+"eighty" ;
				}
				else if(temp==7){
					value = value+"seventy";
				}
				else if(temp==6){
					value = value+"sixty";
				}
				else if(temp==5){
					value = value+"fifty";
				}
				else if(temp==4){
					value = value+"fourty";
				}
				else if(temp==3){
					value = value+"thirty";
				}
				else if(temp==2){
					value = value+"twenty";
				}
			}
			if(last2>=20){
					if(remainder==9){
						value = value+"nine";
					}
					else if(remainder==8){
						value = value+"eight";
					}
					else if(remainder==7){
						value = value+"seven";
					}
					else if(remainder==6){
						value = value+"six";
					}
					else if(remainder==5){
						value = value+"five";
					}
					else if(remainder==4){
						value = value+"four";
					}
					else if(remainder==3){
						value = value+"three";
					}
					else if(remainder==2){
						value = value+"two";
					}
					else if(remainder==1){
						value = value+"one";
					}
					else{
						value = value+"";
					}
			}
			cout << value <<endl;
		}
		cout << counter <<endl;
		words[counter] = value;
		counter++;
	}
}

int main(){
	initializeNumbers();
	initializeWords();
	//printWords();
}