#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*  STACK
Next Smaller Element (Code Studio)

- For every element, find next smaller element than that element

Input = [2,1,4,3]
Output= 1,-1,3,-1

Approach 1:
- For an element, travel complete array again
- Worst Case T.C. = O(n^2)
- Because of 2 loops

Approach 2:
- create stack & push -1 initially
- This stack will always container smaller elements
- Loop through array & check stack.top()
- If Smaller Element -> store ans, stack.push(currArrEle)
- If Bigger Element -> find smaller by looping stack, then store & push
                    -> while(stack.top()>=currArrEle) {stack.pop()}, store when found, push currArrEle
- T.C. = O(n)
*/

vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    
    vector<int>v={2,1,4,3};
    vector<int>ans=nextSmallerElement(v,4);
    for(int i=0;i<4;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    
    return 0;
}