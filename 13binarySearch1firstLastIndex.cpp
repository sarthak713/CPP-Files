#include<iostream>
using namespace std;

// First & Last Position of Element in Sorted Array

int firstOccurence(int arr[],int n,int key){
    int l=0;
    int r=n-1;
    int mid;
    int ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]==key){
            ans=mid;    // updates ans value
            r=mid-1;    // checks to left again if key is present
        }
        else if(arr[mid]>key){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int lastOccurence(int arr[],int n,int key){
    int l=0;
    int r=n-1;
    int mid;
    int ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]==key){
            ans=mid;    // updates ans value
            l=mid+1;    // checks to right again if key is present
        }
        else if(arr[mid]>key){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}


int main(){

    
// First & Last Position of Element in Sorted Array
    int arr[]={1,2,2,3,3,3,3,3,3,3,3,4,5};
    int n=13;
    int key=3;     // Output = -1 -1
    cout<<firstOccurence(arr,n,key)<<" ";
    cout<<lastOccurence(arr,n,key)<<endl;

// Total Occurences Of Element in Sorted Array 
    cout<<(lastOccurence(arr,n,key)-firstOccurence(arr,n,key))+1;




    
    return 0;
}