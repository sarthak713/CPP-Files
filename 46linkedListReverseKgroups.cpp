#include<iostream>
using namespace std;
/*
Reverse K gorups in Linked List
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
node* reverseKgroups(node*head,int k){
    if(head==NULL){
        return NULL;
    }
    int count=1;                                // Revese First K Node
    node*prev=NULL;
    node*curr=head;
    node*forward=NULL;
    while(curr!=NULL && count<=k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL){                          // Make call for remaining Linked List
        head->next=reverseKgroups(forward,k);   
    }       
    return prev;                                // return head of reversed list
}
/*
Time Complexity = O(n)
Space Complexity = O(n)
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

    int k=2;
    node*newhead=reverseKgroups(head,k);
    print(newhead);
    


    return 0;
}