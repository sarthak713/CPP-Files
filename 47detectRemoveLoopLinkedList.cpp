#include<iostream>
#include<map>
using namespace std;
/*
Detect & Remove Loop in Linked List
Q1. Detect cycle in LL
Q2. Return start node of loop in LL
Q3. Remove cycle from LL

Detect Cycle: 
1. Using Map
    - use map data-structure
    - store address, and true if visited
    - if we come accross a node, for which visited is true
    - it means cycle is Present
    - T.C.=O(n), S.C.=O(n)
2. Floyd's Cycle Detection Algo
    - take 2 pointers: slow & fast
    - initially both are at Head
    - slow=takes 1 step, fast=takes 2 steps
    - if fast==slow, cycle is present
    - else not present
    - T.C.=O(n), S.C.=O(1)

Return Start of Loop:
    - using Floyd's cycle detection
    - find the first intersection of fast & slow
    - then put slow = head
    - then start moving both pointers by 1 step
    - the next intersection will be Start of Loop

Delete Loop: 
    - get start of loop 
    - make a temp pointer initially at start of loop
    - temp->next until its next!=start of loop
    - point temp->next to NULL  
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

// Detect Loop 
bool detectLoop(node*head){
    if(head==NULL){
        return false;
    }
    map<node*,bool>visited;
    node*temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"Cycle: "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

// Floyd's Cycle Detection Algorithm
node* floydCycleDetect(node*head){
    if(head==NULL){
        return NULL;
    }
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/ 

node*startOfLoop(node*head){
    if(head==NULL){
        return NULL;
    }
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow){
            slow=head;
            break;
        }
    }
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
// OR
node*getStartOfLoop(node*head){
    if(head==NULL){
        return NULL;
    }
    node* intersection=floydCycleDetect(head);
    node*slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
void deleteLoop(node*head){
    if(head==NULL){
        return;
    }
    node* intersection=floydCycleDetect(head);
    node*slow=head;
    while(slow->next!=intersection->next){
        slow=slow->next;
        intersection=intersection->next;
    }
    intersection->next=NULL;
}
void deleteLoop2(node*head){
    if(head==NULL){
        return;
    }
    node*startOfLoop=getStartOfLoop(head);
    node*temp=startOfLoop;
    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}



int main(){

    node*head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    print(head);

    cout<<detectLoop(head)<<endl;
    cout<<floydCycleDetect(head)<<endl;
    temp->next=head->next;
    cout<<detectLoop(head)<<endl;
    cout<<floydCycleDetect(head)<<endl;

    cout<<endl;

    cout<<"Cycle: "<<startOfLoop(head)->data<<endl;
    cout<<"Cycle: "<<getStartOfLoop(head)->data<<endl;
    
    cout<<endl;

    cout<<detectLoop(head)<<endl;
    deleteLoop(head);
    cout<<detectLoop(head)<<endl;

    
    return 0;
}