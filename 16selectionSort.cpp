#include<iostream>
using namespace std;

/*
Selection Sort :
    - Find smallest element & place it in its right position
Complexity :
    - Time  = O(n^2)
    - Space = O(1)
Used Case :
    - Whenever array/vector size is small
*/

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<=arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main(){

    int arr[]={7,4,5,2,3,5,2,9,8,1,2,4,5,6};
    int n=14;
    print(arr,n);
    selectionSort(arr,n);
    print(arr,n);


    return 0;
}