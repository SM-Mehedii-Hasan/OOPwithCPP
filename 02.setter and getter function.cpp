// In Object-Oriented Programming (OOP), setter and getter functions are used to control access to class data members.
//  Instead of allowing direct access to variables, we use these functions to read (get) or modify (set) them.
//  This is part of encapsulation, one of the key OOP principles.
//  __________________________________________________________________________________________________________________________
// 1️⃣ Getter Function
// Purpose: To retrieve the value of a private member variable.
// Syntax (C++ example):
// class Student {
// private:
//     int age;  // private member
// public:
//     // Getter
//     int getAge() {
//         return age;
//     }
// };
// Here, getAge() allows code outside the class to read the age value safely.
// _____________________________________________________________________________________________________________________________
// 2️⃣ Setter Function
// Purpose: To set/change the value of a private member variable.
// Syntax (C++ example):
// class Student {
// private:
//     int age;  // private member
// public:
//     // Setter
//     void setAge(int a) {
//         if(a > 0) {  // optional validation
//             age = a;
//         }
//     }
// };
// Here, setAge() allows code outside the class to modify age, but you can include validation logic to prevent invalid values.
// _________________________________________________________________________________________________________________________________
#include<iostream>
using namespace std;
class Student{
    string Name;
    int age;
    string grade;
    public:
    // setter function
    void setName(string s){
        Name=s;
    }
     void setAge(int a){
        age=a;
    }
     void setGrade(string g){
        grade=g;
    }
    // getter function
    string getName(){
        return Name;
    }
    int getAge(){
        if(age>0&&age<100) return age;
        return -1;
    }
    string getGrade(int pin){
        if(pin==123) return grade;
        else return "not accessible!";
    }



};
int main(){
    Student s1,s2;
    s1.setName("mehedi");s1.setAge(25);s1.setGrade("A+");
    s2.setName("hasan");s2.setAge(26);s2.setGrade("A");
    cout<<s1.getName()<<" "<<s1.getAge()<<" "<<s1.getGrade(123)<<endl;
     cout<<s2.getName()<<" "<<s2.getAge()<<" "<<s2.getGrade(123)<<endl;
     

        s1.setName("sabbir");s1.setAge(-25);s1.setGrade("A+");
    s2.setName("tayef");s2.setAge(296);s2.setGrade("A");
    cout<<s1.getName()<<" "<<s1.getAge()<<" "<<s1.getGrade(1423)<<endl;
     cout<<s2.getName()<<" "<<s2.getAge()<<" "<<s2.getGrade(123)<<endl;


}
