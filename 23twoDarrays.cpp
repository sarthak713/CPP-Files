#include<iostream>
using namespace std;

bool isPresent(int arr[][3],int target,int n,int m){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }   
    return 0;
}

int main(){

// Taking 2-D array intput
    // int arr[3][4];
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<arr[i][j]<<" ";
    //     }cout<<endl;
    // }

// Already Initialized
    // int arr2[3][3]={{1,11,111},{2,22,222},{3,33,333}};
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<arr2[i][j]<<" ";
    //     }cout<<endl;
    // }

// Search Element in 2-D Array
    // int arr[3][3] = {{1,2,3},{4,51,6},{7,8,9}};
    // int target=5;
    // if(isPresent(arr,target,3,4)){
    //     cout<<"Present"<<endl;
    // }else{
    //     cout<<"Absent"<<endl;
    // }

// Row-Wise Sum
    // int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // for(int i=0;i<3;i++){
    //     int sum=0;
    //     for(int j=0;j<3;j++){
    //         sum+=arr[i][j];
    //     }
    //     cout<<"Sum of "<<i+1<<" row = "<<sum<<endl;
    // }

// Column-Wise Sum
    // int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};  // 12 15 18
    // for(int i=0;i<3;i++){
    //     int sum=0;
    //     for(int j=0;j<3;j++){
    //         sum+=arr[j][i];
    //     }
    //     cout<<"Sum of "<<i+1<<" column = "<<sum<<endl;
    // }

// Largest Row-Sum
    // int arr[3][3] = {{1,2,300},{4,40,6},{7,8,9}};
    // int maxRowSum = INT_MIN;  
    // int rowIndex = -1;
    // for(int i=0;i<3;i++){
    //     int sum=0;
    //     for(int j=0;j<3;j++){
    //         sum+=arr[i][j];
    //     }
    //     if(sum>=maxRowSum){
    //         maxRowSum=sum;
    //         rowIndex = i+1;
    //     }
    // }
    // cout<<"Maximum Row Sum = "<<maxRowSum<<endl;
    // cout<<"Row is = "<<rowIndex<<endl;

// Print Like Wave
    // int arr[3][3] = {{1,6,7},
    //                  {2,5,8},
    //                  {3,4,9}};
    // for(int i=0;i<3;i++){
    //     if(i%2==0){
    //         for(int j=0;j<3;j++){
    //             cout<<arr[j][i]<<" ";
    //         }
    //     }else{
    //         for(int j=2;j>=0;j--){
    //             cout<<arr[j][i]<<" ";
    //         }
    //     }
    // }
    // cout<<endl;

 

    
    
    return 0;
}