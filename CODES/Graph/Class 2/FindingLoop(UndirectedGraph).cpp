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

    void bfs(int src,unordered_map<int,bool>&visited){
        queue<int>q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            // Front node
            int frontNode = q.front();
            q.pop();
            cout<<frontNode;
            // Insert neighbours
            for(auto neighbours : adjList[frontNode]){
                // If not visited then insert
                if(!visited[neighbours]){
                    q.push(neighbours);
                    visited[neighbours] = true;
                }
            }
        }
    }


    bool checkCyclicUsingBfs(int src, unordered_map<int, bool>& visited) {
      queue<int> q;
      unordered_map<int, int> parent;
      q.push(src);
      visited[src] = true;
      parent[src] = -1;

      while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        for(int nbr: adjList[frontNode]) {
          if(!visited[nbr]) {
            q.push(nbr);
            visited[nbr] = true;
            parent[nbr] = frontNode;
          }
          else {
            // already visited
            if(nbr != parent[frontNode]) {
              // cycle preent
              return true;
            }
          }
        }
      }
      return false;
    }
};
int main(){
    Graph<int> g;
    int n = 5;
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);



    g.printAdjList();
    cout << endl;

  bool ans = false;
  unordered_map<int, bool> visited;

  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      ans = g.checkCyclicUsingBfs(i, visited);
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