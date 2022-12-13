#include<iostream>
#include<queue>
using namespace std;

/*
Doubly Ended Queue
- push_front
- push_back
- pop_front
- pop_back
*/

int main(){
    
    deque<int>d;    // doubly ended queue
    cout<<d.empty()<<endl;
    d.push_front(12);
    d.push_front(11);
    d.push_back(13);
    d.push_back(14);
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    d.pop_front();
    cout<<d.front()<<endl;
    d.pop_back();
    cout<<d.back()<<endl;
    cout<<d.empty()<<endl;
    
    
    return 0;
}