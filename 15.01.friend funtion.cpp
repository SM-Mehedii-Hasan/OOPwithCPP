// ============================================================================
// 🧠 FRIEND FUNCTION AND FRIEND CLASS — COMPLETE EXAMPLES IN ONE FILE
// ============================================================================
// In C++, a friend function is a special non-member function that has access
// to the private and protected members of a class. It is mainly used when
// two or more classes need to share private data.
// ============================================================================

#include <iostream>
using namespace std;

// ============================================================================
// 🔹 Example 1: Simple Friend Function
// ============================================================================
// Demonstrates how a friend function can access private data of one class.
class Box {
private:
    int width;  // Private data member

public:
    Box(int w) {
        width = w;
    }

    // Declare friend function (can access private members)
    friend void showWidth(Box b);
};

// Definition of friend function (outside class)
void showWidth(Box b) {
    // ✅ Accessing private data directly using object
    cout << "Width of box: " << b.width << endl;
}

// ============================================================================
// 🔹 Example 2: Friend Function between TWO classes
// ============================================================================
// Demonstrates how a single friend function can access private data from
// two different classes.
class Y;  // Forward declaration

class X {
    int data;  // private member
public:
    void setValue(int value) {
        data = value;
    }

    // Declare friend function (shared with class Y)
    friend void add(X, Y);
};

class Y {
    int num;  // private member
public:
    void setValue(int value) {
        num = value;
    }

    // Declare same friend function again (for access to Y's private members)
    friend void add(X, Y);
};

// Friend function definition
void add(X o1, Y o2) {
    // ✅ Can access private data of both classes
    cout << "Sum of private data (X + Y): " << o1.data + o2.num << endl;
}

// ============================================================================
// 🔹 Example 3: Friend Function Returning Object (Complex Numbers)
// ============================================================================
// Demonstrates how a friend function can return an object after processing.
class Complex {
    int a, b;  // private members
public:
    void setNumber(int n1, int n2) {
        a = n1;
        b = n2;
    }

    void printNumber() {
        cout << a << " + " << b << "i" << endl;
    }

    // Friend function declaration
    friend Complex ComplexSum(Complex o1, Complex o2);
};

// Definition of friend function
Complex ComplexSum(Complex o1, Complex o2) {
    Complex o3;
    // ✅ Direct access to private data members of both objects
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

// ============================================================================
// 💡 MAIN FUNCTION — Runs all the examples
// ============================================================================
int main() {
    cout << "========== Example 1: Simple Friend Function ==========\n";
    Box box1(10);
    showWidth(box1);  // Call friend function

    cout << "\n========== Example 2: Friend Function Between Two Classes ==========\n";
    X a1;
    a1.setValue(3);
    Y b1;
    b1.setValue(5);
    add(a1, b1);  // Call friend function accessing both classes

    cout << "\n========== Example 3: Friend Function Returning Object ==========\n";
    Complex c1, c2, sum;
    c1.setNumber(3, 5);
    c2.setNumber(3, 4);

    c1.printNumber();
    c2.printNumber();

    sum = ComplexSum(c1, c2);  // Call friend function
    cout << "Sum of complex numbers: ";
    sum.printNumber();

    return 0;
}

// ============================================================================
// 🧾 PROPERTIES OF FRIEND FUNCTION IN C++
// ============================================================================
// 1️⃣ Not a member of the class
//      - Declared inside but defined outside the class.
// 2️⃣ Cannot be called using an object
//      - Example: c1.ComplexSum() ❌  |  ComplexSum(c1, c2) ✅
// 3️⃣ Has access to private and protected members
//      - Because it’s declared with `friend`.
// 4️⃣ Takes class objects as arguments
//      - Uses objects to access their private data.
// 5️⃣ Can be declared anywhere inside the class
//      - Public, private, or protected — access level doesn’t matter.
// 6️⃣ Cannot access members directly by name
//      - Must use object name, e.g., o1.a not just 'a'.
// 7️⃣ Not inherited
//      - Friendship is not passed to derived classes.
// 8️⃣ Not affected by access specifiers
//      - Its access does not depend on where it’s declared.
// 9️⃣ Can be friend to multiple classes
//      - The same function can access multiple classes.
// 10️⃣ Friendship is not mutual
//      - If A is friend of B, B isn’t automatically a friend of A.
// 11️⃣ Friendship is not transitive
//      - If A is friend of B, and B is friend of C, A is not friend of C.
// 12️⃣ Can be a friend function or friend class
//      - Entire classes can be declared as friends using `friend class ClassName;`
// 13️⃣ Used for operator overloading
//      - Often used for overloading operators like +, ==, <<, >>.
// ============================================================================


🌟 All Properties of Friend Function in C++
| #      | Property                                                             | Explanation                                                                                                                                                |
| ------ | -------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **1**  | **Not a member of the class**                                        | It’s **declared inside** the class (using `friend`) but **defined outside** it. It does not belong to the class scope.                                     |
| **2**  | **Cannot be called using object**                                    | You **cannot** call it like `c1.sumComplex()`. Must be called like a normal function: `ComplexSum(c1, c2)`.                                                |
| **3**  | **Has access to private and protected data**                         | Because it’s declared as a `friend`, it can directly access private/protected members using `object.member`.                                               |
| **4**  | **Takes class objects as arguments**                                 | Since it’s not a member, it needs objects to access their members.                                                                                         |
| **5**  | **Can be declared anywhere inside class (public/private/protected)** | Placement inside class doesn’t affect its access — still has full access if declared as `friend`.                                                          |
| **6**  | **Cannot access members by name directly**                           | Must use the object name like `obj.a` instead of `a`.                                                                                                      |
| **7**  | **It’s not inherited**                                               | Friend status **is not inherited** by derived classes. If a base class grants friendship, its derived class does **not automatically** get it.             |
| **8**  | **It’s not affected by access specifiers**                           | Whether you declare it in `public`, `private`, or `protected`, the access permission is the same.                                                          |
| **9**  | **Can be friend to multiple classes**                                | The same function can be declared as a friend in multiple classes, allowing access to all of them.                                                         |
| **10** | **Friendship is not mutual**                                         | If class `A` is a friend of class `B`, it doesn’t mean class `B` is automatically a friend of class `A`. Friendship must be declared both ways explicitly. |
| **11** | **Friendship is not transitive**                                     | If `A` is a friend of `B`, and `B` is a friend of `C`, that doesn’t mean `A` is a friend of `C`.                                                           |
| **12** | **Can be declared as a friend function or friend class**             | You can make either a single function or an entire class a friend. Example: `friend class B;`                                                              |
| **13** | **Used for operator overloading**                                    | Friend functions are often used when overloading operators that work with two different types (like `+`, `==`, `<<`, `>>`).                                |
