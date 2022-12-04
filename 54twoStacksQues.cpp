#include<iostream>
using namespace std;
/*
TwoStacks - CodeStudio
*/
class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;
public:
    TwoStack(int s){
        size=s;
        top1=-1;    // start 1st stack from beginning of array
        top2=s;     // start 2nd stack from end of array
        arr = new int[s];
    }
    void push1(int num){
        if(top2-top1>1){    // at least 1 empty space is present
            top1++;
            arr[top1]=num;
        }
    }
    void push2(int num){
        if(top2-top1>1){    
            top2--;
            arr[top2]=num;
        }
    }
    int pop1(){
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }else{
            return -1;
        }
    }
    int pop2(){
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }else{
            return -1;
        }
    }
};

int main(){
    
    
    
    return 0;
}