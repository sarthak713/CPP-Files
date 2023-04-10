#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

/*
BFS Traversal in Graphs

- Breadth First Search
- Unordered map<node,bool> to keep track of visited nodes
- Queue (First In First Out) to insert node, then process its neighbors
- We also need Adjacency List, for neighbors

Approach:
    - Initially all nodes are false
    - If node is not visited, call bfs function for that node
    - put source node in queue
    - save node in queue as Front Node & remove from queue
    - make Front Node visited
    - Print in answer
    - Put all neighbors of Front Node (which are not visited) in Queue
    - Repeat
    - To make sure all nodes are visited, we loop through nodes which checking if they are visited or not
*/

void makeAdjList(unordered_map<int,set<int> >&adjList, vector<pair<int,int> >&edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int> >&adjList, unordered_map<int,bool>&visited, vector<int>&ans, int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int>BFS(int nodes, vector<pair<int,int> >edges){
    unordered_map<int,set<int> >adjList; 
    vector<int>ans;
    unordered_map<int,bool>visited;
    makeAdjList(adjList,edges);     // make adjacency list
    for(int i=0;i<nodes;i++){       // traverse all components of graph
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}

int main(){
    
    
    
    return 0;
}