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
*/

class graph{
public:
    unordered_map<int,list<int> >adj;
    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    
    int nodes=5;
    int edges=6;
    graph g;
    g.addEdge(0,1,0);    
    g.addEdge(1,2,0);    
    g.addEdge(2,3,0);    
    g.addEdge(3,1,0);    
    g.addEdge(3,4,0);    
    g.addEdge(0,4,0);    
    g.printAdjList();
    
    return 0;
}