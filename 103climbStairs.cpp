#include<iostream>
#include<vector>
using namespace std;

/*
Climbing Stairs
*/

// TOP DOWN (Recursion + Memoisation)

int climbStairsTD(int n,vector<int>&dp){
    if(n==0 || n==1 || n==2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]= climbStairsTD(n-1,dp)+climbStairsTD(n-2,dp);
    return dp[n];
}

// BOTTOM UP

int climbStairsBU(int n,vector<int>&dp){
    if(n<0){
        return 0;
    }
    if(n<=3){
        return n;
    }
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// SPACE OPTIMIZATION

int climbStairsSO(int n){
    if(n<0){
        return 0;
    }
    if(n<=3){
        return n;
    }
    int first=2;
    int second=3;
    int curr=first+second;
    for(int i=4;i<=n;i++){
        curr=first+second;
        first=second;
        second=curr;
    }
    return curr;
}


int main(){
    
    int n=10;
    vector<int>dp(n+1,-1);
    cout<<climbStairsTD(n,dp)<<endl;
    cout<<climbStairsBU(n,dp)<<endl;
    cout<<climbStairsSO(n)<<endl;
    
    return 0;
}