#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* RECURSION & BACKTRACKING

Ques: Letter Combinations of a Phone Number [LeetCode]

Given a string containing digits from 2-9 inclusive,
return all possible letter combinations that the number could represent.

Input: digits="23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Input: digits=""
Output: []

Input: digits="2"
Output: ["a","b","c"]

Explaination =>
- take Given input string & Empty Output string
- take iterator index to loop each Number in Given string
- Take 1st number & alphabets mapped to it are take one by one 
- And move to 2nd number & for this
    - take alphabets mapped to this number one by one with individual alphabets of 1st number
- All combinations are output

*/

void solve(string digits,string output,int index,vector<string>&ans,string map[]){
    if(index >= digits.length()){       // BASE CASE
        ans.push_back(output);          // push output string into ans vector
        return;
    }
    int number = digits[index]-'0';     // Ex: to make string "2" to int 2
    string value = map[number];         // Get alphabets mapped to the number
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);             // push 1st number alphabets one by one in output, & recursive call for alphabets of 2nd number
        solve(digits,output,index+1,ans,map);   // now output contains individual alphabet & will combine that one by one with all alphabets of 2nd number
        output.pop_back();                      // BackTracking: remove already added alphabet of 1st number
    }
}

vector<string> letterCombos(string digits){
    vector<string> ans;
    if(digits.length()==0){
        return ans;
    }
    string output;
    int index=0;
    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,index,ans,map);
    return ans;
}

int main(){

    string digits = "23";
    vector<string> ans = letterCombos(digits);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].length();j++){
            cout<<ans[i][j];
        }cout<<endl;
    }

    return 0;
}