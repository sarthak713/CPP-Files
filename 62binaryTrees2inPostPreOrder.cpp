#include<iostream>
#include<queue>
using namespace std;

/*
Binary Tree Traversals

1. Inorder = Left -> Root -> Right
2. Preorder = Root -> Left -> Right
3. Postorder = Left -> Right -> Root
*/

class node{
public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// Level Order Traversal - Simple without new lines
void levelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

// In-order
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Pre-order
void preorder(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order
void postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    
/*
        1
       /  \
      3    5
    /  \  /  \ 
   7  11 17  NULL 
*/

    node*root=new node(1);
    root->left=new node(3);
    root->right=new node(5);
    root->left->left=new node(7);
    root->left->right=new node(11);
    root->right->left=new node(17);
    root->right->right=NULL;
    
    levelOrderTraversal(root);  // 1 3 5 7 11 17
    cout<<endl;

    inorder(root);      // 7 3 11 1 17 5
    cout<<endl;
    preorder(root);     // 1 3 7 11 5 17
    cout<<endl;
    postorder(root);    // 7 11 3 17 5 1
    cout<<endl;
    
    return 0;
}