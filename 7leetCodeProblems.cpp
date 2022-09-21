#include<iostream>
#include<math.h>
using namespace std;

int main(){
   
// Reverse Integer

    int n=120;
    int ans = 0;
    while(n != 0){
        int rem = n%10;     // 5,4,3,2,1
        // if((ans < INT_MIN/10) || (ans > INT_MAX/10)) return 0;
        ans=(ans*10)+rem;   // 5, 50+4=54, 540+3=543, 5430+2=5432, 54320+1=54321
        n=n/10;             // 1234, 123, 12, 1
    }
    cout<<ans<<endl;

/* Complement of Base 10 integer

For 7 = 111 -> 000 = 0
We are changing bits: & | ~ ^ << >>
But keep only those last bits & ignore others

*/
    int num=10;
    int m=num;
    int mask=0;
    // if(num==0) return 1;     // edge case LeetCode
    while(m!=0){
        mask=(mask<<1) | 1;     // creates a number with (000 at start and 111 at end) which we && with complement get desired result with no 1's at beginning 
        m=m>>1;  
    }        
    int answer=(~num)&mask;
    cout<<answer<<endl;
    

// Power of 2

    int a=1024;    // 1000
    bool flag=false;
    for(int i=0;i<31;i++){
        int b = pow(2,i);
        if(a==b){
            flag=true;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    // int a=10;
    // int ans=1;
    // for(int i=0;i<31;i++){
    //     if(ans==n){
    //         return true;
    //     }
    //     if(ans<INT_MAX/2)
    //     ans=ans*2;
    // }
    // return false;


    
    return 0;
}