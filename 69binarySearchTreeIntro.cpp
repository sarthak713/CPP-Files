#include<iostream>
#include<queue>
using namespace std;

/*
Binary Search Tree

- Searching is fast: O(log N)
- Insertion: O(log N)

- For every Root or Node:
    - Left subtree node is Less
    - Right subtree node is Higher

Example:    10
          7    15
        5  9     17
                16 19
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

Node* insertIntoBST(Node*root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }
    else{
        root->left = insertIntoBST(root->left,data);
    }
    return root;
}

void takeInput(Node*&root){
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraverse(Node*root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
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

void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Search Recursive
bool searchInBST1(Node*root, int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data > x){
        searchInBST1(root->left,x);
    }else{
        searchInBST1(root->right,x);
    }
    return false;
}
/*
T.C. = Worst Case O(n), O(n)
S.C. = Worst Case O(n), O(h)
*/

// Search Iterative
bool searchInBST2(Node*root, int x){
    Node*temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data > x){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return false;
}
/*
T.C. = Worst Case O(n), O(n)
S.C. = O(1)
*/

// Minimum & Maximum in BST
void minAndMax(Node*root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    cout<<"Minimum: "<<temp->data<<endl;
    temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    cout<<"Maximum: "<<temp->data<<endl;
}

// Inorder Predecessor
void findPredSuccNodes(Node*root,Node*&pre,Node*&succ,int key){
    if(root==NULL){
        return;
    }
    if(root->data==key){
        if(root->left!=NULL){
            Node*temp=root->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            pre=temp;
        }
        if(root->right!=NULL){
            Node*temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            succ=temp;
        }
        return;
    }
    if(root->data > key){
        succ=root;
        findPredSuccNodes(root->left,pre,succ,key);
    }
    else{
        pre=root;
        findPredSuccNodes(root->right,pre,succ,key);
    }
}
/*
T.C. = O(h)
S.C. = O(1)
*/


// Delete From BST (IMPORTANT)
Node* minVal(Node*root){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
        root=root->right;
    }
    return root;
}
Node* deleteBSTnode(Node*&root, int val){
    if(root==NULL){
        return;
    }
    if(val==root->data){
        if(root->left==NULL && root->right==NULL){      // no children
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){      // right child only
            Node*temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){      // left child only
            Node*temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right!=NULL){      // both children
            int minimum=minVal(root->right)->data;
            root->data=minimum;
            root->right=deleteBSTnode(root->right,minimum);
            return root;
        }
    }
    else if(val < root->data){
        root->left=deleteBSTnode(root->left,val);
        return root;
    }
    else{
        root->right=deleteBSTnode(root->right,val);
        return root;  
    }
}
/*
T.C. = O(h)
S.C. = O(h)
*/


int main(){
    
    // Node*root=NULL;
    // cout<<"Enter Data to create BST: "<<endl;
    // takeInput(root);

/*
            50
         20    70
       10  30    90
               80  110 
*/

    Node*root=new Node(50);
    root->left=new Node(20);
    root->left->left=new Node(10);
    root->left->right=new Node(30);
    root->right=new Node(70);
    root->right->right=new Node(90);
    root->right->right->right=new Node(110);
    root->right->right->left=new Node(80);


    levelOrderTraverse(root);
    cout<<endl;
    inorder(root);      // prints BST in sorted order 
    cout<<endl;
    minAndMax(root);
    cout<<endl;

    Node*pre=NULL;
    Node*succ=NULL;
    findPredSuccNodes(root,pre,succ,110);
    cout<<pre->data<<" ";   // 20
    cout<<succ->data<<" ";  // 50



    return 0;
}