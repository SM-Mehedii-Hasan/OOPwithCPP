// Since there is a constructor in OOP, do we still need to use setter and getter functions?
// Answer:
// Yes, even though a constructor exists in Object-Oriented Programming (OOP), we still need setter and getter functions because they serve different purposes.

// 1.Role of Constructor:
// A constructor is used to initialize an object at the time of creation.
// It allows setting initial values for attributes so that the object starts in a valid state.
// Example:
// Student(string n, int r, float c) {
//     name = n;
//     roll = r;
//     cgpa = c;
// }
// Here, values are set only once—when the object is created.

// 2.Need for Setter Functions:
// A setter allows modifying the value of private data members after the object is created.
// Without setters, the attributes remain fixed once initialized by the constructor.
// Example:
// void setCgpa(float c) {
//     if(c >= 0 && c <= 4.0) cgpa = c;  // validation
// }
// → This ensures controlled modification and validation.

// 3.Need for Getter Functions :
// A getter allows controlled access to private data members.
// This provides encapsulation and data hiding, so values can be read safely without exposing variables directly.
// Example:
// float getCgpa() {
//     return cgpa;
// }


// ✅ Why Use Both?
// Constructor → for initialization (one-time setup).
// Setters/Getters → for controlled access & modification after creation.
// For example:
// You enroll a Student("Mehedi", 101, 3.5) using the constructor.
// Later, if Mehedi improves his result, you can update with setCgpa(3.9) instead of recreating the object.
// 👉 In short:
// Constructor = gives your object valid starting values.
// Setter/Getter = allows safe updates & controlled access later.
#include<iostream>
using namespace std;
class Student{
    string name;
    int roll;
    float cgpa;
    public:
    Student(string name,int roll,float cgpa){
        this->name=name;
        this->roll=roll;
        this->cgpa=cgpa;
    }
    void setName(string n){name=n;}
    void setRoll(int r){ roll=r;}
    void setCgpa(float c){if (c >= 0.0 && c <= 4.0)cgpa = c;}
    string getName(){return name;}
    int getRoll(){return roll;}
    float getCgpa(){return cgpa;}
    void display(){
        cout<<name<<" "<<roll<<" "<<cgpa<<endl;
    }
};
int main(){
    Student s1("mehedi",10,2.5);
    s1.display();
    s1.setCgpa(3.13);
    s1.display();


}
