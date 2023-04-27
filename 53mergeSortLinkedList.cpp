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

<<<<<<< HEAD
class Node{
public:
    int data;
    Node*next;
    Node(int val){
=======
class node{
public:
    int data;
    node*next;
    node(int val){
>>>>>>> coding
        data=val;
        next=NULL;
    }
};
<<<<<<< HEAD
void insertAtTail(Node*&head,int data){
    Node*n=new Node(data);
=======
void insertAtTail(node*&head,int data){
    node*n=new node(data);
>>>>>>> coding
    if(head==NULL){
        head=n;
        return;
    }
<<<<<<< HEAD
    Node*temp=head;
=======
    node*temp=head;
>>>>>>> coding
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return;
}
<<<<<<< HEAD
void print(Node*head){
    Node*temp=head;
=======
void print(node*head){
    node*temp=head;
>>>>>>> coding
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
<<<<<<< HEAD
Node*findMid(Node*head){
    Node*slow=head;
    Node*fast=head->next;
=======
node*findMid(node*head){
    node*slow=head;
    node*fast=head->next;
>>>>>>> coding
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
<<<<<<< HEAD
Node*merge(Node*left,Node*right){
=======
node*merge(node*left,node*right){
>>>>>>> coding
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
<<<<<<< HEAD
    Node*ans=new Node(-1);
    Node*temp=ans;
=======
    node*ans=new node(-1);
    node*temp=ans;
>>>>>>> coding
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
<<<<<<< HEAD
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
=======
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
>>>>>>> coding
    return result;
}


int main(){
<<<<<<< HEAD
    Node*head=NULL;
=======
    node*head=NULL;
>>>>>>> coding
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,10);
    insertAtTail(head,4);
    print(head);
<<<<<<< HEAD
    Node*newH=mergeSort(head);
=======
    node*newH=mergeSort(head);
>>>>>>> coding
    print(newH);

    return 0;
}