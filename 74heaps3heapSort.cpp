#include<iostream>
// Heap is implemented using queue
#include<queue>
#include<vector>
using namespace std;

/*
Max Heap Sort

        70
     60    55
   45  50

Array = {x, 70,60,55,45,50}

Algorithm:
    - Topmost is maximum element, swap root with last element
        - swap(arr[i],arr[size])
        {x, 50,60,55,45|70}
        - size--
    - Put root at correct position
        - by comparing with child left & right nodes, heapify function
        - so we swap 60 with 50, to make max heap
        {x, 60,50,55,45|70}
    - Repeat first step, swap root with last element
        {x, 45,50,55|60,70}
        - size--
    - Put root at correct position
        {x, 55,50,45|60,70}
        {x, 45,50|55,60,70}
        - size--
    Again:
        {x, 45,50,55,60,70}

Steps:
- swap root with last node
- put root at correct position
- repeat while (size > 1)

T.C. = O(n log n)
*/


class heap{
public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }else{
                return;
            }
        }
    }
    void deletion(){
        if(size==0){
            cout<<"Empty heap"<<endl;
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

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i + 1;
    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}


int main(){
    
    heap h;
    h.insert(70);
    h.insert(60);
    h.insert(55);
    h.insert(45);
    h.insert(50);
    h.print();

    int arr[]={-1,70,60,55,45,50};
    int n=5;
    heapSort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<endl<<endl;
    


// Using Priority Queue

// MAX-HEAP
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"Size of MaxHeap: "<<pq.size()<<endl;     // 4
    cout<<"Top Element: "<<pq.top()<<endl;          // 5
    pq.pop();
    cout<<"Top Element: "<<pq.top()<<endl;          // 4
    cout<<"Is MaxHeap empty: "<<pq.empty()<<endl;   // 0

    cout<<endl<<endl;

// MIN-HEAP
    priority_queue<int,vector<int>,greater<int> > minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    cout<<"Size of MinHeap: "<<minHeap.size()<<endl;      // 4
    cout<<"Top Element: "<<minHeap.top()<<endl;           // 2
    minHeap.pop();
    cout<<"Top Element: "<<minHeap.top()<<endl;           // 3
    cout<<"Is MinHeap empty: "<<minHeap.empty()<<endl;    // 0

    
    return 0;
}