#include<iostream>
using namespace std;
/*
Insertion Sort:
    - Pick element & put it in right position in sorted array
Time Complexity = O()    
    Best Case = O()
    Worst Case = O()
Space Complexity = O(1)
*/

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>=0;j--){
            if(arr[j]<=arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}


int main(){
    
    int arr[]={3,5,4,6,1,2,9,8,7};
    int n=9;
    print(arr,n);
    insertionSort(arr,n);
    print(arr,n);
    
    return 0;
}