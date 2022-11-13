#include<iostream>
using namespace std;

/* OOPs

Polymorphism = many forms, existing in multiple forms

Types:

1. Compile Time (Static Polymorphism)

    a. Function Overloading
        - can be achieved by changing number of parameters of diff funcs with same name
        - funcs that have diff return type but same name, same number of parameters cannot be overloaded
        - funcs with same name, diff return type, diff number of parameters or type can be overloaded
            * diff number of arguments
            * diff type of arguments
            * func with default arguments can be called with 2 or 3 or 4 arguments
    
    b. Operator Overloading
        - an operator like '+' can add or concatenate
        - but other custom work can be done using operator overloading
        - Operators that cannot be overloaded  ::  .*  .  ?:
            1 '+' is a binary operator
            2 '++' is a unary operator
        Syntax to overload '+' to subtract
            returnType operator + (input){ }    // in case of '+', first operand is this (current) & second is input argument

2. Run time (Dynamic Polymorphism)

    a. Method Overriding
        - implementing methods with same name differently when inheriting
        Rules
        - method of parent & child class must have same name
        - method of parent & child class must have same parameters
        - possible through inheritance only

        - If we make a child class & do not override method, then parent class's method will be called
        


*/

// Function Overloading

class A{
    public:
        void sayHello(){
            cout<<"Hello1 Sarthak"<<endl;
        }
        void sayHello(string name){         
            cout<<"Hello2 "<<name<<endl;
        }
        int sayHello(string name,int n){
            cout<<"Hello3 "<<name<<endl;
            return n;
        }
        int sayHello(char name){
            cout<<"Hello4 "<<name<<endl;
            return 1;
        }
};

// Operator Overloading

class B{
    public:
        int a;
        int b;
        int add(){
            return a+b;
        }
        void operator+ (B &obj){        // making '+' '-'
            int value1 = this -> a;
            int value2 = obj.a;
            cout<<"Output : "<<value2-value1<<endl;
        }
        void operator- (B &obj){
            cout<<"Hello Mates"<<endl;
        }
        void operator() (){
            cout<<"Bracet overload "<<this->a<<endl;
        }
};

// Method Overriding

class Parent{
    public:
        void show(){
            cout<<"Parent class"<<endl;
        }
};
class Child : public Parent{
    public:
        void show(){
            cout<<"Child class"<<endl;
        }
};

/*

Abstraction

= implementation hiding
= show only what is important, Example: sending email

1. Using classes = using access specifiers like public, privte or protected
2. Header files
3. using access specifiers

Advantages:
- only you can make changes to data
- security 
- reusability
- avoid duplication

*/

int main(){
    
    A obj;
    obj.sayHello();
    obj.sayHello("Sarthak");
    obj.sayHello("Sarthak",1);
    obj.sayHello('n');
    cout<<endl<<endl;

    B obj1,obj2;
    obj1.a=3;
    obj2.a=9;
    obj1 + obj2;    // Output : 6
    obj1 - obj2;    // Hello Mates
    obj1();         // Bracet overload 3
    cout<<endl<<endl;

    Parent o1;
    o1.show();  // Parent class
    Child o2;
    o2.show();  // Child class
    
    
    return 0;
}