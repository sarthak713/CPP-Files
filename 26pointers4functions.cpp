#include<iostream>
using namespace std;

void print(int *p){
    cout<< *p <<endl;
}
void update(int *p){    // Address of value is passed here 
    // p = p + 1;       // No update in Address & Value
    // pointer's value will be updated but no change in original

    *p = *p + 1;    // Now value will change
}


// int getSum(int arr[],int n){
int getSum(int *arr,int n){

    cout<< sizeof(arr) <<endl;  // gives 8, but should give 4x5=20
    // when we pass 'int arr[]' to a function, array is not passed, its Pointer is passed
    // int arr[] = int *arr
    // only location of first memory block of array is passed
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=i[arr];
    }
    return sum;
}

int main(){
    
    int value = 5;
    int *p = &value;
    print(p);       // 5
    
    // cout<<"Before = "<< p <<endl;  // 0x7bfe14
    // update(p); 
    // cout<<"After = "<< p <<endl;   // 0x7bfe14


    cout<<"Before = "<< *p <<endl;  // 5
    update(p); 
    cout<<"After = "<< *p <<endl;   // 6

    cout<<endl<<endl;

    int arr[5] = {1,2,3,4,5};
    cout<<"Sum of arr = "<< getSum(arr,5) <<endl;
    // this benefits as we can send a part of array to a function


    
    
    return 0;
}