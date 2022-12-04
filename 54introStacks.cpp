#include<iostream>
// #include<stack>      // STL: push,pop,empty,top,size
using namespace std;

/*
Stacks Introduction

LIFO = Last In First Out

Operations:
1. Push = insertion from top
2. Pop = removal from top
3. Top = return top element
4. Empty = returns true if stack is empty, false if not 

Stack Implementation:
1. Array
    - take top index, initially top=-1
    - if top > size, stack overflow
    - push top++
    - pop top--
    - T.C. of all operations = O(1)
2. Linked List

*/

// Stack using Array
class StackArr{
public:
    int *arr;
    int top;
    int size;
    StackArr(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int data){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=data;
    } 
    void pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        top--;
    }
    bool empty(){ 
        if(top==-1){
            return 1;
        }
        return 0;
    }
    int peek(){
        if(top>=0){
            return arr[top];
        } 
        return -1;
    }
};

// Stack using Linked List
class Node{
public:
    int data;
    Node*next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
class StackLL{
    Node*top;
public:
    StackLL(){
        top=NULL;
    }
    void push(int data){
        Node*temp=new Node(data);
        if(!temp){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        temp->data=data;
        temp->next=top;
        top=temp;
    } 
    void pop(){
        Node*temp;
        if(top==NULL){
            cout<<"Stack underflow"<<endl;
            return;
        }
        else{
            temp=top;
            top=top->next;
            delete temp;
        }
    }
    bool empty(){ 
        return top==NULL;
    }
    int peek(){
        if(!empty()){
            return top->data;
        }
        cout<<"Stack is Empty"<<endl;
        return;
    }
    void print(){
        Node*temp;
        if(top==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};


int main(){
    
    // stack<int> s;    // Using STL

    StackArr s(3);
    s.push(22);
    s.push(43);
    s.push(44);
    cout<<s.peek()<<endl;   // 44
    s.pop();
    cout<<s.peek()<<endl;   // 43
    s.pop();
    cout<<s.peek()<<endl;   // 22
    s.pop();
    cout<<s.peek()<<endl;   // 22
    s.pop();
    cout<<s.peek()<<endl;   // 22
    cout<<s.empty()<<endl;  // 1


    
    
    return 0;
}