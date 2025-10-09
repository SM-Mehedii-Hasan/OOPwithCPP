// ⚙️ Function Overloading in C++

// 👉 Definition:
// Function overloading is a feature of compile-time polymorphism in C++ where two or more functions have the same name but different parameters (number or type or order of parameters).

// The compiler decides which function to call based on the arguments passed — this happens at compile time.
#include <iostream>
using namespace std;

class Calculator {
public:
    // Function with two integer parameters
    int add(int a, int b) {
        return a + b;
    }

    // Function with three integer parameters
    int add(int a, int b, int c) {
        return a + b + c;
    }
    //   double add(int a, int b, int c) {->>invalid
    //     return a + b + c;
    // }


    // Function with double parameters
    double add(double a, double b) {
        return a + b;
    }
    double add(int a,double b){
        return a+b;
    }
     double add(double a,int b){
        return a+b;
    }
};

int main() {
    Calculator calc;

    cout << "Sum of 2 and 3: " << calc.add(2, 3) << endl;
    cout << "Sum of 2, 3, and 4: " << calc.add(2, 3, 4) << endl;
    cout << "Sum of 2.5 and 3.5: " << calc.add(2.5, 3.5) << endl;
     cout << "Sum of 2 and 3.5: " << calc.add(2, 3.5) << endl;
       cout << "Sum of 3.5 and 2: " << calc.add(3.5,2) << endl;

    return 0;
}
// 🧠 Key Points:
// All functions have the same name, but different signatures (parameters).
// It helps in code readability and reusability.
// Function return type alone cannot distinguish overloaded functions.
// ❌ Invalid Overloading Example:
// int add(int a, int b);
// double add(int a, int b); // ❌ Error — only return type differs
