#include<iostream>
using namespace std;

/*
HEAPS

- Heap = complete binary tree that comes with a heap order property

- Complete Binary Tree
    - each level is fully filled except last level
    - nodes are always added from the left
- Heap Order Property
    - Max Heap = for each node, child nodes are smaller than parent node
    - Min Heap = for each node, child nodes are greater than parent node

We implement Heap with Array:
    - 0th index is always empty
    - For a node at i index:
        - Left child is found at index (2*i)
        - Right child is found at index (2*i + 1)
        - Parent is found at index (i/2)

Insertion:
    - insert new node a end of array
    - take node to correct position
        - by comparing node with its parent at i/2 index
        - if parent is smaller, swap
    - T.C. = O(log n)
Deletion: (deleting root node)
    - make root data = last node data
    - remove last node
    - check if heap order is maintained
        - put root at correct position
    - T.C. = O(log n)
*/

class heap{
public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int value){
        size=size+1;
        int index=size;
        arr[index]=value;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
    void deletion(){
        if(size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};



int main(){
    
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletion();
    h.print();
    
    
    return 0;
}