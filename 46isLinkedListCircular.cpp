#include<iostream>
using namespace std;
/*
Check if Linked List is Circular Or not
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

void print(node*head){
    if(head==NULL){
        cout<<"NULL"<<endl;
        return;
    }
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
    return;
}

bool isCircular(node*head){
    if(head==NULL){
        return 1;
    }
    if(head->next==NULL){
        return 0;
    }
    if(head->next==head){
        return 1;
    }
    node*temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==NULL){
        return 0;
    }
    return 1;
}
/*
Time Complexity = O(n)
Space Complexity = O(1)
*/


int main(){
    
    node*head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    print(head);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    cout<<isCircular(head)<<endl;
    
    return 0;
}