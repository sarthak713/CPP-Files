#include<iostream>
#include<vector>
using namespace std;

// Euclid Algo
// int gcd(int a,int b){
//     if(a==0)return b;
//     if(b==0)return a;
//     while(a!=b){
//         if(a>b){
//             a=a-b;
//         }else{
//             b=b-a;
//         }
//     }
//     return a;
// }

int main(){
    
// Count Prime Numbers - Sieve of Eratosthenes
// Time Complexity = O(n*log(log n))
    // int n=40;
    // int count=0;
    // vector<bool> prime(n+1,true);
    // prime[0]=prime[1]=false;
    // for(int i=2;i<n;i++){
    //     if(prime[i]){
    //         count++;
    //         for(int j=i*2;j<n;j+=i){
    //             prime[j]=0;
    //         }
    //     }
    // }
    // cout<<count<<endl;

// GCD/HCF - Euclid Algo
// gcd(a,b) = gcd(a-b,b) = gcd(a%b,b)
// Fid GCD until one element becomes 0 & other one is answer
// (72,24)(48,24)(24,24)(24,0) a=24=answer
    // int a=24;
    // int b=72;
    // int ans=gcd(a,b);
    // cout<<ans<<endl;

// lcm(a,b)*gcd(a,b)=a*b

// Modulo Arithmetic
// (a % n) = [0 to n-1]

    
    return 0;
}