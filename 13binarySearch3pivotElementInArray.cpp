#include<iostream>
using namespace std;

/*
Pivot index
    - sum of numbers to left of index = sum of numbers to index's right
    - If index is on left edge, then left sum is. Same for right
    - Return the leftmost pivot index. If no such index exists, return -1.
Input: nums = [1,7,3,6,5,6] 
Output: 3
Input: nums = [1,2,3]
Output: -1
Input: nums = [2,1,-1]
Output: 0
*/

int pivotIndex(int arr[],int n){
    int suml=0;
    int sumTotal=0;
    for(int i=0;i<n;i++){
        sumTotal+=arr[i];   // calculate total sum of array
    }
    int i=0;
    while(i<n){
        sumTotal-=arr[i];   // find right sum by subtracting first element from array
    // 27 20 17 11
        if(suml==sumTotal){ // compare left & right sums
    // 27!=0 20!=1 17!=8 11==11
            return i;       // if equal return index
        }
        suml+=arr[i];       // update left sum by adding element
    // 1 8 11
        i++;                // increment i
    }
    return -1;              // if no sum exists, return -1
}

int main(){
    
    // int arr[]={2,1,-1};
    // int n=3;
    // int arr[]={1,2,3};
    // int n=3;
    int arr[]={1,7,3,6,5,6};
    int n=6;
    cout<<pivotIndex(arr,n);


    
    return 0;
}