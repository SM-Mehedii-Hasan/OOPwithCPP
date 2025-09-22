// _______________________Object Pointer in C++ (or sometimes called Pointer to Object)._________________
#include <iostream>
using namespace std;

// 🏫 Class Definition
class Student
{
public:
    string name; // student's name
    int roll;    // student's roll number
    float cgpa;  // student's CGPA

    // 🎯 Constructor → initializes the object with given values
    Student(string name, int roll, float cgpa)
    {
        this->name = name;
        this->roll = roll;
        this->cgpa = cgpa;
    }
};

int main()
{





// 1. Normal Pointer
// Points to a simple data type (like int, float, char etc.).
// Used to store the address of a variable.
// Access data using *ptr.
// 👉 Example:
int x = 10;
int* ptr = &x;      // pointer to int
cout << *ptr;       // prints 10
cout<<"\n\n\n";





// 2. Object Pointer
// Points to a class object.
// Used to store the address of an object.
// Access members using:
// (*ptr).member → dereference
// ptr->member → arrow operator (cleaner way)
// 👉 Example:

    // 🎓 Object Creation → creates a student object s1
    Student s1("mehedi", 1, 3.00);

    // 📌 Pointer Declaration → p points to the address of s1
    Student *p = &s1;

    // 📤 Accessing members directly using dot operator (.)
    cout << "name=" << s1.name
         << " roll=" << s1.roll
         << " cgpa=" << s1.cgpa << endl;

    // 📤 Accessing members using pointer with dereference (*p).member
    cout << "name=" << (*p).name
         << " roll=" << (*p).roll
         << " cgpa=" << (*p).cgpa << endl;

    // ✏️ Modifying object data (changes original object through pointer)
    (*p).name = "hasan";

    // 📤 Printing again after modification (still using (*p).member)
    cout << "name=" << (*p).name
         << " roll=" << (*p).roll
         << " cgpa=" << (*p).cgpa << endl;

    // 📤 Accessing members using arrow operator (p->member)
    cout << "name=" << p->name
         << " roll=" << p->roll
         << " cgpa=" << p->cgpa << endl;
}
| Feature             | Normal Pointer              | Object Pointer                 |
| ------------------- | --------------------------- | ------------------------------ |
| Points to           | Variable (int, float, char) | Object (instance of a class)   |
| Declaration Example | `int* p = &x;`              | `Student* p = &s1;`            |
| Access data         | `*p`                        | `(*p).member` or `p->member`   |
| Used in OOP?        | ❌ No                        | ✅ Yes, to access class members |

Pointer to variable → Normal Pointer
Pointer to object → Object Pointer

____________________________________________________________________________________
#include<iostream>
using namespace std;

// 🏫 Class Definition
class Student {
public:
    string name;   // student's name
    int roll;      // student's roll number
    float cgpa;    // student's CGPA

    // 🎯 Constructor → initializes the object with given values
    Student(string name, int roll, float cgpa) {
        this->name = name;
        this->roll = roll;
        this->cgpa = cgpa;
    }
};

int main() {
    // 🎓 Object Creation (Stack Allocation)
    // s1 is created in stack memory
    Student s1("mehedi", 10, 3.00);

    // 📌 Dynamic Object Creation (Heap Allocation)
    // s2 is a pointer to an object created using 'new' in heap memory
    Student* s2 = new Student("hasan", 1, 3.45);

    // 📤 Accessing members of stack object using dot operator (.)
    cout << s1.name << " " << s1.roll << " " << s1.cgpa << endl;

    // 📤 Accessing members of heap object using arrow operator (->)
    cout << s2->name << " " << s2->roll << " " << s2->cgpa << endl;

    // 🗑️ Freeing heap memory (good practice to avoid memory leaks)
    delete s2;
}
📝 Memory Layout of Your Program
1. Stack Object (s1)
Student s1("mehedi", 10, 3.00);
Created inside main(), so it goes in stack memory.
Accessed using s1.name, s1.roll, s1.cgpa.
2. Heap Object (s2)
Student* s2 = new Student("hasan", 1, 3.45);
new creates a Student object in heap memory.
s2 (pointer variable) lives in the stack, but it stores the address of the object in the heap.
Accessed using s2->name, s2->roll, s2->cgpa.

