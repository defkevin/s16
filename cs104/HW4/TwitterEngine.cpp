#include <fstream>
#include <iostream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class User;
class Tweet;
typedef map<string, User> userMap;
typedef map<string, set<Tweet*> > tagMap;

class TwitterEngine {
public:
  void parseFeed(char* filename);
  void outputFeed();
  set<Tweet*> getTag(const string tag) { return tags_[tag]; }
  void addTweet(const string& username, const string& tweet_text,
                const string& timestamp);

private:
  userMap users_;
  tagMap tags_;
};

struct Tweet {
  Tweet(string timestamp, string n, string t, set<string> hash)
      : ts(timestamp), name(n), text(t), hashtag(hash) {}
  string ts;
  string name;
  string text;
  set<string> hashtag;
};

class User {
public:
  User() {}
  User(string username) : name_(username) {}
  ~User() {
    for (int i = 0; i < tweets_.size(); i++) {
      delete tweets_[i];
    }
  }
  void addFollowing(User* user);
  void addTweet(Tweet*);
  vector<Tweet*> getFeed();
  const string& getName() const { return name_; }
  void setName(string& name) { name_ = name; }

private:
  string name_;
  set<User*> following_;
  set<User*> followers_;
  vector<Tweet*> tweets_;
};

void toUpper(string& s) {
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
}


void User::addFollowing(User* userToAdd) {
  following_.insert(userToAdd);
  userToAdd->followers_.insert(this); // this is a pointer
}

void User::addTweet(Tweet* tweet) { tweets_.push_back(tweet); }

// Return a vector of Tweet* of all the tweets from this users plus
// all the tweets of the users this user is following.

struct TweetCompare {
  bool operator()(Tweet*& s1, Tweet*& s2) { return ((s1->ts) > (s2->ts)); }
};

vector<Tweet*> User::getFeed() {
  vector<Tweet*> feed;
  for (int i = 0; i < tweets_.size(); i++) {
    feed.push_back(tweets_[i]);
  }

  for (set<User*>::iterator i = following_.begin(); i != following_.end();
       i++) {
    User& user = *(*i); // same as User* user = *i;
    for (int j = 0; j < user.tweets_.size(); j++) {
      feed.push_back(user.tweets_[j]);
    }
  }
  sort(feed.begin(), feed.end(), TweetCompare());
  return feed;
}

void TwitterEngine::parseFeed(char* filename) {
  ifstream ifile(filename);
  int numUsers;
  string tempLine;
  getline(ifile, tempLine);
  stringstream temp(tempLine);
  temp >> numUsers;
  string line;
  for (int i = 0; i < numUsers; i++) {
    string username, users;
    getline(ifile, line);
    stringstream iss(line);
    iss >> username;
    User& newUser = users_[username];
    newUser.setName(username);
    string newFollow;
    while (iss >> newFollow) {
      User& UserToFollow = users_[newFollow];
      UserToFollow.setName(newFollow);
      newUser.addFollowing(&UserToFollow);
      // TODO: add to following.
    }
    users_[username] = newUser;
  }
  while (getline(ifile, line)) {
    stringstream iss(line);
    string date, t, timestamp, username, tweet_text;
    iss >> date >> t >> username;
    timestamp = date + " " + t;
    getline(iss, tweet_text);
    addTweet(username, tweet_text, timestamp);
  }
}

void TwitterEngine::addTweet(const string& username, const string& tweet_text,
                             const string& timestamp) {
  stringstream iss2(tweet_text);
  string word;
  set<string> tags;
  while (iss2 >> word) {
    if (word[0] == '#') {
      toUpper(word);
      word = word.substr(1);
      cout  << word << endl;
      tags.insert(word);
    }
  }
  Tweet* newTweet = new Tweet(timestamp, username, tweet_text, tags);
  users_[username].addTweet(newTweet);

  for (set<string>::iterator it = tags.begin(); it != tags.end(); it++) {
    tags_[*it].insert(newTweet);
  }
}

