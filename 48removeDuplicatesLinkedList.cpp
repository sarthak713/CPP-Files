#include<iostream>
using namespace std;

/*
Q1. Remove Duplicated from Sorted LL
Q2. Remove Duplicated from UnSorted LL
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
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

node*removeDupSortedLL(node*head){
    if(head==NULL){
        return head;
    }
    node*curr=head;
    while(curr->next!=NULL){
        if(curr->data!=curr->next->data){
            curr=curr->next;
        }
        else{
            node*temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
    }
    return head;
}
/*
Time Complexity = O(n)
Space Complexity = O(1)
*/

node*removeDupUnSortedLL(node*head){
    if(head==NULL){
        return head;
    }
    node*curr=head;
    while(curr!=NULL && curr->next!=NULL){
        node*temp=curr;
        while(temp->next!=NULL){
            if(temp->next->data!=curr->data){
                temp=temp->next;
            }
            else{
                node*toDel=temp->next;
                temp->next=temp->next->next;
                delete toDel;
            }
        }
        curr=curr->next;
    }
    return head;
}
/*
Time Complexity = O(n^2)
Space Complexity = O(1)
*/

// First Sort Linked List & then remove Duplicates using RemoveDupFromSortedLL
/*
Time Complexity = O(n log n)
Space Complexity = O(1)
*/

// Using Map
/*
Time Complexity = O(n)
Space Complexity = O(n)
*/


int main(){

    node*head=new node(1);
    insertAtTail(head,1);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,4);
    insertAtTail(head,4);
    print(head);
    node*newHead=removeDupSortedLL(head);
    print(newHead);
    cout<<endl;
    
    node*h=new node(1);
    insertAtTail(h,3);
    insertAtTail(h,1);
    insertAtTail(h,3);
    insertAtTail(h,2);
    insertAtTail(h,1);
    insertAtTail(h,5);
    insertAtTail(h,4);
    insertAtTail(h,4);
    insertAtTail(h,6);
    insertAtTail(h,5);
    insertAtTail(h,2);
    insertAtTail(h,3);
    insertAtTail(h,3);
    print(h);
    node*newH=removeDupUnSortedLL(h);
    print(newH);

    
    
    return 0;
}