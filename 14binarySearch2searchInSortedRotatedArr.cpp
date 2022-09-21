#include<iostream>
using namespace std;


// METHOD 1------------------------------
int findPivot(int arr[],int n){
    int l=0;
    int r=n-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]>=arr[0]){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return r;
}
int binarySearch(int arr[],int left,int right,int key){
    int l=left;
    int r=right;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}
int searchInSortRotArr(int arr[],int n,int key){
    int pivot=findPivot(arr,n);
    if(arr[pivot]<=key && key<=arr[n-1]){
        return binarySearch(arr,pivot,n-1,key);
    }
    return binarySearch(arr,0,pivot-1,key);
}

// METHOD 2------------------------------
int findKeyWithBinarySearch(int arr[],int l,int r,int key){
    if(l>r){
        return -1;
    }
    int mid=l+(r-l)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]>=arr[l]){
        if(arr[l]<=key && key<=arr[mid]){
            return findKeyWithBinarySearch(arr,l,mid-1,key);
        }
        return findKeyWithBinarySearch(arr,mid+1,r,key);
    }
    if(arr[mid]<=key && key<=arr[r]){
        return findKeyWithBinarySearch(arr,mid+1,r,key);
    }
    return findKeyWithBinarySearch(arr,l,mid-1,key);
}


// METHOD 3------------------------------


int main(){

    // int arr[]={30, 40, 50, 10, 20};
    // int n=5;   
    // int key=10;
    // int arr[]={5, 6, 7, 8, 9, 10, 1, 2, 3};
    // int n=9;   
    // int key=30;
    int arr[]={5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n=9;   
    int key=3;
    // int arr[]={4,5,6,7,0,1,2};
    // int n=7;   
    // int key=7;
    // cout<<searchInSortRotArr(arr,n,key);


    cout<<findKeyWithBinarySearch(arr,0,n-1,key);
    
    return 0;
}