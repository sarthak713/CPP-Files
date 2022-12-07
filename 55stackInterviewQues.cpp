#include<iostream>
#include<stack>
using namespace std;
/*
Stack Interview Questions:
    1. Reverse a String using stack
    2. Delete middle element from Stack                 (code studio)
    3. Valid Parenthesis                                (code studio)
    4. Insert Element at its bottom in a given stack    (code studio)
    5. Reverse Stack using Recursion                    (code studio)
    6. Sort a Stack                                     (code studio)
    7. Redundant Brackets                               (code studio)
    8. Minimum Cost to make string Valid                (code studio) 
*/

class Stack{
public:
    int*arr;
    int size;
    int top;
    Stack(int size){
        this->size=size;
        top=-1;
        arr=new int[size];
    }
    void push(int data){
        if(size-top>1){
            top++;
            arr[top]=data;
        }else{
            cout<<"Stack Overflow"<<endl;
            return;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    int peek(){
        if(top==-1){
            cout<<"No element in Stack";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
};

// Ques 1: Reverse String Using Stack
string reverseString(string str){
    stack<char> st;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        st.push(ch);
    }
    string ans="";
    while(!st.empty()){
        char ch=st.top();
        ans.push_back(ch);
        st.pop();
    }
    return ans;
}
/*
T.C. = O(n)
S.C. = O(n)
*/

// Ques 2: Delete middle element from Stack
void deleteSolve(stack<int>& inputStack,int count,int size){
    if(count==size/2){
        inputStack.pop();
        return;
    }
    int num=inputStack.top();
    inputStack.pop();
    deleteSolve(inputStack,count+1,size);
    inputStack.push(num);
}
void deleteMiddle(stack<int>& inputStack,int N){
    int count=0;
    deleteSolve(inputStack,count,N);
}

// Ques 3: Valid Parenthesis
bool isValidParenthesis(string expres){
    stack<char>s;
    for(int i=0;i<expres.length();i++){
        char ch=expres[i];
        if(ch=='(' || ch=='[' || ch=='{'){ 
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top=s.top();
                if( (top=='(' && ch==')') || 
                    (top=='[' && ch==']') || 
                    (top=='{' && ch=='}') ){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    return false;
}

// Ques 4: Insert Element at its bottom in a given stack
void solveInsert(stack<int>&st,int data){
    if(st.empty()){
        st.push(data);
        return;
    }
    int top=st.top();
    st.pop();
    solveInsert(st,data);
    st.push(top);
}
stack<int> insertAtBottom(stack<int>& st, int data){
    solveInsert(st,data);
    return st;
}

// Ques 5: Reverse Stack using Recursion
void reverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int top=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,top);
}
/*
TC = O(n^2)
*/

// Ques 6: Sort a Stack
void sortedInsert(stack<int>&st,int num){
    if(st.empty() || st.top()<num){
        st.push(num);
        return;
    }
    int n=st.top();
    st.pop();
    sortedInsert(st,num);
    st.push(n);
}
void sortStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int num=st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st,num);
}

// Ques 7: Redundant Brackets
bool findRedundantBrackets(string &s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='(' || ch=='+'|| ch=='-'|| ch=='*'|| ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedundant=true;
                while(st.top()!='('){
                    char top=st.top();
                    if(top=='+'|| top=='-'|| top=='*'|| top=='/'){
                        isRedundant=false;
                    }
                    st.pop();
                }
                if(isRedundant){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
/*
TC = O(n)
*/

// Ques 8: Minimum Cost to make string Valid
int findMinimumCost(string str) {
    if(str.length()%2==1){
        return -1;
    }
    stack<char>s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='{'){
            s.push(ch);
        }
        else{   // ch is closed brace
            if(!s.empty() && s.top()=='{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }   // stack contains invalid expression   
    }
    int a=0,b=0;    
    while(!s.empty()){
        if(s.top()=='{'){
            b++;
        }
        else{
            a++;
        }
        s.pop();
    }
    int ans=(a+1)/2 + (b+1)/2;
    return ans;   
}


int main(){
    

    // string s="sarthak";
    // cout<<reverseString(s)<<endl; 

    // string s="{([])}";
    // cout<<isValidParenthesis(s)<<endl;
    



    
    
    return 0;
}