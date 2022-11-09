#include<iostream>
#include<vector>
using namespace std;

void solve(string str,int index,vector<string>&ans){
    if(index>=str.length()){
        ans.push_back(str);
        return;
    }
    for(int i=index;i<str.length();i++){
        swap(str[index],str[i]);
        solve(str,index+1,ans);
        swap(str[index],str[i]);
    }
}

vector<string>getPermutations(string str){
    int index=0;
    vector<string>ans;
    solve(str,index,ans);
    return ans;
}

int main(){
    string str="abc";
    vector<string>ans = getPermutations(str);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].length();j++){
            cout<<ans[i][j];
        }cout<<endl;
    }
    
    
    return 0;
}