#include<iostream>
#include<vector>
using namespace std;

// Array Questions

int main(){


// Reverse the Array
    // int arr[]={1,2,3,4,5,6};
    // int n=6;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    // int start=0;
    // int end=n-1;
    // while(start<end){
    //     swap(arr[start],arr[end]);
    //     start++;
    //     end--;
    // }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;


// Reverse Array after a given index
    // int arr[]={1,2,3,4,5,6};
    // int n=6;
    // int m=3;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    // int start=m+1;
    // int end=n-1;
    // while(start<end){
    //     swap(arr[start],arr[end]);
    //     start++;
    //     end--;
    // }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

// merge sorted arrays
    // vector<int> a={1,3,5,7,9};
    // vector<int> b={2,3,6,8,10};
    // vector<int> c;
    // int aPtr=0;
    // int bPtr=0;
    // int aSize=a.size();
    // int bSize=b.size();
    // while(aPtr<aSize && bPtr<bSize){
    //     if(a[aPtr]<=b[bPtr]){
    //         c.push_back(a[aPtr]);
    //         aPtr++;
    //     }else{
    //         c.push_back(b[bPtr]);
    //         bPtr++;
    //     }
    // }
    // while(aPtr<aSize){
    //     c.push_back(a[aPtr]);
    //     aPtr++;
    // }
    // while(bPtr<bSize){
    //     c.push_back(b[bPtr]);
    //     bPtr++;
    // }
    // for(int i=0;i<c.size();i++){
    //     cout<<c[i]<<" ";
    // }cout<<endl;

// merge Sorted array in another array
    // vector<int> a = {1,2,3,0,0,0};
    // int m=3;
    // vector<int> b = {2,5,6};
    // int n=3;
    // int newSize = m+n-1;
    // int aPtr=m-1;
    // int bPtr=n-1;
    // while(bPtr>=0){
    //     if(aPtr>=0 && a[aPtr]>b[bPtr]){
    //         a[newSize]=a[aPtr];
    //         aPtr--;
    //     }else{
    //         a[newSize]=b[bPtr];
    //         bPtr--;
    //     }
    //     newSize--;
    //     for(int i=0;i<6;i++){
    //         cout<<a[i]<<" ";
    //     }cout<<endl;
    // }
    
// Move Zeroes
    // int arr[]={0,1,0,3,2,0};
    // int n=6;
    // int arr[]={1,0,1};
    // int n=3;
    // int a=0;
    // int b=a+1;
    // while(a<n-1 && b<n){
    //     if(arr[a]!=0){
    //         a++;
    //     }
    //     if(arr[a]==0 && arr[b]!=0){
    //         swap(arr[a],arr[b]);
    //         a++;
    //     }
    //     b++;
    // }
    // for(int j=0;j<n;j++){
    //     cout<<arr[j]<<" ";
    // }cout<<endl;

    // Approach 2
    // int nonZero=0;
    // for(int j=0;j<n;j++){
    //     if(arr[j]!=0){
    //         swap(arr[j],arr[nonZero]);
    //         nonZero++;
    //     }
    // }



    
    
    return 0;
}