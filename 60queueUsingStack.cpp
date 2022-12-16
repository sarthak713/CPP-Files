#include<iostream>
#include<stack>
using namespace std;

/*
Queue Using Stack

Approach 1:
    - using 2 stacks
    - dequeue Operation is costly but not enqueue
    - To Push: 
        - push into stack1
    - To Pop:
        - if both stacks empty, return -1
        - if stack2 is empty & stack1 is not empty, push everything from stack1 to stack2
        - pop element from stack2 & return it

Approach 2:
    - using function call stack, only 1 stack needed
    - To Push:
        - push into stack
    - To Pop:
        - if stack is empty, return -1
        - store top, pop from stack
            - if empty, return stored element
        - recursively call pop while storing it
        - push top 
        - return cecursive call

*/

// Approach 1
class QueueUsingStack1{
    stack<int>s1;
    stack<int>s2;
public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top=s2.top();
        s2.top();
        return top;
    }
    bool empty(){
        return s1.empty() && s2.empty();
    }
};

// Approach 2
class QueueUsingStack2{
    stack<int>s;
public:
    void push(int x){
        s.push(x);
    }
    int pop(){
        if(s.empty()){
            return -1;
        }
        int top=s.top();
        s.pop();
        if(s.empty()){
            return top;
        }
        int item=pop();
        s.push(top);
        return item;
    }
    bool empty(){
        return s.empty();
    }
};

int main(){
    
    
    
    return 0;
}