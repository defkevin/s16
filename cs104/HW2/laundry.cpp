#include "stackint.h"
#include <fstream>
#include <iostream>

using namespace std;

void readStack(const char* filename, const char* output, StackInt& x) {
  ifstream myfile(filename);
  ofstream ofile(output);
  if (myfile.is_open()) {
    int num;
    while (myfile >> num) {
      if (num == 0 || num == -1) {
        x.push(num);
      } else {
        int numTowels = num;
        for (int i = 0; i < numTowels; i++) {
          int value = x.top();
          x.pop();
          if (value == -1) {
            ofile << "white ";
          } else {
            ofile << "black ";
          }
        }
        ofile << endl;
      }
    }
  } else {
    cout << "file cannot be found" << endl;
  }
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
     	cout << "./laundry laundry.in laundry.out" << endl;
     	return -1;
   	}
  StackInt x;
  const char* filename = argv[1];
  const char* output = argv[2];
  readStack(filename, output, x);
  return 0;
}