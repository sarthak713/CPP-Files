#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<queue>
using namespace std;

/*
Cycle Detection in Undirected Graph

Using BFS
    - keep visited array
    - keep queue to store unvisited adjacent nodes
    - keep a Data Structure to track Parent of node
    - put initial node in queue
    - Initial node has no parent, so -1, mark visited, remove node from queue
    - Traverse adjacency List of node
    - Visited & Parent nodes are neglected
    - If node is Visited & Not Parent, Cycle is Present

For each node's adjacent elements:
    1 check visited, if not then make them visited
    2 check if they are node's parent   
        if yes dont do anything
        else set parent & push in queue
    3 if visited & not parent, cycle exists
*/

bool isCyclicBFS(int node, unordered_map<int,bool>&visited, unordered_map<int,set<int> >&adj){
    unordered_map<int,int>parent;
    parent[node]=-1;
    visited[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(visited[i] && i!=parent[front]){
                return true;
            }
            else if(!visited[i]){
                parent[i]=front;
                visited[i]=1;
                q.push(i);   
            }
        }
    }
    return false;
}

string cycleDetectionBFS(vector<vector<int> >&edges,int n,int m){
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
            if(isCyclicBFS(i,visited,adj)){
                return "Yes";
            }
        }
    }
    return "No";
}

int main(){
    
    
    
    return 0;
}