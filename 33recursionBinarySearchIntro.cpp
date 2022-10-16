#include<iostream>
using namespace std;

bool isArraySorted(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    return isArraySorted(arr+1,n-1);
}

int findArraySum(int arr[],int n){
    if(n==0){
        return 0;
    }
    int sum=arr[0];
    return sum+findArraySum(arr+1,n-1);
}

bool linearSearch(int arr[],int n,int target){
    if(n==0){
        return false;
    }
    if(arr[0]==target){
        return true;
    }
    return linearSearch(arr+1,n-1,target);
}

// Binary Search

bool binarySearch(int arr[],int n,int start,int end,int target){
    if(start>end){
        return false;
    }
    int mid=start+(end-start)/2;
    if(arr[mid]==target){
        return true;
    }
    if(target<arr[mid]){
        return binarySearch(arr,n,start,mid-1,target);
    }
    return binarySearch(arr,n,mid+1,end,target);
}


int main(){
    
// Find if Array isSorted or Not
    // int arr[]={2,4,6,9,12,13,13};
    // int n=6;
    // cout<<isArraySorted(arr,n)<<endl;
    
// Find Sum of Array
    // int arr[]={2,4,9,9,9};
    // int n=5;
    // cout<<findArraySum(arr,n)<<endl;

// Linear Search
    // int arr[]={2,4,6,9,12,13};
    // int n=6;
    // int target=13;
    // cout<<linearSearch(arr,n,target)<<endl;

// Binary Search
    // int arr[]={2,4,6,9,12,13,17};
    // int n=7;
    // int target=11;
    // int start=0;
    // int end=n-1;
    // cout<<binarySearch(arr,n,start,end,target)<<endl;
    
    
    return 0;
}