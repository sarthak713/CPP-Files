#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

/*
Topological Sort (using Kahn's Algorithm BFS)

Approach:
- find indegree of all nodes
- make a queue, & insert all nodes with 0 indegree
- call BFS for node in queue
    - get front, pop queue
    - put front in answer
    - when nodes is popped from queue, its edges dissappear & indegree array is changed
    - put 0 indegree nodes in queue

1 push 0 indegree nodes in queue
2 get front, pop from queue
3 put in answer
4 get adjacent nodes, call bfs
*/

vector<int>topologicalSort(vector<vector<int> >&edges,int v,int e){
    unordered_map<int,list<int> >adj;
    for(int i=0;i<e;i++){
        int m=edges[i][0];
        int n=edges[i][1];
        adj[m].push_back(n);
    }
    vector<int>indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
}

int main(){
    
    
    
    return 0;
}