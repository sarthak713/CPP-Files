#include<iostream>
#include<cstring>
using namespace std;

class Hero{     
    private:
        int health;     
    public:
        char*name;
        char level;

        static int timeToComplete;
        static int random(){
            return timeToComplete;
        }

        Hero(){
            name=new char[100];
            cout<<"Default Constructor called"<<endl;
        }
        Hero(int health,char level){
            this->health=health;    
            this->level=level;    
        }
        Hero(Hero &temp){  
            char *ch=new char[strlen(temp.name)+1]; // form new array with name as original object but at new address
            strcpy(ch,temp.name);
            this->name=ch;

            cout<<"Copy Constructor called"<<endl;
            this->health=temp.health;
            this->level=temp.level;
        }
        ~Hero(){
            cout<<"Destructor called"<<endl;
        }
        void print(){ 
            cout<<"[ Name : "<<this->name<<", ";
            cout<<"Health : "<<this->health<<", ";
            cout<<"Level : "<<this->level<<" ]"<<endl<<endl;
        }
        int getHealth(){  
            return health;
        }
        char getLevel(){
            return level;
        }
        void setHealth(int h){ 
            health=h;
        }
        void setLevel(char ch){
            level=ch;
        }

        void setName(char name[]){
            strcpy(this->name,name);
        }
};

int Hero::timeToComplete = 5;   // Static

/*
Shallow & Deep copy

1. Default copy constructor = Shallow Copy
    - same memory is accessed by different names
    - when properties are stored using address with pointers

2. Custom copy constructor = Deep Copy 

*/

int main(){
    
    Hero h1;

    h1.setHealth(12);
    h1.setLevel('D');
    char name[7]="Boy";
    h1.setName(name);

    cout<<"H1 = ";
    h1.print();         // Default: [ Name : Boy, Health : 12, Level : D ]

// Use default copy constructor to create copy, when custom copy-constructor does not exist
    // Hero h2 = h1;
    Hero h2(h1);
    cout<<"H2 = ";
    h2.print();         // Default: [ Name : Boy, Health : 12, Level : D ]

    h1.name[0]='G';
    h1.setHealth(70);
    h2.setHealth(50);
    cout<<"H1 = ";
    h1.print();         // Default: [ Name : Goy, Health : 70, Level : D ]  Custom: H1 = [ Name : Goy, Health : 70, Level : D ]
    cout<<"H2 = ";
    h2.print();         // Default: [ Name : Goy, Health : 50, Level : D ]  Custom: H2 = [ Name : Boy, Health : 50, Level : D ]
    

/*
Copy Assignment Operator

When we create 2 objects say:
Hero a(10,'C');
Hero b(20,'B');
and we say: a=b;
what happens is, values of Hero b are copied into Values of Hero a
Means:
    a.health=b.health
    a.level=b.level

*/

/*
Destructor
- Used to deallocate memory
- called only once before object is destroyed 
- name is same as ClassName, no return type no parameter
- Created automatically but can be re-defined
    ~ClassName(){}

- For Statically Allocated Objects = Destructor is called Automatically
But for Dynamically Allocated Objects = Destructor has to called Manually

*/
    Hero h3;                // static
    Hero*h4 = new Hero();   // dynamic
    delete h4;              // Manual Destructor call for dynamically allocated objects

    cout<<endl<<endl;
/*
Static keyword

= creates a data member that only belongs to Class
= to access it, there is no need to create object
= have to initialized outside the class
= :: scope resolution operator
dataType ClassName::dataMemberName = Value;
*/
    cout<<Hero::timeToComplete<<endl;
    
/*
Static Functions
- no need to create object, use className to access
- no 'this' keyword as 'this' is pointer to current object, but there is no object in this case
- can only access static data members
*/
    cout<<Hero::random()<<endl;


    

    return 0;
}