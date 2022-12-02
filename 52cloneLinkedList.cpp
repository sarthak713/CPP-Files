#include<iostream>
#include<unordered_map>
using namespace std;

/*
Clone a Linked List with Next & Random Pointer 
- node contains: 
    int data 
    node*next pointer = points to next list node
    node*random pointer = points to a random list node
- make a clone of this list and return

Approach 1: (with map)
- Forget random pointer
- Loop through List with temp
- Make clone list using Original List's Next pointer
- copy Random pointers - check where they point in Original List & copy to List
- We have to use 2 loops to do this
T.C. = O(n^2)
S.C. = O(1)

Approach 2: (with Map)
- create Clone list using Next Pointers of original list
- Save mapping of Old Nodes from original list with Clone Nodes of new list, using MapDS
- Utilize mapping to set Random Pointers of Clone Nodes
- CloneNode->Random = Mapping[OriginalNode->Random] 
T.C. = O(n)
S.C. = O(n)

Approach 3: (with pointers)
- create Clone list using Next Pointers of original list
- add clone nodes in between nodes of original list
Original: 1 2 3 4 5 NULL
          |/|/|/|/|/
Clone:    1 2 3 4 5 
- copy random pointers in clone list
- make a temp node starting from original list head
- So, temp->next is clone node & we want to set its random
- Therefore: temp->next->random=temp->random
- revert changes done in step2 & 3
T.C. = O(n)
S.C. = O(1)
*/

class node{
public:
    int data;
    node*next;
    node*random;
    node(int val){
        data=val;
        next=NULL;
        random=NULL;
    }
};
void insertAtTail(node*&head,int val){
    node*n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return;
}
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
node*cloneList1(node*head){
    node*cloneHead=NULL;
    node*temp=head; 
    while(temp!=NULL){
        insertAtTail(cloneHead,temp->data);     // copy data from Original to Clone List
        temp=temp->next;
    }
    unordered_map<node*,node*>mapping;          // Create Map to map Original to Clone Nodes
    node*origNode=head;
    node*clonNode=cloneHead;
    while(origNode!=NULL){
        mapping[origNode]=clonNode;
        origNode=origNode->next;
        clonNode=clonNode->next;
    }
    origNode=head;
    clonNode=cloneHead;
    while(origNode!=NULL){                      // clone random nodes
        clonNode->random=mapping[origNode->random];
        origNode=origNode->next;
        clonNode=clonNode->next;
    }
    return cloneHead;
}

node*cloneList2(node*head){
    node*cloneHead=NULL;
    node*temp=head;
    while(temp!=NULL){
        insertAtTail(cloneHead,temp->data);
        temp=temp->next;
    }
    node*origNode=head;
    node*clonNode=cloneHead; 
    while(origNode!=NULL && clonNode!=NULL){
        node*next=origNode->next;
        origNode->next=clonNode;
        origNode=next;
        next=clonNode->next;
        clonNode->next=origNode;
        clonNode=next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            temp->next->random=temp->random?temp->random->next:temp->random;
        }
        temp=temp->next->next;
    }
    origNode=head;
    clonNode=cloneHead;
    while(origNode!=NULL && clonNode!=NULL){
        origNode->next=clonNode->next;
        origNode=origNode->next;
        if(origNode!=NULL){
            clonNode->next=origNode->next;
        }
        clonNode=clonNode->next;
    }
    return cloneHead;
}

int main(){
    
    node*head=new node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    print(head);
    // node*newH=cloneList1(head);
    // print(newH);
    node*newH=cloneList2(head);
    print(newH);

    
    
    return 0;
}