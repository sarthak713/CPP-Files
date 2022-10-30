#include<iostream>
using namespace std;

int main(){

//  * = value at
//  & = address of


    int arrr[10]={2,5,8};    
    // allocate 40-bytes of memory
    // first block is represented by arrr
    // name of arrr points to address of first-block of arrray
    cout<<"Address of 0th memory block is "<< arrr <<endl;
    cout<<"Value at 0th memory block is "<< arrr[0] <<endl;  // Garbage Value if arrray not initialized by anything, in this case = 2
    cout<<"Address of 0th memory block is "<< &arrr[0] <<endl;
    cout<<endl;
    cout<<"Value of 0th memory block is "<< *arrr <<endl;  // Value at 0th memory block = 2
    cout<<"Value of 0th memory block + 1 = "<< *arrr+1 <<endl;  // 3
    cout<<endl;
    cout<<"Value of 1st memory block "<< *(arrr+1) <<endl;  // 5 arrr[1]
    cout<<"Value of 2nd memory block "<< *(arrr+2) <<endl;  // 8 arrr[2]
    cout<<"Value of 4th memory block "<< *(arrr+4) <<endl;  // 0
    cout<<endl;
    cout<<"Address of 0th memory block is "<< &arrr[0] <<endl;   // 0x7bfdf0
    cout<<"Address of 1st memory block is "<< &arrr[0]+1 <<endl; // 0x7bfdf4
    cout<<"Address of 2nd memory block is "<< &arrr[0]+2 <<endl; // 0x7bfdf8
    cout<<endl;

// arr[i] = *(arr+i)
// i[arr] = *(i+arr)

    cout<<"Value ar 1st index is "<< 1[arrr] <<endl;
    cout<<"Value ar 1st index is "<< *(1+arrr) <<endl;
    cout<<"Value ar 2nd index is "<< 2[arrr] <<endl;
    cout<<"Value ar 2nd index is "<< *(2+arrr) <<endl;
    cout<<endl<<endl;

// Differences in Pointers & Array

    int arr[10] = {1,5,10};
    cout<<"Size of arr[10] = "<< sizeof(arr) <<endl;     // 40, 40-bytes
    int *p = &arr[0];   // address of 1st location
    cout<<"Address of 0th block is "<< p <<endl;    // 0x7bfdc0
    cout<<"Address of 1st block is "<< p+1 <<endl;  // 0x7bfdc4
    cout<<"Value at 0th block is "<< *p <<endl;     // 1
    cout<<"Value at 1st block is "<< *(p+1) <<endl; // 5
    cout<<"Size of address is "<< sizeof(p) <<endl; // 8
    cout<<"Size of value at address is "<< sizeof(*p) <<endl;   // 4
    cout<<"Size of address of pointer is "<< sizeof(&p) <<endl;   // 8
    cout<<endl<<endl;

// Size of arr = No. of blocks X 4
// Size of ptr = 8 bytes, as it stores address

    int ar[20] = {1,4,7,10};
    cout<< &ar[0] <<endl;   // 0x7bfd60
    cout<< &ar <<endl;      // 0x7bfd60
    cout<< ar <<endl;       // 0x7bfd60

    cout<<endl;

    int *ptr = &ar[0];
    cout<< ptr <<endl;  // address = 0x7bfd60
    cout<< *ptr <<endl; // value = 1
    cout<< &ptr <<endl; // address of ptr = 0x7bfd58

    cout<<endl<<endl;

// Symbol Table = mapping of names with their addresses
// Content of Symbol Table cannot be changed
// ar = ar+1 ERROR
// ptr = ptr+1  NO ERROR

    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    ptr = ptr+1;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;







    return 0;
}