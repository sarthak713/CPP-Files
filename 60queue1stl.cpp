#include<iostream>
#include<queue>
using namespace std;

/*
QUEUES

- FIFO = first in first out
Push is at end
Pop is from front

Implement using STL and Operations:
- queue<int> q;
- q.push(data);
- q.pop();
- q.size();
- q.empty(); 
- q.front();

*/

int main(){
    
    queue<int>q;
    cout<<"Is queue empty: "<<q.empty()<<endl;  // 1
    q.push(11);
    cout<<"Front of queue: "<<q.front()<<endl;  // 11
    q.push(15);
    q.push(13);
    cout<<"Front of queue: "<<q.front()<<endl;  // 11
    cout<<"Size of Queue: "<<q.size()<<endl;    // 3
    q.pop();
    cout<<"Size of Queue: "<<q.size()<<endl;    // 2
    cout<<"Front of queue: "<<q.front()<<endl;  // 15
    cout<<"Is queue empty: "<<q.empty()<<endl;  // 0

    return 0;
}