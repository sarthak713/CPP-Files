#include<iostream>
using namespace std;

void update(int *p){
    *p = (*p) * 2;
}

int main(){

// Ques 18
    // int i = 10;
    // update(&i);
    // cout<< i <<endl;    // 20
    
// Ques 1
    // int first = 8;
    // int second = 18;
    // int *ptr = &second;
    // *ptr = 9;
    // cout<< first << " " << second <<endl;   // 8 9
/*
first = 8
second = 18
ptr -> Address Second -> 0xhe736
*ptr = 18
*ptr = 9
*/

// Ques 2
    // int first = 6;
    // int *ptr = &first;
    // int *q = ptr;
    // (*q)++;
    // cout<< first <<endl; // 7
/*
first=6
ptr=Address first=710
*ptr=6
q=ptr=710
*q=6
(*q)++=7
*/

// Ques 3
    // int first=8;
    // int *p=&first;
    // cout<< (*p)++ <<" ";    // 8
    // cout<< first <<endl;    // 9
/*
first=8
p=Address first=710
*p=8
9
*/

// Ques 4
    // int *p=0;   // p is NULL pointer
    // int first=110;
    // *p=first;
    // cout<< *p <<endl;   // segmentation fault
/*
first=110
*p=first is ERROR statement
We have to do p=&first
to make it work
*/

// Ques 5
    // int first = 8;
    // int second = 11;
    // int *third = &second;
    // first = *third;
    // *third = *third + 2;
    // cout<< first <<" "<< second <<endl; // 11 13
/*
first=8
sec=11
third=sec address=710
first=11
11=11+2=13
*/

// Ques 6
    // float f = 12.5;
    // float p = 21.5;
    // float *ptr = &f;
    // (*ptr)++;
    // *ptr = p;
    // cout<< *ptr <<" "<< f <<" "<< p <<endl; // 21.5 21.5 21.5
/*
f=12.5 p=21.5
ptr=f address=710
*ptr=12.5
*ptr++, 12.5++, f++
13.5=21.5
*ptr=21.5
f=21.5 p=21.5
*/

// Ques 7
    // int arr[5];
    // int *ptr;
    // cout<< sizeof(arr) <<" "<< sizeof(ptr) <<endl;  // 20 8
/*
1 int = 4byte, 5 ints=4x5=20
Pointer is always of 8-byte size
*/

// Ques 8
    // int arr[]={11,21,13,14};
    // cout<< *arr <<" "<< *(arr+1) <<endl;    // 11 21

// Ques 9
    // int arr[6]={11,12,31};
    // cout<< arr <<" "<< &arr << &arr[0] <<endl; // address of first memory block, same, same

// Ques 10
    // int arr[6]={11,21,13};
    // cout<< (arr+1) <<endl;  // address of second memory block

// Ques 11
    // int arr[6]={11,21,31};
    // int *p=arr;
    // cout<< p[2] <<endl; // 31
/*
p[2] = *(p+2)
*/

// Ques 12
    // int arr[]={11,12,13,14,15};
    // cout<< *(arr) <<" "<< *(arr+3)<<endl;   // 11 14

// Ques 13
    // int arr[] = {11,21,31,41};
    // int *ptr = arr++;   // ERROR, arr!=arr+1, cannot update symbol table
    // cout<< *ptr <<endl;

// Ques 14
    // char ch = 'a';
    // char *ptr = &ch;
    // ch++;
    // cout<< *ptr <<endl; // b

// Ques 15
    // char arr[]="abcde";
    // char *p = &arr[0];
    // cout<< p <<endl;    // abcde, char pointer stores full content
    
// Ques 16
    // char arr[] = "abcde";
    // char *p = &arr[0];
    // p++;
    // cout<< p <<endl;    // bcde

// Ques 17
    // char str[] = "babbar";
    // char *p = str;
    // cout<< str[0] <<" "<< p[0] <<endl;  // b b

    
    return 0;
}