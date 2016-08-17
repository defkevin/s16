#include "User.h"
#include <string>

User::~User() {
  for (size_t i = 0; i < tweets_.size(); i++) {
    delete tweets_[i];
  }
}

void User::addFollowing(User* user) {
  following_.insert(user);
  user->followers_.insert(this);
}

struct TweetCompare {
  bool operator()(const Tweet*& t1, const Tweet*& t2) const {
    return t1->ts_ > t2->ts_;
  }
};

void User::addTweet(Tweet* tweet) { tweets_.push_back(tweet); }

// Return a vector of Tweet* of all the tweets from this users plus
// all the tweets of the users this user is following.
std::vector<const Tweet*> User::getFeed() const {
  std::vector<const Tweet*> feed;
  for (size_t i = 0; i < tweets_.size(); i++) {
    feed.push_back(tweets_[i]);
  }
  for (std::set<User*>::const_iterator i = following_.begin();
       i != following_.end(); i++) {
    const User& user = *(*i);
    for (size_t j = 0; j < user.tweets_.size(); j++) {
      feed.push_back(user.tweets_[j]);
    }
  }
  sort(feed.begin(), feed.end(), TweetCompare());
  return feed;
}