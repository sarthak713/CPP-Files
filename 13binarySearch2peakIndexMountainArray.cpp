#include<iostream>
using namespace std;
/*
Find Peak Index of Mountain Array

First Half:
    - increasing order
    - arr[i] < arr[i+1]
Second Half:
    - decreasing order
    - arr[i] > arr[i+1]
Peak
    - arr[i-1] < arr[i] > arr[i+1]
*/

int peakOfMountain(int arr[],int n){
    int l=0;
    int r=n-1;
    int mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(arr[mid]<arr[mid+1]){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    return l;
}

int main(){

    int arr[]={23,3,2,1};
    int n=5;
    cout<<peakOfMountain(arr,n)<<endl;

    
    return 0;
}