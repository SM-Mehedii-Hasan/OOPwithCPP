// ===========================================================================
// 🔹 GENERIC PROGRAMMING IN C++
// ===========================================================================
/*
Generic programming is a programming paradigm that focuses on writing code
that works with any data type.
In C++, this is achieved mainly through templates.
*/


// ===========================================================================
// 💡 WHAT IS A TEMPLATE IN C++
// ===========================================================================
/*
A template in C++ is a blueprint for creating functions or classes that can
work with any data type.
It allows generic programming — writing code once and reusing it for
multiple data types (like int, float, string, etc.).
*/


// ===========================================================================
// 🔹 TWO TYPES OF TEMPLATES IN C++
// ===========================================================================
/*
1️⃣ Function Template
2️⃣ Class Template
*/


// ===========================================================================
// 🧩 1. FUNCTION TEMPLATE
// ===========================================================================
/*
A function template allows the same function to work with different data types.
🔸 Syntax:
template <typename T>
T functionName(T a, T b) {
    // code using type T
}
*/


// ===========================================================================
// 🧱 2. CLASS TEMPLATE
// ===========================================================================
/*
A class template allows the same class to handle different data types.
🔸 Syntax:
template <class T>
class ClassName {
    T data;
public:
    ClassName(T value) { data = value; }
    void show() { cout << data << endl; }
};
*/


// ===========================================================================
// 🔸 EXAMPLE (Function Template)
// ===========================================================================
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(5, 10) << endl;       // int
    cout << add(2.5, 3.8) << endl;    // double
    cout << add(string("Hi "), string("there!")) << endl;  // string
}
// ===========================================================================
// ____________________________FUNCTION TEMPLATE________________________________________
#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax(3, 7) << endl;          // int
    cout << myMax(3.5, 7.5) << endl;      // double
    cout << myMax('g', 'e') << endl;      // char
}
// ===========================================================================
// _________________________________CLASS TEMPLATE________________________________________
#include <iostream>
using namespace std;

template <class T>
class Box {
public:
    T value;
    Box(T v) : value(v) {}
    void show() { cout << value << endl; }
};

int main() {
    Box<int> intBox(10);
    Box<double> doubleBox(3.14);

    intBox.show();
    doubleBox.show();
}
// ===========================================================================
// 🔹 CLASS TEMPLATE USING typename (Modern Style)
// ===========================================================================
#include <iostream>
using namespace std;

template <typename T>
class Box {
public:
    T value;
    Box(T v) : value(v) {}
    void show() { cout << value << endl; }
};

int main() {
    Box<int> intBox(10);
    Box<double> doubleBox(3.14);

    intBox.show();
    doubleBox.show();
}

/*
In C++ templates, both class and typename mean exactly the same thing when
declaring a type parameter.

So these two lines are equivalent:
    template <class T>
    template <typename T>

Both declare a template type parameter named T.

🧠 Why both?
Originally, only class was allowed.
Later, typename was introduced for clarity.

✅ Modern C++ Best Practice:
Use typename (C++11 and later).
*/
// ===========================================================================
// 📦 NORMAL CLASS (WITHOUT TEMPLATE)
// ===========================================================================
#include<iostream>
using namespace std;

class Box {
    int value;
public:
    Box(int v) : value(v) { }
    void display() {
        cout << value << endl;
    }
};

int main() {
     Box b(30);
     b.display();
}
// ===========================================================================
// 📦 CLASS TEMPLATE EXAMPLE
// ===========================================================================
#include<iostream>
using namespace std;

template<typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) { }
    void display() {
        cout << value << endl;
    }
};

int main() {
     Box<int> b(20);
     Box<string> b1("Mehedi");
     Box<float> b2(4.0);
     b.display();
     b1.display();
     b2.display();
}
// ===========================================================================
// 🔁 SWAP FUNCTION (Without Template)
// ===========================================================================
#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 5, b = 6;
    swap(a, b);
    cout << a << " " << b << endl;
}
// ===========================================================================
// 🔁 SWAP FUNCTION TEMPLATE (Generic Version)
// ===========================================================================
#include<iostream>
using namespace std;

template<typename T>
void swapvalue(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 5, b = 6;
    swapvalue(a, b);
    cout << a << " " << b << endl;

    double x = 56.5, y = 6.7556;
    swapvalue(x, y);
    cout << x << " " << y << endl;

    string m = "mehedi", n = "hasan";
    swapvalue(m, n);
    cout << m << " " << n << endl;

    char c1 = 'a', c2 = 'c';
    swapvalue(c1, c2);
    cout << c1 << " " << c2 << endl;
}
// ===========================================================================
// 🔸 TEMPLATE WITH MULTIPLE PARAMETERS
// ===========================================================================
#include<iostream>
using namespace std;

template <class T1, class T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void show() { cout << first << " and " << second << endl; }
};

