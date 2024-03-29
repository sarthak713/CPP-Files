#include<iostream>
using namespace std;

/*
Merge Sort
*/

void merge(int*arr, int start, int end){
    int mid=start+(end-start)/2;
    int len1 = mid-start+1;
    int len2 = end-mid;
    int *first = new int[len1];
    int *second = new int[len2];
    // copy values
    int mainArrIndex=start;
    for(int i=0;i<len1;i++){   
        first[i]=arr[mainArrIndex++];
    }
    mainArrIndex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrIndex++];
    }
    // merge 2 sorted arrays
    int index1=0;
    int index2=0;
    mainArrIndex=start;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrIndex++]=first[index1++];
        }else{
            arr[mainArrIndex++]=second[index2++];
        }
    }
    while(index1<len1){
        arr[mainArrIndex++]=first[index1++];
    }
    while(index2<len2){
        arr[mainArrIndex++]=second[index2++];
    }
    delete []first;
    delete []second;
}

void mergeSort(int *arr, int start, int end){
    if(start>=end){
        return;
    } 
    int mid=start+(end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);
}

int main(){

    int arr[]={2,5,1,6,9,1,2,4,4,14,7,5};
    int n=12;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    

    return 0;
}


// USING VECTORS
/*
void merge(vector<int>&arr,int start,int end){
    int mid=start+(end-start)/2;
    int len1=mid-start+1;
    int len2=end-mid;
    vector<int>first(len1);
    vector<int>second(len2);
    int k=start;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    } 
    int p1=0;
    int p2=0;
    k=start;
    while(p1<len1 && p2<len2){
        if(first[p1]<second[p2]){
            arr[k++]=first[p1++];
        }else{
            arr[k++]=second[p2++];
        }
    }
    while(p1<len1){
        arr[k++]=first[p1++];
    }
    while(p2<len2){
        arr[k++]=second[p2++];
    }
}
void mergeSort(vector<int> &arr,int start,int end){
    if(start>=end){
        return;
    }
    print(arr);
    int mid=start+(end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);
}
*/
