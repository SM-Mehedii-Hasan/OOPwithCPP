// In C++, a friend function is a special function that is not a member of a class
//  but has access to the class’s private and protected members.

// It’s mainly used when two or more classes need to share private data.
// 🔹 Syntax
// class ClassName {
// private:
//     int data;

// public:
//     friend void showData(ClassName obj);  // declaration of friend function
// };




#include <iostream>
using namespace std;

class Box {
private:
    int width;

public:
    Box(int w) {
        width = w;
    }

    // Declare friend function
    friend void showWidth(Box b);
};

// Definition of friend function
void showWidth(Box b) {
    cout << "Width of box: " << b.width << endl; // Accessing private member
}

int main() {
    Box box1(10);
    showWidth(box1);
    return 0;
}















#include<iostream>
using namespace std;
class Complex{
    int a,b;
    public:
    void setNumber(int n1,int n2){
        a=n1;
        b=n2;
    }
    void printNumber(){
        cout<<a<<" + "<<b<<"i"<<endl;;
    }
    //Below line means thatnon member - sumComplex function 
     //is allowed to do anything with my private parts(members)
    friend Complex ComplexSum(Complex o1,Complex o2);

};
Complex ComplexSum(Complex o1,Complex o2){
    Complex o3;
    o3.setNumber((o1.a+o2.a),(o1.b+o2.b));
    return o3;

}
int main(){
    Complex c1,c2;
    c1.setNumber(3,5);
    c2.setNumber(3,4);
    c1.printNumber();
    c2.printNumber();
    Complex sum=ComplexSum(c1,c2);
    sum.printNumber();
}


/*
Properties of friend function:
1. Not in the scope of class 
2.Since it is not in the scope of the class ,
it cannot be called from the object of that class .
 c1.sumComplex()==Invalid
 3. Can be invoked without the help of any object
 4.Usually contains the object as arguments
 5. Can be declared  inside public or private section of the class
 6.It cannot access the members directly by their names and need 
 need object_name.member_name to access any member.

*/
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
