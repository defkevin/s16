#include "../test/logging.h"
#include "gcd.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
  CHECK_EQ(gcd(9, 6), 4);
  CHECK_EQ(gcd(25, 10), 5);
  CHECK_EQ(gcd(12345 * 13, 12345 * 17), 12345);
  CHECK_EQ(gcd(1, 1), 1);
  CHECK_NE(gcd(4, 2), 3);

}