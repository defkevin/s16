#ifndef _S16_TWEET_H__
#define _S16_TWEET_H__
#include <set>
#include <string>

struct Tweet {
  Tweet(const std::string& timestamp, const std::string& name,
        const std::string& text, const std::set<std::string>& tags)
      : ts_(timestamp), name_(name), text_(text), tags_(tags) {}
  std::string ts_;
  std::string name_;
  std::string text_;
  std::set<std::string> tags_;
  std::string to_string() const { return ts_ + " " + name_ + " " + text_; }
};

#endif