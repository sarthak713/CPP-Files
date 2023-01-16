#include<iostream>
using namespace std;

/*
Max Heapify Algorithm:
    - we have to make heap from an array
    - For complete binary tree, leaf nodes are from
        - (n/2 + 1) to (n) index
    - leaf nodes are heap in themselves as they don't have any child nodes
    - So, to convert array into heap, we process only
        - (n/2) to (>0) 
    - And put nodes at correct position
        - compare node to left, right child
        - then go to parent & compare again
    - T.C. = O(log n)

Build Min Heap:
    - T.C. = O(n)
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

void maxHeapify(int arr[],int n,int i){     // On sedcond iteration of for loop in main():
    int largest=i;                          // largest=2, i=1
    int left=2*i;                           // left=2
    int right=2*i + 1;                      // right=3
    if(left<n && arr[largest]<arr[left]){   // arr[large]=54 arr[left]=53
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){ // arr[large]=54 arr[right]=55
        largest=right;                      // largest=3
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);          // arr[large]=55, arr[i]=54
        maxHeapify(arr,n,largest);
    }
}

/*
Max Heap = 54 55 53 52 50
        54          1 
     53    55       2,3    
   52  50           4,5
n=5,i=2 -> nothing happens as left child of 54 is small      
n=5,i=1 -> 55 is swapped with 54, and maxHeap is updated
        55        
     53    54      
   52  50 
*/

/*
For 0 based indexing:
    - left child = 2*i + 1
    - right child = 2*i + 2
*/
void minHeapify(int arr[],int n,int i){
    int smallest=i;
    int left=2*i + 1;
    int right=2*i + 2;
    if(left<n && arr[smallest]>arr[left]){
        smallest=left;
    }
    if(right<n && arr[smallest]>arr[right]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        minHeapify(arr,n,smallest);
    }
}

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


// MAX HEAPIFY
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){     // from n/2 to > 0, no leaf nodes are processed
        maxHeapify(arr,n,i);   
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

// MIN HEAPIFY  
    int arr2[5]={49,48,50,51,52};
    int m=5;
    for(int i=m/2-1;i>=0;i--){
        minHeapify(arr2,m,i);
    }
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }cout<<endl;

    
    
    return 0;
}