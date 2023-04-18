#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
Minimum Spanning Tree (Prim's Algorithm)

- Spanning Tree 
    - when u convert a graph into a tree
    - such that it contains n nodes & n-1 edges
    - every node reachable by any other node
    (no cycle is present, removes extra weighted edges)
- Minimum Spanning Tree = where combined edge weights is minimum

Approach:
    - Data structures (indexes denote nodes):
        - Distance array = initially INT_MAX
        - MST array = which node is in mst or not, initially False
        - parent array = -1 initially
    - Start with 0th node first
        - mark distance[0]=0
        - parent [0]=-1
    - Find Minimum: go in distance array and get minimum value node (where MST=false)
    - mark MST[min node]=true
    - get adjacent nodes, update in distance array
    - Mark parent of adjacent nodes
    - Repeat until all MST is True
Our Minimum spanning tree is found in Parent Array
*/

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n,int m,vector<pair<pair<int,int>,int>>&g){
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int>distance(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);
    distance[1]=0;
    parent[1]=-1;
    // find minimum value node
    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;
        for(int j=1;j<=n;j++){
            if(mst[j]==false && distance[j]<mini){
                u=j;
                mini=distance[j];
            }
        }
        //mark minimum node true
        mst[u]=true;
        // traverse adjacent nodes
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<distance[v]){
                parent[v]=u;
                distance[v]=w;
            }
        }
    }
    vector<pair<pair<int, int>, int>>result;
    for(int i=2;i<=n;i++){
        result.push_back({{parent[i],i},distance[i]});
    }
    return result;
}

int main(){
    
    
    
    return 0;
}