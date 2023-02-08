#include<iostream>
using namespace std;

/*
TRIE

What is trie:
    - Tree like Data structure
    - Used in implementing Dictionary 
        - hashmap is not used as its has O(1) T.C. for Avergae Case but varies for worst case
    - To implement Dictionary:
        - take a word
        - traverse word character by character
        - check if it is present in Dictionary
        - if present go ahead
        - If not, create new node for that character and add to tree
        - Repeat until entire word/string is processed

Creating Trie Data Structure:
    - char data             (for each node)
    - TrieNode*children[26] (single node can have upto 26 characters A to Z)
    - bool isTerminal       (for each word, to identify where the word ends)
    Insertion: O(length of word)
    Search: O(length of word)
    Removal: O(length of word)
    Deletion: O(length of word)
*/

class TrieNode{
public:
    char data;
    TrieNode*children[26];
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode*root,string word){
        if(word.length()==0){                   // base case (make last charcater node terminal)
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){        // if char already present (move forward)
            child=root->children[index];
        }
        else{                                   // if char absent (create new node, move forward)
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));       // recursion
    }
    void insertWord(string word){
        insertUtil(root,word);
    }   
    bool searchUtil(TrieNode*root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'A';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root,word);
    }   
};

int main(){
    
    Trie *t=new Trie();
    t->insertWord("abcd");
    cout<< t->searchWord("abcd")<<endl;
    
    
    return 0;
}