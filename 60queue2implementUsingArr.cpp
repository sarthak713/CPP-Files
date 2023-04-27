#include<iostream>
using namespace std;

/*
Implementing Queue using Array

- Enqueue = insertion at end
- Dequeue = pop from front

T.C. = O(1) for all operations
*/

class Queue{
    int *arr;
    int size;
    int qfront;
    int rear;
public:
    Queue(){
        size = 1000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    bool isEmpty(){
        return qfront==rear;
    }
    void enqueue(int data){
        if(rear==size){
            return;
        }
        arr[rear] = data;
        rear++;
    }
    int dequeue(){
        if(qfront==rear){
            return -1;
        }
        int data = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(qfront==rear){
            qfront = 0;
            rear = 0;
        }
        return data;
    }
    int front(){
        if(qfront==rear){
            return -1;
        }
        return arr[qfront]; 
    }
};

int main(){

    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(1);
    cout<<q.isEmpty()<<endl;
    
    
    
    return 0;
}