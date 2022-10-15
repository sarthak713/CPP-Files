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

// Spiral Print
    // int arr[4][4] = {{1,  2, 3,4},
    //                  {12,13,14,5},
    //                  {11,16,15,6},
    //                  {10, 9, 8,7}};
    // int n=4,m=4;
    // int arr[1][1]={1};
    // int n=1,m=1;
    // int arr[2][3]={{1,2,3},
    //                {6,5,4}};
    // int n=2;
    // int m=3;
    // int rowStart=0;
    // int colStart=0;
    // int rowEnd=n-1;
    // int colEnd=m-1;
    // while(rowStart<=rowEnd && colStart<=colEnd){
    //     for(int i=colStart;i<=colEnd;i++){
    //         cout<<arr[rowStart][i]<<" ";
    //     }
    //     rowStart++;
    //     for(int i=rowStart;i<=rowEnd;i++){
    //         cout<<arr[i][colEnd]<<" ";
    //     }
    //     colEnd--;
    //     for(int i=colEnd;i>=colStart;i--){
    //         cout<<arr[rowEnd][i]<<" ";
    //     }
    //     rowEnd--;
    //     for(int i=rowEnd;i>=rowStart;i--){
    //         cout<<arr[i][colStart]<<" ";
    //     }
    //     colStart++;
    // }

// Rotate By 90-Degrees
    // int arr[3][3] = {{1,2,3},   // 7 4 1
    //                  {4,5,6},   // 8 5 2
    //                  {7,8,9}};  // 9 6 3
    // int n=3,m=3;
    // int rowStart=0;
    // int colStart=0;
    // int rowEnd=n-1;
    // int colEnd=m-1;
    // int count=n*m;
    // int ptr=1;
    // while(ptr<=count && colStart<=colEnd){
    //     for(int i=rowEnd;i>=rowStart;i--){
    //         cout<<arr[i][colStart]<<" ";
    //         ptr++;
    //     }cout<<endl;
    //     colStart++;
    // }

// Search 2-D Matrix (Row Wise Sorted)
    // int arr[3][4]={
    //     {1,  3, 5, 7},
    //     {10,11,16,20},
    //     {23,30,34,60}};
    // int row=3;
    // int col=4;
    // int start=0;
    // int end=(row*col)-1;
    // int target=161;
    // int mid=start+(end-start)/2;
    // while(start<=end){
    //     int ele=arr[mid/col][mid%col];  // rowIndex = mid/col, colIndex = mid%col
    //     if(ele==target){
    //         cout<<"Found"<<endl;
    //     }
    //     if(ele<target){
    //         start=mid+1;
    //     }else{
    //         end=mid-1;
    //     }
    //     mid=start+(end-start)/2;
    // }

// Search 2-D Matrix (Row & Col Wise Sorted)
    // int arr[4][4]={
    //     { 1, 4, 7,11},
    //     { 2, 5, 8,12},
    //     { 3, 6, 9,16},
    //     {10,13,14,17}};
    // int n=4;
    // int m=4;
    // int target=101;
    // int row=n;
    // int col=m;
    // int rowIndex=0;     // to start from
    // int colIndex=m-1;
    // while(rowIndex<row && colIndex>=0){
    //     int ele=arr[rowIndex][colIndex];
    //     if(ele==target){
    //         cout<<true<<endl;
    //     }
    //     if(ele<target){
    //         rowIndex++;
    //     }else{
    //         colIndex--;
    //     }
    // }







    
    return 0;
}