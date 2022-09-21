#include<iostream>
using namespace std;
/*
Painter's Partition Problem

Given arr[], k painters
1 unit board = 1 unit time to paint
Can paint continuous section
Find minimum time to paint all boards
Partition in such a way, required time to paint is Minimum

- When possible solution
    - store answer
    - go to left part, end=mid-1
- When non-possible solution
    - go to right part, start=mid+1
*/

bool isPossible(int arr[],int n,int m,int mid){
    int painter=1;
    int boardSum=0;
    for(int i=0;i<n;i++){
        if(boardSum+arr[i]<=mid){
            boardSum+=arr[i];
        }else{
            painter++;
            if(painter>m || arr[i]>mid){
                return false;
            }
            boardSum=arr[i];
        }
    }
    return true;
}

int painterPartition(int arr[],int n,int k){
    int start=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int end=sum;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(arr,n,k,mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}


int main(){
    
    // int arr[]={10,20,30,40}; // output: 60
    // int arr[]={5,5,5,5};    // output: 10
    // int n=4;
    // int k=2;

    // int arr[]={48,90};
    // int n=2;
    // int k=2;
    int arr[]={1,2,3,4};
    int n=4;
    int k=2;

    cout<<painterPartition(arr,n,k)<<endl;

    
    
    return 0;
}