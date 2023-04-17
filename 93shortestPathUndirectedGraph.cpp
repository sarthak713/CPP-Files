#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

/*
Shortest Path In Undirected Graph (using BFS)

Approach:   
    - Data structures required:
        - adjacency list
        - visited map
        - parent map
        - queue, for adjacent nodes
    - push first node in queue
        - mark visited
        - make parent -1
        - store as front
        - pop from queue
        - push adjacent nodes in queue (!visited)
    - Now when this is done for all nodes
    - Parent map is completely filled, which is required
    - Now as we know the Source and Destination Nodes
        - to reach a node, we reach it throught its parent
        - So we start from destination, find parent & repeat
        - until start node is reached, we get the path
        - Reverse the path and we get shortest path from start to destination
*/

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>>adj;
	for(int i=0;i<edges.size();i++){
        int v=edges[i].first;
        int u=edges[i].second;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    queue<int>q;
    q.push(s);
    visited[s]=1;
    parent[s]=-1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i]=1;
                parent[i]=front;
                q.push(i);
            }
        }
    }
    vector<int>ans;
    int destination=t;
    ans.push_back(t);
    while(destination!=s){
        destination=parent[destination];
        ans.push_back(destination);
    }
	reverse(ans.begin(),ans.end());
    return ans;
}


int main(){
    
    
    
    return 0;
}