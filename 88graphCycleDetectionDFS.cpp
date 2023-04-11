#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

/*
Cycle Detection in Undirected Graph

Using DFS
    - keep visited array
    - keep queue to store unvisited adjacent nodes
    - keep a Data Structure to track Parent of node
    - put initial node in queue
    - Initial node has no parent, so -1, mark visited, remove node from queue
    - Traverse adjacency List of node
    - Visited & Parent nodes are neglected
    - If node is Visited & Not Parent, Cycle is Present

    Same as Cycle Detection in Undirected Graph using BFS
    Just method has changed to DFS traversal 
*/

bool isCyclicDFS(int node, int parent, unordered_map<int,bool>&visited, unordered_map<int,set<int> >&adj){
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i]){
            bool cycleDetected=isCyclicDFS(i,node,visited,adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(i!=parent){
            return true;
        }
    }
    return false;
}

string cycleDetectionDFS(vector<vector<int> >&edges,int n,int m){
    unordered_map<int,set<int> >adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isCyclicDFS(i,-1,visited,adj)){
                return "Yes";
            }
        }
    }
    return "No";
}

int main(){
    
    
    
    return 0;
}