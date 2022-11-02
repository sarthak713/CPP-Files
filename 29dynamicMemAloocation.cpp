#include<iostream>
using namespace std;

int main(){

/*
Allocate memory Dynamically to 2-D Arrays

BAD PRACTICE:
    int n,m;
    cin>>n>>m;
    int arr[n][m];
- User inputs size in runtime, which is allocated with Stack Memory
- Stack memory has small storage so Program Crashes

int *arr = new int[n]; 
Creates array using Heap Memory,
Heap Memory return address which is stored in arr pointer.
- Above code create array of int type

We create 2-D Array like:
int **arr = new int *[n];
- This creates array of int* type
- We loop all pointers and make int type array for each pointer

Visualization:
int*1->1,2,3
int*2->4,5,6
int*3->7,6,8

Heap memory has to be released manually
- Firstly, we release int type part
- Then, we release int* type part
As doing the opposite will lead to memory leak 
*/ 

    int n;
    cin>>n;

// Creation    
    int **arr = new int*[n];    // creates array of int* type

    for(int i=0;i<n;i++){
        arr[i] = new int[n];    // creates array of int type for each int* tyoe
    }
    
// Input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

// Output
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    
// Memory Release
    for(int i=0;i<n;i++){
        delete [] arr[i];
    }
    delete [] arr;
    

    
    return 0;
}