#include <iostream>
using namespace std;

// 🔹 Forward declaration — tells the compiler that "Complex" will be defined later
class Complex;

// ===========================
// 💡 CLASS: Calculator
// ===========================
class Calculator {
public:
    // 🔸 Normal function (not related to friendship)
    // This can be called normally to add two integers
    int add(int a, int b) {
        return a + b;
    }

    // 🔸 These two functions will work with Complex objects
    // They need access to private data of Complex
    int sumRealComplex(Complex, Complex);
    int sumComComplex(Complex, Complex);
};

// ===========================
// 💡 CLASS: Complex
// ===========================
class Complex {
    // 🔸 Private data members — normally hidden from outside
    int a, b;

    /*
        🧠 FRIEND CLASS PROPERTY:

        By writing "friend class Calculator;", we are giving full access
        of our private and protected data to ALL the member functions
        of the class Calculator.

        ✅ This means:
        - Calculator::sumRealComplex() can access a and b
        - Calculator::sumComComplex() can also access a and b
        - No need to declare each function as a friend individually
    */
    friend class Calculator;

public:
    // Sets the values of real (a) and imaginary (b) parts
    void setNumber(int n1, int n2) {
        a = n1;
        b = n2;
    }

    // Prints complex number in standard form
    void display() {
        cout << a << " + " << b << "i" << endl;
    }
};

// ===========================
// 💡 DEFINING FRIEND FUNCTIONS (belonging to Calculator)
// ===========================

// 🔸 This function sums the real parts of two Complex numbers
int Calculator::sumRealComplex(Complex x, Complex y) {
    // ✅ Can directly access private members (x.a and y.a)
    return (x.a + y.a);
}

// 🔸 This function sums the imaginary parts of two Complex numbers
int Calculator::sumComComplex(Complex x, Complex y) {
    // ✅ Can directly access private members (x.b and y.b)
    return (x.b + y.b);
}

// ===========================
// 💡 MAIN FUNCTION
// ===========================
int main() {
    Complex c1, c2;
    c1.setNumber(5, 3);
    c2.setNumber(3, 6);

    cout << "Complex Numbers:" << endl;
    c1.display();
    c2.display();

    // Creating calculator object
    Calculator calc;

    // Calling friend class functions to access Complex's private data
    int realSum = calc.sumRealComplex(c1, c2);
    cout << "The sum of real parts of c1 and c2 is: " << realSum << endl;

    int imgSum = calc.sumComComplex(c1, c2);
    cout << "The sum of imaginary parts of c1 and c2 is: " << imgSum << endl;

    return 0;
}

/*
============================================
📘 PROPERTIES OF FRIEND CLASS / FUNCTION
============================================

1️⃣ Not a member of the class
    - Friend functions (or friend classes) are not part of the class itself.

2️⃣ Can access private and protected data
    - Even though data members like a, b are private, a friend can access them.

3️⃣ Must be declared with 'friend' keyword
    - Either declare specific functions:
        friend int Calculator::sumRealComplex(Complex, Complex);
      or declare the entire class:
        friend class Calculator;

4️⃣ Can be declared in any section (public/private/protected)
    - No difference in accessibility; friendship is global to that class.

5️⃣ Friendship is not mutual
    - If Calculator is a friend of Complex, Complex is NOT automatically a friend of Calculator.

6️⃣ Friendship is not transitive
    - If A is a friend of B, and B is a friend of C, A is NOT a friend of C automatically.

7️⃣ Friendship is not inherited
    - If Base class gives friendship, Derived class does NOT get it automatically.

8️⃣ Friend class allows all member functions of that class to access private data
    - Here, both sumRealComplex() and sumComComplex() can access Complex’s private data.

9️⃣ Friend functions must use object names to access data
    - Example: x.a, y.b (not just a or b directly).

10️⃣ Used for operator overloading
    - Friend functions are often used for operator overloading like +, <<, >> etc.

============================================
*/
