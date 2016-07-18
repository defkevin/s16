#ifndef NETWORK_H
#define NETWORK_H
#include "user.h"
#include <string>

class Network {
public:
  Network();
  ~Network();
  int read_friends(const char *filename);
  int write_friends(const char *filename);
  void add_user(std::string username, int yr, int zipcode);
  int add_connection(std::string name1, std::string name2);
  int remove_connection(std::string name1, std::string name2);
  int get_id(std::string username);
  void printUsers();
  int usersSize() {return users_.size();}
  User getusers(int index) {return users_[index];}
  void bfs(int start);
  void printDepths();
  void printPath(vector<int> path);
  std::vector<int> shortest_path(int start, int end);

private:
  vector<User> users_;
};

#endif
