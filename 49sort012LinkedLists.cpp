#include<iostream>
using namespace std;

/*
Sort 0,1,2 in Linked List

Approaches:
1. Count 0, 1, 2
   - Change data similar to count of numbers
   - using while loop 
2. Data replacement Not allowed
   - make 3 linked lists: for 0,1,2
   - initialize these lists with a dummy node
   - merge these lists
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
    }cout<<"NULL"<<endl;
    return;
}

// APPROACH 1
void sortLL1(node*&head){
    if(head==NULL){
        return;
    }
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    node*temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            count0++;
        }else if(temp->data==1){
            count1++;
        }else{
            count2++;
        }
        temp=temp->next;
    }
    temp=head;
    int move=1;
    while(move<=count0){
        temp->data=0;
        temp=temp->next;
        move++;
    }
    move=1;
    while(move<=count1){
        temp->data=1;
        temp=temp->next;
        move++;
    }
    move=1;
    while(move<=count2){
        temp->data=2;
        temp=temp->next;
        move++;
    }
    return;
}
/*
TC = O(n)
SC = O(1)
*/

// APPROACH 2
node* sortLL2(node*head){
    node*zerHead = new node(-1);
    node*zerTail = zerHead;
    node*oneHead = new node(-1);
    node*oneTail = oneHead;
    node*twoHead = new node(-1);
    node*twoTail = twoHead;
    node*temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zerTail->next=temp;
            zerTail=temp;
        }
        else if(temp->data==1){
            oneTail->next=temp;
            oneTail=temp;
        }
        else{
            twoTail->next=temp;
            twoTail=temp;
        }
        temp=temp->next;
    }
    if(oneHead->next!=NULL){
        zerTail->next=oneHead->next;
    }else{
        zerTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;
    head=zerHead->next;
    delete zerHead;
    delete oneHead;
    delete twoHead;
    return head;
}
/*
TC = O(n)
SC = O(1)
*/

int main(){

    node*head=new node(1);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,0);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,0);
    print(head);

    // sortLL1(head);
    // print(head);

    node*newH = sortLL2(head);
    print(newH);
    
    
    return 0;
}