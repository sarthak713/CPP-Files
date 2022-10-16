#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

// Bubble Sort
void bubbleSort(int *arr,int n){
    if(n==1 || n==0){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
}

// Selection Sort
void selectionSort(int *arr,int n){
    if(n==0 || n==1){
        return;
    }
    int minIndex=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[minIndex]){
            swap(arr[i],arr[minIndex]);
        }
    }
    selectionSort(arr+1,n-1);
}

// Insertion Sort
void insertionSort(int *arr,int n){
    print(arr,n);
    if(n==0 || n==1){
        return;
    }
    for(int j=1;j<n;j++){
        if(arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
        }
    }
    insertionSort(arr+1,n-1);
}

int main(){
    
// Bubble Sort
    // int arr[]={2,5,9,1,6,6,4,3};
    // int n=8;
    // bubbleSort(arr,n);
    // print(arr,n);
    
// Selection Sort
    // int arr[]={2,5,9,1,6,6,4,3};
    // int n=8;
    // selectionSort(arr,n);
    // print(arr,n);
    
// Insertion Sort
    // int arr[]={2,1,9,1,6,6,4,3};
    // int n=8;
    // insertionSort(arr,n);
    // print(arr,n);






    return 0;
}