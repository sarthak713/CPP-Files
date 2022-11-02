#include<iostream>  // preprocessor directive, before compiling any file included will be brought into code for execution
using namespace std;

// MACROS
#define PI 3.14
#define AREA(l, b) (l * b)
#define NUM1 NUM2
#define NUM2 138

// GLOBAL VARIABLES
int score = 15;

void a(){
    char ch = 'a';  // Local Variable, it doesn't exist outside these blocks
    cout<<"Score: "<<score<<endl;
}

// INLINE FUNCTIONS

// int getMax(int &a,int &b){
//     return (a>b)?a:b;
// }

inline int getMax(int &a,int &b){
    return (a>b)?a:b;
}

// DEFAULT ARGUMENTS

void print(int *arr,int n,int start=2){
    for(int i=start;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}



int main(){
    
/*
MACROS
- created using #define
- variable created using datattypes: like int n, double pi take up some memory space that causes some performance hit
- So how can we store some values we use many times in code without using memory space
Example:
#define PI 3.14
- no need for ';'
Definition = piece of code in program replaced by value of macro
- Before code compilation macroName in code is replaced by its value
- No extra memory needed, can't be changed inside program
*/ 

    int r = 5;
    double area = PI*r*r;
    cout<<"Area Circle: "<<area<<endl;
    int l=5,b=5;
    cout<<"Area Rectangle: "<<AREA(l,b)<<endl<<endl;
    
/*
GLOBAL VARIABLES
- variable that can be share between functions
- They can be shared by Reference Variable also
- Can be used anywhere in the program
- Usage: BAD PRACTICE
    - can be change anywhere inside the program, & this changes its value in entire program
- Use Reference variable Instead
*/
    int i=5;
    cout<<"Score: "<<score<<endl;
    a();

/*
INLINE FUNCTIONS
= used to reduce function call overhead
In Stack Space, where functions exist
    - when function is called, it is pushed onto this stack
    - memory is used and time is delayed in some amount
    - We can reduce this using Inline Functions

*/
    
    int p=6,q=8;
    int ans=0;
    // if(p>q){
    //     ans=p;
    // }else{
    //     ans=q;
    // }
    // ans=(p>q)?p:q;
    ans=getMax(p,q);
    cout<<"Ans: "<<ans<<endl;
    p=p+3;
    q=q+1;
    // ans=(a>q)?a:q;
    ans=getMax(p,q);
    cout<<"Ans: "<<ans<<endl;
/*
This tertiary operator line is being used many times,
So we make a function for this.
- Still memory for a & b is being allocated inside function
- as thier copy is being created 
- function is also being called multiple time which is increasing overhead
- Even if we make arguments reference vars, then also function is being called

So to reduce this we make Inline Function if function body is Single-Lined
Now, function body will be replaced with function call before compilation
*/
    cout<<endl<<endl;

/*
DEFAULT ARGUMENTS
- give value of parameter in function definition
- this makes it optional, if we don't pass any argument it will take that given value
- If we specify it will take passed value

Always start with Rightmost Parameter to make Default Argument
*/
    int arr[]={1,4,7,8,9};
    print(arr,5);




    
    return 0;
}