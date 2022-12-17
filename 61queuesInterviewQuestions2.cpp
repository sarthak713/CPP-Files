#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

/*
Queue Interview Questions:

1. Circular Tour (GFG)
    Approach 1:
        - front and rear = 0
        - balance = previousBalance + petrol - distance
        - if travel is possible which means (petrol-distance>=0)
            - rear++
            - if while doing this (front==rear) then circle is complete
        - if travel not possible
            - increment front, front=rear+1
        - For this approach, in worst case:
            - a block will be travelled 2 times
    Approach 2:
        - When we find that we cannot travel further with one element
            - we store its and previous ones balance, so we don't have to traverse again
        - for this we store a deficit, and when we reach that point where we know deficit is there
            - we add balance & deficit,
            - if balance + deficit >= 0, answer is possible

2. Interleave 1st half of queue with 2nd half (GFG)
    - Input: 1 2 3 4 5 6
    - Output: 1 4 2 5 3 6
    Approach 1:
        - fetch 1st half elements from input queue
            - push into new queue = 1 2 3 
        - while !newQueue.empty()
            - push newQueue element into old queue
            - the push queue element into queue
            - repeat
        - T.C.=O(n), S.C.=O(1) 
    Approach 2:
        - push 1st half of queue into stack
        - push full stack again into queue
        - pop first half of queue, and push into queue
        - push 1st half of queue into stack again
        - now, while stack is not empty
            - pop from stack, push into queue
            - pop from queue, push into queue
        - return queue
        
3. Implement 'k' queues in an array
    - Requirements:
        1 array to store data, arr[n]
        2 we need 2 more arrays: front[k], rear[k]
            - both initialized by -1 
        3 next[n], for next free block
            - initially like this: [1,2,3,4,5,-1]
        4 freeSpot variable, initially 0
    - To Push:
        - Check overflow
            when freeSlot=-1
        - find index to push element, index=freeSpot
            update freeSpot, freeSpot=next[index]
        - if(first element) means front[qn]==-1
            front[qn]=index
        - else, because when we insert elements into diff queue, they are in between each other, 
        so this is done to connect elements of same queue using next[] array
            next[rear[qn]]=index    // link new element of queue with previous rear
        - to push in current, means no freeSpot available so,
            next[index]=-1
        - to push in rear, we increment it to where we push
            rear[qn]=index

4. Sum of minimum & Maximum elements of all subarrays of size k
    
*/

// Ques 1: Circular Tour
struct petrolPump{
    int petrol;
    int distance;
};
int tour(petrolPump p[],int n){
    int deficit = 0;
    int balance = 0;
    int start = 0;
    for(int i=0;i<n;i++){
        balance = balance + p[i].petrol - p[i].distance;
        if(balance < 0){
            deficit = deficit + balance;
            start = i + 1;
            balance = 0;
        }
    }
    if(deficit + balance >= 0){
        return start;
    }
    return -1;
}

// Ques 2: Interleave 1st half of queue with 2nd half
// Approach 1 - using a queue
queue<int> interleave1(queue<int>q,int n){
    queue<int>newq;
    for(int i=0;i<n/2;i++){
        int data=q.front();
        newq.push(data);
        q.pop();
    }
    while(!newq.empty()){
        int data1=newq.front();
        int data2=q.front();
        newq.pop();
        q.pop();
        q.push(data1);
        q.push(data2);
    }
    return q;
}
// Approach 2 - using a stack
queue<int> interleave2(queue<int>q,int n){
    stack<int>s;
    for(int i=0;i<n/2;i++){
        int data=q.front();
        q.pop();
        s.push(data);
    }
    while(!s.empty()){
        int data=s.top();
        s.pop();
        q.push(data);
    }
    for(int i=0;i<n/2;i++){
        int data=q.front();
        q.pop();
        q.push(data);
    }
    for(int i=0;i<n/2;i++){
        int data=q.front();
        q.pop();
        s.push(data);
    }
    while(!s.empty()){
        int data1=s.top();
        s.pop();
        q.push(data1);
        int data2=q.front();
        q.pop();
        q.push(data2);
    }
    return q;
}

// Ques 3: Implement 'k' queues in an array
class kQueue{
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;
public: 
    kQueue(int n,int k){
        this->n=n;
        this->k=k;
        arr=new int[n];
        front=new int[k];
        rear=new int[k];
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        next=new int[n];
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        freeSpot=0;
    }
    void enqueue(int data,int qn){
        if(freeSpot==-1){       // check overflow
            return;
        }
        int index=freeSpot;     // find first free index
        freeSpot=next[index];   // update freeSpot
        if(front[qn-1]==-1){    // check for first element
            front[qn-1]=index;
        }
        else{
            next[rear[qn-1]]=index;     // link new element to previous rear
        }
        next[index]=-1;         // update next
        rear[qn-1]=index;       // update rear
        arr[index]=data;        // push element
    }
    int dequeue(int qn){
        if(front[qn-1]==-1){    // check underflow
            return;
        }
        int index=front[qn-1];      // find index to pop
        front[qn-1]=next[index];    // increment front
        next[index]=freeSpot;       // manage freeSpot
        freeSpot=index;
        return arr[index];
    }
};



int main(){
 
    return 0;
}