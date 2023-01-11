#include<iostream>
using namespace std;

/*
Binary Search Trees (Interview Questions)

Ques 1: Validate BST                                                (CodeStudio)
    Approach 1
    - Every node to left is small, to right is greater
    - Inorder is sorted for BST
    - Find inorder
        - if sorted then it is BST, if not not BST
        - Inorder is T.C. =  O(n)
    Approach 2
    - For every node, left subtree is small, right is greater
    - Find Range for which data exists to left & right of any node
    - If ranges are satisfied, valid BST
        - If it is root, root can be in any range (-infinity to +infinity)
        - For nodes to left of root, nodes can be only smaller to that root node, so (-infinity to that node)
        - For nodes to right of root, nodes can be only larger to that root node, so (that node to +infinity)
    - T.C. = O(n), S.C. = O(h)

Ques 2: Find Kth smallest Element in BST                            (CodeStudio)
    - Inorder traversal of BST is sorted: Left->Root->Right
    - Take i counter, Recursively traverse Tree inorder way
    - increment i 
        - At root, i=0
        - Left call, i=0 for all initially
        - After left calls, we reach root nodes, so increment i
        - then right calls, increment i when roots are reached
    - when i=k return node
    - T.C. = O(n), S.C. = O(h)

Ques 3: Predecessor & Successor in BST                              (CodeStudio)
    - Predecessor = max in left subtree
    - Successor = min in right subtree
    Approach:
    - Find node
    - Find min & max value, find pred & succ
    - T.C. = O(n), S.C. = O(1)

Ques 4: LCA in BST - lowest common ancestor                        (CodeStudio)
    Approach:
    - if root is less than both nodes, both nodes are in right subtree
    - if root is greater than both nodes, both nodes are in left subtree
    - root > a && root < b, root is ans
    - root < a && root > b, root is ans
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


// Ques 1: Validate BST
bool isBST(Node*root, int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->data >= min && root->data <= max){                 // check for current
        bool left = isBST(root->left, min, root->data);         // For min, it is infinity to that number
        bool right = isBST(root->right, root->data, max);       // For max, it is from that number to infinity
        return left && right;
    }
    else{
        return false;
    }
}
bool validateBST(Node*root){
    return isBST(root,INT_MIN,INT_MAX);
}


// Ques 2: Find Kth smallest Element in BST
int solveKth(Node*root, int &i, int k){
    if(root==NULL){
        return -1;
    }
    int left = solveKth(root->left, i, k);      // left call
    if(left != -1){
        return left;
    }
    i++;                                        // increment i when root is reached
    if(i==k){
        return root->data;                  
    }
    return solveKth(root->right, i, k);         // right call
}
int kthSmallestElement(Node*root, int k){
    int i=0;
    return solveKth(root, i, k);
}


// Ques 3: Predecessor & Successor in BST
pair<int,int> predeSuccessor(Node*root, int key){
    Node*temp=root;
    int pred=-1;
    int succ=-1;
    while(temp->data!=key){                     // find key, save data while traversing
        if(temp->data > key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    Node*leftTree=temp->left;                   // find predecessor
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    Node*rightTree=temp->right;                 // find successor
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    pair<int,int>ans=make_pair(pred,succ);
    return ans;
}


// Ques 4: LCA in BST
Node*LCAofBST(Node*root, Node*a, Node*b){
    if(root==NULL){
        return NULL;
    }
    if(root->data < a->data && root->data < b->data){
        return LCAofBST(root->right, a, b);
    }
    if(root->data > a->data && root->data > b->data){
        return LCAofBST(root->left, a, b);
    }
    return root;
}
Node*LCAofBST2(Node*root, Node*a, Node*b){
    while(root!=NULL){
        if(root->data < a->data && root->data < b->data){
            root=root->right;
        }
        else if(root->data > a->data && root->data > b->data){
            root=root->left;
        }
        else{
            return root;
        }
    }
}



int main(){

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

    cout<<validateBST(root)<<endl;
    cout<<kthSmallestElement(root,6)<<endl;
    
    
    
    return 0;
}