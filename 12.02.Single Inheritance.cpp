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


// ___________________________________________________________________________________________________________________________________________



#include <iostream>
using namespace std;

// ===========================================================
// 🧍‍♂️ Base Class → Human
// Represents common attributes and behavior for all humans.
// ===========================================================
class Human {
private:
    string bloodGroup;  // ❌ private → not accessible in derived class
protected:
    string name;
    int age;
public:
    // 🔹 Default Constructor
    Human() {
        cout << "Human Default Constructor Called" << endl;
    }

    // 🔹 Parameterized Constructor
    Human(string name, int age, string bloodGroup) {
        this->name = name;
        this->age = age;
        this->bloodGroup = bloodGroup;
        cout << "Human Parameterized Constructor Called" << endl;
    }

    // 🔹 Public Function
    void showBloodGroup() {
        cout << "Blood Group: " << bloodGroup << endl;
    }

    // 🔹 Function to be overridden in derived class
    void work() {
        cout << "Human is working in general." << endl;
    }

    // 🔹 Destructor
    ~Human() {
        cout << "Human Destructor Called" << endl;
    }
};

// ===========================================================
// 🎓 Derived Class → Student
// Inherits from Human (Single Inheritance)
// Student IS-A Human
// ===========================================================
class Student : public Human {
private:
    int roll;
    double fees;
public:
    // 🔹 Default Constructor
    Student() {
        cout << "Student Default Constructor Called" << endl;
    }

    // 🔹 Parameterized Constructor using Initialization List
    Student(string name, int age, string bloodGroup, int roll, double fees)
        : Human(name, age, bloodGroup)  // 👈 Calls base constructor
    {
        this->roll = roll;
        this->fees = fees;
        cout << "Student Parameterized Constructor Called" << endl;
    }

    // 🔹 Overriding Function
    void work() {
        cout << "Student is studying for exams." << endl;
    }

    // 🔹 New Function (not in base class)
    void showStudentInfo() {
        cout << "Name: " << name
             << " | Age: " << age
             << " | Roll: " << roll
             << " | Fees: " << fees << endl;
    }

    // 🔹 Destructor
    ~Student() {
        cout << "Student Destructor Called" << endl;
    }
};

// ===========================================================
// 🧠 main() Function → Demonstration of Single Inheritance
// ===========================================================
int main() {
    cout << "\n--- Creating Student Object (Parameterized) ---\n";
    Student s1("Mehedi", 20, "O+", 101, 12000);

    cout << "\n--- Showing Student Information ---\n";
    s1.showStudentInfo();
    s1.showBloodGroup(); // inherited from Human

    cout << "\n--- Function Overriding Example ---\n";
    s1.work();           // Student version
    s1.Human::work();    // Base version using scope resolution

    cout << "\n--- Object Destruction (Destructor Order) ---\n";
    return 0;
}

