#include<iostream>
using namespace std;

/*
Circular Linked List
= Last node points to 1st Node not NULL
= Head is not needed, Tail is used
= We use data to input & delete nodes
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

void insertNode(node*&tail,int ele,int data){
    node*n=new node(data);
    if(tail==NULL){
        tail=n;
        n->next=n;
        return;
    }
    node*temp=tail;
    while(temp->data!=ele){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
    return;
}
void print(node*tail){
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    cout<<tail->data<<" ";
    node*temp=tail->next;
    while(temp->data!=tail->data){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
void deleteNode(node*&tail,int ele){
    if(tail==NULL){
        return;
    }
    if(tail->next==tail){
        tail=NULL;
        return;
    }
    node*temp=tail;
    while(temp->next->data!=ele){
        temp=temp->next;
    }
    node*toDel=temp->next;
    temp->next=temp->next->next;
    if(tail==toDel){
        tail=tail->next;
    }
    toDel->next=NULL;
    delete toDel;
    return;
}

int main(){

    node* tail=NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,4);
    print(tail);
    // insertNode(tail,4,5);
    // print(tail);
    // insertNode(tail,4,6);
    // print(tail);
    // insertNode(tail,5,7);
    // print(tail);
    // insertNode(tail,3,2);
    // print(tail);
    // deleteNode(tail,6);
    // print(tail);
    // deleteNode(tail,3);
    // print(tail);
    // cout<<tail->data;
    deleteNode(tail,4);
    print(tail);
    return 0;
}