int main() {
    Pair<int, string> p(1, "Apple");
    p.show();
}
// ===========================================================================
// 🔸 TEMPLATE WITH MULTIPLE PARAMETERS (Using typename)
// ===========================================================================
#include<iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void show() { cout << first << " and " << second << endl; }
};

int main() {
    Pair<int, string> p(1, "Apple");
    p.show();
}
// ============================================================================
// 🎯 MULTIPLE TYPE PARAMETER CLASS TEMPLATE IN C++
// ============================================================================
// This program demonstrates how to define and use a class template
// with multiple type parameters (T1, T2, T3).
// It shows how templates enable writing generic and reusable code.
// ============================================================================

#include <iostream>
using namespace std;

// ============================================================================
// 🔹 CLASS TEMPLATE DEFINITION
// ----------------------------------------------------------------------------
// `template <typename T1, typename T2, typename T3>`
// → Declares a class that can work with three different data types.
//
// This allows creating objects that store and manipulate mixed-type data.
// ============================================================================

template <typename T1, typename T2, typename T3>
class Geek
{
public:
    T1 x;  // First data member (can be of any type)
    T2 y;  // Second data member (can be of any type)
    T3 z;  // Third data member (can be of any type)

    // ------------------------------------------------------------------------
    // 🔸 Constructor
    // Initializes x, y, z with the given values using a member initializer list.
    // ------------------------------------------------------------------------
    Geek(T1 val1, T2 val2, T3 val3) : x(val1), y(val2), z(val3)
    {
    }

    // ------------------------------------------------------------------------
    // 🔸 Member Function: getValues()
    // Prints the values of x, y, and z to the console.
    // ------------------------------------------------------------------------
    void getValues()
    {
        cout << x << " " << y << " " << z;
    }
};

// ============================================================================
// 🔹 MAIN FUNCTION
// ----------------------------------------------------------------------------
// Demonstrates how to create template objects with different type combinations.
// ============================================================================

int main()
{
    // ------------------------------------------------------------------------
    // 🧩 Example 1: Using (int, double, string)
    // Creates an object with three different data types.
    // ------------------------------------------------------------------------
    Geek<int, double, string> intDoubleStringGeek(10, 3.14, "Hello");

    // ------------------------------------------------------------------------
    // 🧩 Example 2: Using (char, float, bool)
    // Creates another object with different type parameters.
    // ------------------------------------------------------------------------
    Geek<char, float, bool> charFloatBoolGeek('A', 5.67f, true);

    // ------------------------------------------------------------------------
    // 🔸 Display Values
    // Prints the stored data for both objects.
    // ------------------------------------------------------------------------
    intDoubleStringGeek.getValues();
    cout << endl;
    charFloatBoolGeek.getValues();

    return 0;
}

// ============================================================================
// 💡 OUTPUT:
// 10 3.14 Hello
// A 5.67 1
// -----------------------------------------------------------------------------
// Note:
// - 'true' is printed as '1' by default.
// - This demonstrates how templates make the class reusable for any data type.
// ============================================================================







🔹 1. Template type parameters (T1, T2, T3)
template <typename T1, typename T2, typename T3>


These are placeholders. They don’t have a type yet — they represent types you’ll decide later.

You use them whenever you want your class or function to work with multiple types without rewriting code.

Example:

template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void show() { cout << first << ", " << second << endl; }
};

int main() {
    Pair<int, string> p(10, "Hello");  // T1 = int, T2 = string
    p.show();
}


✅ Here, T1 and T2 are mandatory placeholders. You must tell C++ what types to use.

🔹 2. Default template types (= int, = string, = float)
template <typename T1 = int, typename T2 = string, typename T3 = float>


The = int (etc.) sets a default type for that template parameter.

This means if you don’t specify a type when creating an object, C++ will automatically use the default.

Example:

template <typename T1 = int, typename T2 = string>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void show() { cout << first << ", " << second << endl; }
};

int main() {
    Pair<> p1(5, "Hi");          // Uses defaults: T1=int, T2=string
    Pair<double, char> p2(3.14, 'A'); // Overrides defaults
    p1.show();
    p2.show();
}

🔹 3. When to use each
| Feature                                     | When to use                                                                                              | Why                                                      |
| ------------------------------------------- | -------------------------------------------------------------------------------------------------------- | -------------------------------------------------------- |
| **Template type parameters (`T1, T2, T3`)** | When you want your class or function to be **generic** and work with **any type**.                       | Provides **flexibility** for multiple data types.        |
| **Default template types (`= int`, etc.)**  | When you want to make some type parameters **optional**, so users **don’t have to always specify them**. | Makes **code easier to use** without losing flexibility. |
🔹 4. Analogy

Think of it like a recipe:

T1, T2, T3 → Ingredients you must choose.

= int, = string, = float → Default ingredients if you don’t choose.

You can override them, but you don’t have to.
