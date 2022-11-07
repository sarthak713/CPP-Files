#include<iostream>
using namespace std;

/*
QUICK SORT

2 Step Process:
    - Partition
    - Sort using recursion

- pick an element (Pivot) & put it in its right position 
- where on its left there should only be smaller elements
- & on its right there should ony be greater elements (Partition)

Pivot
    - element picked to put in right position
    - count all elements < pivot
    - put pivot at right place: start+count, by swapping element there
Apply Condition: 
    - smaller elements on left & greater on right
    - take 2 pointers, i=start & j=end
    - if i>j swap, i++ j--
    - when position of i=j, stop 
Use recursion & sort for rest of the parts
*/

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int partition(int *arr,int start,int end){
    int pivot = arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++){          // find number of elements smaller than pivot
        if(arr[i]<pivot){                   // to put it in its place 
            count++;
        }
    }
    int pivotIndex = start+count;
    swap(arr[start], arr[pivotIndex]); 

    // solve: smaller elements on left & greater elements on right
    int i=start;
    int j=end;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>=pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr,int start,int end){
    if(start>=end){
        return;
    }
    int p = partition(arr,start,end);   // gives a partition index as output
    quickSort(arr,start,p-1);           // sort left part
    quickSort(arr,p+1,end);             // sort right part
}

int main(){

    int arr[]={2,5,1,6,9,1,2,4,14,7,5};
    int n=11;
    quickSort(arr,0,n-1);
    print(arr,n);
    
    return 0;
}