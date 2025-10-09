// Multipath Inheritance in C++
// Definition:
// 👉 Multipath inheritance is a type of inheritance in which a derived class is derived from two or more classes that have a common base class.
// This creates multiple inheritance paths to the same base class — hence the name multipath.
// However, this can cause the “Diamond Problem”, where the derived class inherits multiple copies of the base class members — leading to ambiguity.
// | Concept                   | Explanation                                                                              |
// | ------------------------- | ---------------------------------------------------------------------------------------- |
// | **Multipath inheritance** | When a class inherits from two or more classes that share a common base.                 |
// | **Problem**               | Without `virtual`, the derived class gets multiple copies of the base class (ambiguity). |
// | **Solution**              | Use `virtual` inheritance so only one shared copy of the base (`Human`) exists.          |


//         Human
//         /   \
//   Engineer  Youtuber
//         \   /
//      CodeTeacher





#include<iostream>
using namespace std;

class Human {
public:
    string name;
    void display() {
        cout << "Name: " << name << endl;
    }
};

class Engineer : public virtual Human {
public:
    string specialization;
    void work() {
        cout << "I have specialization in " << specialization << endl;
    }
};

class Youtuber : public virtual Human {
public:
    int subscribers;
    void contentCreator() {
        cout << "I have a subscriber base of " << subscribers << endl;
    }
};

class CodeTeacher : public Youtuber, public Engineer {
public:
    int salary;

    CodeTeacher(string name, string specialization, int subscribers, int salary) {
        this->name = name;
        this->specialization = specialization;
        this->subscribers = subscribers;
        this->salary = salary;
    }

    void showDetails() {
        display();
        work();
        contentCreator();
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    CodeTeacher A1("Mehedi", "CSE", 590, 300);
    A1.showDetails();  // ✅ show all information
    return 0;
}
