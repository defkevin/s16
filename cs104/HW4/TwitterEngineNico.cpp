#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <time.h>
#include <vector>
using namespace std;

class User;
struct Tweet;
typedef map<string, User> UserMap;
typedef map<string, set<const Tweet*> > TagMap;

// to_upper modifies the input string.
void to_upper(string& s) {
  for (int i = 0; i < s.size(); i++) {
    if (islower(s[i])) {
      s[i] = toupper(s[i]);
    }
  }
}

struct Tweet {
  Tweet(string timestamp, string name, string text, set<string> tags)
      : ts_(timestamp), name_(name), text_(text), tags_(tags) {}
  string ts_;
  string name_;
  string text_;
  set<string> tags_;
  string to_string() const { return ts_ + " " + name_ + " " + text_; }
};

class User {
public:
  User() {}
  User(const string& n) : name_(n) {}
  ~User() {
    for (int i = 0; i < tweets_.size(); i++) {
      delete tweets_[i];
    }
  }
  void addFollowing(User* user);
  void addTweet(Tweet* tweet);
  string getName() const { return name_; }
  void setName(const string& s) { name_ = s; }
  vector<const Tweet*> getFeed() const;

private:
  string name_;
  set<User*> followers_;
  set<User*> following_;
  vector<Tweet*> tweets_;
};

class TwitEng {
public:
  void parseFeed(const char* filename);
  void outputFeed() const;
  set<const Tweet*> getTag(string tag) const {
    to_upper(tag);
    TagMap::const_iterator it = tagMap_.find(tag);
    if (it != tagMap_.end()) {
      return it->second;
    } else {
      return set<const Tweet*>();
    }
  }
  void addTweet(const string& username, const string& tweet_text,
                const string& timestamp);

private:
  UserMap users_;
  TagMap tagMap_;
};

//
// User
//
void User::addFollowing(User* user) {
  following_.insert(user);
  user->followers_.insert(this);
}

void User::addTweet(Tweet* tweet) { tweets_.push_back(tweet); }

struct TweetCompare {
  bool operator()(const Tweet*& t1, const Tweet*& t2) const {
    return t1->ts_ > t2->ts_;
  }
};

// Return a vector of Tweet* of all the tweets from this users plus
// all the tweets of the users this user is following.
vector<const Tweet*> User::getFeed() const {
  vector<const Tweet*> feed;
  for (int i = 0; i < tweets_.size(); i++) {
    feed.push_back(tweets_[i]);
  }
  for (set<User*>::const_iterator i = following_.begin(); i != following_.end();
       i++) {
    const User& user = *(*i);
    for (int j = 0; j < user.tweets_.size(); j++) {
      feed.push_back(user.tweets_[j]);
    }
  }
  sort(feed.begin(), feed.end(), TweetCompare());
  return feed;
}

string GetTimestamp() {
  time_t rawtime;
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  char buffer[80];
  strftime(buffer, 80, "%F %T", timeinfo);

  string ts(buffer);
  return ts;
}

//
// TwitEng
//
void TwitEng::addTweet(const string& username, const string& tweet_text,
                       const string& timestamp) {
  stringstream iss(tweet_text);
  string word;
  set<string> tags;
  while (iss >> word) {
    if (word[0] == '#') {
      string tag = word.substr(1);
      to_upper(tag);
      tags.insert(tag);
    }
  }
  Tweet* newTweet = new Tweet(timestamp, username, tweet_text, tags);
  users_[username].addTweet(newTweet);

  // Associate in the tagMap the new Tweet to all its tags.
  for (set<string>::const_iterator it = tags.begin(); it != tags.end(); it++) {
    // cout << "Adding tweet_text = " << tweet_text << " to tag " << *it <<
    // endl;
    tagMap_[*it].insert(newTweet);
  }
}

