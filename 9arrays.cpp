#include<iostream>
using namespace std;
/*
Whenever we want to input size of array
We should Not intialize by int arr[size]
We should intialize it as arr[100] (GOOD PRACTICE)
*/
    
int getMax(int arr[],int n){
    int maximum=INT_MIN;
    for(int i=0;i<n;i++){
        maximum=max(maximum,arr[i]);
    }
    return maximum;
}
int getMin(int arr[],int n){
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

// change in arr in function, will change the main array when passed to the function
// this is because in case of arr, base address is passed to the function instead of copy of array
// in case of varibales, copy is passed

bool linearSearch(int arr[],int n,int key){
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

bool binarySearch(int arr[],int n,int key){
    int l=0;
    int r=n-1;
    int mid=(l+r)/2;
    while(l<r){
        if(key==arr[mid]){
            return true;
        }
        else if(key<arr[mid]){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return false;
}

int main(){

    int arr[]={10,4,31,23,9,19};

    cout<<getMax(arr,6)<<endl;
    cout<<getMin(arr,6)<<endl;

    cout<<linearSearch(arr,6,10)<<endl;
    cout<<linearSearch(arr,6,0)<<endl;
    
    int array[]={1,3,5,8,9,11,15};
    cout<<binarySearch(array,7,5)<<endl;



    
    return 0;
}