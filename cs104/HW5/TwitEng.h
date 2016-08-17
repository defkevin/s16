#ifndef _S16_TWITENG_H__
#define _S16_TWITENG_H__
#include "tweet.h"
#include "user.h"
#include <map>
#include <string>

typedef std::map<std::string, User> UserMap;
typedef std::map<std::string, std::set<const Tweet*> > TagMap;

class TwitEng {
public:
  bool parseFeed(const char* filename);
  void outputFeed() const;
  std::set<const Tweet*> getTag(std::string tag) const;
  std::vector<User*> getUsers();
  User* getUser(const std::string& name);
  void addTweet(const std::string& username, const std::string& tweet_text,
                const std::string& timestamp);

private:
  UserMap users_;
  TagMap tagMap_;
};

#endif // _S16_TWITENG_H__