#include<iostream>
using namespace std;

/*
Flatten A Binary Tree

- Flatten into linked list using Preorder
- Left will be NULL, right will be the nodes
- T.C. = O(n), S.C. = O(1)
- No extra space should be used, should be in-place
- Cannot be solved using traversing making nodes or Recursion because it will give O(n) space complexity
- We use Morris Traversal

Approach:
- In preorder trversal: Root Left Right
- For Inorder Predecessor: we go one left, then right
- Then we link node to right part, Left->Right
- We have to link Root to Left, we remove left pointer of root connect to NULL
- Then right of root to Left
1. Find inorder Predecessor, right of Pred -> current's right
2. Current's right -> left part
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

void flatten(Node* root){
    Node*curr=root;
    while(curr!=NULL){
        if(curr->left){
            Node*pred=curr->left;
            while(pred->right){
                pred=pred->right;
            }
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
}

int main(){
    
    
    
    return 0;
}