#include<iostream>
#include<vector>
using namespace std;

/*
Count Derangements

- Derangement is a permutation of N elements
    - such that no element appears in its original position
    - Example: for {0,1,2,3} -> {2,3,1,0}
    - Find total number of derangements

Approach:
    - For n numbers
    - for any number we can place it in any position except its original position
    - so for a number, we have n-1 possibilities
    - (n-1)*[solution of subproblems]
        1. we swap any 2 numbers a,b to make derangement & place a at b index & b at a index
            - now we have (n-2) indexes empty & (n-2) elements to place
            - so now f(n-2)
        2. we place place b at a index but a Not at b index
            - in this case, we have (n-1) indexes empty & (n-1) elements to place
            - so now f(n-1)
    - So f(n) = (n-1)*[f(n-2)+f(n-1)]
*/

// RECURSION

#define MOD 1000000007

long long int countDerangements(int n){
    if(n==1){       // for single element, no derangement
        return 0;
    }
    if(n==2){       // for 2 elements, only one derangement
        return 1;
    }
    int ans=(n-1)*(countDerangements(n-1)+countDerangements(n-2));
    return ans;
}

// RECURSION + MEMOISATION

long long int solveTD(int n,vector<long long int>&dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1; 
    }
    if(dp[n]!=-1)return dp[n];
    dp[n]=(((n-1))%MOD*((solveTD(n-1,dp))%MOD+(solveTD(n-2, dp))%MOD))%MOD;
    return dp[n];
}
long long int countTD(int n) {
    vector<long long int>dp(n+1,-1);
    return solveTD(n,dp);
}

// TABULATION

long long int countBU(int n) {
    vector<long long int>dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=( (i-1)%MOD * (dp[i-1]%MOD + dp[i-2]%MOD)%MOD ) %MOD;
    }
    return dp[n];
}
long long int countBU2(int n) {
    vector<long long int>dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        long long int sum = (first+second)%MOD;
        dp[i] = ((i-1)*sum)%MOD;
    }
    return dp[n];
}

// SPACE OPTIMIZATION

long long int countSO(int n) {
    if(n==1 || n==2){
        return n-1;
    }
    long long int first=0;
    long long int second=1;
    long long int curr=(((n-1)%MOD)*(first+second)%MOD)%MOD;
    for(int i=3;i<=n;i++){
        long long int sum = (first+second)%MOD;
        curr = ((i-1)*sum)%MOD;
        first = second;
        second = curr;
    }
    return curr;
}


int main(){
    
    
    
    return 0;
}