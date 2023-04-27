#include<iostream>
using namespace std;

/*
Merge Sort In Linked List
- Split list into 2 halves using mid
- find mid using slow & fast pointers
- make new list (initialized by -1) and append nodes using logic
- return new list->next
T.C. = O(n log n)
S.C. = O(log n)
Question : Why prefer MergeSort in Linked List & Quick Sort in Arrays ?
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
node*findMid(node*head){
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node*merge(node*left,node*right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    node*ans=new node(-1);
    node*temp=ans;
    while(left!=NULL && right!=NULL){
        if(left->data<=right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    return ans->next;
}
node* mergeSort(node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*mid=findMid(head);
    node*left=head;
    node*right=mid->next;
    mid->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);
    node*result = merge(left,right);
    return result;
}


int main(){
    node*head=NULL;
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,10);
    insertAtTail(head,4);
    print(head);
    node*newH=mergeSort(head);
    print(newH);

    return 0;
}