📊 Diagram
                   ┌───────────────┐
   Stack Memory     │   s1 object   │
   (inside main)    │---------------│
                    │ name = mehedi │
                    │ roll = 10     │
                    │ cgpa = 3.00   │
                    └───────────────┘

                    ┌───────────────┐
                    │    s2 (ptr)   │   --->  points to heap
                    │ stores addr   │
                    │ of heap obj   │
                    └──────┬────────┘
                           │
                           ▼
                   ┌───────────────┐
   Heap Memory     │  Student obj  │
   (dynamic)       │---------------│
                    │ name = hasan │
                    │ roll = 1     │
                    │ cgpa = 3.45  │
                   └───────────────┘







🔹 Case 1: With delete s2;
int main() {
    Student s1("mehedi", 10, 3.00);       
    Student* s2 = new Student("hasan", 1, 3.45);

    cout << s1.name << " " << s1.roll << " " << s1.cgpa << endl;
    cout << s2->name << " " << s2->roll << " " << s2->cgpa << endl;

    delete s2;   // ✅ frees heap memory
}

Memory Diagram
Stack:                       Heap:
 ┌───────────────┐           ┌───────────────┐
 │ s1 object     │           │ Student obj   │
 │ name=mehedi   │           │ name=hasan    │
 │ roll=10       │           │ roll=1        │
 │ cgpa=3.00     │           │ cgpa=3.45     │
 └───────────────┘           └───────────────┘
 ┌───────────────┐
 │ s2 (pointer)  │  ---> freed after delete
 └───────────────┘


👉 After delete s2;, heap memory is released, program exits cleanly.

🔹 Case 2: Without delete s2;
int main() {
    Student s1("mehedi", 10, 3.00);       
    Student* s2 = new Student("hasan", 1, 3.45);

    cout << s1.name << " " << s1.roll << " " << s1.cgpa << endl;
    cout << s2->name << " " << s2->roll << " " << s2->cgpa << endl;

    // ⚠️ Forgot delete s2;
}

Memory Diagram
Stack:                       Heap:
 ┌───────────────┐           ┌───────────────┐
 │ s1 object     │           │ Student obj   │
 │ name=mehedi   │           │ name=hasan    │
 │ roll=10       │           │ roll=1        │
 │ cgpa=3.00     │           │ cgpa=3.45     │
 └───────────────┘           └───────────────┘  (❌ still occupied)
 ┌───────────────┐
 │ s2 (pointer)  │  ---> pointer destroyed when main ends
 └───────────────┘


👉 What happens:

The pointer s2 is destroyed when main ends (stack clears).

But the object in heap is still there — memory remains allocated.

Since you lost the pointer, you can’t free that memory anymore.

This is called a Memory Leak.

✅ Conclusion

Always use delete with new.

Stack objects don’t need manual cleanup.

In big projects (like servers or games), forgetting delete repeatedly can cause your program to keep using more and more memory until it crashes.




#include <iostream>
#include <memory>   // ✅ For unique_ptr
using namespace std;

// 🏫 Class Definition
class Student {
public:
    string name;   // student's name
    int roll;      // student's roll number
    float cgpa;    // student's CGPA

    // 🎯 Constructor → initializes the object with given values
    Student(string name, int roll, float cgpa) {
        this->name = name;
        this->roll = roll;
        this->cgpa = cgpa;
    }
};

int main() {
    // 🎓 Stack object
    Student s1("mehedi", 10, 3.00);

    // 📌 Heap object managed by unique_ptr (automatic cleanup)
    unique_ptr<Student> s2 = make_unique<Student>("hasan", 1, 3.45);

    // 📤 Accessing members
    cout << s1.name << " " << s1.roll << " " << s1.cgpa << endl;
    cout << s2->name << " " << s2->roll << " " << s2->cgpa << endl;

    // No need to call delete → memory is freed automatically when s2 goes out of scope
}



