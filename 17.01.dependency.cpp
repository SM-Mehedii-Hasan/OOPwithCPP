// // Dependency Relationship - Explained
// Core Concept:
// A dependency represents a temporary "use" relationship where one class relies on another class for specific functionality,
//  but doesn't maintain a long-term association with it.

//  Key Characteristics:
// Temporary: The relationship exists only during method execution
// No Ownership: The dependent class doesn't contain or own the other class
// Weakest Relationship: More transient than association, aggregation, or composition
// UML Notation:
// ClassA --> ClassB
// Meaning: ClassA uses ClassB temporarily (like in a function parameter or local variable).



#include <iostream>
#include <string>
using namespace std;

class Calculator {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

class Student {
    string name;
    int mathScore;
    int scienceScore;

public:
    Student(const string& n, int math, int science)
        : name(n), mathScore(math), scienceScore(science) {}

    void displayTotal() {
        int total = Calculator::add(mathScore, scienceScore);
        cout << name << "'s total score: " << total
             << " (" << mathScore << " + " << scienceScore << ")\n";
    }

    void displayScores() {
        cout << name << "'s scores - Math: " << mathScore
             << ", Science: " << scienceScore << "\n";
    }
};

int main() {
    Student alice("Alice", 85, 90);
    Student bob("Bob", 78, 82);

    alice.displayTotal();
    bob.displayTotal();

    alice.displayScores();
    bob.displayScores();

    return 0;
}

UML Relationship:Student --> Calculator

Key Point: Student can work perfectly fine without Calculator - 
it only uses Calculator temporarily when it needs to add numbers in the displayTotal() method.
