🔹 1. What is Static Memory Allocation?
Definition: Memory is allocated at compile time (size is fixed).
// 1️⃣ Compile Time
// Definition:
// Compile time is the phase when your source code is being translated into machine code by the compiler.
// All the decisions that can be made before the program runs happen here.
Where stored: Stack segment of memory.
Lifetime: Ends automatically when the object goes out of scope.
Features:
Easy to use, no new/delete.
Size must be known in advance.
Faster access because stack is lightweight.
But limited size (stack overflow possible for large arrays).
______________________________________________________________________________________________________
🔹 2. What is Dynamic Memory Allocation?
Definition: Memory is allocated at runtime using new.
Where stored: Heap segment of memory.
Lifetime: Exists until explicitly released with delete.
Features:
Flexible size → can be decided at runtime.
// 2️⃣ Runtime
// Definition:
// Runtime is the period when your program is actually running, after compilation.
// Anything that happens while the program is executing is runtime.
Required for large data structures (linked list, trees, graphs).
Slower than stack allocation (because it uses heap).
Must manage memory manually (risk of memory leaks).
*******************************************************************
Compile time = reading the recipe, gathering ingredients, preheating the oven.
Runtime = actually mixing ingredients, baking, and serving the cake.
*****************************************************************************************************************************************
#include<iostream>
using namespace std;
class Student{
    string name;
    int roll;
    string grade;
    public:
    void set(string n,int r,string g){
        name=n;roll=r;grade=g;
    }
    string getName(){return name;}
    int getRoll(){return roll;}
    string  getGrade(){return grade;}

};
int main(){
    Student s1;
    s1.set("mehedi",19,"a++");//memory allocated at compile-time (stack)
    cout<<s1.getName()<<" "<<s1.getRoll()<<" "<<s1.getGrade()<<endl; // automatically destroyed when main ends
     Student* s2 = new Student;
     (*s2).set("hasan",20,"b++");// allocated at runtime (heap)
     cout<<(*s2).getName()<<" "<<s2->getRoll()<<" "<<s2->getGrade()<<endl;
       delete s2; // must manually free memory
    
}
