#include<iostream>
using namespace std;
/*
N Stacks In An Array (Code Studio)

- array is given in input
- implement N number of Stacks in Array
- can perform push and pop on any stack
- Similar to 2 stacks in Array but Hard:difficulty

Approach 1 :
- Let array length = n, no. of stacks = k
- Divide array into k parts, so size of 1 stack = n/k
- Assign all these parts to stacks, n/k size wise
- Drawback = Space Utilization is Not Optimized

Approach 2 :
- Let array length = 9, no. of stacks = 3
    - In 2 stacks, we had 2 tops. one from start & one from end to keep track of stacks
- We want 2 additional things:
    - Array of top[], if we have 3 stacks, size of this top[] will be 3
        - represents index of top element
    - Array of next[], contains 2 things
        - point to next element after stack top, inside that stack only
        - point to next free space
            - if arr[i] stores an element, then next points to next element after stack top
            - else if arr[i] is empty, then next points to next free space

Question:
N = number of stacks  3
S = the size of array 6
Q = number of queries 5
Type 1: for push(x,m)
Type 2: for pop(m)

Input:
    N S Q
    3 6 5
    1 10 1 = push 10 in 1st stack 
    1 20 1 = push 20 in 1st stack
    1 30 2 = push 30 in 2nd stack
    2 1 = pop 1st stack
    2 2 = pop 2nd stack
Output:
    True
    True
    True
    20 
    30                                                              0 1 2 3 4 5
- we have empty array that will contain n stacks of size S = 6, arr[- - - - - -]
- make top[] array of size 3, top[- - -]                     0 1 2 3 4 5
- make next[] array of size equeal to array size S = 6, next[- - - - - -]

- Initialize all top[] elements by -1 = [-1,-1,-1]
- Main array is empty, so next[]elements point to next free space for main array elements
    - next[1,2,3,4,5,-1]
    - next[] array gives info about next free space
- freeSpot variable tells starting index of free list, initially free = 0
    - to utilize next array to tell next free index

- push(10,1)
    1. find free index to push in
            int index = freeSpot    (index=0)
    2. update freeSpot as first one is utilized and we find free spot using next[] 
            freeSpot = next[index]  (freeSpot=1)
    3. insert in array
            arr[index] = x          (arr[0]=10)
    4. Now arr[index] contains element, so update next[index] by previous value of top
            next[index] = top[m-1]  (next[0]=top[0]=-1), m-1 is done because of 0 base indexing
    5. update top
            top[m-1] = index        (top[0]=0)

Now Array=[10,-,-,-,-,-]
    Top=[0,-1,-1]
    Next=[-1,2,3,4,5,-1]
    freeSpot=1

- push(x,m), push(20,1)
    1. index = freeSpot = 1
    2. freeSpot = next[index] = next[1] = 2
    3. arr[index] = arr[1] = 20
    4. next[index] = top[m-1], next[1] = top[0] = 0
    5. top[0] = 1
Now Array=[10,20,-,-,-,-]
    Top=[1,-1,-1]
    Next=[-1,0,3,4,5,-1]
    freeSpot=2

- pop(m), pop(1)
    reverse of push operation
    1. Find index 
            index = top[m-1], index = top[0] = 1
    2. top[m-1] = next[index] 
            top[0] = next[1]
            top[0] = 0
    3. next[index] = freeSpot
           next[1] = 2
    4. freeSpot = index
            freeSpot = 1
            
Now Array=[10,-,-,-,-,-]
    Top=[0,-1,-1]
    Next=[-1,2,3,4,5,-1]
    freeSpot=1 

T.C. = O(1)
S.C. = O(s+n)
*/

class NStack{
    int *arr;
    int *top;
    int *next;
    int n,s;
    int freeSpot;

public:
    NStack(int N,int S){
        n=N;    // no. of stacks
        s=S;    // size of array
        arr=new int[s];
        top=new int[n];
        next=new int[s];
        for(int i=0;i<n;i++){   // initialize top[] elements by -1 
            top[i]=-1;
        }
        for(int i=0;i<s;i++){   // initialize next[] elements by 1+index value
            next[i]=i+1;
        }
        next[s-1]=-1;           // last element of next[] is -1
        freeSpot=0;
    }
    bool push(int x,int m){     // pushes x into mth stack, return true if pushed, esle false
        if(freeSpot==-1){       // stack overflow
            return false;
        }
        int index=freeSpot;     // Step 1: find index
        freeSpot=next[index];   // Step 2: update freeSpot
        arr[index]=x;           // Step 3: insert element in array
        next[index]=top[m-1];   // Step 4: update next
        top[m-1]=index;         // Step 5: update top
        return true;
    }
    int pop(int m){             // pops top element from mth stack, return -1 if stack is empty, else return popped element
        if(top[m-1]==-1){       // stack underflow
            return -1;
        }
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freeSpot;
        freeSpot=index;
        return arr[index];
    }
};

int main(){
    
    
    
    return 0;
}