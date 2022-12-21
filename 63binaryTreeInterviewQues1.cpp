#include<iostream>
#include<utility>
using namespace std;

/*
Binary Tree Interview Questions

1. Height Of Binary Tree                            (GFG) 
    - height = longest path between root & leaf node
    Approach (recursion):
    - height = maximum(left subtree height, right subtree height) + 1
    - +1 is done for root node
    - T.C. = O(n), S.C. = O(height)

2. Diameter of Binary Tree                          (GFG)
    - diameter = longest path between 2 end nodes
    - end node can be leaf or root node
    Approach 1:
        - using diameter ans heights
        - option 1 (left subtree)  = diamter(root->left) 
        - option 2 (right subtree) = diameter(root->right)
        - option 3 (both combined) = height(root->left) + 1 + height(root->right)
        - T.C. = O(n^2)
    Approach 2:
        - using pair
        - T.C. = O(n), S.C. = O(height)

3. Check for Balanced Tree                          (GFG)
    - height balanced tree = diff bet heights of left & right subtree is <= 1 for all nodes
    - balanced: height(left)-height(right)<=1
    Approach 1:
        - using isbalanced1 and height
        - T.C. = O(n^2), S.C. = O(height)
    Approach 2:
        - using pair
        - T.C. = O(n), S.C. = O(height)

4. Determine if 2 trees are identical or not        (GFG)
    - T.C. = O(n), S.C. = O(height)
    
5. Sum Tree                                         (GFG)
    - Value of each Node = sum of left subtree + sum of right subtree
    - T.C. = O(n), S.C. = O(height)
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


// Ques 1: Height of Binary Tree
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left,right)+1;
    return ans;
}


// Ques 2: Diameter of Binary Tree
// Approach 1
int diameter1(node*root){
    if(root==NULL){
        return 0;
    }
    int left = diameter1(root->left);
    int right = diameter1(root->right);
    int combo = height(root->left)+1+height(root->right);
    int ans = max(left, max(right,combo));
    return ans;
}
// Approach 2
pair<int,int> diameterFast(node*root){
    if(root==NULL){
        pair<int,int>p = make_pair(0,0);                // p.first = diameter, p.second = height
        return p;                                       // when root is null, diameter & height both are 0
    }
    pair<int,int> left = diameterFast(root->left);      // get diameter & height for Left Subtree
    pair<int,int> right = diameterFast(root->right);    // get diameter & height for Right Subtree
    int opt1 = left.first;                              // diameter of left subtree
    int opt2 = right.first;                             // diameter of right subtree
    int opt3 = left.second + right.second + 1;          // diameter of combo =  maximum left & right height + 1 for root node
    pair<int,int> ans;
    ans.first = max(opt1, max(opt2, opt3));             // diameter of answer = maximum of left subtree diameter, right subtree diameter & combo diameter
    ans.second = max(left.second, right.second) + 1;    // height of answer = maximum of left & right subtree height + 1 for root
    return ans;
}
int diameter2(node*root){
    return diameterFast(root).first;
}


// Ques 3: Check for Balanced Tree
// Approach 1
bool isBalanced1(node*root){
    if(root==NULL){
        return true;
    }
    bool leftBalance = isBalanced1(root->left);
    bool rightBalance = isBalanced1(root->right);
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    bool diff = (leftHeight-rightHeight) <= 1;
    if(diff && leftBalance && rightBalance){
        return true;
    }
    return false;
}
// Approach 2
pair<bool,int> balanceFast(node*root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);  
        return p;
    }
    pair<bool,int> left = balanceFast(root->left);
    pair<bool,int> right = balanceFast(root->right);
    bool leftBalance = left.first;
    bool rightBalance = right.first;
    bool diff = abs(left.second-right.second) <= 1;
    pair<bool,int> ans;
    ans.second = max(left.second,right.second) + 1;
    if(leftBalance && rightBalance && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    return ans;
}
bool isBalanced2(node*root){
    return balanceFast(root).first;
}


// Ques 4: Determine if 2 trees are identical or not
bool isIdentical(node*r1, node*r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL)){
        return false;
    }
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool value = (r1->data == r2->data);
    if(left && right && value){
        return true;
    }
    return false;
}


// Ques 5: Sum Tree
pair<bool,int> sumTreeFast(node*root){
    if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
    pair<bool,int> leftAns = sumTreeFast(root->left);
    pair<bool,int> rightAns = sumTreeFast(root->right);
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    int leftSum = leftAns.second;
    int rightSum = rightAns.second;
    bool isNodeSum = root->data == (leftSum + rightSum);
    pair<bool,int> ans;
    if(isLeftSumTree && isRightSumTree && isNodeSum){
        ans.first = true;
        ans.second = root->data + leftSum + rightSum ;
    }
    else{
        ans.first = false;
    }
    return ans;
}
bool isSumTree(node*root){
    return sumTreeFast(root).first;
}



int main(){

/*
            1
          3   5
       7  11 17  
*/

    node*root=new node(1);
    root->left=new node(3);
    root->right=new node(5);
    root->left->left=new node(7);
    root->left->right=new node(11);
    root->right->left=new node(17);

    cout<<height(root)<<endl;        // 3
    cout<<diameter1(root)<<endl;     // 5
    cout<<diameter2(root)<<endl;     // 5

    cout<<isBalanced1(root)<<endl;   // 1
    cout<<isBalanced2(root)<<endl;   // 1

    node*root1=new node(1);
    root1->left=new node(3);
    root1->right=new node(5);
    root1->left->left=new node(7);
    root1->left->right=new node(11);
    root1->right->left=new node(17);

    cout<<isIdentical(root,root1)<<endl;    // 1


    node*root2=new node(3);
    root2->left=new node(2);
    root2->right=new node(1);
    cout<<isSumTree(root)<<endl;        // 0
    cout<<isSumTree(root2)<<endl;       // 1


    
    
    return 0;
}