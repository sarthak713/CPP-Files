#include<iostream>
using namespace std;
/*
Recursion :
    1. Base Case
    2. Recursive Relation
- Head Recursion 
    1. Base case
    2. Recursive Relation
    3. Processing
- Tail Recursion
    1. Base case
    2. Processing
    3. Recursive Relation
*/

int factorial(int n){
    if(n==0){           // base case
        return 1;
    }
    return n * factorial(n-1);  // recursive relation
}

int powerOfTwo(int n){
    if(n==0){
        return 1;
    }
    return 2 * powerOfTwo(n-1);
}

void printCount(int n){
    if(n==0){
        return;
    }
    printCount(n-1);
    cout<<n<<" ";
}

int main(){
    
    int n=4;
    int ans=factorial(n);
    cout<<ans<<endl;

    int m=5;
    int answer=powerOfTwo(m);
    cout<<answer<<endl;
    
    int s=10;
    printCount(s);
    cout<<endl;
    
    return 0;
}