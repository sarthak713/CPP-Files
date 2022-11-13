#include<iostream>
using namespace std;

/*
Pillars of OOPs

1. Encapsulation
    = wrapping up data members & functions
    = achived by creating a class & putting in data-members & functions inside it

    Full Encapsulated Class
        = all Data members are private

Advantages :
    - also called Information/Data hiding
    - data can be hidden by making Data members private (increase in Security)
    - Class can be made Read-Only by using Getter Methods
    - Code Reusability
    - helps in Unit Testing & Managability

*/

class Student{
    private:
        string name;
        int age;
        int height;
    public:
        int getAge(){
            return this->age;
        }
};

/*

2. Inheritance

- Upper class is Parent/Super Class
- Lower class is Sub/Child Class

Make child class using - 
class Child : accessMod Parent{ }; 

Mode of Inheritance =
                            Mode to be Inherited From
Base Class Member|     Public       Protected       Private
Access Specifier |    --------     -----------     ---------
-   Public       |     Public       Protected       Private
-   Protected    |    Protected     Protected       Private
-   Private      | Not Accessible Not Accessible Not Accessible

Private Data Member cannot be inherited

Protected = Can only be accessible inside Child Class only

*/
 
class Human{
    public:
        int height;
        int weight;
        int age;
        int getAge(){
            return this->age;
        }
        void setWeight(int w){
            this->weight=w;
        }
    protected:
        int grow;
};

class Male : public Human{
    public:
        string color;
        void sleep(){
            cout<<"Male sleeping"<<endl;
        }
};

/*

Types of Inheritance :

1 Single
    class B inherits from class A
    class A -> class B
2 Multi-Level
    class C inherits from class B that inherits from class A, etc
    class A -> class B -> class C
3 Multiple
    class C inherits from both class A & class B
    class C -> class A, class B
    Example = class C: public A, public B { };
4 Heirarchical
    One class serves as Parent for more than one class
    Single class Multiple Children with Multiple children
5 Hybrid
    Combination of more than 1 type of inheritance

---------------------------------------------

Inheritance Ambiguity :

Suppose =
- class A has func abc()
- class B has func abc()
- class C inherits both A and B classes
Which Class's function will be called ?
- We use scope resolution operator ::
    Example, C obj;
             obj.A :: abc();    // this will call A's func
             obj.B :: abc();    // this will call B's func


*/

int main(){

// Inheritance

    Male obj1;
    cout<<obj1.age<<endl;
    cout<<obj1.weight<<endl;
    cout<<obj1.height<<endl;
    cout<<obj1.color<<endl;
    obj1.sleep();
    obj1.setWeight(56);
    cout<<obj1.weight<<endl<<endl<<endl;


    
    

    
    
    return 0;
}