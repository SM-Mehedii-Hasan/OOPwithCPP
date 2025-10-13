// 🧩 Example 1 — Abstract Class & Pure Virtual Function
#include<iostream>
using namespace std;

class A {
public:
    virtual void show() = 0;   // ✅ pure virtual, no body
};

class B : public A {
public:
    void show() {
        cout << "I am Derived" << endl;
    }
};

int main() {
    A *ptr;
    B b;
    ptr = &b;
    ptr->show();   // ✅ Output: I am Derived
}

🧠 Explanation:

A is now an abstract class because it has a pure virtual function (=0).

You cannot create an object of class A.

But you can create a pointer of type A*.

Since B overrides show(), it becomes concrete and can be instantiated.

--------------------------------------------------------------


// 🧩 Example 2 — With virtual keyword
#include<iostream>
using namespace std;
class A {
public:
   virtual void show() {   // ✅ virtual function
        cout << "I am Base" << endl;
   }
};
class B : public A {
public:
    void show() {          // overrides A::show()
        cout << "I am Derived" << endl;
    }
};
int main() {
     A *ptr;
     B b;
     ptr = &b;
     ptr->show();          // 🔹 Output: I am Derived
}

✅ Explanation

Here A::show() is declared virtual.

That means C++ will use runtime binding (dynamic binding).

Even though ptr is a pointer of type A*, it points to an object of type B.

So ptr->show() calls B’s version of show() → “I am Derived”.

🧠 This is runtime polymorphism.

--------------------------------------------------------------


// 🧩 Example 3 — Without virtual keyword
#include<iostream>
using namespace std;
class A {
public:
    void show() {          // ❌ not virtual
        cout << "I am Base" << endl;
    }
};
class B : public A {
public:
    void show() {
        cout << "I am Derived" << endl;
    }
};
int main() {
     A *ptr;
     B b;
     ptr = &b;
     ptr->show();          // 🔹 Output: I am Base
}

⚙️ Explanation

Now show() in base class is not virtual.

So compiler uses compile-time binding (static binding).

The function to call is decided by the type of pointer (A*), not the object.

Therefore, ptr->show() calls A’s show() → “I am Base”.

🧠 This is function overriding without polymorphism (static binding).

--------------------------------------------------------------


// 🧩 Example 4 — Calling base and derived methods directly
#include<iostream>
using namespace std;
class A {
public:
    void show() {
        cout << "I am Base" << endl;
    }
};
class B : public A {
public:
    void show() {
        cout << "I am Derived" << endl;
    }
};
int main() {
    B b1;
    b1.show();       // 🔹 Output: I am Derived
    B b2;
    b2.A::show();    // 🔹 Output: I am Base
}

✅ Explanation

b1.show() calls B’s version (normal overriding).

b2.A::show() explicitly calls the Base class function using the scope resolution operator A::.

This allows you to access the overridden base class method.

🧠 This is function overriding with explicit base call (no polymorphism).
