#include<iostream>
using namespace std;

/*
Reference Variable = same memory, different names
int i = 5;
int &j = i;
Now i & j both point to the same memory block
*/ 

int update1(int n){     // pass by value
    n=n+1;              // this n is copy of original value, for which new memory is created & then value is changed
    return n;
}
int update2(int &n){    // pass by reference
    n=n+1;              // this n is a reference valriable, which points to same memory address as argument number & changes value in that memory address only
    return n;
}

int &update3(int n){    // can also return a reference variable 
    int num=n;          // BAD PRACTICE: as num is a local variable
    int &ans=num;       // so is ans, & memory for both is destroyed outside blocks of this function
    return ans;         // and cannot be accessed
}                       // same is with returning a pointer, as local variables does not exist outside functions

int main(){
    
    int i = 5;
    int &j = i;     // Creating Reference Variable

    cout<< i <<" "<< j <<endl;      // same value
    cout<< &i <<" "<< &j <<endl;    // same address
    i++;        // both values will change
    cout<< i <<" "<< j <<endl;      
    j++;    
    cout<< i <<" "<< j <<endl;      
    cout<<endl;

// Pass by Value & Reference

    int n = 1;
    update1(n);
    cout<<"Pass by Val: "<< n <<endl;
    update2(n);
    cout<<"Pass by Ref: "<< n <<endl;
    cout<<endl<<endl;

// Arrays

/*
BAD PRACTICE:
    int n;
    cin>>n;
    int arr[n]; 
- array size is determined on runtime, this is dangerous
- Size should be known in Compile Time
We should do this:
    int arr[100];
- When program is started
    - Memory is assigned in 2 types = Stack & Heap
    - Stack is small but Heap is large
- If we determine size in Compile time, it will make sure that memory size is given to program before start & will be allocated in Heap size
- But when we give size on runtime, program will crash if large array is created as Stack memory is used which is usually small

All variable memory assigning is done through Stack Memory = Static Memory Allocation
But what if we want a Variable size array or char, etc through Heap Memory in runtime = Dynamic Memory Allocation

When we want Heap Memory, we use 'new' keyword.
Example: new char;
No name is allowed in Heap Memory, it return address, we do:
char *ch = new char;
Heap memory:
    - char block is formed of 1-byte
In stack Memory:
    - char pointer ch is formed of 8-bytes which stores address of new char
So total memory assigned is of 9-bytes
*/

    char ch = 'q';
    cout<< sizeof(ch) <<endl;   // 1-byte
    char *c = &ch;
    cout<< sizeof(c) <<endl;    // 8-bytes
    int *num = new int;         // 4-bytes in Heap memory
    cout<< sizeof(num) <<endl;  // 8-bytes in Stack memory

// Array

    int n;
    cin>>n;                 // Variable Size Array
    int *arr = new int[n];  // ptrSize=8(Static), arrSize=5x4=20(Dynamic)
    // *arr is done because, Heap Memory return Address so we store it in a Pointer

// arr[i] = *(arr+i)

/*
Diff bet Static & Dynamic

Static:
- int arr[50]
- Memory = 50x4 = 200 (Stack)
Dynamic:
- int *arr = new int[50]
- Memory = 200(Stack) + 8(Heap) = 208(Total)

Dangerous Scenarios

Statically 
    while(true){
        int i=5;
    }
= 4-byte memory is allocated everytime we enter & is destroyed everytime we exit the loop


Dynamically 
    while(true){
        int *ptr=new int;
    }
= 8-byte(stack) & 4-byte(heap) memory is allocated everytime
= but when we exit the loop, Stack memory is destroyed freed but Heap Memory is not
= it will fill Heap memory until program crashes

Static Allocation -> memory is automatically released
Dynamic Allocation -> memory is has to be manually released using 'delete' keyword

Example:
    int *i = new int;
    delete i;

    int *arr = new int[50];
    delete []arr;
*/


    
    return 0;
}