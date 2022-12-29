#include<iostream>
using namespace std;

/*
Morris Traversal

For Traversals: LevelOrder, Inorder, preorder, postorder
    - T.C.=O(n), S.C.=O(n)
For Morris Traversal
    - T.C.=O(n), S.C.=O(1)

With other traversals:
    - we travel back to root using recursion
But in Morris Traversal:
    - we make temporary links to help move back up to root
 
Tree:           1
            2       3
        4      5        6
          7 

Algorithm:
- current = root
- while(root!=NULL)
    - if(left not exist)
        visit(current)                      // printing current
        current=current->right              // move current to its right
    - else
        - predecessor=find(current)         // go one left, then right until NULL is found, that node is predecessor
        - if(pred->right==NULL)             // if right of predecessor is NULL
            - pred->right=current           // make a link of pred->right to current
            - current=current->left         // now move current to its left
        - else
            - pred->right=NULL
            - visit(current)
            - current=current->right

Morris Traversal of Above Tree: 4 7 2 5 1 3 6
Similar to Inorder but less Space Complexity
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

void morrisTraversal(Node*root){
    Node *current, *pre;
    if(root==NULL){
        return;
    }
    current = root;
    while(current != NULL){
        if(current->left == NULL){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            pre = current->left;
            while(pre->right!=NULL && pre->right!=current){
                pre = pre->right;
            }
            if(pre->right==NULL){
                pre->right = current;
                current = current->left;
            }
            else{
                pre->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}

int main(){
    
    
    
    return 0;
}