🔹 What Changed?
Included <memory> for unique_ptr.
Used unique_ptr<Student> instead of raw pointer.
Created the object with make_unique<Student>(...).
No delete is needed — unique_ptr automatically frees heap memory when it goes out of scope.
✅ Benefits of Using unique_ptr:
Avoids memory leaks automatically.
Safer than raw pointers.
Clear ownership: only one unique_ptr can own the object.
🔹 What Happens When You Shut Down Your System
Heap memory is allocated per program.
When your program runs, the OS gives it a portion of memory (stack + heap).
Your program uses the heap for objects created with new.
If you forget delete while the program is running
The memory stays allocated while the program is running.
This is called a memory leak.
When you shut down your system (or the program ends)
The Operating System automatically reclaims all memory used by programs.
So all heap memory used by your program is freed when the program terminates, whether or not you used delete.
🔹 Important Clarification
Memory leak only matters while the program is running.
If your program keeps allocating memory without freeing it, it can eventually consume all available memory and crash.
After program ends, the OS cleans everything up, so shutting down your computer also clears it.
🔹 Analogy
Think of memory like a desk:
You put books (heap objects) on the desk (memory).
If you forget to put them back in the shelf (delete), the desk stays messy while you’re working.
But when you leave the office (program ends / shutdown), the cleaning staff (OS) comes and clears everything.
✅ Summary
Situation	Heap Memory Behavior
Program running + forgot delete	Memory stays allocated → memory leak
Program ends / system shutdown	OS frees all memory automatically
So, for short-lived programs, forgetting delete may not cause permanent harm because the OS cleans it up.
For long-running programs (servers, games), memory leaks are dangerous because the memory stays allocated while the program runs.



🔹 Why Use Dynamic Objects in C++

A dynamic object is an object created on the heap using new.
Example:

Student* s = new Student("Hasan", 1, 3.45);

1. Memory Lifespan Control

Stack objects are destroyed automatically when the function ends.

Heap (dynamic) objects remain in memory until you explicitly delete them.

✅ Use case: You want the object to exist beyond the scope of the function.

Student* s = new Student("Hasan", 1, 3.45);
// use s in multiple functions or store globally
delete s;  // free memory when done

2. Large Objects or Arrays

Stack memory is limited.

Large objects or arrays may overflow the stack.

Dynamic allocation moves them to the heap, which is much larger.

int* arr = new int[100000];  // large array in heap

3. Flexible / Runtime Size

Stack objects must have known size at compile time.

Heap objects can be created dynamically based on user input or program logic.

int n;
cin >> n;
Student* students = new Student[n]; // size known at runtime

4. Polymorphism / OOP Use

In OOP, you often use base class pointers pointing to derived class objects.

These must be dynamic to persist correctly and support polymorphism.

class Base { virtual void display() {} };
class Derived : public Base {};
Base* obj = new Derived();  // dynamic object

5. Sharing / Passing Objects

Pointers to dynamic objects can be passed around, stored in containers, or returned from functions safely.

Stack objects cannot be returned by reference safely because they are destroyed when the function ends.

Student* createStudent() {
    return new Student("Mehedi", 1, 3.00);  // safe, survives after function ends
}

🔹 Summary Table
Feature	Stack Object	Dynamic Object (Heap)
Lifetime	Automatic	Manual (delete)
Size	Fixed / Compile-time	Flexible / Runtime
Memory Limit	Small	Large
Scope	Function only	Can persist beyond function
Polymorphism Use	Limited	Fully supported

✅ In short:

Use stack objects for small, short-lived data.

Use dynamic objects when:

You need flexible size

You need long lifetime beyond scope

You are using OOP polymorphism

You have large data




🔹 Stack vs Heap Objects
1. Stack Object
Student s1("Mehedi", 1, 3.00);


Created in stack memory.

Lifetime: only while the function is running.

Automatically destroyed when function ends.

Size must be known at compile time.

Stack Memory:
┌───────────────┐
│   s1 object   │
│ name=Mehedi   │
│ roll=1        │
│ cgpa=3.00     │
└───────────────┘

2. Heap Object (Dynamic)
Student* s2 = new Student("Hasan", 2, 3.45);


Created in heap memory.

Lifetime: until you delete it explicitly.

Size can be decided at runtime.

Can be shared or returned from functions safely.

Stack Memory:           Heap Memory:
┌───────────────┐       ┌───────────────┐
│   s2 pointer  │  ---> │  s2 object    │
│ stores addr   │       │ name=Hasan    │
└───────────────┘       │ roll=2        │
                        │ cgpa=3.45     │
                        └───────────────┘


s2 pointer is in stack, actual object is in heap.

If you forget delete s2;, heap memory remains until the program ends → memory leak.

🔹 Why Use Dynamic Objects (Heap)?

Live beyond function scope.

Flexible size (e.g., arrays or objects created at runtime).

Large objects won’t overflow the stack.

Needed for OOP features like polymorphism.

Can be shared or returned safely from functions.

✅ Summary:

Stack objects → fast, short-lived, fixed size.

Heap objects → flexible, long-lived, used when runtime decisions or OOP features are needed.
