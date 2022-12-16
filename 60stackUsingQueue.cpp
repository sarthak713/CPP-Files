#include<iostream>
#include<queue>
using namespace std;

/*
Stack Using Queue:
    Approach 1 = Making Push Costly 
        - We use 2 queues: q1 and q2
        - push element in q2
        - then pop elements from q1 and push into q2
        - swap q1 and q2
        - To pop: pop from q1
    Approach 2 = Making Pop Costly
        - We use 2 queues: q1 and q2
        - To Push: push in q1
        - To Pop:
            - put elements from q1 to q2 except one, So till q1.size()!=1
            - pop that element from q1
            - swap q1 q2
*/

// Push Costly
class StackUsingQueue1{     
    int size;
    queue<int>q1;
    queue<int>q2;
public:
    StackUsingQueue1(){
        size=0;
    }
    void push(int x){
        q2.push(x);                 // push element into q2
        size++;                     // increment size
        while(!q1.empty()){         // pop all elements from q1, push into q2
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>temp=q1;          // swap q1 and q2
        q1=q2;
        q2=temp;
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        q1.pop();                   // pop from q1
        size--;
    }
    int top(){
        return q1.front();
    }
    int stacksize(){
        return size;
    }
};

// Pop Costly
class StackUsingQueue2{
    int size;
    queue<int>q1;
    queue<int>q2;
public:
    StackUsingQueue2(){
        size=0;
    }
    void push(int x){
        q1.push(x);                 // push into q1
        size++;
    }
    void pop(){
        if(q1.empty()){
            return;
        }
        while(q1.size()!=1){        // push elements from q1 into q2, except one
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();                   // pop last element
        size--;
        queue<int>temp=q1;
        q1=q2;
        q2=temp;
    }
};


int main(){
    
    
    
    return 0;
}