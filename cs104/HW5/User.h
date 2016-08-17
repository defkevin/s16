#ifndef _S16_USER_H__
#define _S16_USER_H__
#include "Tweet.h"
#include <string>
#include <vector>

class User {
public:
  User() {}
  User(const std::string& n) : name_(n) {}
  ~User();
  void addFollowing(User* user);
  void addTweet(Tweet* tweet);
  std::string getName() const { return name_; }
  void setName(const std::string& s) { name_ = s; }
  std::vector<const Tweet*> getFeed() const;
  const std::set<User*>& getFollowing() const { return following_; }
  const std::set<User*>& getFollowers() const { return followers_; }

private:
  std::string name_;
  std::set<User*> followers_;
  std::set<User*> following_;
  std::vector<Tweet*> tweets_;
};
#endif