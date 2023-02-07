#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Ques: Maximum Frequency Number
    - T.C. = O(n)
*/

int maxFrequency(vector<int>&arr,int n){
    unordered_map<int,int>count;
    int maxFreq=0;
    int maxAns=0;
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
        maxFreq=max(maxFreq,count[arr[i]]); 
    }
    for(int i=0;i<arr.size();i++){
        if(maxFreq==count[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }
    return maxAns;
}

/*
- Bucket Array
    - Array to store mapping of key value pairs
    - Array that stores values (ints,strings,etc.) at paritcular indexes
    - We use Hash Functions to map key with indexes of values
- Hash Function
    - combination of Hash Code & Compression Function
    Hash Code
        - conversion of any type of value to integer index is done by hash code
            - convert to int
            - uniform distribution, no collision, no mapping of values to same index
            Collision Handling
                - open hashing = store in same place, head of linked list is stored at index, so multiple values are stored as blocks of linked list, also called Separate Chaining
                - Closed addressing = if cannot store at a place, store at index determined by a function, hi(a)=h(a)+fi(a), make attempts to store at next diff indexes, Linear Probing
                - Quadratic probing = next indexes are checked by adding squares of number
        - T.C. = O(1)
    Compression Function
        - Hash code outputs an integer
        - Compression Func makes this output in the range of Bucket Array Index
*/

int main(){
    
    
    
    return 0;
}