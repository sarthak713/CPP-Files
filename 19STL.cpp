#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
/*
C++ STL (Standard Template Library)

C++ STL:
    - Algorithms
    - Containers

Containers:
    - Sequence Containers
        - Array = similar type of data stored in contiguous memory location
        - Vector = dynamic array, as size is changed to fit more elements
        - Deque = doubly ended queue, means we can do any operation from both sizes: front or back, dynamic, random access
        - List = implemented using doubly linked list, no random access
        - forward_list
    - Container Adaptors
        - Stack = last in first out
        - Queue = first in first out
        - Priority Queue = first ele is always greatest, heap relation, when we form max_heap - first element out is always max, vice versa for min_heap
    - Associative Containers
        - Set = stores only unique elements, implemented using bst, returned in sorted order
        - Map = data is stored in key:value pairs, all keys are unique & a key points to only a single value
        - MultiSet
        - MultiMap
    - Unordered Associatives
        - Unordered Set = ele are randomly fetched
        - Unordered Map
        - Unordered Multiset
        - Unordered MultiMap

Algorithms:
    - binary search
    - Lower/Upper bound
    - min/max
    - reverse/rotate
    - sort/swap, etc

*/


int main(){

// Array
    // array<int,4> a = {1,2,3,4};  // int data-type, 4 elements
    // int size = a.size();
    // for(int i=0;i<size;i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;
    // cout<<"Ele at 2nd index "<<a.at(2)<<endl;
    // cout<<"Is array empty: "<<a.empty()<<endl;
    // cout<<a.front()<<endl;
    // cout<<a.back()<<endl;

// Vector
    // vector<int> v;  // size is initially 0
    // cout<<"Size -> "<<v.capacity()<<endl;
    // v.push_back(1);
    // cout<<"Size -> "<<v.capacity()<<endl;
    // v.push_back(2);
    // cout<<"Size -> "<<v.capacity()<<endl;
    // v.push_back(3);
    // cout<<"Size -> "<<v.capacity()<<endl;   // capacity is doubled
    // // Size = how many eles, Capacity = how much space is assigned for eles
    // cout<<"Ele at 2nd index "<<v.at(2)<<endl;
    // cout<<v.front()<<endl;
    // cout<<v.back()<<endl;
    // v.pop_back();
    // cout<<v.back()<<endl; 
    // // Clear = when vector is cleared, its size=0, not capacity
    // cout<<v.size()<<endl;
    // cout<<v.capacity()<<endl;
    // v.clear();
    // cout<<v.size()<<endl;
    // cout<<v.capacity()<<endl;
    // vector<int> v1(5,1); // size=5, initialize all eles as 1
    // for(int i:v1){
    //     cout<<i<<" ";
    // }cout<<endl;
    // vector<int> v2(v1); // basically v2 similar to v1 
    
// Deque
    // deque<int> d;
    // d.push_back(1);
    // d.push_front(2);
    // d.push_back(3);
    // for(int i:d){
    //     cout<<i<<" ";
    // }cout<<endl;
    // cout<<d.at(1)<<endl;
    // cout<<d.empty()<<endl;
    // cout<<d.size()<<endl;       // num of ele
    // cout<<d.max_size()<<endl;   
    // d.erase(d.begin(),d.end());
    // cout<<d.size()<<endl;
    // cout<<d.max_size()<<endl;

// List
    // list<int> l;
    // l.push_back(1);
    // l.push_front(2);
    // for(int i:l){
    //     cout<<i<<" ";
    // }cout<<endl;
    // cout<<l.front()<<endl;
    // cout<<l.back()<<endl;
    // cout<<l.size()<<endl;
    // l.erase(l.begin());
    // cout<<l.empty()<<endl; 
    // list<int> l2(5,100);    // 5 elements, initialized with 100
    // for(int i:l2){
    //     cout<<i<<" ";
    // }cout<<endl;

// Stack
    // stack<string> s;
    // s.push("love");
    // s.push("babbar");
    // s.push("kumar");
    // cout<<"Top ele :"<<s.top()<<endl;
    // cout<<"Size :"<<s.size()<<endl;
    // s.pop();
    // cout<<"Top ele :"<<s.top()<<endl;
    // cout<<"Size :"<<s.size()<<endl;

// Queue
    // queue<string> q;
    // q.push("love");
    // q.push("babbar");
    // q.push("kumar");
    // cout<<"Front ele :"<<q.front()<<endl;
    // cout<<"Size : "<<q.size()<<endl;
    // q.pop();
    // cout<<"Front ele :"<<q.front()<<endl;
    // cout<<"Size : "<<q.size()<<endl;

// Priority Queue
    // priority_queue<int> maxHeap;  // default is max_heap based
    // maxHeap.push(1);
    // maxHeap.push(2);
    // maxHeap.push(0);
    // maxHeap.push(3);
    // int n=maxHeap.size();
    // for(int i=0;i<n;i++){
    //     cout<<maxHeap.top()<<" ";
    //     maxHeap.pop();
    // }cout<<endl;
    // priority_queue<int,vector<int>,greater<int>> minHeap;
    // minHeap.push(1);
    // minHeap.push(2);
    // minHeap.push(3);
    // minHeap.push(0);
    // int m=minHeap.size();
    // for(int i=0;i<m;i++){
    //     cout<<minHeap.top()<<" ";
    //     minHeap.pop();
    // }cout<<endl;
    // cout<<minHeap.empty()<<endl;

// Set
    // set<int> s;
    // s.insert(1);
    // s.insert(5);
    // s.insert(5);
    // s.insert(6);
    // s.insert(3);
    // s.insert(3);
    // s.insert(3);
    // for(auto i:s){
    //     cout<<i<<" ";
    // }cout<<endl;
    // cout<<s.size()<<endl;
    // set<int>::iterator it=s.begin();
    // it++;
    // s.erase(it);
    // cout<<s.count(-5)<<endl;
    // set<int>::iterator itr=s.find(5);
    // cout<<*itr<<endl;

// Map
    // map<int,string> m;
    // m[1] = "babbar";
    // m[2] = "love";
    // m[13] = "kumar";
    // m.insert({5,"bheem"});
    // for(auto i:m){
    //     cout<<i.first<<" "; // printed in sorted order in map & unsorted in unordered map
    //     cout<<i.second<<" ";
    // }cout<<endl;
    // cout<<"finding 13 -> "<<m.count(13)<<endl;
    // cout<<"finding 13 -> "<<m.count(-13)<<endl;
    // cout<<"Erasing 13"<<endl;
    // m.erase(13);  
    // for(auto i:m){
    //     cout<<i.first<<" ";
    //     cout<<i.second<<" ";
    // }cout<<endl;
    // auto it=m.find(5);
    // for(auto i=it;i!=m.end();i++){
    //     cout<<(*i).first<<endl;
    // }

// ALGORITHMS
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    cout<<binary_search(v.begin(),v.end(),7)<<endl;
    cout<<"Lower bound -> "<<lower_bound(v.begin(),v.end(),4)-v.begin()<<endl;
    cout<<"Lower bound -> "<<upper_bound(v.begin(),v.end(),5)-v.begin()<<endl;
    cout<<max(3,10)<<endl;
    cout<<min(3,18)<<endl;
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    string name="Sarthak";
    reverse(name.begin(),name.end());
    cout<<name<<endl;
    reverse(name.begin(),name.end());
    cout<<name<<endl;
    rotate(name.begin(),name.begin()+2,name.end());
    cout<<name<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;


    
    return 0;
}