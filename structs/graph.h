#ifndef _S16_GRAPH_H__
#define _S16_GRAPH_H__

#include <vector>

// Abstract base class
class graph {
public:
  struct edge {
    edge();
    edge(int n, int w) : neighbor(n), weight(w){};
    int neighbor;
    int weight;
  };

  virtual bool add_edge(int v1, int v2,
                        int weight = 1) = 0; // derived class has to provide the
                                             // methods. add_edge method doesn't
                                             // have anything
  virtual bool remove_edge(int v1, int v2) = 0;
  virtual bool edge_exists(int v1, int v2) const = 0;

  virtual int size() const = 0;

  virtual std::vector<edge> neighbors(int v) const = 0;
  std::vector<int> bfs(int root) const;

  // last element
  std::vector<int> shortest_unweighted_path(int start, int end) const;
  // use dijsktra's algorithm to get the shortest distance from start to all
  // other nodes
  std::vector<int> shortest_paths(int start) const;

  void print() const;
};

// derived class
class list_graph : public graph {

public:
  list_graph(int num_nodes);

  // return true if edge added false if edge exists
  bool add_edge(int v1, int v2, int weight = 1);
  bool remove_edge(int v1, int v2);
  // return true if edge exists. false if it does not
  bool edge_exists(int v1, int v2) const;

  // get the number of nodes
  int size() const { return adj_.size(); }

  // get the neighbors of Node v
  std::vector<edge> neighbors(int v) const;
  // return distance from root to every node. if node isn't reachable return -1
  void bfs(int root, std::vector<int> *distances) const;

private:
  std::vector<std::vector<edge> > adj_;
};

class matrix_graph : public graph {
public:
  matrix_graph(int num_nodes);

  bool add_edge(int v1, int v2, int weight = 1);
  bool remove_edge(int v1, int v2);
  bool edge_exists(int v1, int v2) const;
  int size() const { return matrix_.size(); }
  std::vector<edge> neighbors(int v) const;

private:
  std::vector<std::vector<int> > matrix_;
};

#endif // _S16_GRAPH_H__