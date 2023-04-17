#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

/*
Shortest Path in Directed Acyclic Graph (using DFS)

- Tell shortest path from a node to all other nodes

Approach:
    - Find Topological sort ordering (find which node lies before which one)
    - Use Linear Topological sort ordering to find Distance Array
    - Data Structures: Stack, Visited Map, Adjacency List (have to store weights also)
        - For Adj List: unordered_map<int,list<pair<int,int>>>
    - call DFS for unvisited nodes
        - mark visited
        - call for adjacent nodes
    - while returning, save node in stack
    - We get topological sort
    - Now we have to find shortest path, make Distance Array
        - store INT_MAX in all initially
        - distance[source]=0
        - get top from Stack
        - get distance from Array, If infinite leave
        - Get adjacent nodes from Adj List & update distance if smaller than already stored value
*/

class graph{
public:
    unordered_map<int,list<pair<int,int>>>adj;
    void addEdge(int u,int v,int weight){
        adj[u].push_back({v,weight});
    }
    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }cout<<endl;
        }
    }
    void dfs(int node,unordered_map<int,bool>&visited,stack<int>&s){
        visited[node]=1;
        for(auto i:adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,s);
            }
        }
        s.push(node);
    }
    void getShortest(int src,vector<int>&distance,stack<int>&s){
        distance[src]=0;
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(distance[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(distance[top]+i.second<distance[i.first]){
                        distance[i.first]=distance[top]+i.second;
                    }
                }
            }
        }
    }
};


int main(){
    
    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,2);
    g.printAdj();

    int n=6;
    unordered_map<int,bool>visited;
    stack<int>s;

    // Topological sort
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    int source=1;
    vector<int>distance(n,INT_MAX);
    g.getShortest(source,distance,s);
    for(auto i:distance)cout<<i<<endl;

    return 0;
}