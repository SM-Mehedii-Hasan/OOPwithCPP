Constructors in C++ OOP
  ----------------------------------
Constructors are special member functions in C++ that are automatically called when an object is created. 
They are used to initialize objects and set up their initial state.
  
Key Points about Constructors:
----------------------------------
Same name as class: Constructors have exactly the same name as the class
No return type: They don't have a return type, not even void
Automatic invocation: Called automatically when object is created
Can be overloaded: Multiple constructors with different parameters
Default constructor: If no constructor is defined, compiler provides a default one
Initialization: Used to initialize object's member variables
Constructors are fundamental to object-oriented programming in C++ as they ensure objects are properly initialized before use.

______________________________1. Default Constructor_______________________________________
#include<iostream>
using namespace std;
class Student{
   
    string name;
    int rollno;
     public:
    Student(){
           
        cout<<"default constructor is called."<<endl;
         name="unknown";
        rollno=0;
    
    }
    void display(){
        cout<<name<<" "<<rollno<<endl;
    }

};
int main(){
    Student s1;
    s1.display();

}
__________________parameterized constructor in C++_______________________________________
#include<iostream>
using namespace std;
class Student{
    string name;
    int rollno;
    int age;
    public:
    Student(string n,int r,int a){
   
        cout<<"parameterized constructor is called"<<endl;
                name=n;
        rollno=r;
        age=a;
     
    }
    void display(){
        cout<<name<<" "<<rollno<<" "<<age<<endl;
    }
};
int main(){
    Student s("mehedi",100,24);
    s.display();

}
____________________________copy constructor________________-

#include<iostream>
using namespace std;
class Student{
    string name;
    int rollno;
    int age;
    public:
    Student(string n,int r,int a){
   
        cout<<"parameterized constructor is called"<<endl;
                name=n;
        rollno=r;
        age=a;
     
    }
    Student(const Student &s)
    
    {
      cout<<"copy constructor is called"<<endl;
                name=s.name;
        rollno=s.rollno;
        age=s.age;
    }
    
    void display(){
        cout<<name<<" "<<rollno<<" "<<age<<endl;
    }
};
int main(){
    Student s1("mehedi",100,24);
      Student s2 = s1;    
    s1.display();
    s2.display();

}
_____________________________Constructor Overloading____________________________
// #include<iostream>
// using namespace std;
// class Student{
//     string name;
//     int rollno;
//     int age;
//     public:
//        Student(){
           
//         cout<<"default constructor is called."<<endl;
//          name="unknown";
//         rollno=0;
//         age=0;
    
//     }
//     Student(string n,int r,int a){
   
//         cout<<"parameterized constructor is called"<<endl;
//                 name=n;
//         rollno=r;
//         age=a;
     
//     }
//        Student(string n,int r){
   
//         cout<<"parameterized constructor is called"<<endl;
//                 name=n;
//         rollno=r;
       
     
//     }
 
    
//     void display(){
//         cout<<name<<" "<<rollno<<" "<<age<<endl;
//     }
// };
// int main(){
//     Student s,s1("mehedi",100,24),s2("hasan",20); 
//     s.display(); 
//     s1.display();
//     s2.display();

// }
#include<iostream>
using namespace std;
class Student{
    string name;int rollno; float cgpa;
    public:
    Student(){
        name="unknown";rollno=0;cgpa=0;
    }
    Student(string n,int r,float c){
        name=n;rollno=r;cgpa=c;
    }
    Student(int r,float c,string n){
         name=n;rollno=r;cgpa=c;
    }
    Student(string n,int r){
        name=n;rollno=r;
    }
    void display(){
        cout<<name<<" "<<rollno<<" "<<cgpa<<endl;
    }


};
int main(){
    Student s1,s2("mehedi",10,3.00),s3(20,3.4,"hasan"),s4("adil",30);
    s1.display(); 
    s2.display();
    s3.display();
    s4.display();

    
}
