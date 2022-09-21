#include<iostream>
using namespace std;

int main(){


    // int a=10;
    // int b=1;
    // if(++a){    // 11
    //     cout<<b<<endl;  // 1
    // }else{
    //     cout<<++b<<endl;    // 2
    // }
// Output = 1


    // int a=1;
    // int b=2;
    // if(a-->0 && ++b>2){     // a=1, b=3
    // // a=0,b=3
    //     cout<<"Stage1 - Inside if"<<endl;   // executes
    // }else{
    //     cout<<"Stage2 - Inside else"<<endl;
    // }
    // cout<<a<<" "<<b<<endl;  // 0 3
// Output = Inside if, 0 3


    // int a=1;
    // int b=2;
    // if(a-->0 || ++b>2){     // a=1, b=2
    // // a=0,b=2
    //     cout<<"Stage1 - Inside if"<<endl;   // executes
    // }else{
    //     cout<<"Stage2 - Inside else"<<endl;
    // }
    // cout<<a<<" "<<b<<endl;  // 0 2
// Output = Inside if, 0 2


    // int number = 3;
    // cout<<(25*(++number))<<endl;    
// Output = 100


    int a=1;
    int b=a++;  // b=1
    // a=2
    int c=++a;  // c=3
    // a=3
    cout<<a<<endl;  // 3
    cout<<b<<endl;  // 1
    cout<<c<<endl;  // 3
// Ouput = 3 1 3
    
    
    return 0;
}