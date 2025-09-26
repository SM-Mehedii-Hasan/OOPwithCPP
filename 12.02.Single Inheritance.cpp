// 🔹 What is Single Inheritance?
// Single Inheritance is a type of inheritance where a single derived class inherits from one base class.
// Syntax:
// class Base {
//     // properties and methods
// };
// class Derived : access_specifier Base {
//     // properties and methods
// };
// Here, Derived is inheriting from only one Base class → that’s why it’s called single inheritance.
// 🔹 Key Points of Single Inheritance
// Only one parent class → one child class.
// Child class inherits all non-private members (public → stays public, protected → stays protected).
// Private members of the base class are not directly accessible in the derived class.
// Relationship:
// Student is a Human.
// This is called an “IS-A” relationship.
// 📌 Quick recap of types in your examples:
// class Student : public Human → Single Public Inheritance
// class Student : protected Human → Single Protected Inheritance
// class Student : private Human → Single Private Inheritance
// But all of them are still Single Inheritance since there’s only one base class.






#include<iostream>
using namespace std;
class Human{
    protected:
    string name;
    int age;
    public:
    Human(){
        cout<<"Hello,Human"<<endl;
    }
    ~Human(){
        cout<<"Hello, this is Human Destructor"<<endl;
    }
    void work(){
        cout<<"i am working"<<endl;
    }
};
class Student:public Human{
    int roll,fees;
    public:
    Student(){
        cout<<"Hello,Student"<<endl;
    }
    ~Student(){
        cout<<"Hello, this is Student Destructor"<<endl;
    }
    Student(string name,int age,int roll,int fees){
        this->name=name;
        this->age=age;
        this->roll=roll;
        this->fees=fees;
    }
    void show(){
        cout<<name<<" "<<age<<" "<<roll<<" "<<fees<<endl;
    }
};
int main(){
    Student s;
    Student s1("mehedi",35,399,10000);
    s1.show();
    s1.work();

}
