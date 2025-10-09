// Hierarchical Inheritance in C++ is a type of inheritance where multiple derived classes inherit from a single base class. This is different from single, multilevel, or multiple inheritance.

// 🔹 Key Points:

// There is one base class.

// There can be two or more derived classes.

// Each derived class inherits members of the base class, but they are independent of each other.



// #include<iostream>
// using namespace std;
// class Human{
//     protected:
//     string name;
//     int age;
//     public:
//     Human(){ }
//     Human(string name,int age){
//         this->name=name;
//         this->age=age;
//     }
// };
// class Teacher:public Human{
//     private:
//     string subject;
//     public:
//     Teacher(string name,int age,string subject){
//         this->name=name;
//         this->age=age;
//         this->subject=subject;
//     }
//     void display(){
//         cout<<"Name : "<<name
//         <<"Age : "<<age
//         <<"Subjec : "<<subject<<endl;
//     }
// };
// class Student:public Human{
//     private:
//     float grade;
//     public:
//     Student(string name,int age,float grade) {
//         this->name=name;
//         this->age=age;
//         this->grade=grade;
//     }
//     void display(){
//         cout<<"Name : "<<name
//         <<"Age : "<<age
//         <<"Grade : "<<grade<<endl;

//     }
// };
// int main(){
//       Teacher t("Jahir", 35, "Math");
//     t.display();

//     Student s("Mehedi", 16, 9.5);
//     s.display();

// }


// 2️⃣ Improved Version:
#include <iostream>
using namespace std;

class Human {
protected:
    string name;
    int age;
public:
    Human() { }
    Human(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Teacher : public Human {
private:
    string subject;
public:
    // Properly call base class constructor
    Teacher(string name, int age, string subject) : Human(name, age) {
        this->subject = subject;
    }

    void display() {
        cout << "Name: " << name 
             << ", Age: " << age 
             << ", Subject: " << subject << endl;
    }
};

class Student : public Human {
private:
    float grade;
public:
    Student(string name, int age, float grade) : Human(name, age) {
        this->grade = grade;
    }

    void display() {
        cout << "Name: " << name 
             << ", Age: " << age 
             << ", Grade: " << grade << endl;
    }
};

int main() {
    Teacher t("Jahir", 35, "Math");
    t.display();

    Student s("Mehedi", 16, 9.5);
    s.display();

    return 0;
}
