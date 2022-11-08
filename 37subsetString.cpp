#include<iostream>
#include<vector>
using namespace std;

/* RECURSION

Ques 1: Subsets [LeetCode]

Given an integer array of unique elements, return all possible subsets (power set).
The solution set must not contain duplicate subsets. Return solution in any order.
No. of elements in Power Set = 2^n

- Input: arr={1,2,3}
- Output: {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}}

- Input: arr={0}
- Output: {{},{0}}

Explaination:
- take given arr and one Empty Output array
- use index i to iterate through array
- with i on each element make a call to
- exclude or include that element in Output arr
- in this way, make a tree and answers will be the end nodes

*/

void solve(vector<int> arr, vector<int> output, int index, vector<vector<int> > &ans){  // pass by ref, as to store values in original ans array
    if(index >= arr.size()){        // BASE CASE 
        ans.push_back(output);      // before return, we have to push End node Outputs into Ans arr
        return;
    }
    solve(arr,output,index+1,ans);  // EXCLUDE: increment index
    int element = arr[index];       // INCLUDE: put Given arr Element into Output
    output.push_back(element);
    solve(arr,output,index+1,ans);
}

vector<vector<int> > subsets(vector<int> &arr){
    vector<vector<int> > ans;       // array that will be returned, contains all subsets
    vector<int> output;             // contains individual subsets, pushed into ans
    int index = 0;                  // index to iterate through all given arr elements
    solve(arr,output,index,ans);
    return ans;
}


int main(){
    
    vector<int> arr={1,2,3};

    vector<vector<int> > answer=subsets(arr);

    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }cout<<endl;
    }
    
    
    
    return 0;
}