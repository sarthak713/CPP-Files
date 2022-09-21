#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

/*
Aggressive Cows : 
    - arr[N] = position of stalls
    - k = number of cows
    - Assign cows to stalls
    - Minimum distance between any 2 cows is maximum
    - Return largest minimum distace
Example : 
    - Let start=0 & maximum=maxEleInArray
    - For search space: start=0, end=maximum
    - Find mid 0+5/2=2, we check if we can place cows in distance=2
    - From left 1 to 2=1, not possible
    - We move ahead 1 to 3=2, possible as (max-min>=2)
    - It is possible, so we move start=mid+1, as higher than this will also be possible
*/
 
bool isPossible(int arr[],int n,int k,int mid){
    int cow=1;
    int lastPosition=arr[0];    // we start by placing first cow at first index
    for(int i=0;i<n;i++){
        if(arr[i]-lastPosition>=mid){   // keep finding bigger distance
            cow++;                   
            if(cow==k){           
                return true;
            }
            lastPosition=arr[i];        
        }
    }
    return false;
}

int aggresiveCows(int arr[],int n,int k){
    sort(arr,arr+n);
    int start=0;
    int maximum=-1;
    for(int i=0;i<n;i++){
        maximum=max(maximum,arr[i]);
    }
    int end=maximum;  
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;  
        if(isPossible(arr,n,k,mid)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;               
        }
    }
    return ans;
}

int main(){

    // int n=3;
    // int arr[]={1,2,3};  // output: 2

    int n=5;
    int arr[]={4,1,2,3,6};  // output: 5
 
    int k=2;
    cout<<aggresiveCows(arr,n,k)<<endl;
    
    return 0;
}