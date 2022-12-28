#include<iostream>
#include<vector>
using namespace std;
/*
Binary Tree Interview Questions

1. Sum of longest bloodline of a Tree               (GFG)
    - sum of nodes on the longest path from root to leaf node
    - if sum of two paths is equal, choose longer path
    Approach:
    - make a pair of <sum,length of path>
    - recursively traverse from root to leaf
    - increment length when we move down the tree
    - compare lengths and sum & update with larger values only for leafs
    T.C. = O(n), S.C. = O(height)

2. Lowest Common Ancestor in Binary Tree            (GFG)
    T.C. = O(n), S.C. = O(height)
    
3. K Sum Paths                                      (GFG)
    - find number of paths in tree having sum = k
    - path may start & end at any node

4. Kth ancestor                                     (GFG)
    T.C. = O(n), S.C. = O(height)

5. Maximum Sum of non-adjacent nodes                (GFG)

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

// Ques 1: Sum of longest bloodline of a Tree
void solveLongRoot(node*root,int sum,int &maxSum,int length,int &maxLength){
    if(root==NULL){
        if(length > maxLength){
            maxLength=length;
            maxSum=sum;
        }
        else if(length==maxLength){
            maxSum=max(sum,maxSum);
        }
        return;
    }
    sum = sum+root->data;
    solveLongRoot(root->left,sum,maxSum,length+1,maxLength);
    solveLongRoot(root->right,sum,maxSum,length+1,maxLength);
}
int sumOfLongRootToLeaf(node*root){
    int length=0;
    int maxLength=0;
    int sum=0;
    int maxSum=INT_MIN;
    solveLongRoot(root,sum,maxSum,length,maxLength);
    return maxSum;
}


// Ques 2: Lowest Common Ancestor
node*lca(node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node*leftAns=lca(root->left,n1,n2);
    node*rightAns=lca(root->right,n1,n2);
    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    else if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}


// Ques 3: K Sum Paths
void solveKsum(node*root,int k,int &count,vector<int>path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);             // push root's data 
    solveKsum(root->left,k,count,path);     // for left subtree
    solveKsum(root->right,k,count,path);    // for right subtree
    int size=path.size();
    int sum=0;                              // to check sum == k
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;                        // when sum == k, increment count
        }
    }
    path.pop_back();                        // when we return from recursive callback, remove node
}
int sumK(node*root,int k){
    vector<int>path;                        // for each group of nodes
    int count=0;                            // no. of paths with k sum
    solveKsum(root,k,count,path);
    return count;
}


// Ques 4: Kth ancestor
node* solveKancestor(node*root,int &k,int value){
    if(root==NULL){
        return NULL;
    }
    if(root->data==value){                  // when node is found, return node
        return root;
    }
    node*leftAns=solveKancestor(root->left,k,value);
    node*rightAns=solveKancestor(root->right,k,value);
    if(leftAns!=NULL && rightAns==NULL){
        k--;                                // decrement kth ancestor as we return node upwards
        if(k<=0){
            k=INT_MAX;                      // ans lock
            return root;                    // return root when kth ancestor = 0, as we cannot go any further up & this is ans
        }
        return leftAns;                     // return node when kth ancestor not yet zero
    }
    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(node*root,int k,int value){
    node*ans=solveKancestor(root,k,value);
    if(ans==NULL || ans->data==value){
        return -1;
    }
    return ans->data;
}


// Ques 5: Maximum Sum of non-adjacent nodes
pair<int,int>solveMaxSum(node*root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }
    pair<int,int>leftAns=solveMaxSum(root->left);
    pair<int,int>rightAns=solveMaxSum(root->right);
    pair<int,int>result;
    result.first=root->data+leftAns.second+rightAns.second;     // by including nodes at current level, left & right's second = values by exculding left & right of root as we want non-adjacent nodes
    result.second=max(leftAns.first,leftAns.second)+max(rightAns.first,rightAns.second);    // get max from both sides and add
    return result;
}
int getMaxSum(node*root){
    pair<int,int>ans=solveMaxSum(root);
    return max(ans.first,ans.second);
}


int main(){
/*
        1
     2     3
  4    5 6    7      
*/
    
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);


    cout<<sumOfLongRootToLeaf(root)<<endl;

    cout<<lca(root,4,6)->data<<endl;

    cout<<sumK(root,6)<<endl;

    cout<<kthAncestor(root,2,5)<<endl;

    cout<<getMaxSum(root)<<endl;

    
    
    return 0;
}