#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// print vector 
void printVector(vector<string> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
}

// 
vector<string> returnValidLines(const char* filename) {
  ifstream myfile(filename);
  int counter = 0;
  string line;
  vector<string> posts;
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      if (!line.empty()) {
        posts.push_back(line);
        counter++;
      }
    }
  }
  return posts;
}

vector<string> countTweets(const char* filename, vector<string> posts) {
  ifstream myfile(filename);
  vector<string> tweets;
  for (int i = 0; i <= posts.size(); i++) {
    string line;
    getline(myfile, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
      if (word.substr(0, 1) == "#") {
        word = word.substr(1, word.size());
        bool found = false;
        for (int i = 0; i < tweets.size(); i++) {
          if (tweets[i] == word) {
            found = true;
          }
        }
        if (!found) {
          tweets.push_back(word);
        }
      }
    }
  }
  return tweets;
}

vector<string> countUsers(const char* filename, vector<string> posts) {
  ifstream myfile(filename);
  vector<string> users;
  for (int i = 0; i <= posts.size(); i++) {
    string line;
    getline(myfile, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
      if (word.substr(0, 1) == "@") {
        word = word.substr(1, word.size());
        bool found = false;
        for (int i = 0; i < users.size(); i++) {
          if (users[i] == word) {
            found = true;
          }
        }
        if (!found) {
          users.push_back(word);
        }
      }
    }
  }
  return users;
}

void formatOutput(vector<string> posts, vector<string> tweets,
                  vector<string> users) {
  cout << "1. Number of tweets = " << posts.size() << endl;
  cout << "2. Unique users" << endl;
  printVector(users);
  cout << "3. Unique hashtags" << endl;
  printVector(tweets);
}

int main(int argc, char* argv[]) {
  vector<string> posts;
  vector<string> tweets;
  vector<string> users;
  if (argc != 2) {
    cout << "usage: " << argv[0] << " <filename>" << endl;
  } else {
    string filename = argv[1];
    posts = returnValidLines(argv[1]);
    tweets = countTweets(argv[1], posts);
    users = countUsers(argv[1], posts);
    formatOutput(posts, tweets, users);
  }
}