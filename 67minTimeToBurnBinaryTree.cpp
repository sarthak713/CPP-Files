#include<iostream>
#include<map>
#include<queue>
using namespace std;

/*
Minimum Time to burn the Entire Binary Tree     (GFG)

Approach:
- For each node, we want 3 nodes to burn
    - left, right & parent = which does not exist so we use map
1. Make a mapping nodeToParent <Node*,Node*>
2. Find Target Node
- start burning tree 
- variable time=0 initially
3. We want 2 dataStructure:
    - map of visited nodes <Node*,bool>
    - queue, to store node,right,parent,left
        - if we push anything in queue, time has to be incremented
        - if not, do nothing 
    - only push into queue if not visited

T.C. = O(n)
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

// create parent to node mapping, return target node
Node* createMapping(Node* root, int target, map<Node*,Node*> &nodeToParent){
    Node* result = NULL;                // to return as target in the end
    queue<Node*> q;                     // For Level Order Traversal, to create mapping
    q.push(root);
    nodeToParent[root] = NULL;          // set root's parent as NULL
    while(!q.empty()){
        Node*front = q.front();
        q.pop();
        if(front->data == target){
            result = front;
        }
        if(front->left){
            nodeToParent[front->left] = front;      // store in mapping, parent of front->left is front
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return result;
}

void burnTree(Node*root, map<Node*,Node*> nodeToParent, int &ans){
    map<Node*,bool> visited;            // map to mark visited nodes
    queue<Node*> q;                     // queue to push & burn nodes

    q.push(root);                       // push root in queue
    visited[root] = true;               // root is visited 

    while(!q.empty()){

        bool flag = 0;                  // to check queue addition or not, to increment time
        int size=q.size();              // to process for each node: left, right, parent
        
        for(int i=0;i<size;i++){
            Node* front = q.front();                        // store front
            q.pop();
            if(front->left && !visited[front->left]){       // only push if: Not NULL, not visited
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if(front->right && !visited[front->right]){  
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            // now visit parent: get parent from nodeToParent mapping for front, & check if not visited already
            if(nodeToParent[front] && !visited[nodeToParent[front]]){ 
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }

        if(flag == 1){
            ans++;
        }
    }
}

int minTime(Node*root,int target){
    int ans=0;
    map<Node*,Node*> nodeToParent;
    Node* targetNode = createMapping(root, target, nodeToParent);
    burnTree(targetNode, nodeToParent, ans);
    return ans;
}

int main(){
    
    
    
    return 0;
}