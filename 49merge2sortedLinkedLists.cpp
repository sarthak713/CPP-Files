#include<iostream>
using namespace std;

/*
Merge 2 Sorted Linked Lists
*/

class node{
public:
    int data;
    node*next;
    node(int val){
        data=val;
        next=NULL;
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
    if(head==NULL){
        cout<<"NULL"<<endl;
        return;
    }
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL";
    return;
}

node* solve(node*head1,node*head2){
    if(head1->next==NULL){
        head1->next=head2;
        return head1;
    }
    node*curr1=head1;
    node*next1=curr1->next;
    node*curr2=head2;
    node*next2=curr2->next;
    while(next1!=NULL && curr2!=NULL){
        if((curr2->data>=curr1->data) && (curr2->data<=next1->data)){
            next2=curr2->next;
            curr1->next=curr2;
            curr2->next=next1;
            curr1=curr2;
            curr2=next2;
        }else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return head1;
            }
        }
    }
    return head1;
}

node* merge2sortedLL(node*head1,node*head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<=head2->data){
        return solve(head1,head2);
    }else{
        return solve(head2,head1);
    }
}

int main(){

    node*head1=new node(1);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    node*head2=new node(2);
    insertAtTail(head2,3);
    insertAtTail(head2,5);
    insertAtTail(head2,6);
    
    node*head3=merge2sortedLL(head1,head2);
    print(head3);
    
    
    return 0;
}