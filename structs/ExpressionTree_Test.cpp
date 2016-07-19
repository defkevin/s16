#include "ExpressionTree.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
  string s = "3 4 +";
  ExpressionTree ET(s);
  cout << ET.eval();
}