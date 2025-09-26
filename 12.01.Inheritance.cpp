🔹 What is Inheritance?
Inheritance is an Object-Oriented Programming (OOP) concept where one class (child/derived class) can reuse properties and methods of another class (parent/base class).
This helps in code reusability and creating a natural hierarchy between classes.
🔹 Types of Inheritance in C++
Single Inheritance → One class inherits from one base class.
Multilevel Inheritance → A derived class becomes base class for another class.
Multiple Inheritance → A class inherits from more than one base class.
Hierarchical Inheritance → Multiple classes inherit from the same base class.
Hybrid Inheritance → Combination of above types.

🔑 Access Specifiers in Inheritance (C++)
When a class is derived from a base class, the mode of inheritance
 (public, protected, or private) determines how the base class members are treated in the derived class.
 | Inheritance Type | Base `public` → in Derived | Base `protected` → in Derived | Base `private` → in Derived |
| ---------------- | -------------------------- | ----------------------------- | --------------------------- |
| **public**       | public                     | protected                     | ❌ not accessible            |
| **protected**    | protected                  | protected                     | ❌ not accessible            |
| **private**      | private                    | private                       | ❌ not accessible            |
|_______________________________________________________________________________________________________________|

🔍 Notes:

Private members of the base class are never directly accessible in the derived class (regardless of inheritance type).
 They can only be accessed through base class’s public/protected methods.
Public inheritance is the most common — it models an "is-a" relationship.
Protected inheritance is rare, usually used in framework/library design.
Private inheritance means "is-implemented-in-terms-of", not "is-a".

🔹 Base Class
#include <iostream>
using namespace std;

class Base {
public:
    int pub = 1;        // public member
protected:
    int prot = 2;       // protected member
private:
    int priv = 3;       // private member
};
🔹 1. Public Inheritance
class DerivedPublic : public Base {
public:
    void show() {
        cout << "pub = " << pub << endl;   // ✅ accessible (stays public)
        cout << "prot = " << prot << endl; // ✅ accessible (stays protected)
        // cout << "priv = " << priv;      // ❌ ERROR (private not accessible)
    }
};
👉 In DerivedPublic,
pub remains public
prot remains protected
priv is not accessible

🔹 2. Protected Inheritance
class DerivedProtected : protected Base {
public:
    void show() {
        cout << "pub = " << pub << endl;   // ✅ accessible (becomes protected)
        cout << "prot = " << prot << endl; // ✅ accessible (stays protected)
        // cout << "priv = " << priv;      // ❌ ERROR
    }
};
👉 In DerivedProtected,
pub becomes protected
prot stays protected
priv is not accessible


🔹 3. Private Inheritance
class DerivedPrivate : private Base {
public:
    void show() {
        cout << "pub = " << pub << endl;   // ✅ accessible (becomes private)
        cout << "prot = " << prot << endl; // ✅ accessible (becomes private)
        // cout << "priv = " << priv;      // ❌ ERROR
    }
};
👉 In DerivedPrivate,
pub becomes private
prot becomes private
priv is not accessible

🔹 Testing in main()
int main() {
    DerivedPublic d1;
    d1.show();
    cout << d1.pub << endl;   // ✅ allowed (still public)
    DerivedProtected d2;
    d2.show();
    // cout << d2.pub;        // ❌ ERROR (protected in derived)
    DerivedPrivate d3;
    d3.show();
    // cout << d3.pub;        // ❌ ERROR (private in derived)
    return 0;
}



_______________________________________________________________________________________________________________________________________
#include<iostream>
using namespace std;
class Base{
    public:int pub=1;
    protected:int prot=2;
    private: int pri=3;

};
class DerivedPublic:public Base{
    public:
    void show(){
        cout<<"pub="<<pub<<endl;
        cout<<"prot="<<prot<<endl;
        // cout<<"pri="<<pri<<endl;
    }
};
class DerivedProtected:protected Base{
    public:
    void show(){
        cout<<"pub="<<pub<<endl;
        cout<<"prot="<<prot<<endl;
        // cout<<"pri="<<pri<<endl;
    }
};
class DerivedPrivate:private Base{
    public:
    void show(){
         cout<<"pub="<<pub<<endl;
        cout<<"prot="<<prot<<endl;
        // cout<<"pri="<<pri<<endl;
    }
};
int main(){
    DerivedPublic dpublic;
    dpublic.show();
    DerivedProtected dprotected;
    dprotected.show();
    DerivedPrivate dprivate;
    dprivate.show();
    cout<<"----------------------------"<<endl;
     cout<<dpublic.pub<<endl;
    //  cout<<dpublic.prot<<endl;
    // cout<<dpublic.pri<<endl;

}
