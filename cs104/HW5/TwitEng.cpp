#include "twiteng.h"
#include <fstream>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
using std::stringstream;
using std::string;
using std::set;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;

// to_upper modifies the input string.
void to_upper(std::string& s) {
  for (size_t i = 0; i < s.size(); i++) {
    if (islower(s[i])) {
      s[i] = toupper(s[i]);
    }
  }
}

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

set<const Tweet*> TwitEng::getTag(string tag) const {
  to_upper(tag);
  TagMap::const_iterator it = tagMap_.find(tag);
  if (it != tagMap_.end()) {
    return it->second;
  } else {
    return set<const Tweet*>();
  }
}

std::vector<User*> TwitEng::getUsers() {
  vector<User*> users;
  for (UserMap::iterator i = users_.begin(); i != users_.end(); i++) {
    User& user = (*i).second;
    users.push_back(&user);
  }
  return users;
}

User* TwitEng::getUser(const string& name) {
  UserMap::iterator it = users_.find(name);
  if (it != users_.end()) {
    return &(it->second);
  } else {
    return nullptr;
  }
}

bool TwitEng::parseFeed(const char* filename) {
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
  return true;
}

void TwitEng::outputFeed() const {
  for (UserMap::const_iterator i = users_.begin(); i != users_.end(); i++) {
    const User& user = (*i).second;
    const string& username = user.getName();
    string filename = username + ".feed";
    ofstream ofile(filename.c_str());
    ofile << username << endl;
    vector<const Tweet*> tweets = user.getFeed();
    for (size_t i = 0; i < tweets.size(); i++) {
      ofile << tweets[i]->to_string() << endl;
    }
  }
}

