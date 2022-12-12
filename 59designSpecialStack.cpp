#include<iostream>
#include<stack>
using namespace std;
/*
Design a stack that supports 
getMin in O(1) time & O(1) extra space.

- Make a get minimum element function, to get minimum value from stack

Approach 1:
- Let elements = 5 3 8 2 4
- Initialize variable mini = INT_MAX
- Make curr variable which points to elements one by one
- When element is pushed into stack, we have to update mini
    - mini = min(mini,curr)
    - So, when curr = 5 is pushed into stack, mini=5
    - When 3 is pushed into stack, mini=3
    - push 8, mini=3
    - push 2, mini=2
    - push 4, mini=2
- We have to store mini values also for easy access
    - We can use one more stack to store mini values, but then S.C. = O(n)
- So for this solution we have 2 stacks
    - One for elements, one for mini values corresponding to those elements as they are added
    - when stack is popped, we pop from both stacks
    - When getMin() is called, we return top of mini storing stack
    - here T.C. = O(1), S.C. = O(n)

Whenever we use a different data structure to solve question, S.C. becomes O(n)
To make S.C. O(1), we have to solve using variables

Approach 2:
- Let elements = 5 3 8 2 4
- We have 1 stack to push values & we Initialize variable mini = INT_MAX
- For push(5) 
    - check overflow
    - for curr = 5, push normally (for 1st element)
    - update mini = min(mini,curr)
    - mini=5

- For rest of elements, 
    - if curr < mini
        - make value = 2*curr-mini
        - push(value)
        - update mini
    - else
        - push(current)

- For push(3)
    - 3 < 5
    - value = 2*3-5 = 6-5 = 1
    - push(1)   ,Stack [5 1]
    - mini = 3
- For push(8)
    - 8 is bigger than 3
    - push(8)   ,Stack [5 1 8]
- For push(2)
    - 2 < 3
    - value = 2*2-3 = 1
    - push(1)
    - mini = 2  ,Stack [5 1 8 1]
- For push(4)
    - 4 is not less than 2
    - push(4)
    - Stack [5 1 8 1 4]
    - mini = 2

- For pop()
    - check underflow
    - if curr > mini
        pop()
    - else
        value = 2*mini-curr
        mini = value
        pop()
- 1st Pop Operation, 4 will be popped
    - curr > mini, 4 > 2, true
    - pop()
    - Stack [5 1 8 1]
- 2nd Pop Operation, 1 will be popped
    - curr > mini, 1 > 2, false
    - value = 2*mini-curr = 2*2-1 = 3, means mini ele for remaining element is 3
    - mini = value = 3
    - pop()
    - Stack [5 1 8]
- pop for 8
    - 8 > 3, true
    - pop()
    - Stack [5 1]
- pop for 1
    - 1 > 3, false
    - value = 2*mini-curr = 2*3-1 = 5, min value is 5 in remaining elements
    - mini = 5
    - pop()
    - Stack [5]
- Mini is 5 from remaining stack, which contains 5 only

- For getMin() function, return mini

Now S.C. = O(1) and T.C. = O(1)

In Formulae, we use current minimum to find previous minimum 
1. For Push() = 2 * curr - mini
    - lets say we have to push x which is curr, and previous minimum is greater that x
    - So we use formula, 2x-previousMinimum
    - now x becomes minimum, so mini=x
2. For Pop()  = 2 * mini - curr
    - lets say we have stack [5 1]
    - mini is x, so 2x-curr
    - curr is 1 and 1 is 2x-previousMinimum
    - so, 2x - (2x - previousMinimum) = previousMinimum
Therefore, we have used current Minimum to make previous Minimum
*/

class SpecialStack{
    stack<int>s;
    int mini;
public:
    void push(int data){
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                int val = 2*data-mini;
                s.push(val);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }
    int pop(){
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr > mini){
            return curr;
        }
        else{
            int prevMini = mini;
            int value = 2*mini-curr;
            mini = value;
            return prevMini;
        }
    }
    int top(){
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }
    bool isEmpty(){
        return s.empty();
    }
    int getMin(){
        if(s.empty()){
            return -1;
        }
        return mini;
    }
};


int main(){
    
    
    
    return 0;
}