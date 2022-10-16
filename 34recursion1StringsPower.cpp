#include<iostream>
using namespace std;

// Reverse String (CodeStudio) with 2 pointers
void reverseString(string &s,int start,int end){
    if(start>end){
        return;
    }
    swap(s[start],s[end]);
    start++;end--;
    reverseString(s,start,end);
}

// Reverse with 1 pointer
void reverseString2(string &s,int ptr,int n){
    if(ptr>n/2){
        return;
    }
    swap(s[ptr],s[n-ptr-1]);
    ptr++;
    reverseString2(s,ptr,n);
}

// Palindrome
bool checkPalindrome(string s,int start,int end){
    if(start>end){
        return true;
    }
    if(s[start]!=s[end]){
        return false;
    }
    return checkPalindrome(s,start+1,end-1);
}

// Find Power
int findPower(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;   
    }
    int ans=findPower(a,b/2);
    if(b%2==0){
        return ans*ans;
    }else{
        return a*ans*ans;
    }
}

int main(){
    
// Reverse String (with 1,2 pointers)
    // string s = "abcde";
    // int start=0;
    // int end=s.length()-1;
    // reverseString(s,start,end);
    // int n=5;
    // reverseString2(s,start,n);
    // cout<<s<<endl;

// Check Palindrome
    // string s="sarthakkahtras";
    // int start=0;
    // int end=s.length()-1;
    // cout<<checkPalindrome(s,start,end)<<endl;

// Find Power
    // int a=3;
    // int b=11;
    // cout<<findPower(a,b)<<endl;


    
    return 0;
}