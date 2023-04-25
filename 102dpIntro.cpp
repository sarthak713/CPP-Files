#include<iostream>
#include<vector>
using namespace std;

/*
Dynamic Programming (DP)

Ways to solve problems using DP:
    1. Top Down = Recursion + Memoization
    2. Bottom Up = Tabulation

Fibonacci Series: 0 1 1 2 3 5 8 13...

1. Top Down:
    T.C. = O(n)
    S.C. = O(n)
2. Bottom Up:
    T.C. = O(n)
    S.C. = O(n)
1. Space Optimization:
    T.C. = O(n)
    S.C. = O(1)
*/


// ---------- TOP DOWN APPROACH ----------

// Recursion
int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
// Recursion + Memoisation
int fibonacciDP(int n,vector<int>&dp){
    if(n==0 || n==1){                               // step 1
        return n;
    }
    if(dp[n]!=-1){                                  // step 3
        return dp[n];
    }
    dp[n]=fibonacciDP(n-1,dp)+fibonacciDP(n-2,dp);  // step 2
    return dp[n];
}


// ---------- BOTTOM UP APPROACH ----------

int fibonaccidp(int n,vector<int>&dp){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];  
    }
    return dp[n];
}


// ---------- SPACE OPTIMIZATION ----------

int fibonacciOptimal(int n){
    int prev1=0;
    int prev2=1;
    int curr=prev1+prev2;
    for(int i=2;i<=n;i++){
        curr=prev1+prev2; 
        prev1=prev2;
        prev2=curr; 
    }
    return curr;
}

int main(){

    int n=10;
    vector<int>dp(n+1,-1);
    // cout<<fibonacciDP(n,dp)<<endl;
    // cout<<fibonaccidp(n,dp)<<endl;
    cout<<fibonacciOptimal(n)<<endl;

    return 0;
}