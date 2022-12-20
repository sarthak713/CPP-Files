#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
Iterative Traversal

1. Inorder 
2. Preorder 
3. Postorder 

Inorder Iterative Algorithm:
    1 Create empty stack 
    2 initialize current Node as Root
    3 push current node into stack
        - set current=current->left until current==NULL
    4 if current==NULL & !stack.empty()
        - pop top item from stack
        - print popped item, set current=popped_item->right
        - push current node into stack
    5 if current==NULL & stack.empty() done

Preorder Iterative Algorithm:
    1 Create empty stack and push root
    2 while(!stack.empty())
        - pop item from stack and print it
        - push right child of popped item to stack 
        - push left child of popped item to stack
    Right child is pushed before left so left tree is processed first 

Postorder Iterative Algorithm:
    1 Create 2 stacks and push root in s1
    2 while(!s1.empty())
        - store and pop item from stack, push this into s2 
        - push left child of popped item to stack 
        - push right child of popped item to stack
    Then while(!s2.empty()) print s2.top and pop 

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

// In-order Iterative
void inorderIterative(node*root){
    stack<node*>s;
    node*temp=root;
    while(temp!=NULL || !s.empty()){
        while(temp!=NULL){      // reach left most node using temp
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();           // temp is NULL at this point
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;       // traverse right subtree
    }
}

// Pre-order Iterative
void preorderIterative(node*root){
    if(root==NULL){
        return;
    }
    stack<node*>s;
    s.push(root);
    while(!s.empty()){
        node*temp=s.top();
        cout<<temp->data<<" ";
        s.pop();
        if(temp->right){
            s.push(temp->right);
        }
        if(temp->left){
            s.push(temp->left);
        }
    }
}

// Post-order Iterative
void postorderIterative(node*root){
    if(root==NULL){
        return;
    }
    stack<node*>s1,s2;
    s1.push(root);
    node*temp;
    while(!s1.empty()){
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
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
    
    inorderIterative(root);      // 7 3 11 1 17 5
    cout<<endl;
    preorderIterative(root);     // 1 3 7 11 5 17
    cout<<endl;
    postorderIterative(root);    // 7 11 3 17 5 1
    cout<<endl;
    
    return 0;
}