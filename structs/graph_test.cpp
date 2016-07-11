#include "../test/logging.h"
#include "graph.h"
#include <iostream>

using std::endl;
using std::cout;

void printpath(std::vector<int> path){
  for(int i =0;i <path.size();i++){
    cout << i << ": ";
    if(i!=path.size()-1){
      cout << path[i] << endl;
    }
    else{
      cout << path[i];
    }
  }
}

int main() {
  matrix_graph mat(9);
  std::vector<int> distances(12);
  std::vector<int> path;
  mat.add_edge(0, 1, 4);
  mat.add_edge(1,2,8);
  mat.add_edge(2,3,7);
  mat.add_edge(3,4,9);
  mat.add_edge(4,5,10);
  mat.add_edge(5,6,2);
  mat.add_edge(6,7,1);
  mat.add_edge(7,0,8);
  mat.add_edge(1,7,11);
  mat.add_edge(7,8,7);
  mat.add_edge(8,6,6);
  mat.add_edge(2,8,2);
  mat.add_edge(2,5,4);
  mat.add_edge(3,5,14);
  std::vector<int> shortestdistances = mat.shortest_paths(4);
  printpath(shortestdistances);
  cout << endl <<endl <<endl;
  //mat.print();

  return 0;
}