void TwitEng::parseFeed(const char* filename) {
  ifstream ifile(filename);

  // Get the number of users.
  string line;
  getline(ifile, line);
  stringstream temp(line);
  int numUsers;
  temp >> numUsers;

  // Read one line for each user.
  for (int i = 0; i < numUsers; i++) {
    getline(ifile, line);
    stringstream ss(line);

    // Create the user if necessary.
    string name;
    ss >> name;
    User& user = users_[name];
    user.setName(name);

    // Add following users to this user.
    string followingName;
    while (ss >> followingName) {
      User& followingUser = users_[followingName];
      user.addFollowing(&followingUser);
    }
  }
  string tweet_text;
  while (getline(ifile, tweet_text)) {
    // Get the timestamp.
    stringstream ss(tweet_text);

    string date, hms, username;
    ss >> date >> hms >> username;
    string timestamp = date + " " + hms;

    // The rest of the line is the tweet text.
    getline(ss, tweet_text);
    tweet_text = tweet_text.substr(1);

    addTweet(username, tweet_text, timestamp);
  }
}

void TwitEng::outputFeed() const {
  for (UserMap::const_iterator i = users_.begin(); i != users_.end(); i++) {
    const User& user = (*i).second;
    const string& username = user.getName();
    string filename = username + ".feed";
    ofstream ofile(filename.c_str());
    ofile << username << endl;
    vector<const Tweet*> tweets = user.getFeed();
    for (int i = 0; i < tweets.size(); i++) {
      ofile << tweets[i]->to_string() << endl;
    }
  }
}

set<const Tweet*> Union(const set<const Tweet*>& s1,
                        const set<const Tweet*>& s2) {
  set<const Tweet*> s = s1;
  for (set<const Tweet*>::const_iterator it = s2.begin(); it != s2.end();
       it++) {
    s.insert(*it);
  }
  return s;
}

set<const Tweet*> Intersection(const set<const Tweet*>& s1,
                               const set<const Tweet*>& s2) {
  set<const Tweet*> s;
  for (set<const Tweet*>::const_iterator it = s2.begin(); it != s2.end();
       it++) {
    if (s1.find(*it) != s1.end()) {
      s.insert(*it);
    }
  }
  return s;
}

void menu() {
  cout << "=====================================" << endl;
  cout << "Menu:" << endl;
  cout << " AND term term ..." << endl;
  cout << " OR term term ..." << endl;
  cout << " TWEET username tweet_text" << endl;
  cout << " QUIT (and write feed files)" << endl;
  cout << "=====================================" << endl;
}

void printMatches(const set<const Tweet*>& s) {
  if (!s.empty()) {
    cout << s.size() << " matches:" << endl;
  } else {
    cout << "No matches." << endl;
  }
  vector<const Tweet*> v;
  for (set<const Tweet*>::const_iterator it = s.begin(); it != s.end(); it++) {
    v.push_back(*it);
  }
  sort(v.begin(), v.end(), TweetCompare());
  for (vector<const Tweet*>::const_iterator it = v.begin(); it != v.end();
       it++) {
    cout << (*it)->to_string() << endl;
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Invalid input." << endl;
    cout << "./twitter twitter.dat" << endl;
    return -1;
  }
  TwitEng twitter;
  twitter.parseFeed(argv[1]);

  menu();
  cout << "Enter command" << endl;
  string input_line;
  while (getline(cin, input_line)) {
    stringstream ss(input_line);
    string command;
    ss >> command;
    to_upper(command);
    if (command == "QUIT") {
      break;
    } else if (command == "AND") {
      string tag;
      ss >> tag;
      set<const Tweet*> s = twitter.getTag(tag);
      while (ss >> tag) {
        set<const Tweet*> s2 = twitter.getTag(tag);
        s = Intersection(s, s2);
      }
      printMatches(s);
    } else if (command == "OR") {
      set<const Tweet*> s;
      string tag;
      while (ss >> tag) {
        set<const Tweet*> s2 = twitter.getTag(tag);
        s = Union(s, s2);
      }
      printMatches(s);
    } else if (command == "TWEET") {
      string ts = GetTimestamp();
      string username;
      string tweet_text;
      ss >> username;
      getline(ss, tweet_text);
      tweet_text = tweet_text.substr(1);
      twitter.addTweet(username, tweet_text, ts);
    } else {
      cout << "Not a valid command" << endl;
    }
    cout << endl;
    menu();
    cout << "Enter command" << endl;
  }
  twitter.outputFeed();
}

