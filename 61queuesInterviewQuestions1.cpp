#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;

/*
Queues Interview Questions:

1. Reverse Queue (GFG)
    - Stack
    - Recursion
    - T.C. = O(n), S.C. = O(n) 

2. Find negative integer in every window of size k (GFG)
    - make doubly ended queue, push first k elements
    - that window of k elements, contains answer (sliding window approach)
    - when we move forward, pop_front and push_back is done
    - while pushing, if number is negative store its index

3. Reverse 1st K elements of Queue (GFG)
    - pop first k elements from queue and push into stack
    - pop from stack and push into queue
    - loop q q.size()-k times and pop and push into queue
    - T.C. = O(n), S.C. = O(k)

4. First non-repeating character in a stream (GFG)
    - make map<char,i> stores the number of times a character is present in string
    - map is of 26 size, make queue to store new element and increment count in map
    - check front element of queue & count, if it repeats or not 
        - if repeating pop
        - else store in answer string

*/

// Ques 1: Reverse Queue
queue<int> rev(queue<int> q){
    stack<int>s;
    while(!q.empty()){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int element=s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

// Ques 2: Find negative integer in window of size k
vector<long long> printFirstNegativeInt(long long int arr[], long long int n, long long int k){
    vector<long long> ans;
    deque<long long int> dq;

    for(int i=0;i<k;i++){       // process 1st window of k size
        if(arr[i]<0){           // if element is negative
            dq.push_back(i);    // store index in deque
        }
    }

    if(dq.size()>0){            
        ans.push_back(arr[dq.front()]);     // store ans of 1st k sized window
    }
    else{
        ans.push_back(0);
    }

    for(int i=k;i<n;i++){       // process for remaining windows
        if(!dq.empty() && i-dq.front()>=k){     // if dq.front() comes in k sized window or not
            dq.pop_front();                     // if yes, then pop 
        }
        if(arr[i]<0){
            dq.push_back(i);    // addition
        }
        if(dq.size()>0){            
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}

// Ques 3: Reverse 1st K elements of Queue
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int>s;
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }
    int t=q.size()-k;
    while(t--){
        int val=q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

// Ques 4: First non-repeating character in a stream
string FirstNonRepeating(string str){
    unordered_map<char,int>count;
    queue<int>q;
    string ans="";
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        count[ch]++;                    // increment count for all chars as they come
        q.push(ch);                     // push in queue
        while(!q.empty()){              // iterate in queue as elements are pushed
            if(count[q.front()]>1){     // if count of that char is > 1, pop
                q.pop();
            }
            else{
                ans.push_back(q.front());   // if count=1, store in answer string
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}



int main(){
    
    // string s="zz";
    // string ans=FirstNonRepeating(s);
    // cout<<ans<<endl;
    
    
    return 0;
}