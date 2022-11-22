#include<iostream>
using namespace std;
/*
1. Reverse a Linked List
*/
class node{
public:
    int data;
    node*next;
    node(int value){
        data=value;
        next=NULL;
    }
};

void insertAtTail(node*&head,int data){
    node*n=new node(data);
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

void insertAtHead(node*&head,int data){
    node*n=new node(data);
    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head=n;
    return;
}

void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

node* reverseIterative(node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*prev=NULL;
    node*curr=head;
    node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
/* Reverse Iterative
Time Complexity = O(n), n=no. of nodes in linked list
Space Complexity = O(1)
*/
void reverse(node*&head,node*prev,node*curr){
    if(curr==NULL){
        head=prev;
        return;
    }
    node*forward=curr->next;
    reverse(head,curr,forward);
    curr->next=prev;
}
node* reverseRecursive1(node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*prev=NULL;
    node*curr=head;
    reverse(head,prev,curr);
    return head;
}
/* Reverse Recursive
Time Complexity = O(n)
Space Complexity = O(n)
*/
node* reverseRecursive2(node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*newHead=reverseRecursive2(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}


int main(){
    
    node*head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    print(head);
    
    node* newHead=reverseIterative(head);
    print(newHead);

    cout<<endl;

    node*h=NULL;
    insertAtHead(h,10);
    insertAtHead(h,9);
    insertAtHead(h,8);
    insertAtHead(h,7);
    insertAtHead(h,6);
    print(h);

    node*newL=reverseRecursive1(h);
    print(newL);

    cout<<endl;

    node*l=NULL;
    insertAtTail(l,1);
    insertAtTail(l,2);
    insertAtTail(l,3);
    insertAtTail(l,4);
    insertAtTail(l,5);
    print(l);
    node*newH=reverseRecursive2(l);
    print(newH);

    cout<<endl;


    return 0;
}