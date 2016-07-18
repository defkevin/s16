#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using std::string;
using std::vector;
class User {
public:
  User() {}
  User(int id, string name, int year, int zip)
      : _id(id), _name(name), _year(year), _zip(zip) {}
  ~User() {}
  void add_friend(int friend_id);
  void delete_friend(int friend_id);
  int getID() { return _id; }
  string getName() { return _name; }
  int getYear() { return _year; }
  int getZip() { return _zip; }
  vector<int> getFriends() {return friends_;}
  int depth;
  int predecessor;
  bool visited; 

private:
  int _id;
  string _name;
  int _year;
  int _zip;

  vector<int> friends_;
};

#endif
