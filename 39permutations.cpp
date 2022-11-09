#include<iostream>
#include<vector>
using namespace std;

/* RECURSION

Permutions of String OR Array

Given a string "STR" consisting lowercase letters.
Return all permutations of given string in lexicographically increasing order.

Input: abc
Output: abc acb bac bca cab cba
Input: bc
Output: bc cb

Explaination:
- Example "abc" is given string
- output will be a 3 char string in each case
- Fix 1st char 'a' at 1st position, then put 'b' & 'c' at different positions 2 times.
    - abc acb
- Then fix 'b' at 1st position, then put 'a' & 'c' at diff positions. 
    - bac bca
- Then for 'c'
    - cab cba

If length of String is = n
Then Total Permutations = n! 
For n=3, permutations=1x2x3=6

Approach:
- Take index, start at 1st position
- At 1st position, there will be either a,b or c
- Then swap for diff positions
    - put 'a' at 1st & because there was 'a' only at 1st position
    - swap 'a' with itself   = abc , i is at b
    - then swap 'b' with 'a' = bac , i is at a
    - then swap 'c' with 'a' = cba , i is at b
- Then swap all elements with element at i again
    - i is at 2nd position
    - repeat this until i is out of given string
PUT every char at every place
*/

void solve(vector<int>arr, int index, vector<vector<int> >&ans){
    if(index>=arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        solve(arr,index+1,ans);
        swap(arr[index],arr[i]);
    }
}

vector<vector<int> > getPermutations(vector<int>& arr){
    vector<vector<int> > ans;
    int index=0;
    solve(arr,index,ans);
    return ans;
}

int main(){

    vector<int>arr={1,2,3};
    vector<vector<int> > ans=getPermutations(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    
    
    return 0;
}