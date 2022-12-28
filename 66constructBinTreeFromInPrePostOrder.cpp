#include<iostream>
#include<map>
using namespace std;
/*
Construct Binary Tree from Inorder & Preorder
- Inorder = 1 6 8 7   (left root right)
- Preorder = 1 6 7 8  (root left right)

Approach:
    - 1st element of Preorder is root, which is 1
    - Find 1 in Inorder 
        - 1 is first element, so Left subtree is not there
        - Right subtree = 6 8 7
    - So Inorder = 6 8 7, Preorder = 6 7 8
    - This is a subproblem
        - 1st element of Preorder, root = 6
        - 6 is also 1st in Inorder, so no left subtree again
    - Now, Inorder = 8 7, Preorder = 7 8
        - In preorder, 7 is root as it is first
        - Find in inorder, 8 is to left of 7, 7 is root & 8 is left subtree
    - When we assign 7 as root now, only 8 is left in both inorder & preorder
    - So Tree:
    1
     \
      6 
       \
        7
       /
      8
    - Inorder = 1 6 8 7
    - Preorder = 1 6 7 8
    - Postorder = 8 7 6 1
So, Steps:
1 refer preorder, get root
    - start from 0th index of preorder, take this index as root
2 find root in inorder
    - find root element position in inorder
    - create map to search in O(1) time
3 left of root is leftSubtree, right of root is rightSubtree
    - recursive call for root->left, from inorder start till position-1
    - recursive call for root->right, from position+1 till inorder end

T.C. = O(n log n)
S.C. = O(n)

----------------------------------------------------------------------------------


Construct Binary Tree from Inorder & Postorder

Approach:
- Inorder = Left Root Right
- Postorder = Left Right Root
- So here we start postIndex from end, as root is at the end of preorder array
- Same as before, find root in inorder array
- nodes to the left are left subtree
- nodes to the right are right subtree

T.C. = O(n long n)
S.C. = O(n)

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

// Construct Tree from Inorder & Preorder

// APPROACH 1 
int findPos(int in[],int element,int n){
    for(int i=0;i<n;i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}
Node*solve1(int in[],int pre[],int &preIndex,int inorderStart,int inorderEnd,int n){
    if(preIndex>=n || inorderStart>inorderEnd){                
        return NULL;
    }
    int element = pre[preIndex++];   
    Node*root=new Node(element);       
    int position=findPos(in,element,n);               
    root->left=solve1(in,pre,preIndex,inorderStart,position-1,n);
    root->right=solve1(in,pre,preIndex,position+1,inorderEnd,n);
    return root;
}
Node*constructInPreOrder1(int in[],int pre[],int n){
    int preIndex=0;                      
    Node*ans=solve1(in,pre,preIndex,0,n-1,n);
    return ans;
}   

// APPROACH 2
void createMap(int in[],map<int,int>&NodeToIndex,int n){
    for(int i=0;i<n;i++){
        NodeToIndex[in[i]]=i;
    }
}
Node*solve2(int in[],int pre[],int &preIndex,int inorderStart,int inorderEnd,int n,map<int,int>&NodeToIndex){
    if(preIndex>=n || inorderStart>inorderEnd){                 // preorder Index crosses array length OR start of inorderIndex greater than its end
        return NULL;
    }
    int element = pre[preIndex++];                              // get root element from preorder array using preorder index
    Node*root=new Node(element);                                // make Node using element to insert in tree                            
    int position=NodeToIndex[element];                          // find in inorder array
    root->left=solve2(in,pre,preIndex,inorderStart,position-1,n,NodeToIndex);  // recursive left call
    root->right=solve2(in,pre,preIndex,position+1,inorderEnd,n,NodeToIndex);   // recursive right call
    return root;
}
Node*constructInPreOrder2(int in[],int pre[],int n){
    int preIndex=0;
    map<int,int>NodeToIndex;
    createMap(in,NodeToIndex,n);                            // create mapping Node to index
    Node*ans=solve2(in,pre,preIndex,0,n-1,n,NodeToIndex);                      // (inorder arr,preorder arr,preorder Index,inorder start index,inorder end index)
    return ans;
}   

//-----------------------------------------------------------------------------------------------------------------

// Create from Inorder & Postorder

void createMap2(int in[], map<int,int>& nodeToIndex, int n){
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]]=i;
    }
}

Node* solve2(int in[], int post[], int &postIndex, int inorderStart, int inorderEnd, int n, map<int,int> &nodeToIndex){
    if(postIndex < 0 || inorderStart > inorderEnd){
        return NULL;
    }
    int element = post[postIndex--];
    Node* root = new Node(element);
    int position = nodeToIndex[element];
    root->right = solve2(in, post, postIndex, position+1, inorderEnd, n, nodeToIndex);
    root->left = solve2(in, post, postIndex, inorderStart, position-1, n, nodeToIndex);
    return root;
}

Node* contructFromInPostOrder(int in[], int post[], int n){
    int postIndex = n-1;
    map<int,int>nodeToIndex;
    createMap2(in, nodeToIndex, n);
    Node*ans = solve2(in, post, postIndex, 0, n-1, n, nodeToIndex);
    return ans;
}


int main(){

    int inorder[]={1,6,8,7};
    int preorder[]={1,6,7,8};
    int n=4;
    
    
    
    return 0;
}