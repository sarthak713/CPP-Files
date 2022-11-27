#include<iostream>
using namespace std;

/*
Add 2 numbers represented by Linked List
OR
Add 1 to a number represented by Linked List

Input =list1     3->4->NULL 4 3
       list2  2->3->0->NULL 0 3 2
Output=list3  2->6->4->NULL

Approach:
- Reverse Linked list
- Add corresponding list data
    - at first carry=0, so first sum=carry+firstData+secondData
    - Take this sum, keep last digit & update carry with first digit of sum
- Reverse answer List
- return head
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
node*reverse(node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*curr=head;
    node*prev=NULL;
    node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

node*add1(node*first,node*second){
    int carry=0;
    node*ans=NULL;
    while(first!=NULL && second!=NULL){
        int sum=(first->data)+(second->data)+carry;
        insertAtTail(ans,sum%10);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
        int sum=(first->data)+carry;
        insertAtTail(ans,sum%10);
        carry=sum/10;
        first=first->next;
    }
    while(second!=NULL){
        int sum=(second->data)+carry;
        insertAtTail(ans,sum%10);
        carry=sum/10;
        second=second->next;
    }
    if(carry!=0){
        insertAtTail(ans,carry);
    }
    return ans;
}

node*add2(node*first,node*second){
    int carry=0;
    node*ans=NULL;
    while(first!=NULL || second!=NULL || carry!=0){
        int val1=0;
        if(first!=NULL){
            val1=first->data;
        }
        int val2=0;
        if(second!=NULL){
            val2=second->data;
        }
        int sum=val1+val2+carry;
        insertAtTail(ans,sum%10);
        carry=sum/10;
        if(first!=NULL){
            first=first->next;
        }
        if(second!=NULL){
            second=second->next;
        }
    }
    return ans;
}
node*addTwoLists(node*first,node*second){
    if(first==NULL){
        return second;
    }
    if(second==NULL){
        return first;
    }
    first=reverse(first);
    second=reverse(second);
    node*ans=add2(first,second);
    return reverse(ans);
}   
/*
TC = O(m+n)
SC = O(max(m,n))
*/

int main(){
    
    node*h1=new node(1);
    insertAtTail(h1,0);
    node*h2=new node(9);
    insertAtTail(h2,0);
    insertAtTail(h2,0);
    node*h3=addTwoLists(h1,h2);
    print(h3);
    
    return 0;
}