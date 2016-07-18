#include "../test/logging.h"
#include "dlistNico.h"
#include "hash_map.h"
#include "key_value.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::transform;
using std::cin;

using namespace std;

void StringIntHash() {
  hash_map<int> h(19);

  int& d = h["dog"];
  CHECK_EQ(h["dog"], 0);
  d++;
  CHECK_EQ(h["dog"], 1);
  d = 10;
  CHECK_EQ(h["dog"], 10);
  d++;
  CHECK_EQ(h["dog"], 11);
  cout << h["dog"] << endl;
}

struct Player {
  Player() {}
  Player(string t, int n) : team(t), number(n){};
  string team;
  int number;
};

ostream& operator<<(ostream& os, Player p) {
  os << "Team: " << p.team << ", "
     << "number: " << p.number;
  return os;
}

void StringPlayerHash() {
  hash_map<Player> h(19);

  Player kobe("Lakers", 24);
  Player jordan("bulls", 23);

  h["kobe"] = kobe;
  h["jordan"] = jordan;
  CHECK_EQ(h["kobe"].number, 24);
  CHECK_EQ(h.find("kobe") == nullptr, false);

  CHECK_EQ(h["jordan"].number, 23);

  CHECK_EQ(h.find("Filip") == nullptr, true);
  w
}

int main() {
  BEGIN_TESTS();

  StringIntHash();
  StringPlayerHash();

  return 0;
}