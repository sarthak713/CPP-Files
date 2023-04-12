#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<stack>
using namespace std;

/*
Topological Sort (using DFS)

- apply for DAG only = Directed Acyclic Graph
- Topological Sort 
    - linear ordering of vertices 
    - such that for every edge u->v
    - u always appears before v in that ordering

Approach:
- Need: visited map, stack, adjacency list
- Call for nodes
- For each node (!visited)
    - mark visited
    - call for adjacent nodes
    - when we return, push node into stack
- Now when we pop from stack, it is Topological Order
*/

void topologicalSortSolve(int node, unordered_map<int,set<int> >&adj, stack<int>&st, vector<bool>&visited){
    visited[node]=1;
    for(auto i:adj[node]){
        if(!visited[i]){
            topologicalSortSolve(i,adj,st,visited);
        }
    }
    st.push(node);
}

vector<int>topologicalSort(vector<vector<int> >&edges,int v,int e){
    unordered_map<int,set<int> >adj;
    for(int i=0;i<e;i++){
        int m=edges[i][0];
        int n=edges[i][1];
        adj[m].insert(n);
    }
    vector<bool>visited(v);
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            topologicalSortSolve(i,adj,st,visited);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    
    
    
    return 0;
}