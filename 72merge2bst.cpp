#include<iostream>
#include<vector>
using namespace std;

/*
Merge 2 BST     (CodeStudio)

Approach 1:
    - get vector Inorders of both BSTs
    - merge these 2 inorder vectors
    - apply inorder to BST function to that merged array
    - T.C. = O(m+n), S.C. = O(m+n)
Approach 2:
    - Space Optimized Approach
    - T.C. = O(m+n), S.C. = O(h1+h2)
    - Flatten both BST into Sorted Linked Lists
        - convert right subtree into LL using recursion (head of LL)
        - root->right=head
        - head->left=root
        - convert left subtree into LL using LL (head)
        - return
    - Merge these sorted Linked Lists
    - Convert sorted Linked List to BST
        - make left subtree with n/2 nodes
        - make curr node root, root->left = left subtree
        - head->next
        - make right subtree with n-n/2-1 nodes
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


// Approach 1: using inorder to BST, merge 2 sorted arrays, make inorder vector
void makeInorder(Node*root, vector<int> &v){
    if(root==NULL){
        return;
    }
    makeInorder(root->left,v);
    v.push_back(root->data);
    makeInorder(root->right,v);
}
vector<int> mergeInorders(vector<int>v1, vector<int>v2){
    vector<int>ans(v1.size()+v2.size());
    int i=0, j=0, k=0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            ans[k++] = v1[i];
            i++;
        }
        else{
            ans[k++] = v2[j];
            j++;
        }
    }
    while(i < v1.size()){
        ans[k++] = v1[i];
        i++;
    }
    while(j < v2.size()){
        ans[k++] = v2[j];
        j++;
    }
    return ans;
}
Node* inorderToBST(int s, int e, vector<int> inorder){
    if(s > e){
        return NULL;
    }
    int mid=(s+e)/2;
    Node* root=new Node(inorder[mid]);
    root->left=inorderToBST(s,mid-1,inorder);
    root->right=inorderToBST(mid+1,e,inorder);
    return root;
}
Node* mergeBST(Node*root1, Node*root2){
    vector<int>v1, v2;
    makeInorder(root1, v1);
    makeInorder(root2, v2);
    vector<int> merged = mergeInorders(v1,v2);
    return inorderToBST(0, merged.size()-1, merged);
}


// Approach 2
void convertIntoSortedDoublyList(Node*root, Node* &head){
    if(root==NULL){
        return;
    }
    convertIntoSortedDoublyList(root->right, head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertIntoSortedDoublyList(root->left, head);
}
Node* mergeDoublyLists(Node*head1, Node*head2){
    Node*head=NULL;
    Node*tail=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }
    return head;
}
int countNodes(Node*head){
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->right;
    }
    return count;
}
Node* sortedLLtoBST(Node* &head, int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    Node*left=sortedLLtoBST(head, n/2);
    Node*root=head;
    root->left=left;
    head=head->right;
    root->right=sortedLLtoBST(head,n-n/2-1);
    return root;
}
Node* mergeBST2(Node*root1, Node*root2){
    Node*head1=NULL;
    Node*head2=NULL;
    convertIntoSortedDoublyList(root1,head1);
    convertIntoSortedDoublyList(root2,head2);
    head1->left=NULL;
    head2->left=NULL;
    Node*head=mergeDoublyLists(head1,head2);
    return sortedLLtoBST(head,countNodes(head));
}





int main(){
    
    
    
    return 0;
}