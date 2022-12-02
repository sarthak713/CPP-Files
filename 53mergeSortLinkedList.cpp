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

class Node{
public:
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtTail(Node*&head,int data){
    Node*n=new Node(data);
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
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
Node*findMid(Node*head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node*merge(Node*left,Node*right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node*ans=new Node(-1);
    Node*temp=ans;
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
Node* mergeSort(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*mid=findMid(head);
    Node*left=head;
    Node*right=mid->next;
    mid->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);
    Node*result = merge(left,right);
    return result;
}


int main(){
    Node*head=NULL;
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,10);
    insertAtTail(head,4);
    print(head);
    Node*newH=mergeSort(head);
    print(newH);

    return 0;
}