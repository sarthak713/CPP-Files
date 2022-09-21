#include<iostream>
using namespace std;

int main(){
/*
BitWise Operators:
- AND &
- OR |
- NOT ~
- XOR ^

- XOR ^
    0 0 = 0
    0 1 = 1
    1 0 = 1
    1 1 = 0

Left & Right Shift

Left Shift <<
    Example 1:
        5<<1, means shift 5 to left 1 time
        101<<1  
        1010 = 10
    Example 2:
        3<<2
        11<<2
        1100 = 12
    - In most cases (for smaller numbers), left shifting once, means multiplying by 2
Right Shift >>
    Example 1:
        5>>1, means shift 5 to right 1 time
        101>>1
        10 = 2
    - In most cases, right shifting once, means dividing by 2

- In case of +ve numbers, padding is done with 0
- In case of -ve numbers, padding is compiler dependent

Increment & Decrement
-  i++ post increment, increment after execution or usage
-  ++i pre increment
-  i-- post decrement
-  --i pre decrement

*/
    int a=2;
    int b=~a;
// FIND NOT~ = We invert all 32 bits of any number
// Firstly, all 32 bits will become 1
// Then 1's complement of that, which inverts all bits again
// Then 2's complement, which is 1's complement +1 at rightmost bit
// So, the answer is the number in negative
    cout<<"NOT 2 = "<<b<<endl;  // -3

    int d=2;    // 10
    int e=4;    // 100
    int f=d^e;
    cout<<"XOR of 2 & 4 = "<<f<<endl;

// Left << & right >> Shift
    int m=20<<2;
    cout<<m<<endl;  // 80
    int y=17>>1;
    cout<<y<<endl;  // 8
    int n=17>>2;
    cout<<n<<endl;  // 4

cout<<endl;

// Increment & Decrement

    int i=3;
    int l=2;
    int sum=l+(i++);
    cout<<sum<<endl;    // 5
    cout<<i<<endl;      // 4

    int h=11;
    cout<<l+(++h)<<endl;  // 14

cout<<endl;

// EXAMPLES

    int p=7;
    cout<<++p<<endl;    // 8
    cout<<p++<<endl;    // 8
    // 9
    cout<<p--<<endl;    // 9
    // 8
    cout<<--p<<endl;    // 7



    
    
    return 0;
}