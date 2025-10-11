// ====================== 1️⃣ Complex Number Addition ======================
#include <iostream>
using namespace std;

class Complex {
private:
    int real, img;

public:
    Complex(int real = 0, int img = 0) {
        this->real = real;
        this->img = img;
    }

    Complex operator+(const Complex &obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.img = img + obj.img;
        return temp;
    }

    void display() {
        cout << real << " + " << img << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(5, 6);
    Complex c3 = c1 + c2;
    c3.display();  // Output: 8 + 10i
    return 0;
}

// ====================== 2️⃣ Number Increment (Simple, No Chaining) ======================
/*
#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v = 0) { value = v; }

    void operator++() { value = value + 1; }       // Prefix
    void operator++(int) { value = value + 1; }   // Postfix

    void display() { cout << value << endl; }
};

int main() {
    Number n1(5);

    ++n1;
    cout << "After Prefix ++: ";
    n1.display();

    n1++;
    cout << "After Postfix ++: ";
    n1.display();

    return 0;
}
*/

// ====================== 3️⃣ Number Increment (Proper Chaining) ======================
/*
#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v = 0) { value = v; }

    Number operator++() {          // Prefix
        value++;
        return *this;
    }

    Number operator++(int) {       // Postfix
        Number temp = *this;
        value++;
        return temp;
    }

    void display() { cout << value << endl; }
};

int main() {
    Number n1(5);

    cout << "Original: "; n1.display();

    ++n1;
    cout << "After Prefix ++: "; n1.display();

    n1++;
    cout << "After Postfix ++: "; n1.display();

    return 0;
}
*/

// ====================== 4️⃣ String Concatenation Using Operator+ ======================
/*
#include <iostream>
using namespace std;

class MyString {
    string str;
public:
    MyString(string s = "") { str = s; }

    MyString operator+(const MyString &obj) {
        MyString temp;
        temp.str = str + obj.str;
        return temp;
    }

    void display() { cout << str << endl; }
};

int main() {
    MyString s1("Hello "), s2("World!");
    MyString ans = s1 + s2;

    cout << "Concatenated String: ";
    ans.display();

    return 0;
}
*/

// ====================== 5️⃣ Number Addition Using Operator+ ======================
/*
#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v = 0) { value = v; }

    Number operator+(const Number &obj) {
        Number temp;
        temp.value = value + obj.value;
        return temp;
    }

    void display() { cout << "Value: " << value << endl; }
};

int main() {
    Number n1(10), n2(20);
    Number sum = n1 + n2;

    cout << "Number Addition Result: ";
    sum.display();

    return 0;
}
*/
