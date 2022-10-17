#include<iostream>
#include<vector>
using namespace std;

/*
Phone Keypad Problem
- Input = "23"
- Output = ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Find combinations we can make using any num/nums
- 2=(abc) & 3=(def)
*/

void solve(string digits, string output, int index, vector<string> &ans, string map[]){
    if(index>=digits.length()){
        ans.push_back(output);
        return;
    }
    int num=digits[index]-'0';  // get the number
    string value=map[num];      // get value according to number
    for(int i=0;i<value.length();i++){  // loop 'abc' for 2
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,map);
        output.pop_back();      // backtrack
    }
}

vector<string> letterCombos(string digits){
    vector<string> ans;
    if(digits.length()==0){
        return ans;
    }
    string output="";
    int index=0;
    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,index,ans,map);
    return ans;
}


int main(){
    
    string s="23";
    vector<string>ans=letterCombos(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}