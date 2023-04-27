#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int countWayToStairs(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return countWayToStairs(n-1)+countWayToStairs(n-2);
}

void sayDigits(int n){
    if(n==0){
        return;
    }
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int digit=n%10;
<<<<<<< HEAD
    n=n/10;
    sayDigits(n);
=======
    sayDigits(n/10);
>>>>>>> coding
    cout<<arr[digit]<<" ";
}

int main(){
    
// Fibonacci Number (LeetCode)
// 0 1 1 2 3 5 8 13 21 34
    // int n = 9;
    // cout<<fibonacci(n)<<endl;

// Count Ways to reach n stairs (CodeStudio)
    // int n=5;
    // cout<<countWayToStairs(n)<<endl;

// Say Digits
    // int n=876;
    // sayDigits(n);
    // cout<<endl;


    



    
    return 0;
}