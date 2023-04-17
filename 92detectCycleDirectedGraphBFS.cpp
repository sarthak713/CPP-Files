#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

/*
Detect Cycle in Directed Graph using BFS
*/

int topologicalSort(int n, vector<pair<int,int> >&edges){
    unordered_map<int,list<int> >adj;
    for(int i=0;i<edges.size();i++){
        int m=edges[i].first-1;
        int n=edges[i].second-1;
        adj[m].push_back(n);
    }
    vector<int>indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        count++;
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    if(count==n)return 0;
    return 1;
}

int main(){
    
    
    
    return 0;
}