| Feature             | OOP (Class)          | Procedural (Struct + Func) | Pure Procedural |
| ------------------- | -------------------- | -------------------------- | --------------- |
| Data + Functions    | ✅ together           | ⚠️ separate                | ❌ separate      |
| Encapsulation       | ✅ private/public     | ❌ public only              | ❌ none          |
| Reusability         | ✅ high (inheritance) | ⚠️ medium                  | ❌ low           |
| Real-world modeling | ✅ natural            | ⚠️ okay                    | ❌ hard          |
| Maintenance         | ✅ easy               | ⚠️ moderate                | ❌ hard          |
💡 Rule of Thumb
Small, simple programs → procedural is okay.
Real-world, complex systems → OOP makes your code organized, reusable, and easier to maintain

  Definition of OOP
👉 Object - Oriented Programming(OOP) is a way of programming where we design software using objects(real - world like entities) that have data(attributes) and functions(behaviors) inside them.
 ____________________________________________________________________________________________________
 🔹 Easy Definition of OOP

OOP (Object-Oriented Programming) is a way of programming where we use objects to represent real-world things.

Each object has data (attributes) and actions (methods/functions).

It helps make code organized, reusable, and easy to understand.
🔹 Example in real life

Object: Your phone

Data: brand, color, model

Actions: call(), message(), playMusic()

Class: Phone (blueprint for making many phones)
_________________________________________________________________________________
OOP = Programming with objects like real-world things.
____________________________________________________________________________________
class Phone { public: string brand; void call() { cout << "Calling..."; } }; // class (blueprint)
Phone myPhone; myPhone.brand = "Samsung"; myPhone.call(); // object using the class
_____________________________________________________________________________________________
✅ Key Points

Class = blueprint

Object = real instance (s1, s2)

Methods inside class can be called using objects

Each object has its own copy of data

// _____________________________________________________________________________________________

// _______________With OOP_______________
// #include<iostream>
// using namespace std;
// class Student{
//     public:
//     string name;
//     int rollNo;
//     float cgpa;
//     void display(){
//         cout<<name<<" "<<rollNo<<" "<<cgpa<<endl;
//     }
// };
// int main(){
//     Student s1,s2;
//     s1.name="mehedi";
//     s1.rollNo=199;
//     s1.cgpa=3.00;
//     cout<<"enter value for object s2:"<<endl;
//     cout<<"Enter name: ";
//     cin>>s2.name;
//     cout<<"\n Enter Roll:";
//     cin>>s2.rollNo;
//     cout<<"\n Enter cgpa:";
//     cin>>s2.cgpa;
//     s1.display();
//     s2.display();

// }
// ___________Without OOP (Procedural Style)_______________


// #include<iostream>
// using namespace std;
// struct Student{
//     public:
//     string name;
//     int rollNo;
//     float cgpa;
   
// };
//  void display(Student s){
//         cout<<s.name<<" "<<s.rollNo<<" "<<s.cgpa<<endl;
//     }
//     int main(){
//             Student s1,s2;
//     s1.name="mehedi";
//     s1.rollNo=199;
//     s1.cgpa=3.00;
//     cout<<"enter value for object s2:"<<endl;
//     cout<<"Enter name: ";
//     cin>>s2.name;
//     cout<<"\n Enter Roll:";
//     cin>>s2.rollNo;
//     cout<<"\n Enter cgpa:";
//     cin>>s2.cgpa;
//     display(s1);
//     display(s2);


//     }

// __________________________________ More Procedural (No struct at all)___________________
// #include<iostream>
// using namespace std;
// void display(string name,int roll,float cg){
//     cout<<name<<"\n"<<roll<<"\n"<<cg<<endl;

// }
// int main(){
//     string name1="mehedi",name2;
//     int rollno1=199,rollno2;
//     float cgpa1=2.00,cgpa2;
//     cout<<"enter value for object s2:"<<endl;
//      cout<<"Enter name: ";
//      cin>>name2;
//      cout<<"\n Enter Roll:";
//      cin>>rollno2;
//      cout<<"\n Enter cgpa:";
//      cin>>cgpa2;
//      display(name1,rollno1,cgpa1);
//        display(name2,rollno2,cgpa2);





// }
