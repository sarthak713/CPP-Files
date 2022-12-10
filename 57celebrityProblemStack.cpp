#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*  STACK
Celebrity problem
    - everyone knows celeb
    - celeb knows no one
       
         0 1 2
Input: {{0,1,0}, 0 
        {0,0,0}, 1
        {0,1,0}} 2

- Now 0,1,2 are persons
- Ignore diagonal - as it refers to the same person itself
    0 know 1
    0 does not know 2
    1 knows no one
    2 knows 1
    2 does not know 0
So 2 & 0 know 1, but 1 knows no one
Answer = 1

Approach 1:
- Row of celeb is 0s only
- Column of celeb is 1s except diagonal element
- We have to check rows & columns for all elements
- One loop for elements, 2 loops inside for row & columns
- T.C. = O(n^2)

Approach 2:
- Put all elements in stack 0 1 2
- while stack size != 1, take 2 elements (A and B), store s.top & s.pop
    - if A knows B -> remove A and push B back
    - if B knows A -> remove B and push A
- repeat until single element is left in stack, this single ele can be answer
- Verify by 2 conditions: check its rows and columns
- T.C. = O(n)
*/

bool knows(vector<vector<int>>&M,int a,int b){
    if(M[a][b]==1){
        return true;
    }
    return false;
}
int celebrity(vector<vector<int>>&M,int n){
    stack<int>s;
    for(int i=0;i<n;i++){                   // step 1: push all ele in stack
        s.push(i);
    }
    while(s.size()>1){                      // step 2: take 2 ele, check for each
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(knows(M,a,b)){         // if a knows b, push b
            s.push(b);
        }else{
            s.push(a);          // if b knows a, push a
        }
    }
    int candidate=s.top();                  // step 3: verify answer by checking rows & columns
    int zeroCount=0;
    for(int i=0;i<n;i++){
        if(M[candidate][i]==0){
            zeroCount++;
        }
    }
    if(zeroCount!=n){
        return -1;
    }
    int oneCount=0;
    for(int i=0;i<n;i++){
        if(M[i][candidate]==1){
            oneCount++;
        }
    }
    if(oneCount!=n-1){
        return -1;
    }
    return candidate;
}

int main(){
    
    int n=3;
    vector<vector<int>> arr={{0,1,1},
                             {0,0,1},
                             {0,0,0}};
    int ans=celebrity(arr,n);
    cout<<ans<<endl;
    
    return 0;
}