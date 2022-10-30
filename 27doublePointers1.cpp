#include<iostream>
using namespace std;

void update(int **pt){
    // pt = pt + 1;   // No change, as passed by value so changes only in function, not in main
    // *pt = *pt + 1; // change in value of pt (address stored in pt)
    **pt = **pt + 1;  // change in value at address stored in pt
}

int main(){
    
    // int i = 5;      // i block created at an address which contains 5, in symbol table i is mapped with address
    // int *ptr = &i;  // ptr block is created at an address which contains address of i
    // when we want to created a Pointer corresponding to int, we do 'int *'
    // but if we want to create a pointer corresponding to ptr, we do 'int **'
    
    int i = 5;
    int *p = &i;
    int **pt = &p;      // Double Pointer
    int ***ptr = &pt;   // Triple Pointer
    // To make pointer for anything, we write its exact data-type with a *

/* 
Example :
i, value=5, address=710
p, value=710, address=820 (Pointer)
pt, value=820, address=900 (Double Pointer)
ptr, value=900, address=1010 (Triple Pointer)
These are maaped with thier addresses in Symbol Table
*/

    cout<< "Address of i: "<<p<<", Value: "<<*p<<endl;      // 0x7bfe14, 5
    cout<< "Address of p: "<<pt<<", Value: "<<*pt<<endl;    // 0x7bfe08, 0x7bfe14
    cout<< "Address of pt: "<<ptr<<", Value: "<<*ptr<<endl; // 0x7bfe00, 0x7bfe08
    cout<<endl;

    cout<<ptr<<endl;    // Address of pt: 0x7bfe00
    cout<<*ptr<<endl;   // Value of pt: 0x7bfe08
    cout<<**ptr<<endl;  // Value of p: 0x7bfe14
    cout<<***ptr<<endl; // Value of i: 5
    cout<<endl;

// To print value of i
    cout<< i << *p << **pt << ***ptr;
    cout<<endl<<endl;

// Updating with Function
    cout<<"Before i: "<<i<<endl;
    cout<<"Before p: "<<p<<endl;
    cout<<"Before pt: "<<pt<<endl;
    update(pt);
    cout<<"After i: "<<i<<endl;
    cout<<"After p: "<<p<<endl;
    cout<<"After pt: "<<pt<<endl;
    cout<<endl;




    return 0;
}