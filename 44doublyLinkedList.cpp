#include<iostream>
using namespace std;
/*
Doubly Linked List

Node contains: 
previous pointer|data node|next pointer

*/

class node{
public:
    int data;
    node*prev;
    node*next;
    node(int value){
        data=value;
        prev=NULL;
        next=NULL;
    }
};

int lengthLL(node*head){
    node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

void insertAtHead(node*&head,int data){
    node*n=new node(data);
    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head->prev=n;
    head=n;
    return;
}

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
    n->prev=temp;
    return;
}

void insertAtPosition(node*&head,int data,int position){
    node*n=new node(data);
    if(head==NULL){
        head=n;
        return;
    }
    if(position==1){
        insertAtHead(head,data);
        return;
    }
    int count=1;
    node*temp=head;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    n->next=temp->next;
    temp->next->prev=n;
    temp->next=n;
    n->prev=temp;
    return;
}
void deleteHead(node*&head){   
    node*temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    delete temp;
}
void deleteTail(node*&head){
    node*temp=head;
    int count=1;
    while(count<lengthLL(head)-1){
        temp=temp->next;
        count++;
    }
    node*toDel=temp->next;
    temp->next->prev=NULL;
    temp->next->next=NULL;
    temp->next=NULL;
    delete toDel;
}
void deleteNode(node*&head,int position){
    if(position==1){
        deleteHead(head);
        return;
    }
    if(position==lengthLL(head)){
        deleteTail(head);
        return;
    }
    node*temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    node*todelete=temp->next;
    temp->next=temp->next->next;
    temp->next->next->prev=temp;
    todelete->next=NULL;
    todelete->prev=NULL;
    delete todelete;
    return;
}

int main(){
    
    node* head=new node(10);
    print(head);
    cout<<lengthLL(head)<<endl<<endl;

    insertAtHead(head,5);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    cout<<endl;

    insertAtTail(head,7);
    insertAtTail(head,9);
    print(head);
    cout<<endl;

    print(head);
    insertAtPosition(head,8,3);
    print(head);
    insertAtPosition(head,8,1);
    print(head);
    cout<<endl;

    print(head);
    deleteNode(head,1);
    print(head);
    deleteNode(head,3);
    print(head);
    cout<<endl;

    print(head);
    deleteNode(head,6);
    print(head);
    deleteNode(head,5);
    print(head);
    
    return 0;
}