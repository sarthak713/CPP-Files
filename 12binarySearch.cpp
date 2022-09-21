#include<iostream>
using namespace std;

/*
Linear Search
    - Check elements in array, one by one to check if key exists
    - Time Complexity O(n)

Binary Search
    - only works on monotonic functions (elements should either be in ascending or descending order)
    - Time Complexity O(log n)
*/

int binarySearch(int arr[],int n,int key){
    int l=0;
    int r=n-1;
    int mid;
    while(l<=r){
        mid=l+(r-l)/2;      // to stay in int range (2^31-1)
        if(arr[mid]==key){
            return mid;
        }
        else if(key>arr[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}

int main(){

    int arr[]={1,2,3,4,5,6};
    int n=5;
    int key=4;
    cout<<binarySearch(arr,n,key)<<endl;

    
    return 0;
}