#include<iostream>
#include<vector>
using namespace std;

/*
Minimum Number of Coins To Make Amount
Coin Change (Leetcode 322)
*/

// RECURSION
int solve(vector<int>&arr,int n,int sum){
    if(sum==0){
        return 0;
    }
    if(sum<0){
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++){
        int ans=solve(arr,n,sum-arr[i]);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }
    return mini;
}
int coinChange(vector<int>&arr,int n){
    int ans=solve(arr,n,n);
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}

// TOP DOWN
int solveTD(vector<int>&arr,int n,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MAX;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int mini=INT_MAX;
    for(int i=0;i<arr.size();i++){
        int ans=solve(arr,n,n-arr[i]);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }
    dp[n]=mini;
    return dp[n];
}
int coinChangeTD(vector<int>&arr,int n){
    vector<int>dp(n+1,-1);
    int ans=solveTD(arr,n,dp);
    if(ans==INT_MAX)return -1;
    return ans;
}

// BOTTOM UP
int coinChangeBU(vector<int>&arr,int n){
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<arr.size();j++){
            if(i-arr[j]>=0 && dp[i-arr[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-arr[j]]);
            }
        }
    }
    if(dp[n]==INT_MAX){
        return -1;
    }
    return dp[n];
}

int main(){
    
    vector<int>arr={1,2,5}; // coins
    int n=11;               // amount
    cout<<coinChange(arr,n)<<endl;
    cout<<coinChangeTD(arr,n)<<endl;
    cout<<coinChangeBU(arr,n)<<endl;
    
    return 0;
}