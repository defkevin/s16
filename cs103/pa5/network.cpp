#include "network.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <queue>
#include <cassert>

using std::ifstream;
using std::cout;
using std::endl;
using std::stringstream;
using std::ofstream;
using std::setw;
using std::left;
using std::queue;
using std::vector;
using std::reverse;

Network::Network(){};
Network::~Network(){};

void Network::printDepths() {
  cout << "List of Depths: " <<endl;
  for(int i =0;i<usersSize();i++){
    cout << users_[i].getName() <<": " <<users_[i].depth <<endl;
  }
}

void Network::printUsers() {
  cout <<setw(10) <<left <<"ID"  <<setw(25) <<left << "Name" <<setw(10) <<"Year" <<setw(10)<<"Zip" <<endl;
  cout << "================================================================" <<endl;
  for (int i = 0; i < users_.size(); i++) {
    cout << setw(10)  <<users_[i].getID() ;
    cout  <<setw(25) << users_[i].getName();
    cout << setw(10) << users_[i].getYear();
    cout << setw(10) << users_[i].getZip();
    // cout << "   ";
    // vector<int> friends = users_[i].getFriends();
    // for(int j = 0; j<friends.size() ;j++){
    //   cout << friends[j] << " ";
    // }
    cout << endl <<endl;
  }
}

int Network::write_friends(const char*filename) {
  ofstream myfile(filename);
  if(myfile.is_open()){
    int size = users_.size();
    myfile << size <<endl;
    for(int i = 0; i<size;i++){
      myfile << users_[i].getID() <<endl;
      myfile << "   " << users_[i].getName() << endl;
      myfile << "   " << users_[i].getYear() <<endl;
      myfile << "   " << users_[i].getZip() <<endl;
      myfile << "   ";
      vector<int> friends = users_[i].getFriends();
      for(int j = 0; j<friends.size();j++){
        myfile << friends[j] << " ";
      }
      myfile << endl;
    }
  }
  else{
    cout << "Unable to access file" <<endl;
    return -1;
  }
  return 0;
}

int Network::read_friends(const char* filename) {
  string line;
  ifstream myfile(filename);
  int numfriends;
  if (myfile.is_open()) {
    myfile >> numfriends;
   // cout << "number of friends: " << numfriends << endl;
  } else {
    //cout << "not a real file" << endl;
    return -1;
  }
  users_.resize(numfriends);
  for (int i = 0; i < numfriends; i++) {
    int id;
    string first;
    string last;
    int year;
    int zip;

    // assigning all information but friends
    myfile >> id;
   // cout << "ID: " << id << endl;
    myfile >> first >> last;
    string name = first + " " + last;
    //cout << "name = " << name << endl;
    myfile >> year;
    //cout << "year: " << year << endl;
    myfile >> zip;
    //cout << "zip: " << zip << endl;
    User newuser(id, name, year, zip);
    users_[id] = newuser;

    // friends
    string str;
    getline(myfile,str);
    //cout << "str1 = " << str << endl;
    getline(myfile,str);
    //cout << "str2 = " << str << endl;
    stringstream iss(str);
    while(iss >>id){
      //cout << "adding friend id: " <<id <<endl;
      add_connection(name, users_[id].getName());
    }
    //cout << "finished adding user: " <<name <<endl;
  }

  return 0;
}

void Network::add_user(string username, int year, int zip) {
  int size = users_.size();
  User x(size, username, year, zip);
  users_.push_back(x);
}

int Network::get_id(string username) {
  for (int i = 0; i < users_.size(); i++) {
    if (users_[i].getName() == username) {
      return i;
    }
  }
  return -1;
}

int Network::add_connection(string name1, string name2) {
  int id1 = get_id(name1);
  int id2 = get_id(name2);
  //cout << "Adding connection between " <<id1 << " and " << id2 <<endl;
  if (name1 == name2 || id1 == -1 || id2 == -1) {
    return -1;
  }

  else {
    users_[id1].add_friend(id2);
    users_[id2].add_friend(id1);
    return 0;
  }
}

int Network::remove_connection(string name1, string name2) {
  int id1 = get_id(name1);
  int id2 = get_id(name2);
  if (name1 == name2 || id1 == -1 || id2 == -1) {
    return -1;
  } else {
    users_[id1].delete_friend(id2);
    users_[id2].delete_friend(id1);
    return 0;
  }
}

void Network::bfs(int start){
  std::queue<int> q;
  q.push(start);
  for(int i = 0; i<usersSize();i++){
    users_[i].visited = false;
    users_[i].depth = -1;
    users_[i].predecessor = -1;
  }
  users_[start].visited = true;
  users_[start].depth = 0;
  while(!q.empty()){
    int current = q.front();
    q.pop();
    std::vector<int> current_neighbors = users_[current].getFriends();
    for(int i = 0; i <current_neighbors.size();i++){
      int n = current_neighbors[i];
      if(!users_[n].visited){
        users_[n].visited = true;
        users_[n].depth = users_[current].depth +1;
        q.push(n);
        users_[n].predecessor = current;
      }
    }
  }
}

void Network::printPath(vector<int> path){
  for(int i = 0; i<path.size();i++){
    if(i == path.size()-1){
      cout << path[i];
    }
    else{
      cout << path[i] << " --> ";
    }
  }
  cout <<endl;
}

std::vector<int> Network::shortest_path(int start, int end){
  assert(start >= 0 && start < usersSize());
  assert(end >= 0 && end < usersSize());

  bfs(start);
  vector<int> path;
  if(start==end){
    path.push_back(start);
    return path;
  }
  int id = end;
  bool found = false;
  while(id!=start && id!=-1){
    path.push_back(id);
    id = users_[id].predecessor;
    if(id == start){
      found = true;
    }
  }
  if(found == true){
    path.push_back(start);
  }
  else{
    cout << "Path not found";
    return vector<int>();
  }
  reverse(path.begin(),path.end());
  return path;
  }
  




