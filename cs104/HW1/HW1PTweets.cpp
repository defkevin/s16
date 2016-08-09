#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<string> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
}

vector<string> countValidLines(const char* filename) {
  ifstream myfile(filename);
  int counter = 0;
  string line;
  vector<string> posts;
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      posts.push_back(line);
      counter++;
    }
  }
  return posts;
}
// int countTweets(filename)
// int countUsers(filename)
// int countHashTags(filename)

int main(int argc, char* argv[]) {
  vector<string> posts;
  if (argc != 2) {
    cout << "usage: " << argv[0] << " <filename>" << endl;
  } else {
    posts = countValidLines(argv[1]);
    printVector(posts);
  }
}