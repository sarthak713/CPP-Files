#include<iostream>
using namespace std;
/*
Bubble Sort:
    - Biggest element goes to end after each iteration
Time Complexity = O(n^2)    
    Best Case = O(n)
    Worst Case = O(n^2)
Space Complexity = O(1)
*/

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void bubbleSort(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        bool swapped=false;
        for(int j=0;j<i;j++){
            if(arr[j]>=arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main(){
    
    int arr[]={7,4,5,2,3,5,2,9,8,1,2,4,5,6};
    int n=14;
    print(arr,n);
    bubbleSort(arr,n);
    print(arr,n);
    
    
    return 0;
}