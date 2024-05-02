#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

class Graph {
public:
  unordered_map<int, list<pair<int, int>>> adjList;

  void addEdge(int u, int v, int weight,  bool direction) {
    // direction = 0 -> undirected graph
    // direction = 1 -> directed graph
    adjList[u].push_back({v, weight});
    if(direction == 0) {
      // undirected edges
      // create an edge from v to u
      adjList[v].push_back({u, weight});
    }   
  }
  void printAdjList() {
    for(auto node: adjList) {
      cout << node.first << "-> ";
      for(auto neighbour: node.second) {
        cout << "(" << neighbour.first << ", " << neighbour.second << "), ";
      }
      cout << endl;
    }
  }
};

int main() {

  Graph g;

  // undirected edge input
  // g.addEdge(0, 1, 0);
  // g.addEdge(1, 2, 0);
  // g.addEdge(0, 2, 0);
  // cout << endl;
  // g.printAdjList();

  // Directed edge input
  g.addEdge(0, 1, 5, 1);
  g.addEdge(1, 2, 8, 1);
  g.addEdge(0, 2, 6, 1);
  cout << endl;
  g.printAdjList();
  
}