// 🧩 What Is Multilevel Inheritance (in C++)?
// Multilevel inheritance is a type of inheritance where a class is derived from another derived class, forming a chain of inheritance.
// That means there are multiple levels (2 or more) in the inheritance hierarchy.
// 🧠 Simple Way to Understand
// Think of it like a family chain:
// Grandparent → Parent → Child
// The Parent inherits from Grandparent
// The Child inherits from Parent
// So, Child indirectly inherits from Grandparent too.
// | Feature              | Description                                                                               |
// | -------------------- | ----------------------------------------------------------------------------------------- |
// | **Levels**           | Involves more than two classes in a chain.                                                |
// | **Access**           | Each derived class gets all accessible members of its base class.                         |
// | **Reusability**      | Code from base classes is reused in all derived classes.                                  |
// | **ISA Relationship** | Manager **is an** Employee, Employee **is a** Person → therefore Manager **is a** Person. |

// 📊 Diagram:
// Person
//   ↑
// Employee
//   ↑
// Manager


#include<iostream>
using namespace std;
class Person{
    protected:
    string name;
    public:
    void introduce(){
        cout<<"Hello! I'm "<<name<<endl;
    }
};
class Employee:public Person{
    protected:
    int salary;
    public:
    void monthlySalary(){cout<<"my monthly salary "<<salary<<endl;}
};
class Manager:public Employee{
    public:
    string department;
    Manager(string name,int salary ,string department){
        this->name=name;
        this->salary=salary;
        this->department=department;
    }
    void work(){cout<<"I'm leading the department "<<department<<endl;}
};
int main(){
    Manager m1("Mehedi",300,"Finance");
    m1.work();
    m1.monthlySalary();
    m1.introduce();
}
