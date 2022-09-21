#include<iostream>
#include<math.h>
using namespace std;

int main(){
    
/* 
Decimal to Binary

Logic 1: 
    - divide by 2
    - store remainder in answer
    - repeat above 2 steps until n!=0
    - reverse answer
Logic 2: 
    - while n>0
    - bit = n & 1
    - n = n>>1 
- When any num is & with 1: 
    - if 1 then num=odd
    - if 0 then num=even
*/

// Decimal to Binary (+ve number)

    int n=5;   // 1010
    int ans=0;
    int i=0;
    while(n!=0){
        int bit=n&1;            
        // 1010 & 0001 = 1  
        // 101 & 001 = 1
        // 10 & 01 = 0
        // 1 & 1 = 1
        ans=ans+(pow(10,i)*bit);   
        // 0+0=0, ans = 0
        // 0+10, ans = 10
        // 10+0, ans = 10
        // 10+1000, ans = 1010
        n=n>>1;     // same as n=n/2
        // 5
        // 2    
        // 1
        // 0   
        i++;    
        // 1
        // 2
        // 3  
        // 4         
    }
    cout<<ans<<endl;

/*
Decimal to Binary (-ve number)

- Get binary of number
- for 6: 110
- Find 2's complement = 1's complement + 1
- 000_ _ _110 -> 111_ _ _001
- 111_ _ _001 + 1 = 111_ _ _010
- Now we see, start num is 1 so it is negative
- So again 2's complement = 1's complement + 1
- 111_ _ _010 -> 000_ _ _ 101 + 1
- 000_ _ _ 110 = 6 -> -6
*/
    int m = 6;   // ans = 11010
    int answer = 0;
    int j = 0;
    while(m != 0){
        int bits = m & 1;
        answer = answer + (pow(10,j)*bits);
        m = - (m >> 1); 
        j++;        
    } 
    cout<<answer<<endl;



    
    
    return 0;
}