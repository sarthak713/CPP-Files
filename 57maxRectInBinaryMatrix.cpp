#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*      STACKS
Max Rectangle in Binary Matrix with all 1s

Input = {{0,1,1,0},
         {1,1,1,1},
         {1,1,1,1},
         {1,1,0,0}}
Output = 8 

- Find maximum area of reactangle formed by all 1s
- Similar to Largest Rectangular Area in Histogram

Approach:
- Dividing into sub-problems, take 1st row
- 0 1 1 0, use Largest area Histogram algo and find largest area = 2 for this row
- Now combine 2nd row into 1st row. Add 1s in both rows
- 1 2 2 1, largest area = 4. New Answer=4
- Take 3 rows now, 2 3 3 2, largest area = 8
- We take the row we add as a base, so if base is 0 initially we discard it
- So with 4th row as a base, we add other 3 top rows onto 4th row
- Now, 3 4 0 0, largest area = 6
- Maximum Area = 8

Code:
- Compute max area for 1st row
- For loop & for every remaining row
    - add upper row elements to current row element
- Compute area

T.C. = O(n*m)
S.C. = O(m)
*/

vector<int> nextSmallerElement(int* arr,int n){
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
}
vector<int> prevSmallerElement(int* arr,int n){
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
int largestRectangleArea(int *heights,int n){
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

int maxArea(int M[4][4],int n,int m){
    int area = largestRectangleArea(M[0],m);        // Area for 1st row 
    for(int i=1;i<n;i++){                           
        for(int j=0;j<m;j++){
            if(M[i][j]!=0){
                M[i][j]=M[i][j]+M[i-1][j];          // update row by adding previous row elements
            }
            else{
                M[i][j]=0;
            }
        }                                           // row updated
        area = max(area,largestRectangleArea(M[i],m));
    }
    return area;
}

int main(){
    


    
    
    return 0;
}