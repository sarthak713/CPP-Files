#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
using namespace std;

/*
DFS traversal in Graphs

- Depth first search
- Make a visited array, loop through elements
    - Call DFS for not visited elements
- Make visited true for that node 
- Keep Adjacency List
- Push adjacent nodes for visited in Queue
- Call DFS for nodes in Queue (which are not visited)

*/

void makeAdjList(unordered_map<int,set<int> >&adjList, vector<vector<int> >&edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void dfs(int node, unordered_map<int,bool>&visited, unordered_map<int,set<int> >&adjList, vector<int>&component){
    component.push_back(node);
    visited[node]=1;
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,visited,adjList,component);
        }
    }
}

vector<vector<int> >depthFirstSearch(int v,int e,vector<vector<int> >&edges){
    vector<vector<int> >ans;
    unordered_map<int,set<int> >adjList;
    makeAdjList(adjList,edges);
    unordered_map<int,bool>visited;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i,visited,adjList,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){
    
    
    
    return 0;
}