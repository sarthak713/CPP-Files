#include<iostream>
#include<math.h>
using namespace std;

int main(){

// Binary to Decimal
    
    int n = 100;   // 10
    int i = 0;
    int ans = 0;
    while(n!=0){
        int rem = n%10;
        // 0
        // 1
        // 0
        // 1
        ans = ans + (pow(2,i)*rem);
        // 0+0 = 0
        // 0+10 = 10
        // 10+0 = 0
        // 10+1000 = 1010
        n=n/10;
        // 101
        // 10
        // 1
        // 0
        i++;
        // 1
        // 2
        // 3
        // 4
    }
    cout<<ans<<endl;


    int m = 10101;
    int j = 0, answer = 0;
    while(m>0){
        int digit = m%10;
        if(digit==1){
            answer = answer + pow(2,j);
        }   
        m = m/10;
        j++;
    }
    cout<<answer<<endl;
    


    
    return 0;
}