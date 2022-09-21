#include<iostream>
using namespace std;
/*
Book Allocation Problem:
    - book array
    - m students
Allocate Books in this way:
    - each student at least 1 book
    - no book remains
    - allocate books contiguously
    - Maximum num of pages assigned to a student is minimum
We have to find max value for each case
Then Return least max value

Example:
1. arr={10,20,30,40}
    n=4 m=2
    Output: 60, first student is assigned first 3 books
        1st Way: 10 & 20,30,40  10-90  max-90
        2nd Way: 10,20 & 30,40  30-70  max-70  (min of these = 60)
        3rd Way: 10,20,30 & 40  60-40  max-60
    MinValue that can be answer=0
    MinValue that can be answer=100
Find Mid & check if it is a Possible Solution (while(start<=end))
    Then do BinarySearch on both sides & check if sum is less than mid
First Mid = 50
    1st student = 10,20 (if we add more it will be > 50 mid)
    2nd student = 30 (if we add more it will be > 50 mid)
    50 is not a possible solution as no more books cas be alloted.
    - If 50 is not a solution, values left to it that are <50 also cannot make a solution
    - So we do start=mid+1;
Second Mid = 75
    1st student = 10,20,30
    2nd student = 40
    75 can be a possible solution
    - Store in answer
    - It is possible, so values right to 75 are also possible soltuions, so we don't check there
    - We do end=mid-1, to go to left to find minimum solution 
Third Mid = 62
    1st student = 10,20,30
    2nd student = 40
    Possible Solution exists, we do end=mid-1
Fourth Mid = 55
    Not possible, start=mid+1
Fifth Mid = 57
    Not possible, start=mid+1
Sixth Mid = 59
    Not possible, start=mid+1
Seventh Mid = 60
    Possible, end=mid-1=60
    SOLUTION = 60

*/

bool isPossible(int arr[],int n,int m,int mid){
    int studentCount=1;     // start with 1st student
    int pageSum=0;          // to add pages in array
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid){
            pageSum+=arr[i];
        }else{
            studentCount++; // move to next student
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;
}

int bookAllocation(int arr[],int n,int m){
    int start=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int ans=-1;
    int end=sum;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}

int main(){

    int arr[]={10,20,30,40};
    int n=4;
    int m=2;
    cout<<bookAllocation(arr,n,m)<<endl;

    
    return 0;
}