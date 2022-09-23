#include<iostream>
using namespace std;

int main(){
/*
- Variables are stored at specific addresses in the memory
- Memory contains a Symbol Table: data structure created & maintained by compiler to keep track of variables
    - This maps variables names with their corresponding addresses
*/
    int num=5;
    cout<<num<<endl;    // 5

/*
Address Of Operator: &
    - Address is stored in hexadecimal format
    - 0 to 9 a b c d e f
*/
    cout<<"Address of num: "<< &num <<endl;
/*
Pointer = stores address
    - always initialize pointers when declared 
    - int *ptr;   // bad practice
    - do this instead: int *ptr=0;  // segmentation fault
*/
    int *ptr = &num;    // ptr is a pointer to int
    cout<<ptr<<endl;

    char ch='a';
    char *cptr = &ch;   
    cout<<cptr<<endl;

/*
Dereference Operator: *
    - gives value at address
    - *pointer = give value at pointer
*/
    cout<<*cptr<<endl;  // a
    cout<<*ptr<<endl;   // 5

cout<<endl;

    double d=4.33;
    double *dptr = &d;
    cout<<"Address is: "<<dptr<<endl;
    cout<<"Value is: "<<*dptr<<endl;

    cout<<"Size of interger: "<<sizeof(num)<<endl;  // 4
    cout<<"Size of interger Pointer: "<<sizeof(ptr)<<endl;  // 8
    cout<<"Size of char: "<<sizeof(ch)<<endl;  // 1
    cout<<"Size of char Pointer: "<<sizeof(cptr)<<endl;  // 8
    cout<<"Size of double: "<<sizeof(d)<<endl;  // 8
    cout<<"Size of double Pointer: "<<sizeof(dptr)<<endl;  // 8

// Size of pointer is always 8-bytes, no matter the data type
cout<<endl;

    int n=5;
    cout<<n<<endl;  // 5
    int a=n;
    a++;    // value at copy is incremented
    cout<<n<<endl;  // 5
    int *p = &n;
    (*p)++; // value at address p is incremented
    cout<<n<<endl;  // 6
// Make a copy of pointer
    int *q=p;
    cout<<p<<" "<<q<<endl;
    cout<<*p<<" "<<*q<<endl;
    (*q)++; // value at copy pointer incremented
    cout<<n<<endl;  // 7

cout<<endl;
// Important
    int m=2;
    int *t=&m; 
    cout<<t<<endl;
    cout<<(*t)++<<endl;
    cout<<m<<endl;
    t=t+1;  
    // incrementing pointer - pointer jumps to next integer
    // Suppose: int address is 100, incrementing it will get to 104
    // as size of int is 4-bytes  
    cout<<t<<endl;
    cout<<*t<<endl;   

cout<<endl;

    double b=1.2;
    double *bb=&b;
    cout<<"Address is: "<<bb<<endl;
    cout<<"Value is: "<<*bb<<endl;
    bb=bb+1;
    cout<<"Address after increment is: "<<bb<<endl;
    // increments by 8, as size of double is 8-bytes




    
    
    return 0;
}