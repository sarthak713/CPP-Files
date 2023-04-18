#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<list>
using namespace std;

/*
Dijkstra's Shortest Path Algorithm
(weighted undirected graph)

- Find shortest path from one node to all 
Approach:
    - Data Structures:
        - adj list with pairs (node & weight)
        - Distance Vector (int_max initialized)
        - set (to get minimum distance at all times)
            - stores pair <distance of node, node>
    - initialize distance[source]=0, insert {0,0} in set
    - get top from set, pop 
    - traverse adjacent nodes of top
    - update Distance vector & insert in set (minimum distance will be on top always)
    - we compare already added distance and new distance with distance to current node
        - if small we update else not
    - when distance is updated by smaller value for a node
        - we have to update it in the set also
*/

vector<int>dijkstra(vector<vector<int> >&vec, int vertices, int edges, int source){
    // create Adjacency list
    unordered_map<int,list<pair<int,int> > >adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    // distance array
    vector<int>distance(vertices,INT_MAX);
    // set to get minimum distance value always
    set<pair<int,int> >st;
    distance[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        // get top minimum
        auto top=*(st.begin());
        int nodeDistance=top.first;
        int topNode=top.second;
        // remove top
        st.erase(st.begin());
        // traverse adjacent nodes
        for(auto i:adj[topNode]){
            if(nodeDistance+i.second<distance[i.first]){
                auto record=st.find(make_pair(distance[i.first],i.first));
                // if record found, then erase
                if(record!=st.end()){
                    st.erase(record);
                }
                // update distance
                distance[i.first]=nodeDistance+i.second;
                // insert record in set
                st.insert(make_pair(distance[i.first],i.first));
            }
        }
    }
    return distance;
}


int main(){
    
    
    
    return 0;
}