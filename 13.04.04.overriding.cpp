// This program demonstrates the process of runtime polymorphism 
// using virtual functions and a vector of base class pointers in C++.
#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
    virtual void speak() { cout << "huhu\n"; }
    virtual ~Animal() {}  // ✅ Always make destructor virtual when using base pointers
};

class Dog : public Animal {
public:
    void speak() override { cout << "bark\n"; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "meow\n"; }
};

int main() {
    vector<Animal*> animals;

    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Animal());
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for (int i = 0; i < animals.size(); i++) {
        animals[i]->speak();  // ✅ Correct: dynamic dispatch happens here
    }

    // ✅ Clean up memory
    for (int i = 0; i < animals.size(); i++) {
        delete animals[i];
    }

    return 0;
}

