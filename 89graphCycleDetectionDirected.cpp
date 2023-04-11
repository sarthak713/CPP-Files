#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

/*
Cycle Detection in Directed Graph DFS

- Cannot apply undirected graph logic
- We have to keep DFSvisited map alongside visited map
- For each node (!visited) call isCycle function
    - mark true in visited & DFSvisited
- Call for adjacent nodes
- If no more adjacent nodes present, return and mark DFSvisited false
    - if node is visited in Both Maps, Cycle Present
*/

bool checkCycle(int node, unordered_map<int,bool>&visited, unordered_map<int,bool>&dfsVisited, unordered_map<int,set<int> >&adj){
    visited[node]=true;
    dfsVisited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            if(checkCycle(i,visited,dfsVisited,adj)){
                return true;
            }
        }
        else if(dfsVisited[i]){
            return true;
        }
    }
    dfsVisited[node]=false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,set<int> >adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].insert(v);
    }
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(checkCycle(i,visited,dfsVisited,adj)){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    
    
    
    return 0;
}