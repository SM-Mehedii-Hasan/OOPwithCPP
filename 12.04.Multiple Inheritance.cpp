// 🧩 Multiple Inheritance in C++ (OOP)

// Definition:
// 👉 Multiple inheritance is a type of inheritance where a derived class inherits from more than one base class.
// It allows a class to combine the functionality of multiple parent classes.
// 🧱 Syntax:
// class Base1 {
//     // members of Base1
// };

// class Base2 {
//     // members of Base2
// };

// class Derived : public Base1, public Base2 {
//     // members of Derived
// };
// Here, Derived inherits features from both Base1 and Base2.

#include<iostream>
using namespace std;
class Person{
    protected:
    string name;
    public: 
    void setName(string name){this->name=name;}
};

class Job{
    protected:
    string role;
    public:
    void setRole(string role){this->role=role;}
};

class Employee:public Person,public Job{
    private:
    int salary;
    public:
    void setSalary(int salary){this->salary=salary;}
    void display() {
        cout << "Name: " << name << endl;
        cout << "Role: " << role << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main(){
    Employee e1;
    e1.setName("Mehedi Hasan");
    e1.setRole("Sofware Engineer");
    e1.setSalary(45000);
    e1.display();

}
// _______________________________________________________________________________________
// ⚠️ Example of Ambiguity:
class A {
public:
    void show() { cout << "From A\n"; }
};
class B {
public:
    void show() { cout << "From B\n"; }
};
class C : public A, public B {
    // Ambiguous: both A and B have show()
};
int main() {
    C obj;
    // obj.show(); ❌ ERROR: ambiguous
    obj.A::show(); // ✅ specify which one
    obj.B::show(); // ✅
}



// ________________________________________________-
// 🧭 Real-life Example:
// Imagine a SmartPhone class:
// Inherits from Camera (to take photos)
// Inherits from Phone (to make calls)

class Camera { public: void takePhoto() { cout << "Photo taken\n"; } };
class Phone { public: void makeCall() { cout << "Calling...\n"; } };
class SmartPhone : public Camera, public Phone {};
