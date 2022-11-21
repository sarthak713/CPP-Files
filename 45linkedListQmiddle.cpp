#include<iostream>
using namespace std;

// Find middle of Linked List

class node{
    public:
    int data;
    node*next;
    node(int val){
        data=val;
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

int lengthLL(node*head){
    node*temp=head;
    int l=0;
    if(head==NULL){
        return 0;
    }
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

int middleLL(node*head){
    if(head==NULL){
        return 0;
    }
    if(head->next==NULL){
        return head->data;
    }
    int length=lengthLL(head);
    int middleIndex=(length/2)+1;
    node*temp=head;
    int count=1;
    while(count!=middleIndex){
        temp=temp->next;
        count++;
    }
    return temp->data;
}
/*
Time Complexity = O(n)
*/

// Optimized Solution

int middleLLoptimized(node*head){
    if(head==NULL){
        return 0;
    }
    if(head->next==NULL){
        return head->data;
    }
    node*fast=head->next;
    node*slow=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow->data;
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
    cout<<middleLL(head)<<endl;
    cout<<middleLLoptimized(head);
    
    
    return 0;
}