#include<iostream>
using namespace std;

/*
Largest BST in Binary Tree  (HARD)

- For BST, left has smaller elements, right has greater elements

Approach 1:
    - traverse each node, check for valid bst
    - if yes, store size and keep max size count
    - T.C. = O(n^2)
Approach 2:
    - check for nodes only once
    - For each node = left & right subtree -> valid subtree
    - Root->data must be bigger than maximum of left subTree 
    - Root->data must be smaller than minimum of right subTree 
    So, for each node we must have following values:
    - int maximum of left subtree
    - int minimum of right subtree
    - bool isValidBST, for both left & right
    - int size = leftSubtreeSize + rightSubtreeSize + 1
    - T.C. = O(n)
*/

class Node{
public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }  
};

class info{
public:
    int maximum;
    int minimum;
    bool isBST;
    int size;
};

info solve(Node*root, int &maxSize){
    if(root==NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left = solve(root->left, maxSize);
    info right = solve(root->right, maxSize);
    info currentNode;
    currentNode.size = left.size + right.size + 1;
    currentNode.maximum = max(root->data, right.maximum);
    currentNode.minimum = min(root->data, left.minimum);
    if(left.isBST && right.isBST && (root->data > left.maximum && root->data < right.minimum)){
        currentNode.isBST = true;
    }
    else{
        currentNode.isBST = false;
    }
    if(currentNode.isBST){
        maxSize = max(maxSize, currentNode.size);
    }
    return currentNode;
}

int largestBST(Node*root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main(){
    
    
    
    return 0;
}