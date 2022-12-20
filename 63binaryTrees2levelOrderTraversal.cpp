#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
Level Order Traversal
- Root of tree is at Level 0
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

// Level Order Traversal - BFS
void levelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);                       // separator - to print next level in new line
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){                 // if temp is NULL, previous level is completely traversed
            cout<<endl;                 // all nodes of that level are in queue, so print in next line
            if(!q.empty()){             // if queue is still not empty, push endl again
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";      // print data, only when temp is not NULL
            if(temp->left != NULL){     // if we print when temp is NULL, it will give Segmentation Fault
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

// Reverse Level Order Traversal
void reverseLevelOrderTraversal(node*root){
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        s.push(temp);               // instead of printing, push elements in stack
        if(temp->right){            // right child is pushed before left
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    while(!s.empty()){
        node*temp=s.top();
        cout<<temp->data<<" ";
        s.pop();
    }
}


int main(){
    

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout<<endl;
    cout<<"Printing Level Order Traversal: "<<endl;
    levelOrderTraversal(root);  // Output: 1 2 3 4 5
    cout<<endl;

    cout<<endl;
    cout<<"Printing Reverse Level Order Traversal: "<<endl;
    reverseLevelOrderTraversal(root);  // Output: 4 5 2 3 1
    cout<<endl;


    
    return 0;
}