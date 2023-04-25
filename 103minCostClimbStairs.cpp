#include<iostream>
#include<vector>
using namespace std;

/*
Minimum Cost Climbing Stairs (Leetcode 746)
*/

// RECURSION
int solve(int n,vector<int>arr){
    if(n==0 || n==1){
        return arr[n];
    }
    return min(solve(n-1,arr),solve(n-2,arr))+arr[n];
}
int minCost(vector<int>& arr){
    int n=arr.size();
    return min(solve(n-1,arr),solve(n-2,arr));    
}

// TOP DOWN
int solve1(int n,vector<int>arr,vector<int>&dp){
    if(n==0 || n==1){
        return arr[n];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=min(solve1(n-1,arr,dp),solve1(n-2,arr,dp))+arr[n];
    return dp[n];
}
int minCost1(vector<int>& arr) {
    int n=arr.size();
    vector<int>dp(n+1,-1);
    return min(solve1(n-1,arr,dp),solve1(n-2,arr,dp));
}

// BOTTOM UP
int minCost2(vector<int>& arr) {
    int n=arr.size();
    vector<int>dp(n+1);
    dp[0]=arr[0];
    dp[1]=arr[1];
    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1],dp[i-2])+arr[i];
    }
    return min(dp[n-1],dp[n-2]);
}

// SPACE OPTIMIZATION
int minCost3(vector<int>& arr) {
    int n=arr.size();
    int first=arr[0];
    int second=arr[1];
    int curr=min(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        curr=min(first,second)+arr[i];
        first=second;
        second=curr;
    }
    return min(first,second);
}


int main(){
    
    vector<int>arr={10,15,20};
    vector<int>arr1={1,100,1,1,1,100,1,1,100,1};
    cout<<minCost(arr1)<<endl;
    cout<<minCost1(arr1)<<endl;
    cout<<minCost2(arr1)<<endl;
    cout<<minCost3(arr1)<<endl;
    
    return 0;
}