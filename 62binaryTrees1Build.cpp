#include<iostream>
#include<queue>
using namespace std;

/*
BINARY TREES
- non linear data structure
- one node can be linked to multiple nodes

Basic Terms:
- Node = an element of tree that stores data
- Root = starting point of tree
- Children, Parent, Sibling = nodes with same parent
- Ancestor = all nodes above node, Descendent = all nodes blow node 
- Leaf = end node, has no children
- Binary Tree = each node has less than equal to 2 children
*/

class node{
public:  
    int data;
    node*left;  
    node*right;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

// Building Tree using Recursion
node*buildTree(node*root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

int main(){
    
    node*root = NULL;
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);
    
    
    return 0;
}