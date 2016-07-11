#include <iostream>
using namespace std;

const string ones[20] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
  "ten",
  "eleven",
  "twelve",
  "thirteen",
  "fourteen",
  "fifteen",
  "sixteen",
  "seventeen",
  "eighteen",
  "nineteen"
};

const string tens[10] = {
  "zero",
  "ten",
  "twenty",
  "thirty",
  "forty",
  "fifty",
  "sixty",
  "seventy",
  "eighty",
  "ninety"
};

string SpellNumber(int n) {
  if (n < 20) {
    return ones[n];
  }
  else if(n%1000 ==0){
    return ones[n/1000] + "thousand";
  }
  else if(n>1000){
    return ones[n/1000] + "thousandand";
  }
  else if(n%100 ==0){
    return ones[n/100] + "hundred";
  }
  else if(n>100){
    return ones[n/100] + "hundredand" +SpellNumber(n%100);
  }
  else if(n%10==0){
    return tens[n/10]; // REVIEW 
  }
  else if(n>=20 && n<=99){
    return tens[n/10] + ones[n%10];
  }
  return "";
}
    
int main() {
  int counter = 0;
  int longest =0;
  string longestword;
  for (int i = 1; i <= 1000; i++) {
    if(SpellNumber(i).length()>longest){
        longest = SpellNumber(i).length();
        longestword = SpellNumber(i);
    }
    counter = counter + SpellNumber(i).length();
    cout << SpellNumber(i) << " " <<SpellNumber(i).length()<< endl;
  }
  cout << counter <<endl;
  cout << "Longest word is " << longestword <<": " <<longest <<endl;
}