void TwitterEngine::outputFeed() {
  for (userMap::iterator i = users_.begin(); i != users_.end(); i++) {
    User& user = (*i).second;
    const string& username = user.getName();
    string filename = username + ".feed";

    ofstream ofile(filename.c_str());
    ofile << username << endl;
    vector<Tweet*> tweets = user.getFeed();
    for (int i = 0; i < tweets.size(); i++) {
      ofile << tweets[i]->ts << " " << tweets[i]->name << " " << tweets[i]->text
            << endl;
    }
  }
}

void print(vector<string> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
    if (i % 9 == 0 && i != 0) {
      cout << endl;
    }
  }
  cout << endl;
}

set<Tweet*> Union(set<Tweet*> s1, set<Tweet*> s2) {
  set<Tweet*> uSet = s1;
  for (set<Tweet*>::iterator it = s2.begin(); it != s2.end(); it++) {
    uSet.insert(*it);
  }
  return uSet;
}

set<Tweet*> Intersect(set<Tweet*> s1, set<Tweet*> s2) {
  for (set<Tweet*>::iterator it = s1.begin(); it != s1.end(); it++) {
    cout <<(*it)->text <<endl;
  }
  for (set<Tweet*>::iterator it = s2.begin(); it != s2.end(); it++) {
    cout <<(*it)->text <<endl;
    
  }
  set<Tweet*> iSet;
  for (set<Tweet*>::iterator it = s2.begin(); it != s2.end(); it++) {
    cout << (*it)->text <<endl;
    if (s1.find(*it) != s1.end()) {
      iSet.insert(*it);
    }
  }
  return iSet;
}

string GetTimeStamp() { return "2000-01-00 00:00:00"; }

void printSet(int numMatches, const set<Tweet*>& s){
  vector<Tweet*> v;
  if(numMatches==0){
    cout << "No matches." <<endl;
  }
  else{
    cout << numMatches << " matches:" <<endl;
    for(set<Tweet*>::const_iterator i =s.begin();i!=s.end();i++){
      v.push_back(*i);
    }
    sort(v.begin(),v.end(),TweetCompare());
  }
  for(int i = 0;i<v.size();i++){
    cout << v[i]->ts << " " << v[i]->name << " " << v[i]->text <<endl;
  }
}

void menu(char* filename) {
  TwitterEngine TE;
  TE.parseFeed(filename);
  TE.outputFeed();

  cout << "=====================================" << endl;
  cout << "Menu:" << endl;
  cout << " AND term term ..." << endl;
  cout << " OR term term ..." << endl;
  cout << " TWEET username tweet_text" << endl;
  cout << " QUIT (and write feed files)" << endl;
  cout << "=====================================" << endl;
  string input;
  while (true) {
    string first;
    cout << "Enter command: " << endl;
    getline(cin,input);
    toUpper(input);
    stringstream iss(input);
    iss >> first;
    toUpper(first);
    cout << "First: " << first <<endl;
    if (first == "OR") {
      set<Tweet*> s;
      string words;
      while (iss >> words) {
        cout << "Words: " <<words <<endl;
        set<Tweet*> s2 = TE.getTag(words);
        s = Union(s, s2);
      }
      cout << "size: "<<s.size() <<endl;
      int numMatches = s.size();
      printSet(numMatches,s);
    } else if (first == "AND") {
      set<Tweet*>s;
      string words;
      while (iss >> words) {
        cout << "Words: " <<words <<endl;
        set<Tweet*> s2 = TE.getTag(words);
        s = Intersect(s, s2);
      }
      int numMatches = s.size();
      printSet(numMatches,s);


    } else if (first == "TWEET") {
      string username;
      string tweet_text;
      iss >> username;
      getline(iss, tweet_text);
      string ts = GetTimeStamp();
      TE.addTweet(username, tweet_text, ts);
      cout << "username: " <<username <<endl;
      cout << "username: " <<username <<endl;
      cout << "username: " <<username <<endl;

    } else if(first =="QUIT"){
      break;
    }
    else{
      cout <<"Invalid Input" <<endl;
    }
    
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "./twitter twitter.txt" << endl;
    return -1;
  }
  menu(argv[1]);
}