#include <fstream>
#include <iostream>
using std::endl;
using std::ifstream;
using std::ofstream;
using std::cout;

int makeSums(const char* filename) {
  ifstream myfile(filename);
  int size;
  if (myfile.is_open()) {
    myfile >> size;
  } else {
    return -1; // nothing could be read
  }
  int a[size];
  int sum[size / 2 + 1];
  for (int i = 0; i < size; i++) {
    int value;
    myfile >> value;
    a[i] = value;
  }
  for (int i = 0; i <= size / 2; i++) {
    int result;
    result = a[i] + a[size - i - 1];
    sum[i] = result;
  }
  ofstream outfile("Result.txt");
  if (outfile.is_open()) {
    for (int i = 0; i < size / 2 + 1; i++) {
      outfile << sum[i] << endl;
    }
  }
  return 1;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "usage: " << argv[0] << " <filename>" << endl;
  } else {
    makeSums(argv[1]);
  }
}
