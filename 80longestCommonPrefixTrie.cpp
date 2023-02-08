#include<iostream>
#include<vector>
using namespace std;

/*
Trie Question: Longest Common Prefix

Given Array: {"coding","codezen","codingninja","coders"}
Answer: "cod"

Approach 1:
    - Take first char of first String
    - Compare that char for other strings
    - If exists for all, add in answer, move to next char
    - If not, stop
    T.C. = O((string length)*(no of string)) = O(m*n)
    S.C. = O(1) || O(m)
Approach 2:
    - create trie & insert all strings in trie
    - traverse trie from top
    - if for any char node (child count==1) add in answer & move forward
    - if not, return 
    T.C. = O((string length)*(no of string)) = O(m*n)
    S.C. = O(m*n)
*/

// Approach 1
string longestCommonPrefix1(vector<string>&arr,int n){
    string ans="";
    for(int i=0;i<arr[0].length();i++){
        char ch=arr[0][i];
        bool match=true;
        for(int j=1;j<n;j++){
            if(arr[j].size()<i || ch!=arr[j][i]){
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}

// Approach 2
class TrieNode{
public:
    char data;
    TrieNode*children[26];
    int childCount;
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};
class Trie{
public:
    TrieNode*root;
    Trie(char ch){
        root=new TrieNode(ch);
    }
    void insertUtil(TrieNode*root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->childCount++;
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->childCount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break;
            }
        }
    }
};
string longestCommonPrefix2(vector<string>&arr,int n){
    Trie*t=new Trie('\0');
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }
    string first=arr[0];
    string ans="";
    t->lcp(first,ans);
    return ans;
}



int main(){
    
    
    
    return 0;
}