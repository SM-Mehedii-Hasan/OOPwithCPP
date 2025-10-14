// 🔹 Exception Handling in C++
//     Exception : An unexpected problem that occurs during program execution. 
//     If not handled, it may cause the program to terminate suddenly.

// 🔹 try block :
//     A block of code that may throw an exception.
//     It’s followed by one or more catch blocks.
//     If an exception occurs, the try block throws that exception.

// 🔹 catch block :
//     A block of code that executes when an exception is thrown from the try block.
//     The code to handle the exception is written inside the catch block.

// 🔹 throw keyword :
//     Used to throw an exception manually.
//     When a throw statement executes,
//     the program jumps to the nearest matching catch block to handle the exception.

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    try {
        if (b == 0) {
            throw "Division by zero error!";  // throwing an exception
        }
        cout << "Result = " << a / b << endl;
    }
    catch (const char *msg) {  // catching the exception
        cout << "Exception caught: " << msg << endl;
    }

    cout << "Program continues normally..." << endl;
    return 0;
}
// _______________________________________________________________________________________________

#include <iostream>
using namespace std;

class Customer {
    string name;
    double balance;
    string account_number;

public:
    Customer(string name, double balance, string account_number) {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << " is credited successfully\n";
        } else {
            throw "Amount should be greater than 0";
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << " is debited successfully\n";
        } 
        else if (amount < 0) {
            throw "Amount should be greater than 0";
        } 
        else {
            throw "Insufficient balance";
        }
    }
};

int main() {
    Customer c1("Mehedi", 5999, "mhr0wpeour345678");

    try {
        c1.deposit(1000);     // ✅ Works fine
        c1.withdraw(40083);   // ❌ Will throw an exception
    } 
    catch (const char *e) {
        cout << "Exception Occurred: " << e << endl;
    }

    cout << "Program continues normally..." << endl;
    return 0;
}
// ________________________________________________________________________


// #include<iostream>
// using namespace std;
// int main(){
//     int x;cin>>x;
//     try{
//         if(x==0) throw(x);
//         if(x==100) throw(" x=100");
//         if(x==5) throw(5.5);

//     }
//     catch(const int x){
//         cout<<" x= "<<x<<endl;
//     }
//     catch(const char* msg){
//         cout<<msg<<endl;
//     }
//     catch(const double x){
//         cout<<"x="<<x<<endl;
//     }
// }
// _________________________________________________________
// #include<iostream>
// using namespace std;
// int main(){
//     int x;cin>>x;
//     try{
//         if(x==0) throw(x);
//         if(x==100) throw(" x=100");
//         if(x==5) throw(5.5);

//     }
  
//     catch(...){
//         cout<<"found exception"<<endl;
//     }
// }
