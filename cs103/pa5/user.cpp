#include "user.h"
#include <iostream>

using std::cout;

void User::add_friend(int friend_id) {
  //cout << "Adding friend id: " <<friend_id << 
  //  "to user " << _id;
  for (int i = 0; i < friends_.size(); i++) {
    if (friends_[i] == friend_id) { // already friends
      return;
    }
  }
  friends_.push_back(friend_id);
}

void User::delete_friend(int friend_id) {
  for (int i = 0; i < friends_.size(); i++) {
    if (friends_[i] == friend_id) { // already friends
      friends_.erase(friends_.begin() + i);
    }
  }
  return; // already not friends
}