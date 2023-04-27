#include<iostream>
#include<unordered_map>
#include<list>
<<<<<<< HEAD
=======
#include<vector>
>>>>>>> coding
using namespace std;

/*
Graph: Data Structure which is a combination of Nodes & Edges
    - Node = entity to store data
    - Edge = to connect nodes
<<<<<<< HEAD
Types:
    - Directed = Degree of Node = edges connected to that node
    - UnDirected
        - InDegree  = edges coming into node
        - OutDegree = edges moving out from node
    - Weighted
    - Cyclic = Contains a cycle
    - Acyclic = no cycle is present
Terms:
    - Path = sequence of nodes containing all nodes once
=======
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
>>>>>>> coding

Representation:
    - Adjacency Matrix = 2D matrix representing nodes connected to each other
    - Adjacency List = we list each node, & for each node we specify other nodes it is connected to
        - map<int,list<int>>
*/

<<<<<<< HEAD
template<typename T>

class graph{
public:
    unordered_map<T, list<T> > adj;
    void addEdge(T u, T v, bool direction){
        adj[u].push_back(v);
        if(!direction){
=======
class graph{
public:
    unordered_map<int,list<int> >adj;
    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==0){
>>>>>>> coding
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i:adj){
<<<<<<< HEAD
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }cout<<endl;
=======
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
>>>>>>> coding
        }
    }
};

int main(){
    
<<<<<<< HEAD
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

    
=======
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
>>>>>>> coding
    
    return 0;
}