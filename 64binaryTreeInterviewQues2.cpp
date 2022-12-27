#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<map>
using namespace std;
/*
Binary Tree Interview Ques Part 2

1. Zig-Zag Traversal                (GFG)
    - print nodes in order = left to right, right to left, so on
    Approach:
    - use queue & a bool leftToRight
    - queue stores all nodes of single level
    - leftToRight is true or false based on direction in which we will print
    - nodes are popped and pushed in answer vector
    T.C. = O(n), S.C. = O(n)        

2. Boundary Traversal               (GFG)
    - print left part except leaf node
    - print all leaf nodes (left->right)
    - print right part except leaf & root nodes (bottom->top) 

3. Vertical Traversal               (GFG)
    Approach:
        - imagine a number line, root is in middle at 0
        - nodes to left of root, are at -1 -2 -3, etc
        - nodes to right of root, are at +1 +2 +3, etc 
        - now we know horizontal distance of nodes from root
    - we find nodes from smallest level to greatest ex: -3 to 3, and print them in this order only
    - create (Mapping of Horizontal Distance -> level wise nodes (mapping of level -> nodes (vector<node*> ) ) )
    map<int, map<int, vector<int>>> nodes
   (distance   level   nodes-for-each-level)
        - if we want to store values in this map, we need = horizontal distance hd & level
        - so when we will traverse, we need a queue to store: nodes, hd, level
        - so we make queue(pair of node, (pair of hd, level))
        queue<pair<node*, pair<int, int>>>

4. Top View                         (GFG)
    - similar to vertical traversal
    - but for each horizontal distance, only one node will be stored (to hide nodes beneath above node of same hd)
    map<int, int> mapping
        hd  nodeData 
    - mapping will be one to one, only one Node for one Horizontal Distance

5. Bottom View                      (GFG)
    - traverse level by level as before, and take nodes wrt horizontal distance
    - remove conditions from top view question and done
    - as we traverse level by level, horizontal distance values are updated to the final end nodes and we get the ans
    - where as before we were only assigning values once, here they are updated till the end level

6. Left View                        (GFG)
    - only first node of each Level is required
    - track level, and use it to store each node value
    
7. Right View                       (GFG)

8. Diagonal View                    (GFG)
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


// Ques 1: Zig Zag Traversal
vector<int> zigZagTraversal(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    queue<node*>q;
    q.push(root);   
    bool leftToRight=true;
    while(!q.empty()){      
        int size=q.size();
        vector<int>temp(size);          // made to insert elements in normal or reverse order
        for(int i=0;i<size;i++){        // process each level
            node*front=q.front();
            q.pop();
            int index = leftToRight ? i : size-i-1;     // normal or reverse insert     
            temp[index] = front->data;
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        leftToRight=!leftToRight;       // change direction after each level
        for(auto i: temp){
            ans.push_back(i);
        }
    }
    return ans;
}


// Ques 2: Boundary Traversal
void traverseLeft(node*root,vector<int>&ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}
void traverseLeaf(node*root,vector<int>&ans){
    if(root==NULL){
        return;
    } 
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}
void traverseRight(node*root,vector<int>&ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}
vector<int>boundary(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);          // 1 store root data
    traverseLeft(root->left,ans);       // 2 traverse left outer subtree
    traverseLeaf(root->left,ans);       // 3 traverse leaf nodes of left subtree
    traverseLeaf(root->right,ans);      //   traverse leaf nodes of right subtree
    traverseRight(root->right,ans);     // 4 traverse right outer subtree
    return ans;
}


// Ques 3: Vertical Traversal 
vector<int>vertical(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }

    map<int, map<int, vector<int> > > nodes;        // map(hd,map(level,nodes))
    queue<pair<node*, pair<int,int> > > q;          // queue(pair(nodes,pair(hd,level)))
    // initial push in queue, node=root,hd=0,level=0
    q.push(make_pair(root, make_pair(0,0)));        // pushing pair of (root, pair(hd,level)), or root hd=0 & level=0
    // iterate queue
    while(!q.empty()){
    // getting values from queue
        pair<node*, pair<int,int> > temp = q.front();
        q.pop();
        node*front = temp.first;                    // in above pair, first = node & second = pair of (hd & level)
        int hd = temp.second.first;                 // horizontal distance = first of second in pair
        int level = temp.second.second;             // level = second of second in pair
    // make entry of current node in map of nodes
        nodes[hd][level].push_back(front->data);
    // traverse to left & right subtrees
        if(front->left){
            q.push(make_pair(front->left,make_pair(hd-1,level+1)));     // to the left, hd-- as on number line & level++ while going down
        }
        if(front->right){
            q.push(make_pair(front->right,make_pair(hd+1,level+1)));    // to the right, hd++ as on number line & level++
        }
    }
    // getting answer vector 
    for(auto i:nodes){                  // for map<int hd, map<int level, vector<int> >
        for(auto j:i.second){           // for <int level, vector<int> >
            for(auto k:j.second){       // for vector<int>
                ans.push_back(k);
            }
        }
    }
    return ans;
}


// Ques 4: Top View
vector<int> topView(node *root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }

    map<int,int>mapping;            // map(horizontal distance hd, node data)
    queue<pair<node*,int> > q;      // queue(pair(node, hd))
    q.push(make_pair(root,0));      // initial push, root & hd=0
    while(!q.empty()){
        pair<node*,int> temp = q.front();   // get values
        q.pop();
        node*front = temp.first;
        int hd = temp.second;
        // find entry corresponding to hd in mapping, if no entry is found -> then iterator iterates to end of map, in that case fill the entry with data
        // if mapping is found, nothing is done 
        if(mapping.find(hd)==mapping.end()){
            mapping[hd]=front->data;
        }
        if(front->left){
            q.push(make_pair(front->left,hd-1));
        }
        if(front->right){
            q.push(make_pair(front->right,hd+1));
        }
    }
    for(auto i:mapping){
        ans.push_back(i.second);            // in map, second value is node
    }
    return ans;
}


// Ques 5: Bottom View
vector<int> bottomView(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>mapping;
    queue<pair<node*,int> >q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int>temp=q.front();
        q.pop();
        node*front=temp.first;
        int hd=temp.second;
        mapping[hd]=front->data;    // mapping value is updated to end nodes as loop goes on
        if(front->left){
            q.push(make_pair(front->left,hd-1));
        }
        if(front->right){
            q.push(make_pair(front->right,hd+1));
        }
    }
    for(auto i:mapping){
        ans.push_back(i.second);
    }
    return ans;
}


// Ques 6: Left View
void solveLeftView(node*root,vector<int>&ans,int level){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){      // new level is reached
        ans.push_back(root->data);
    }
    solveLeftView(root->left,ans,level+1);
    solveLeftView(root->right,ans,level+1);
}
vector<int> leftView(node*root){
    vector<int>ans;
    solveLeftView(root,ans,0);  // level 0 initially
    return ans;
}


// Ques 7: Right View
void solveRightView(node*root,vector<int>&ans,int level){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){      // new level is reached
        ans.push_back(root->data);
    }
    solveRightView(root->right,ans,level+1);
    solveRightView(root->left,ans,level+1);
}
vector<int> rightView(node*root){
    vector<int>ans;
    solveRightView(root,ans,0);
    return ans;
}


// Ques 8: Diagonal View
vector<int>diagonalView(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        while(temp){
            if(temp->left){
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
    return ans;
}


int main(){
/*
                1
             2     4     
          3     5     6
                   7     8
*/
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(4);
    root->left->left=new node(3);
    root->left->right=new node(5);
    root->right->right=new node(6);
    root->right->right->left=new node(7);
    root->right->right->right=new node(8);

