🧩 1. Pure Virtual Function (Object on Stack)
#include<iostream>
using namespace std;
class Animal{
    public:
    virtual void speak() = 0;  // pure virtual function
};
class Dog : public Animal{
    public:
    void speak(){ cout << "bark\n"; }
};
int main(){
    Animal *p;
    Dog d;
    p = &d;
    p->speak();  // Output: bark
}

🧩 2. Pure Virtual Function (Dynamic Object)
#include<iostream>
using namespace std;
class Animal{
    public:
    virtual void speak() = 0;  // pure virtual function
};
class Dog : public Animal{
    public:
    void speak(){ cout << "bark\n"; }
};
int main(){
    Animal *p;
    p = new Dog();
    p->speak();  // Output: bark
}

🧩 3. Virtual Function with Definition (Object on Stack)
#include<iostream>
using namespace std;
class Animal{
    public:
    virtual void speak(){ cout << "huhu\n"; }
};
class Dog : public Animal{
    public:
    void speak(){ cout << "bark\n"; }
};
int main(){
    Animal *p;
    Dog d;
    p = &d;
    p->speak();  // Output: bark
}

🧩 4. Virtual Function with Definition (Dynamic Object)
#include<iostream>
using namespace std;
class Animal{
    public:
    virtual void speak(){ cout << "huhu\n"; }
};
class Dog : public Animal{
    public:
    void speak(){ cout << "bark\n"; }
};
int main(){
    Animal *p;
    p = new Dog();
    p->speak();  // Output: bark
}

🧩 5. Non-Virtual Function (Object on Stack)
#include<iostream>
using namespace std;
class Animal{
    public:
    void speak(){ cout << "huhu\n"; }
};
class Dog : public Animal{
    public:
    void speak(){ cout << "bark\n"; }
};
int main(){
    Animal *p;
    Dog d;
    p = &d;
    p->speak();  // Output: huhu
}

🧩 6. Non-Virtual Function (Dynamic Object)
#include<iostream>
using namespace std;
class Animal{
    public:
    void speak(){ cout << "huhu\n"; }
};
class Dog : public Animal{
    public:
    void speak(){ cout << "bark\n"; }
};
int main(){
    Animal *p;
    p = new Dog();
    p->speak();  // Output: huhu
}
