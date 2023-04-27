#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*  STACK
Largest Rectangular Area In a Histogram (Code Studio)

Area = Length X Breadth

Approach 1:
- Take 1 rectangle at a time, maximize breadth, then calculate area
- Loop through all elements, 2 another loops for left and right of an element to maximize breadth
- Calculate area for each and find maximum
- T.C. = O(n^2)

Approach 2:
- Take an element, find next smaller & previous smaller elements
- Width = next - previous - 1
- Now Area is = length X width
- T.C. = O(n)
- S.C. = O(n)
*/

vector<int> nextSmallerElement(vector<int>&arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
<<<<<<< HEAD
}   
=======
}
>>>>>>> coding
vector<int> prevSmallerElement(vector<int>&arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}   

int largestRectangleArea(vector<int>&heights){
    int n=heights.size();
    vector<int>next(n);
    vector<int>prev(n);
    next=nextSmallerElement(heights,n);
    prev=prevSmallerElement(heights,n);
    int area=INT_MIN;
    for(int i=0;i<n;i++){
        int length=heights[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int breadth=next[i]-prev[i]-1;
        int newArea=length*breadth;
        area=max(area,newArea);
    }
    return area;
}

int main(){
    
    vector<int>arr1={2,1,5,6,2,3};
<<<<<<< HEAD
    vector<int>arr={2,2,2,2,2};
=======
    vector<int>arr={2,2,2,2,2,2};
>>>>>>> coding
    int ans=largestRectangleArea(arr);
    cout<<ans<<endl;
    
    
    return 0;
}