// Zig Zag Traversal = 1 4 2 3 5 6 8 7 
// Boundary Traversal = 1 2 3 5 7 8 6 4
// Vertical Traversal = 3 2 1 5 4 7 6 8
// Top View = 3 2 1 4 6 8
// Bottom View = 3 2 5 7 6 8
// Left View = 1 2 3 7
// Right View = 1 4 6 8

    cout<<"Zig Zag: ";
    vector<int>zigzag=zigZagTraversal(root);
    for(int i=0;i<zigzag.size();i++){
        cout<<zigzag[i]<<" ";
    }cout<<endl;

    cout<<"Boundary: ";
    vector<int>bound=boundary(root);
    for(int i=0;i<bound.size();i++){
        cout<<bound[i]<<" ";
    }cout<<endl;

    cout<<"Vertical: ";
    vector<int>verticalTraverse=vertical(root);
    for(int i=0;i<verticalTraverse.size();i++){
        cout<<verticalTraverse[i]<<" ";
    }cout<<endl;

    cout<<"Top: ";
    vector<int>topViewTraverse=topView(root);
    for(int i=0;i<topViewTraverse.size();i++){
        cout<<topViewTraverse[i]<<" ";
    }cout<<endl;

    cout<<"Bottom: ";
    vector<int>bottomViewTraverse=bottomView(root);
    for(int i=0;i<bottomViewTraverse.size();i++){
        cout<<bottomViewTraverse[i]<<" ";
    }cout<<endl;

    cout<<"Left: ";
    vector<int>leftViewTraverse=leftView(root);
    for(int i=0;i<leftViewTraverse.size();i++){
        cout<<leftViewTraverse[i]<<" ";
    }cout<<endl;

    cout<<"Right: ";
    vector<int>rightViewTraverse=rightView(root);
    for(int i=0;i<rightViewTraverse.size();i++){
        cout<<rightViewTraverse[i]<<" ";
    }cout<<endl;



    
    
    return 0;
}