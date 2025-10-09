🧩 What is Hybrid Inheritance?

Hybrid Inheritance = Combination of different types of inheritance in one program.

It often leads to “diamond problem”, which is solved using virtual inheritance.

✅ Example: Hybrid Inheritance (Student System)

We’ll combine:

Single inheritance → Student → Test

Hierarchical inheritance → Test → Result, Test → Sports

Multiple inheritance → Result inherits from both Test and Sports

🧠 Diagram (Structure)
      Student
         |
        Test
       /    \
   Sports   Result
         \  /
        FinalResult


  #include<iostream>
using namespace std;

// Base class
class Student {
protected:
    int roll;
public:
    void getRoll(int r) {
        roll = r;
    }
    void showRoll() {
        cout << "Roll No: " << roll << endl;
    }
};

// Derived from Student (Single Inheritance)
class Test : virtual public Student {
protected:
    float marks1, marks2;
public:
    void getMarks(float m1, float m2) {
        marks1 = m1;
        marks2 = m2;
    }
    void showMarks() {
        cout << "Marks in Subject 1: " << marks1 << endl;
        cout << "Marks in Subject 2: " << marks2 << endl;
    }
};

// Another class derived from Student
class Sports : virtual public Student {
protected:
    float score;
public:
    void getScore(float s) {
        score = s;
    }
    void showScore() {
        cout << "Sports Score: " << score << endl;
    }
};

// Derived from both Test and Sports (Multiple + Hierarchical)
class Result : public Test, public Sports {
    float total;
public:
    void display() {
        total = marks1 + marks2 + score;
        showRoll();
        showMarks();
        showScore();
        cout << "Total Score: " << total << endl;
    }
};

int main() {
    Result r1;

    r1.getRoll(101);
    r1.getMarks(85.5, 90.0);
    r1.getScore(9.5);

    r1.display();

    return 0;
}




________________________________________________________________________________










#include<iostream>
using namespace std;

// Base Class
class Student {
public:
    void print() {
        cout << "I am a student." << endl;
    }
};

// Derived Classes from Student
class Male : public Student {
public:
    void printMale() {
        cout << "I am male." << endl;
    }
};

class Female : public Student {
public:
    void printFemale() {
        cout << "I am female." << endl;
    }
};

// Further Derived Classes (Multiple Inheritance)
class Boy : public Student, public Male {
public:
    void BoyPrint() {
        cout << "I am a boy." << endl;
    }
};

class Girl : public Student, public Female {
public:
    void GirlPrint() {
        cout << "I am a girl." << endl;
    }
};

int main() {
    Girl g1;
    Boy b1;

    g1.printFemale();
    b1.printMale();

    return 0;
}
⚙️ Output:
I am female.
I am male.
🧠 Concepts Used Here:
Hierarchical Inheritance →
Male and Female both inherit from Student.

Multiple Inheritance →
Boy inherits from both Student and Male,
Girl inherits from both Student and Female.

Inheritance Ambiguity Possibility →
Since Boy inherits Student twice (once directly, once via Male), it can cause ambiguity if you call print() directly from Boy.
To fix that, you can use virtual inheritance.

⚠️ Ambiguity Fix (using virtual inheritance)
If you want to avoid Student being inherited multiple times:

cpp
Copy code
class Student {
public:
    void print() { cout << "I am a student." << endl; }
};

class Male : virtual public Student {
public:
    void printMale() { cout << "I am male." << endl; }
};

class Female : virtual public Student {
public:
    void printFemale() { cout << "I am female." << endl; }
};

class Boy : public Male {
public:
    void BoyPrint() { cout << "I am a boy." << endl; }
};

class Girl : public Female {
public:
    void GirlPrint() { cout << "I am a girl." << endl; }
};
Now, Boy and Girl share only one common Student base, avoiding duplication.
