// 🔹 What is a Destructor?
// A destructor in C++ is a special member function of a class that is automatically invoked when an object goes out of scope or is explicitly deleted.
// Its job is to clean up resources (like memory, files, or network connections) that the object acquired during its lifetime.
// Constructor → used for initialization (birth of an object).
// Destructor → used for cleanup (death of an object).
// ________________________________________________________________________________________________________________________________________________________________
// 🔹 Why create a Destructor if it’s already automatically provided?

// In C++, every class automatically gets a default destructor if you don’t explicitly write one.
// But that default destructor is empty — it doesn’t do any cleanup beyond destroying member variables.
// So, you only need to write your own destructor when your class manages resources that are not automatically cleaned up.
// ________________________________________________________________________________________________________________________________________________________________
// 🔸 Cases where you DON’T need a destructor

// If your class only contains:
// Primitive types (int, float, char, etc.)
// Standard library objects (std::string, std::vector, std::map, etc.)
// then the compiler-generated destructor is enough, because those objects clean themselves up.
// Example:
// class Student {
//     std::string name;
//     int roll;
// public:
//     Student(std::string n, int r) : name(n), roll(r) {}
//     // No need for destructor, string and int clean themselves
// };

// ________________________________________________________________________________________________________________________________________________________________
// 🔸 Cases where you DO need a destructor

// If your class acquires resources manually, like:
// Dynamic memory (new)
// File handles (fopen, ifstream.open)
// Network sockets
// Database connections
// then you must define a destructor to release those resources, otherwise you get memory leaks or resource leaks.
// Example:
// class Student {
//     char* name;
// public:
//     Student(const char* n) {
//         name = new char[strlen(n) + 1];
//         strcpy(name, n);
//     }
//     ~Student() {   // Destructor
//         delete[] name;  // Free memory
//         std::cout << "Memory released!\n";
//     }
// };
// Here, without a destructor, the memory allocated with new would never be freed.
// ________________________________________________________________________________________________________________________________________________________________
// 🔹 Summary
// Default destructor → fine for simple classes.
// Custom destructor → necessary when your class manages external resources (heap memory, files, sockets, etc.).
// Rule of thumb:
// If you write a constructor with new, you almost always need a destructor with delete.
// ________________________________________________________________________________________________________________________________________________________________
// #include<iostream>
// using namespace std;
// class Student{
//     string name;
//     int roll;
//     public:
//     Student(string name,int roll){
//         this->name=name;
//         this->roll=roll;
//         cout<<"constructor is called"<<" "<<roll<<endl;
//     }
//     ~Student(){
//          cout<<"destructor is called"<<" "<<roll<<endl;
//     }
// };
// int main(){
//     Student s1("adil",1),s2("mehedi",2),s3("sabbir",3);
// }


// ________________________________________________________________________________________________________________________________________________________________
// 🔹 Rule of Three

// In C++, if a class manages a resource (like dynamic memory, file handles, etc.), then you usually need to define three special member functions:

// Destructor (~ClassName) → frees the resource.

// Copy Constructor (ClassName(const ClassName&)) → defines how to copy objects safely.

// Copy Assignment Operator (operator=) → defines how to assign one object to another safely.

// 👉 Why?
// Because the default versions do a shallow copy, which can lead to double deletion or memory leaks if pointers are involved.

// ________________________________________________________________________________________________________________________________________________________________
// #include <iostream>
// #include <cstring>
// using namespace std;

// class Student {
//     char* name;
// public:
//     Student(const char* n) {
//         name = new char[strlen(n)+1];
//         strcpy(name, n);
//         cout<<" constructor is called";
//     }
//     // ❌ No destructor, copy constructor, or assignment operator

// };

// int main() {
//     Student s1("Mehedi");
//     Student s2 = s1;  // Shallow copy (problem!)

//     // Both objects now point to the same "name"
// }
// When program ends, both objects will try to delete the same pointer → crash (double free).
// ________________________________________________________________________________________________________________________________________________________________
// #include <iostream>
// #include <cstring>
// using namespace std;
// class Student {
//     char* name;
// public:
//     // Constructor
//     Student(const char* n) {
//         name = new char[strlen(n)+1];
//         strcpy(name, n);
//         cout<<"1"<<endl;
//     }

//     // Destructor
//     ~Student() {
//         delete[] name;
//         cout<<"destructor"<<endl;
//     }

//     // Copy Constructor
//     Student(const Student& other) {
//         name = new char[strlen(other.name)+1];
//         strcpy(name, other.name);
//         cout<<"copy constructor is called"<<endl;
//     }

//     // Copy Assignment Operator
//     Student& operator=(const Student& other) {
//         if (this != &other) {   // avoid self-assignment
//             delete[] name;      // free old memory
//             name = new char[strlen(other.name)+1];
//             strcpy(name, other.name);
//         }
//         return *this;
//     }
// };
// int main() {
//     Student s1("Mehedi");
//     Student s2 = s1; 
// }
// ________________________________________________________________________________________________________________________________________________

// __________________🔹 Version 1: Shallow Copy (Default Copy Constructor)___________________________________
// #include <iostream>
// #include <cstring>
// using namespace std;

// class Student {
//     char* name;
// public:
//     // Constructor
//     Student(const char* n) {
//         name = new char[strlen(n) + 1];
//         strcpy(name, n);
//     }

//     // ❌ Default Shallow Copy Constructor (compiler provides this)

//     // Destructor
//     ~Student() {
//         cout << "Destructor called, freeing memory for: " 
//              << (name ? name : "null") << endl;
//         delete[] name;
//     }

//     void display() {
//         cout << "Name: " << name << " | Address: " << (void*)name << endl;
//     }
// };

// int main() {
//     cout << "=== Creating s1 ===" << endl;
//     Student s1("Mehedi");
//     s1.display();

//     cout << "\n=== Copying s1 into s2 (shallow copy) ===" << endl;
//     Student s2 = s1;   // Default shallow copy
//     s2.display();

//     cout << "\n=== End of main() ===" << endl;
//     return 0;
// }
// Expected behavior:
// Both s1 and s2 point to the same memory.
// When destructors run → double free error (crash).
// ____________________________🔹 Version 2: Deep Copy (Custom Copy Constructor)______________________________________________________________________________________

#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char* name;
public:
    // Constructor
    Student(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // ❌ Shallow Copy Constructor (default provided by compiler)
    // Student(const Student& other) = default;

    // ✅ Deep Copy Constructor
    Student(const Student& other) {
        cout << "Deep Copy Constructor Called!\n";
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // Destructor
    ~Student() {
        cout << "Destructor called, freeing memory for: " 
             << (name ? name : "null") << endl;
        delete[] name;
    }

    void display() {
        cout << "Name: " << name << " | Address: " << (void*)name << endl;
    }
};

int main() {
    cout << "=== Creating s1 ===" << endl;
    Student s1("Mehedi");
    s1.display();

    cout << "\n=== Copying s1 into s2 ===" << endl;
    Student s2 = s1;   // Calls copy constructor (deep copy version)
    s2.display();

    cout << "\n=== End of main() ===" << endl;
    return 0;
}
// Expected behavior:
// Each object has its own memory.
// No crash, destructors free memory safely.
// ✅ Key takeaway:
// Shallow copy → dangerous when managing dynamic resources.
// Deep copy → safe, prevents memory corruption and crashes.
