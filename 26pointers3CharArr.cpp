#include<iostream>
using namespace std;

// Pointers & Character Arrays



int main(){

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    cout<< arr <<endl;  // 0x7bfe00 = address
    cout<< ch <<endl;   // abcde = entire content

    char *c = &ch[0];
    cout<< c <<endl;        // abcde, execution stops when null character is encountered
    cout<< *c <<endl;       // a  

    cout<<endl;  
    
    cout<< c+1 <<endl;      // bcde    
    cout<< *c+1 <<endl;     // 98    
    cout<< *c+2 <<endl;     // 99   
    cout<< *(c+1) <<endl;   // b
    cout<< *(c+2) <<endl;   // c

    cout<<endl;

/*  
    char temp = 'z';    // if no null char exists
    char *ptr = &temp;  
    cout<< ptr <<endl;  // prints = 'm↨■{', cout prints z then goes to another address & does not stop until null char is encountered 

1. char ch = "abcde";
    Behind the scenes:
        - temp memory = abcde\0
        - memory ch = copy temp memory
2. char *c = "abcde";
    Behind the scenes: (BAD Practice)
        - temp memory = abcde
        - pointer for c, stores address of temp memory
*/




    return 0;
}