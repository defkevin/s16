#ifndef Q4_H
#define Q4_H

#include <fstream>
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;

struct Node {
  Node(int v, Node* n) : value(v), next(n) {}
  int value;
  Node* next;
};

void printList(Node* n) {
  while (n != nullptr) {
    cout << n->value << " ";
    n = n->next;
  }
  cout << endl;
}

void removeDuplicates(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return;
  } else if (head->value == head->next->value) {
    Node* temp = head->next;
    head->next = temp->next;
    delete temp;
    removeDuplicates(head->next);
  } else {
    removeDuplicates(head->next);
  }
}

void readFile(char* filename) {
  ifstream ifile(filename);
  string line;
  getline(ifile, line);
  istringstream iss(line);
}

#endif