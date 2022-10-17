#include<iostream>
#include<vector>
using namespace std;

// Subsets of Array

void solveSubset(vector<int> arr, vector<int> output, int index, vector<vector<int>> &ans){
    if(index>=arr.size()){
        ans.push_back(output);
        return;
    }
    solveSubset(arr, output, index+1, ans);   // exclude
    int element = arr[index];   // include
    output.push_back(element);
    solveSubset(arr, output, index+1, ans);
}
vector<vector<int>> subsets(vector<int>arr){   
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solveSubset(arr,output,index,ans);
    return ans;
}

// Subsequences
void solveSubsequence(string str, string output, int index, vector<string> &ans){
    if(index>=str.length()){
        if(output.length()>0){
            ans.push_back(output);
        }
        return;
    }
    solveSubsequence(str, output, index+1, ans);
    char ele = str[index];
    output.push_back(ele);
    solveSubsequence(str, output, index+1, ans);
}
vector<string> subsequences(string str){
    vector<string> ans;
    string output="";
    int index=0;
    solveSubsequence(str, output, index, ans);
    return ans;
}


int main(){

/*
Subsets (LeetCode)
- Return all possible subsets of Array (power sets)
- Input = {1,2,3}
- Output = [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/ 
    // vector<int> arr={1,2,3};
    // int n=3;
    // vector<vector<int>> ans = subsets(arr);
    // for(int i=0;i<ans.size();i++){
    //     cout<<"[";
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }cout<<"]";
    // }cout<<endl;


/*
Subsequences Of String
- Input = "abc"
- Output = bc ac ab a b c abc " "
*/
    // string s="abc";
    // vector<string> ans=subsequences(s);
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }cout<<endl;
    
    
    return 0;
}