#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* RECURSION

Subsequences of String [CodeStudio]

Given a string 'STR' containing lowercase English letter from a to z.
Find all non-empty possible subsequences of 'STR'.

Input: "abc"
Output: a,b,c,ab,bc,ca,abc
*/

void solve(string str, string output, int index, vector<string>& ans){
    if(index >= str.length()){
        if(output.length()>0){
            ans.push_back(output);
        }
        return;
    }
    solve(str,output,index+1,ans);
    char ele = str[index];
    output.push_back(ele);
    solve(str,output,index+1,ans);
}

vector<string> subsequences(string str){
    int index=0;
    string output="";
    vector<string>ans;
    solve(str,output,index,ans);
    return ans;
}

int main(){
    
    string str="abc";
    vector<string>ans=subsequences(str);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].length();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    
    
    return 0;
}