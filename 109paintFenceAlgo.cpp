#include<iostream>
#include<vector>
using namespace std;

/*
Painting Fence Algorithm DP (Ninja And The Fence)

- Given: N posts, K colors
- Paint all posts, not more than 2 adjacent posts has same color
- Find number of ways we can color N posts with given condition

Example:
    We have 2 ways of coloring posts:
        - with same color, meaning last 2 posts of same color
        - with diff color
    1. N=2, K=3 (let colors be R,G,B)
        - same color: RR,GG,BB              - 3 outputs, equal to k
        - diff color: RG,RB,GR,GB,BR,BG     - 6 outputs, k*(k-1)
        - Total: 9                          - k + k*(k-1)
    2. N=3, K=3 (colors R,G,B)
        - same color: RRG,RRB,GGR,GGB,BBR,BBG   
            - 6 outputs, equal to different posts in n=2
            - applying diff color to same k posts as in n=2         
        - diff color: Total was 9 in n=2, so we use those and put one more color in back for all combos
            - Diff means last 2 posts diff
            - RGR,RGB,RBG,RGR,GRB,GRG,GBR,GBG,BRB,BRG,BGR,BGB
            - 18 outputs
        - Total: 24
    3. N=4, K=3
        - Way 1- last 2 same: 18
        - Way 2- last 2 diff: 48
        - total: 66
    For any N, lets say N=4:
        - we have 2 ways: either last 2 same or different
        - For Same at last: 
            - we have RG,RB,GR,GB,BR,BG and we have to add 2 more
            - which are the same, but for those 2 more we have 2 choices for each
              so (k-1) choices
            - So for solve(n)=solve(n-2)*(k-1)
        - For Diff at last: 
            - we get total of 3 which was 24
            - We have to add one more to each, 
              and it can be of any color other than last so (k-1) choices
            - so solve(n-1)*(k-1)
        So, Total = solve(n-2)*(k-1) + solve(n-1)*(k-1)

- Recursive Relation: solve(n)=solve(n-2)*(k-1) + solve(n-1)*(k-1)
-                       (for last 2 same posts) + (for last 2 diff posts)
*/


#define MOD 1000000007
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a,int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}

// RECURSION

int solve(int n,int k){
    if(n==1){
        return k;   // if one pole, it can be painted in number of colors present ways
    }
    if(n==2){
        return add(k,mul(k,k-1));   // for 2 poles, we can paint in k+(k*(k-1)) ways
    }
    int ans=add( mul(solve(n-2,k), k-1), 
                 mul(solve(n-1,k), k-1) );
    return ans;
}
int numberOfWays(int n,int k){
    return solve(n,k);
}

// RECURSION + MEMOISATION

int solveTD(int n,int k,vector<int>&dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=add( mul(solveTD(n-2,k,dp), k-1), 
               mul(solveTD(n-1,k,dp), k-1) );
    return dp[n];
}
int numberOfWays(int n,int k){
    vector<int>dp(n+1,-1);
    return solveTD(n,k,dp);
}

// TABULATION

int numberOfWaysBU(int n,int k){
    vector<int>dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        dp[i]=add( mul(dp[i-2], k-1), 
                   mul(dp[i-1], k-1) );
    }
    return dp[n];
}

// SPACE OPTIMIZATION

int numberOfWaysSO(int n,int k){
    int first=k;
    int second=add(k,mul(k,k-1));
    if(n==1)return first;
    if(n==2)return second;
    int curr=add( mul(first, k-1), 
                  mul(second, k-1) );
    for(int i=3;i<=n;i++){
        curr=add( mul(first, k-1), 
                  mul(second, k-1) );
        first=second;
        second=curr;
    }
    return curr;
}

int main(){
    
    
    
    return 0;
}