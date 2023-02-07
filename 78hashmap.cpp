#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

/*
HASHMAPS

- Data Structure which is Used vastly in development
- Insertion, Deletion, Searching functions are fast O(1)
- Map is used to store key-value pairs

- Implementation:
    - Hashmap cannot be implemented using LinkedList or BST 
      as time complexity of these Data Structures is not constant
    - We use HashTable to implement these functions in O(1)

- Inbuilt:
    - map
        - sequence is maintained
        - Complexity O(log n)
    - unordered_map
        - based on hashtable
        - Complexity O(1)

*/

int main(){


    // Create
    unordered_map<string,int>m;         // <string,int> key-value pair
    
    // Insert 1
    pair<string,int>p1=make_pair("babbr",3);
    m.insert(p1);
    // Insert 2
    pair<string,int>p2("love",2);
    m.insert(p2);
    // Insert 3
    m["mera"]=1;                        // create
    m["mera"]=2;                        // update (for every key, only one value exists)

    // Search
    cout<<m["mera"]<<endl;              // 2
    cout<<m.at("babbr")<<endl;          // 3
    cout<<m["anyKey"]<<endl;            // creates new key, with value 0
    // cout<<m.at("unknownKey")<<endl;     // Error

    // Size
    cout<<m.size()<<endl;               // 4

    // Check If Key is Present
    cout<<m.count("babbr")<<endl;       // if no->0, if yes->1

    // Erase
    m.erase("love");
    cout<<m.size()<<endl;               // 3 

    // Access
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    // iterator
    unordered_map<string,int>::iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    

    return 0;
}