#include<iostream>
#include<vector>
using namespace std;

/*
Check Palindrome in LL

1 - create array
  - push data of linked list in array
  - check palindrome for array
TC = O(n)
SC = O(n)

2 - find middle 
  - reverse list from middle->next
  - compare fist & second half
  - reverse again
TC = O(n)
SC = O(1)
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
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}

// APPROACH 1
bool isPalidrome1(node*head){
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return true;
    }
    vector<int>v;
    node*temp=head;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }
    int start=0;
    int end=v.size()-1;
    while(start<=end){
        if(v[start]==v[end]){
            start++;
            end--;
        }else{
            return false;
        }
    }
    return true;
}

// APPROACH 2 - Optimized
node*findMiddle(node*head){
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node*reverseLL(node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*prev=NULL;
    node*curr=head;
    node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool isPalidrome2(node*head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    node*middle=findMiddle(head);
    middle->next=reverseLL(middle->next);
    node*temp1=head;
    node*temp2=middle->next;
    while(temp2!=NULL){
        if(temp1->data!=temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    middle->next=reverseLL(middle->next);
    return true;
}

int main(){
    
    node*head=new node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    print(head);
    // cout<<isPalidrome1(head)<<endl;
    cout<<isPalidrome2(head)<<endl;
    

    return 0;
}