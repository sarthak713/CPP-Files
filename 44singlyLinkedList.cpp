#include<iostream>
using namespace std;

/*
Linked List
- linear Data structure
- collection of nodes
    - Node = contains data & address of next node

Why ?
- Array size cannot be changed in runtime
- In vector, when size is increased, new storage is allocated & values are copied into it
These is not Optical
- So Linked List 
    - dynamic data structure
    - can grow & shrink it in runtime
    - no memory wastage
    Insertion & deletion is easy = No shift in element is needed

Singly Linked List looks like this:
    5|710 -> 8|810 -> 9|910 -> 11|NULL
 Data|Address

In array, memory is stored contiguously
But linked list is a non-contiguous data structure
    - Created in Hea Memory

TYPES:
1 Singly
2 Doubly
3 Circular
4 Circular Dounbly

*/

// Singly Linked List

class Node{
public:
    int data;
    Node* next;
    Node(int value){    // constructor
        this->data = value;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head,int data){    // pass by referece = we want to change at original address, not in copy
    Node* n = new Node(data);
    n->next=head;
    head=n;
}

void insertAtTail(Node* &head,int data){
    Node* n=new Node(data);
    if(head==NULL){
        head=n;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next; 
    }
    temp->next=n;
    return;
}

void insertInMiddle(Node*&head,int data,int position){
    Node*n=new Node(data);
    if(head==NULL){
        head=n;
        return;
    }
    if(position==1){
        insertAtHead(head,data);
        return;
    }
    Node*temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    n->next=temp->next;
    temp->next=n;
    return;
}

void deleteHead(Node*&head){
    Node*todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(Node*&head,int position){
    if(head->next==NULL || position==1){
        deleteHead(head);
        return;
    } 
    int count=1;
    Node*temp=head;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    Node*toDelete = temp->next;
    temp->next=temp->next->next;
    delete toDelete;
    return;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main(){
    
    Node* node1 = new Node(10);
    cout<<node1->data<<endl<<endl;

    print(node1);
    insertAtHead(node1,20);
    print(node1);
    cout<<endl;

    insertAtTail(node1,40);
    print(node1);
    cout<<endl;

    insertInMiddle(node1,70,3);
    print(node1);
    insertInMiddle(node1,100,1);
    print(node1);
    cout<<endl;

    print(node1);
    deletion(node1,1);
    print(node1);
    deletion(node1,4);
    print(node1);
    
    
    return 0;
}