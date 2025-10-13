🧩 Code 1 — Runtime Polymorphism with Dynamic Allocation
#include<iostream>
using namespace std;
class Animal {
public:
    virtual void speak() { cout << "huhu\n"; }
};
class Dog : public Animal {
public:
    void speak() { cout << "bark\n"; }
};
int main() {
    Animal *p;
    p = new Dog();
    p->speak();
    delete p;
}



✅ Explanation

Animal is the base class.
Dog is a derived class that overrides speak().
p is a pointer of type Animal*, but it points to a Dog object created dynamically using new.
Because speak() is virtual, C++ uses runtime polymorphism, so the Dog version is called.

🧠 Concepts used

Inheritance

Virtual function

Runtime polymorphism (dynamic binding)

Dynamic memory allocation

💡 Why it’s used
Used when you don’t know at compile time which subclass object you’ll create.

⚠️ Important
Always free memory:

delete p;

🧩 Code 2 — Runtime Polymorphism with Stack Object
#include<iostream>
using namespace std;
class Animal {
public:
    virtual void speak() { cout << "huhu\n"; }
};
class Dog : public Animal {
public:
    void speak() { cout << "bark\n"; }
};
int main() {
    Animal *p;
    Dog d;
    p = &d;
    p->speak();
}


✅ Explanation

Here Dog d; is created on the stack, not dynamically.
We assign its address to p (a base class pointer).
Because speak() is virtual, it calls the Dog version at runtime.

🧠 Concepts used

Inheritance

Virtual function

Runtime polymorphism (dynamic binding)

Pointer to base class

💡 Why it’s used
Gives polymorphism without dynamic memory — simpler and safer.

🧩 Code 3 — Function Overriding without Polymorphism
#include<iostream>
using namespace std;
class Animal {
public:
    virtual void speak() { cout << "huhu\n"; }
};
class Dog : public Animal {
public:
    void speak() { cout << "bark\n"; }
};
int main() {
    Dog d;
    d.speak();
}


✅ Explanation

Here you directly create a Dog object and call its function.
It calls Dog’s speak() — no pointer, no polymorphism.

🧠 Concepts used

Inheritance

Function overriding (not polymorphism)

Static binding

💡 Why it’s used
Used when you already know the exact object type — simple, efficient, no need for flexibility.
