#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/*
Cut Rot in Segments of X,Y,Z

- n = rod length
- determine max number of segments you can make of this rod
- such that each segment should be of length x,y,z

Input: n=7, x=5 y=2 z=2
Output: 2
Input: n=8, x=3 y=3 z=3
Output: -1
*/

// RECURSION

int solve(int n,int x,int y,int z){
    if(n<0){
        return INT_MIN;
    }
    if(n==0){
        return 0;
    }
    int a=solve(n-x,x,y,z)+1;
    int b=solve(n-y,x,y,z)+1;
    int c=solve(n-z,x,y,z)+1;
    return max(a,max(b,c));
}
int cutSegments(int n,int x,int y,int z){
    int ans=solve(n,x,y,z);
    if(ans<0){
        return 0;
    }
    return ans;
}

// TOP DOWN

int solveTD(int n,int x,int y,int z,vector<int>&dp){
    if(n<0){
        return INT_MIN;
    }
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int a=solveTD(n-x,x,y,z,dp)+1;
    int b=solveTD(n-y,x,y,z,dp)+1;
    int c=solveTD(n-z,x,y,z,dp)+1;
    dp[n]=max(a,max(b,c));
    return dp[n];
}
int cutSegmentsTD(int n,int x,int y,int z){
    vector<int>dp(n+1,-1);
    int ans=solveTD(n,x,y,z,dp);
    if(ans<0){
        return 0;
    }
    return ans;
}

// BOTTOM UP

int cutSegmentsBU(int n,int x,int y,int z){
    vector<int>dp(n+1,INT_MIN);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(i-x>=0){
            dp[i]=max(dp[i],dp[i-x]+1);
        }
        if(i-y>=0){
            dp[i]=max(dp[i],dp[i-y]+1);
        }
        if(i-z>=0){
            dp[i]=max(dp[i],dp[i-z]+1);
        }
    }
    if(dp[n]<0){
        return 0;
    }
    return dp[n];
} 

int main(){
    
    int n=7;
    cout<<cutSegments(n,5,2,2)<<endl;
    cout<<cutSegmentsTD(n,5,2,2)<<endl;
    cout<<cutSegmentsBU(n,5,2,2)<<endl;
    
    return 0;
}