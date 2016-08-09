#include "stackint.h"
#include "Llistint.h"
#include <fstream>
#include <iostream>
using namespace std;

StackInt::StackInt(){};
StackInt::~StackInt(){};
bool StackInt::empty() const { return list_.empty(); }
void StackInt::push(const double& val) { list_.push_back(val); }
int const& StackInt::top() const { return list_.get(list_.size() - 1); }
void StackInt::pop() { list_.pop_back(); }
