#include<iostream>
#include<vector>
using namespace std;

/*
Ques 1: Two Sum in BST                              (CodeStudio)
    Approach 1 BruteForce:
    - take root node, search (target-10) in left & right parts
    - Go to left subtree, take a node, search (target-node) in left & right parts
    - do the same for right subtree
    - T.C. = O(n^2)
    Approach 2 SingleTraversal:
    - BST inorder is always sorted
    - Inorder traversal T.C. = O(n), S.C. = O(n) to store inorder
    - Use 2 pointers Approach = i start, j end
    - if(i+j>target) j--, if(i+j<target) i++, if(i+j==target) return true

Ques 2: Flatten BST to a Sorted Linked List         (CodeStudio)    
    Approach 1:
    - BST inorder is sorted & we want a sorted list
    - Store vector<Node*> of inorder of bst, we can also access left & right pointers
    - Traverse vector, make left=NULL, & point right to next Node
    - For last node, make left=right=NULL
    - T.C. = O(n), S.C. = O(n)
    Approach 2:
    - Store inorder in vector<int>
    - To create a LinkedList, we need a new node (newRoot), assign newRoot with value inorder vector[0]
    - Make another node current, point it to newRoot
    - Traverse inorderVector from 1st index to end
        - make tempNode with value inoderVector[i] in loop
        - Assign curr->left=NULL, curr->right=temp
        - And move curr forward, curr=temp
    - Now for last node, make left=right=NULL

Ques 3: Normal BST to Balanced BST                  (CodeStudio)
    - BalanceBST: for each node, abs[height(left)-height(right)] <= 1
    - BST Inorder is sorted
    Approach:
    - Save inorder in vector<int>
    - Find mid, make node for mid
    - Recursive call to make left & right subtree

Ques 4: Preorder traversal of BST                   (CodeStudio)
    (Correct Name: BST from Preorder)
    Approach 1:
    - Simply traverse Preorder & insert nodes
    - T.C. = O(n^2)
    Approach 2:
    - Sort Preorder, now it is Inorder
    - And we know how to make tree from Inorder & Preorder 
    - T.C. = O(n log n)
    Approach 3:
    - Use input Preorder for optimized approach: Root->Left->Right
    - Use Range Approach, used in ValidateBST
    - Traverse Preorder array:
    - Start from [INT_MIN,INT_MAX], if current value lies between this range, create Node
    - For left subTree, range = [INT_MIN,curr value]
    - For right subTree, range = [curr value,INT_MAX]
    - If does not belong in range: return NULL
    - So, we traverse Preorder array once, check for each node & insert into bst
    - T.C. = O(n)
*/

class Node{
public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

// Ques 1: Two Sum in BST
void inorderStore(Node*root, vector<int>& inorder){
    if(root==NULL){
        return;
    }
    inorderStore(root->left, inorder);
    inorder.push_back(root->data);
    inorderStore(root->right, inorder);
}
bool twoSumInBST(Node*root, int target){
    vector<int>inorder;
    inorderStore(root, inorder);
    int i=0;
    int j=inorder.size()-1;
    while(i<j){
        int sum=inorder[i]+inorder[j];
        if(sum==target){
            return true;
        }
        if(sum<target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

// Ques 2: Flatten BST to a Sorted Linked List
void makeInorder(Node*root, vector<int> &v){
    if(root==NULL){
        return;
    }
    makeInorder(root->left, v);
    v.push_back(root->data);
    makeInorder(root->right, v);
}
Node* flatterBstIntoList(Node*root){
    vector<int> inorder;
    makeInorder(root, inorder);
    Node* newRoot = new Node(inorder[0]);
    Node* curr = newRoot;
    for(int i=1;i<inorder.size();i++){
        Node* temp=new Node(inorder[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
}

// Ques 3: Normal BST to Balanced BST
void inorderVector(Node*root, vector<int> &v){
    if(root==NULL){
        return;
    }
    inorderVector(root->left, v);
    v.push_back(root->data);
    inorderVector(root->right, v);
}
Node* inorderToBST(int start, int end, vector<int> v){
    if(start > end){ 
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=new Node(v[mid]);
    root->left=inorderToBST(start, mid-1, v);
    root->right=inorderToBST(mid+1, end, v);
    return root;
}
Node* balancedBST(Node*root){
    vector<int> inorder;
    inorderVector(root, inorder);
    return inorderToBST(0, inorder.size()-1, inorder);
}

// Ques 4: BST from Preorder
Node* solve(vector<int>& preorder, int min, int max, int &i){
    if(i >= preorder.size() || preorder[i] < min || preorder[i] > max){     // for out of range
        return NULL;
    }
    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder, min, root->data, i);
    root->right = solve(preorder, root->data, max, i); 
    return root;
}
Node* preorderToBST(vector<int>& preorder){
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solve(preorder, min, max, i);
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

    cout<<twoSumInBST(root,1110)<<endl;
    
    
    return 0;
}