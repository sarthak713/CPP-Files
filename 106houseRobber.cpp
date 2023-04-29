#include<iostream>
#include<vector>
using namespace std;

/*
House Robber (Leetcode 198)
*/

int rob(vector<int>&arr){
    int n=arr.size();
    if(n==1){
        return arr[0];
    }
    int prev1=0;
    int prev2=arr[0];
    int curr=max(prev1,prev2);
    for(int i=1;i<n;i++){
        int include=prev1+arr[i];
        int exclude=prev2;
        curr=max(include,exclude);
        prev1=prev2;
        prev2=curr;
    }
    return curr;
}

int main(){
    
    vector<int>arr={2,7,9,3,1};
    cout<<rob(arr)<<endl;
    
    return 0;
}