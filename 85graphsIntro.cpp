#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

/*
Graph: Data Structure which is a combination of Nodes & Edges
    - Node = entity to store data
    - Edge = to connect nodes
    - Degree = number of edges connected to node 
        - InDegree  = edges coming into node
        - OutDegree = edges moving out from node
Types:
    1 Directed
    2 UnDirected
    3 Weighted = edges have values 
                (if no weights given, assume weight as 1)
    4 Cyclic = Contains a cycle
    5 Acyclic = no cycle is present
Terms:
    - Path = sequence of nodes containing nodes once

Representation:
    - Adjacency Matrix = 2D matrix representing nodes connected to each other
    - Adjacency List = we list each node, & for each node we specify other nodes it is connected to
        - map<int,list<int>>

Important Basics:
    - add edge
    - contains edge
    - contains vertex
    - number of edges
    - delete vertex
    - delete edge
    - has path
*/

template<typename T>

class graph{
public:
    unordered_map<T, list<T> > adj;
    void addEdge(T u, T v, bool direction){
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }cout<<endl;
        }
    }
};

int main(){
    
    int n;
    cout<<"Enter Number of nodes: "<<endl;
    cin>>n;
    int m;
    cout<<"Enter Number of edges: "<<endl;
    cin>>m;
    graph<int> g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printAdjList();

    
    
    return 0;
}