#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
Heaps Interview Questions

Ques 1 = Kth smallest element               (GFG - Practice)
    Approach 1 (Brute):
        - sort input array
        - return ans, which is at (k-1) index
        - T.C. = O(n log n)
    Approach 2 (Use Heap):
        - create max-heap for 1st k elements, 0 to k-1 index
        - for remaining elements, k to n-1 index
            - if element < heap.top
                - heap.pop
                - heap.push(element)
        - After this operation,
            - heap contains k small elements
            - As it is max-heap, top element is maximum
            - So, answer = heap.top
        - T.C. = O(n log k), S.C. = O(k)
    - To find kth smallest element, we use max-heap
    - To find kth largest element, we use min-heap

Ques 2 = Is Binary Tree Heap                (GFG - Practice)
    - heap is a complete Binary Tree having Heap order property
    - these are properties we have to check in binary tree
    Approach:
        - check CBT & MaxHeap property
        - isCBT(Node*root, current node index, nodes count)
        - In 0-based indexing, for a node at i: leftChild is 2*i+1, rightChild is 2*i+2
        For CBT:    
            - if root null, return true
            - if index > nodeCount, return false
            - else check for left & right child
            - if both true, then CBT
        For MaxHeap Property:
            - Now we know, tree is CBT
            - Now 3 types of cases arise for a node
                - if Leaf Node
                    - return true (as leaf is heap in itself)
                - if both child 
                    - return root->data > root->left->data && root->right->data
                    - recursive call for left & right child
                - if only left child
                    - return root->data > root->left->data
        - T.C. = O(n), S.C. = O(n)

Ques 3 = Merge 2 Binary Max Heaps           (GFG - Practice)
    - we have 2 heaps as vector in input
    - merge these vectors in one
    - heapify merged vector
    - T.C. = O(m+n)

Ques 4 = Minimum cost of ropes              (GFG - Practice)
    - given n ropes of diff lengths
    - connect these ropes into one
    - cost to connect 2 ropes = sum of lengths
    Input: {4,3,2,6}
        - connect 3 & 2: {4,5,6}, cost=5
        - connect 4 & 5: {9,6}, cost=9
        - connect 9 & 6: {15}, cost=15
        - Total cost = 5+9+15 = 29
    - Each time, take 2 minimum length ropes 
    - connect these 2 minimum ropes
    - Repeat until size of array > 1
    - We use MinHeap, which provids min element in O(1)
    Approach:
        - while(size > 1)
        - a=pq.top(), pq.pop()
        - b=pq.top(), pq.pop()
        - sum=a+b
        - ans+=sum
        - pq.push(sum)
        - return ans
    - T.C. = O(n log n), S.C. = O(n)

Ques 5 = Convert BST to MinHeap             (GFG - Practice)
    - Tree is already a CBT
    - No structure change is required to convert into Heap
    - We should satisfy MinOrderProperty & left subtree < right subtree
    Approach:
        - Get inorder of BST
        - From above observations: Root < Left < Right
*/


// Ques 1: Kth smallest element
int kthSmallest(int arr[],int l,int r,int k){
    priority_queue<int>pq;                      // max-heap
    for(int i=0;i<k;i++){                       // Step 1: push first k elements
        pq.push(arr[i]);
    }
    for(int i=k;i<=r;i++){                      // for the remaining elements
        if(arr[i]<pq.top()){                    // if element is smaller that top
            pq.pop();                           // pop 
            pq.push(arr[i]);                    // push element
        }
    }
    return pq.top();                            // return top
}


// Ques 2: Is Binary Tree Heap
class Node{
public:
    int data;
    Node*left,*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int countNodes(Node*root){
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}
bool isCBT(Node*root,int index,int nodeCount){
    if(root==NULL){
        return true;
    }
    if(index>=nodeCount){
        return false;
    }
    else{
        bool left=isCBT(root->left,2*index+1,nodeCount);
        bool right=isCBT(root->right,2*index+2,nodeCount);
        return left && right;
    }
}
bool isMaxHeap(Node*root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){
        return (root->data > root->left->data);
    }
    if(root->left!=NULL && root->right!=NULL){
        bool left=isMaxHeap(root->left);
        bool right=isMaxHeap(root->right);
        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}
bool isHeap(Node*root){
    int index=0;
    int nodeCount=countNodes(root);
    if(isCBT(root,index,nodeCount) && isMaxHeap(root)){
        return true;
    }
    return false;
}


// Ques 3: Merge 2 Binary Max Heaps (0-based indexing)
void maxHeapify(vector<int>arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
}
vector<int>mergeHeaps(vector<int>&a,vector<int>&b,int n,int m){
    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(a[i]);
    }
    for(int i=0;i<m;i++){
        ans.push_back(b[i]);
    }
    int size=ans.size();
    for(int i=size/2-1;i>=0;i--){
        maxHeapify(ans,size,i);
    }
    return ans;
}


// Ques 4: Minimum cost of ropes
long long minCost(long long arr[],long long n){
    priority_queue<long long,vector<long long>,greater<long long> >pq;
    for(long long i=0;i<n;i++){
        pq.push(arr[i]);
    }
    long long ans=0;
    while(pq.size() > 1){
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();
        long long sum=a+b;
        ans+=sum;
        pq.push(sum);
    }
    return ans;
}


int main(){
    
    
    
    return 0;
}