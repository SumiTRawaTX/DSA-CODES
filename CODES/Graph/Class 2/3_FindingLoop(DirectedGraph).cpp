#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph{
  public:
    unordered_map<T,list<T>>adjList;
    void addEdge(T u,T v,bool direction){
      // direction = 0 -> undirected
      // direction = 1 -> directed 
      // Create an edge from u to v
      adjList[u].push_back(v);
      // if undirected 
      if(direction == 0)
        adjList[v].push_back(u); // edge created from v to u    
      }

    void printAdjList(){
      for(auto node : adjList){
        cout<<node.first<<"-> ";
          for(auto neighbours : node.second){
            cout<<neighbours<<", ";
          }
          cout<<endl;
      }
    }

    void dfs(int src, unordered_map<int, bool>& visited) {
        cout << src << ", ";
        visited[src] = true;
        for(auto neighbour: adjList[src]) {
        if(!visited[neighbour]) {
            dfs(neighbour, visited);
            }
        }
    }



    bool checkCyclicUsingDfs(int src, unordered_map<int, bool>& visited, int parent) {
      visited[src] = true;
      for(auto nbr: adjList[src]) {
        if(!visited[nbr]) {
          bool ans = checkCyclicUsingDfs(nbr, visited, src);
          if(ans == true) return true;
        }
        if(visited[nbr] && nbr != parent) {
          // cycle present
          return true;
        }
      }
      return false;
    }

    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int, bool>& visited, unordered_map<int, bool> dfsVisited) {
      visited[src] = true;
      dfsVisited[src] = true;

      for(auto nbr: adjList[src]) {
        if(!visited[nbr]) {
          bool ans = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
          if(ans == true) return true;
        }
        if(visited[nbr] == true && dfsVisited[nbr] == true) {
          return false;
        }
      }
      dfsVisited[src] = false;
      return false;
    }
};

int main(){
    Graph<int> g;
    int n = 5;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,0,1);



    g.printAdjList();
    cout << endl;

  bool ans = false;
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;

  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      ans = g.checkCyclicDirectedGraphUsingDfs(i, visited, dfsVisited);
      if(ans == true) break;
    }
  }

  if(ans == true) {
    cout << "Cycle is present in graph" << endl;
  }
  else {
    cout << "Cycle is not present in graph" << endl;
  }

    return 0;
}