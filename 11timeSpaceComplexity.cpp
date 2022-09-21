#include<iostream>
using namespace std;

int main(){
/*
Time Complexity :
    - It is the amount of time taken by an algorithm to run
    - as a function of length of the input
Why ?
    - For making better programs
    - Comparison of algo
Notations :
    - Big O = Upper Bound (means at-max an algo will take this much time to finish)
    - Theta O = For avg case compelxity
    - Omega = Lower Bound (means at-min an algo will take this much time to finish)
Examples :
    - Constant Time = O(1), for loop as the number of time it will execute is constant
    - Linear Time = O(n), depends on input n for number of times it will execute
    - Logarithmic Time = O(log n), binary search
    - Quadratic Time = O(n^2), loop in loop
    - Cubic Time = O(n^3), loop in loop in loop
Complexity in Increasing Order :
    O(1) -> O(Log N) -> O(N) -> O(N log N) -> O(N^2) -> O(N^3) -> O(2^N) -> O(N!) 
Questions :
    1. f(n) -> 2n^2 + 3n
    2. f(n) -> 4n^4 + 3n^3
    3. f(n) -> n^2 + log n
    4. f(n) -> 12001
    5. f(n) -> 3n^3 + 2n^2 + 5
    6. f(n) -> n^3/300
    7. f(n) -> 5n^2 + log n
    8. f(n) -> n/4
    9. f(n) -> n+4/4

- For BigO Notation
    - Ignore Lower degree (power)
    - Ignore constants
    - Pick up the Worst Case
    1. O(n^2)
    2. O(n^4)
    3. O(n^2)
    4. O(1)
    5. O(n^3)
    6. O(n^3)
    7. O(n^2)
    8. O(n)
    9. O(n)

- When we have 2 loops side by side we '+' add Time Complexities
- When we have 2 loops one inside other we '*' multiply Time Complexities

Stuck In TLE (Time Limit Exceeded)
10^8 Operation Rule = Most of the modern machines can perform 10^8 operations/second

Examples: 
    - 1<n<10^6 = means machine can perform 10^6 operations/second
    - 1<n<1000 = machine can perform 1000 operations/second

Here, we can use Algo of Time Complexity Lower than given, but not higher as the it will give TLE
    <=[10..11] = O(n!), O(n^6) 
    < [15..18] = O(2^n*n^2)
    < 100      = O(n^4)
    < 400      = O(n^3)
    < 2000     = O(n^2*log n)
    < 10^4     = O(n^2)
    < 10^6     = O(n log n)
    < 10^8     = O(n), O(log n)


Space Complexity
    - It is the amount of memory taken by an algorithm to run
    - as a function of length of the input

- Extra space is not used when variables or something of fixed size like arrays are formed. It is all Contant Space only O(1)
- Fixed space means Contant space whether variable or array
- In case of Vector whose size is input by user, then Space Complexity is O(n)
- Space complexity is not multiplied when nested with loops

*/
    
    
    return 0;
}