#include<iostream>
using namespace std;

/*
OOPs (Object Oriented Programming)
- Type or technique of programming that revolves around objects
- Inlcuding real-life objects to program to enhance readability

Object is an Entity that contains:
1. State/Properties
2. Behaviour

Class = user defined data type
Object is an instance of a Class

1. Size of Object = Total Size of all its Properties
- If object does not have any Properties, then Size = 1 byte
    this is because of just keeping identification/track of object in memory
- Data Alignment
    Way data is arranged and accessed in computer memory
    Putting data in memory at address equal to some multiple of word size
    This increases performance of system due to the way the CPU handles memory
- Data Structure Padding 
    To align data, it is necessary to insert some extra bytes between end of last data structure & start of next data structure because data is placed in memory as multiples of fixed word size 
    This insertion of extra bytes of memory to align data is call DS padding

2. We can define class in a File & use it in another File also
    - define it in one file
    - then include the filename in new file: #include"fileName.cpp"

To access properties/data members of a Class
We use '.' dot operator

Access Modifiers :

- how will data members/properties be accessed in the program
- what will be thier Scope, by Default it is Private

1. public 
    - can be accessed inside/outside the class, anywhere 
2. private 
    - can be accessed inside the class only
3. protected

Getter/Setter:

- functions/methods inside the class through which properties can be accessed or changed
- can access or set private data members also using Getter & Setter
Getter is used to fetch data
Setter is used to set, change, specify conditions


*/

class NewFile{
    int number;
    char character;
};

class Hero{     
    private:
        int health;     
    public:
        char level;
        void printLevel(){
            cout<<level<<endl;
        }
        int getHealth(){            // Getter
            return health;
        }
        char getLevel(){
            return level;
        }
        void setHealth(int h){      // Setter
            health=h;
        }
        void setLevel(char ch){
            level=ch;
        }
    // Default Constructor
        Hero(){
            cout<<"Default Constructor called"<<endl;
        }
    // Parameterized Constructor
        Hero(int health){
            // cout<<"this -> "<<this<<endl;
            this->health=health;    
        }
    // Custom Copy Constructor
        Hero(Hero &temp){   // pass by reference 
            cout<<"Copy Constructor called"<<endl;
            this->health=temp.health;
            this->level=temp.level;
        }
};


int main(){
    
    Hero h1;    // creation of Object using Class
    
    cout<<"Size of Hero h1: "<<sizeof(h1)<<endl;     // 8

    cout<<"Heath is: "<<h1.getHealth()<<endl;
    cout<<"Level is: "<<h1.level<<endl;
    h1.level='A';
    h1.setHealth(99);
    cout<<"After setting, Heath is: "<<h1.getHealth()<<endl;
    h1.printLevel();
    cout<<endl<<endl;

// Static Allocation
    Hero h2; 
    h2.setHealth(55);
    cout<<"Health of Static Object: "<< h2.getHealth() <<endl<<endl;
/*
Dynamic Allocation
- Now memory for this new object is allocated in Heap
- This Pointer h3 is pointing to address of the object in Heap Memory
*/ 
    Hero *h3 = new Hero;
    h3->setHealth(77);                                              // we can't do h3.setHealth() because h3 is pointer storing address not the object
    cout<<"Health of Dynamic Object: "<< (*h3).getHealth() <<endl;  // We have to dereference h3 so, *h3 is the object
    cout<<"Health of Dynamic Object: "<< h3->getHealth() <<endl;    // alternative implementation
    h3->setLevel('B');
    cout<<"Level of Dynamic Object: "<< (*h3).getLevel() <<endl;
    (*h3).setLevel('A');
    cout<<"Level of Dynamic Object: "<< h3->getLevel() <<endl;
    
    cout<<endl<<endl;

/*
Constructors

When object is created:
- First thing invoked is its constructor
- Constructor has no return type
- BTS h4.Hero() is invoked, this is Default Constructor
- Default constructor is not visible but can be made like above
- Constructor is invoked in both cases: Static & Dynamic Object Creation

- When we make a Contructor ourselves, in-built constructor is destroyed

Parameterised Constructor:
- this keyword = address of current object is stored in 'this'

Even if the Default Constructor we made is deleted
And we have put Parameterised Constructors in our Class
Will the Default Constructor still be made in Memory?: NOO

So, making any type of constructor will lead to Destruction of Constructor in Memory
And then we cannot make Default object without any parameters,
So if we want to make Parameterised constructor, we also have to make Default, if it will be used in program

Copy Constructor:
Copy of object, with same values
ClassName copyObjName(OrigObjName);
On making custom Copy Constr. -> Default copy Contr. is destroyed
*/
    cout<<"Hii"<<endl;
    Hero h4;
    cout<<"Byi"<<endl<<endl;


    cout<<"Hii1"<<endl;
    Hero *h5 = new Hero;
    cout<<"Bye2"<<endl<<endl<<endl;

    Hero h6(55);
    cout<<&h6<<endl;
    Hero *h7 = new Hero(66);

    cout<<endl<<endl;

    Hero h9(80);
    h9.setLevel('C');
    cout<<h9.getHealth()<<endl;

    Hero h10(h9); // Copy Constructor
    cout<<h10.getHealth()<<endl;
    cout<<endl<<endl;
/*
Shallow & Deep copy

- Default copy constructor = shallow copy

*/















    return 0;
}