#include<iostream>
using namespace std;

/*
Circular Queue

- In normal queue, elemens are pushed until rear=size-1, then rear=size
- But in circular queue, after elements are pushed till rear=size-1, rear comes back to 0 index of array
    - And elements are pushed again from starting
*/

class CircularQueue{
    int *arr;
    int size;
    int front;
    int rear;
public:
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    bool enqueue(int data){
        if(front==0 && rear==size || rear==(front-1)%(size-1)){   // condition when queue is full
            return false;
        }
        else if(front==-1){     // means queue is empty, so initialize front & rear with 0
            front = 0;
            rear = 0;
        }
        else if(rear==size-1 && front!=0){      // rear is at end and front in middle, so space is left in the starting
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear]=data;
        return true;
    }
    int dequeue(){
        if(front==-1){      // check for empty queue
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front==rear){        // only 1 element in queue
            front = -1;
            rear = -1;
        }
        else if(front==size-1){     // front is at end of queue, so put front at start again
            front = 0;              // maintain cyclic nature
        }
        else{
            front++;
        }
        return ans;
    }
};

int main(){
    
    
    
    return 0;
}