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

};
int main(){
    Graph<int> g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);
  
    cout<<endl;
    cout << "printing DFS" << endl;
    unordered_map<int, bool> visited2;
    for(int i = 0;i<7;i++){
        if(!visited2[i])
            g.dfs(i,visited2);
    }
    return 0;
}