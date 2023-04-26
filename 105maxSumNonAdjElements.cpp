#include<iostream>
#include<vector>
using namespace std;

/*
Maximum Sum of Non Adjacent Elements
*/

// RECURSION
int solve(int index,vector<int>&arr){
    if(index<0){
        return 0;
    }
    if(index==0){
        return arr[0];
    } 
    int ans1=solve(index-2,arr)+arr[index];
    int ans2=solve(index-1,arr);
    return max(ans1,ans2);
}
int maxSum(vector<int>&arr){
    int n=arr.size();
    return solve(n-1,arr);
}

// TOP DOWN
int solveTD(int index,vector<int>&arr,vector<int>&dp){
    if(index<0){
        return 0;
    }
    if(index==0){
        return arr[0];
    } 
    if(dp[index]!=-1){
        return dp[index];
    }
    int ans1=solveTD(index-2,arr,dp)+arr[index];
    int ans2=solveTD(index-1,arr,dp);
    dp[index]=max(ans1,ans2);
    return dp[index];
}
int maxSumTD(vector<int>&arr){
    int n=arr.size();
    vector<int>dp(n,-1);
    return solveTD(n-1,arr,dp);
}

// BOTTOM UP
int maxSumBU(vector<int>&arr){
    int n=arr.size();
    vector<int>dp(n,0);
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        int include=dp[i-2]+arr[i];
        int exclude=dp[i-1];
        dp[i]=max(include,exclude);
    }
    return dp[n-1];
}

// SPACE OPTIMIZED
int maxSumSO(vector<int>&arr){
    int n=arr.size();
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
    
    vector<int>arr={9,9,8,2};
    cout<<maxSum(arr)<<endl;
    cout<<maxSumTD(arr)<<endl;
    cout<<maxSumBU(arr)<<endl;
    cout<<maxSumSO(arr)<<endl;
    
    return 0;
}