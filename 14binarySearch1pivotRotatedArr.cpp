#include<iostream>
using namespace std;

int pivotIndexRotated(int arr[],int n){
    int l=0;
    int r=n-1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]>=arr[0]){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    return r;
}

int main(){

/*
Pivot Index In Rotated Array

int arr[]={7,9,1,2,3};int n=5;
Output : 2
int arr[]={7,10,10,2};int n=4;
Output : 3
int arr[]={3,8,10,17,1};int n=5;
Output : 4
*/

    int arr[]={7,10,10,2};int n=4;
    cout<<pivotIndexRotated(arr,n)<<endl;

    return 0;
}